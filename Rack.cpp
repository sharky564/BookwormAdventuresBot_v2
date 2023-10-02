#include "Rack.h"

#ifndef CONSTANTS_H
#include "constants.h"
#endif // CONSTANTS_H

#include <cassert>
#include <unordered_map>
#include <random>
#include <tuple>
#include <algorithm>
#include <queue>


Rack::Rack() {
    this->tiles = std::unordered_multiset<Tile>({});
    this->size = 16;
}

Rack::Rack(int size) {
    this->tiles = std::unordered_multiset<Tile>({});
    this->size = size;
}

Rack::Rack(const std::unordered_multiset<Tile>& tiles) {
    this->tiles = tiles;
    this->size = 16;
    assert(tiles.size() <= 16);
}

Rack::Rack(const std::unordered_multiset<Tile>& tiles, int size) {
    this->tiles = tiles;
    this->size = size;
    assert(tiles.size() <= size);
}

std::unordered_multiset<Tile> Rack::get_tiles() const {
    return this->tiles;
}

inline void Rack::add_tile(const Tile& tile) {
    this->tiles.emplace(tile);
}

inline void Rack::remove_tile(const Tile& tile) {
    this->tiles.erase(tile);
}

void Rack::regenerate() {
    int num_tiles_to_add = size - this->tiles.size();
    std::unordered_map<char, int> letter_freq;
    for (auto tile : this->tiles) {
        letter_freq[tile.letter]++;
    }
    for (int i = 0; i < num_tiles_to_add; i++) {
        int letter_index_to_add = letter_distribution(generator);
        char letter_to_add = 'A' + letter_index_to_add;
        if (letter_freq[letter_to_add] < max_letter_counts.at(letter_to_add)) {
            this->add_tile(Tile(letter_to_add));
            letter_freq[letter_to_add]++;
        } else {
            i--;
        }
    }
}

void Rack::find_words_in_trie(
    const Trie& trie,
    int curr_node, // TrieNode *curr_node, 
    std::vector<Tile> &curr_word, 
    Rack &curr_rack, 
    std::set<Word> &valid_words, 
    int num_top_words, 
    std::unordered_set<std::string> &cache
) {
    std::string cache_key = "";
    for (Tile tile : curr_word) {
        cache_key += tile.letter;
    }
    if (cache.find(cache_key) != cache.end()) {
        return;
    }
    cache.insert(cache_key);

    if(trie.word_finished[curr_node]) {
        valid_words.insert(Word(curr_word));
        if (valid_words.size() > num_top_words) {
            valid_words.erase(--valid_words.end());
        }
    }
    
    for (auto tile : curr_rack.tiles) {
        int idx = (int)(tile.letter - 'A');
        if (tile.letter == '?' 
            || trie.x[curr_node][idx] != -1
        ) {
            Rack new_rack = curr_rack;
            new_rack.remove_tile(tile);

            curr_word.push_back(tile);
            if (tile.letter != '?') [[likely]] {
                find_words_in_trie(
                    trie,
                    trie.x[curr_node][idx], 
                    curr_word, 
                    new_rack, 
                    valid_words, 
                    num_top_words, 
                    cache
                );
            }
            else [[unlikely]] {
                for(int i=0;i<26;i++) {
                    if (trie.x[curr_node][i] != -1) {
                        find_words_in_trie(
                            trie,
                            trie.x[curr_node][i], 
                            curr_word, 
                            new_rack, 
                            valid_words, 
                            num_top_words, 
                            cache
                        );
                    }                    
                }
            }
            // curr_rack.add_tile(tile);
            
            curr_word.pop_back();
        }
    }
}


std::set<Word> Rack::generate_wordlist(const Trie &trie, int num_top_words) {
    std::set<Word> valid_words;
    std::vector<Tile> curr_word = std::vector<Tile>();
    Rack curr_rack = Rack(this->tiles, this->size);
    std::unordered_set<std::string> cache;
    find_words_in_trie(
        trie,
        trie.get_root(), 
        curr_word, 
        curr_rack, 
        valid_words, 
        num_top_words, 
        cache
    );
    return valid_words;
}

void Rack::play(Word word, bool regen) {
    for (auto tile : word.get_tiles()) {
        this->remove_tile(tile);
    }
    if (regen) {
        this->regenerate();
    }
}

double Rack::incomplete_rack_score(
    const Trie &trie, 
    int num_top_words, 
    int num_simulations
) {
    double sum = 0;
    for (int i = 0; i < num_simulations; i++) {
        Rack curr_rack = Rack(this->tiles, this->size);
        curr_rack.regenerate();
        std::set<Word> curr_wordlist = curr_rack.generate_wordlist(trie, num_top_words);
        double curr_score = 0;
        int count = 0;
        auto it = curr_wordlist.begin();
        for (int j = 0; j < num_top_words && it != curr_wordlist.end(); j++, it++) {
            curr_score += it->word_dmg();
            count++;
        }
        sum += curr_score / count;
    }
    return sum / num_simulations;
}

std::pair<Word, double> Rack::best_word(
    const Trie &trie, 
    int num_top_words, 
    int num_simulations
) {
    std::set<Word> wordlist = this->generate_wordlist(trie, num_top_words);
    Word best_word = Word();
    double best_score = 0;
    for (auto word : wordlist) {
        double curr_score = word.word_dmg();
        Rack curr_rack = Rack(this->tiles, this->size);
        curr_rack.regenerate();
        curr_rack.play(word, false);
        curr_score += curr_rack.incomplete_rack_score(trie, num_top_words, num_simulations);
        if (curr_score > best_score) {
            best_score = curr_score;
            best_word = std::move(word);
        }
    }
    return std::make_pair(best_word, best_score);
}