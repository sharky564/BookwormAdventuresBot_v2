#ifndef RACK_H
#define RACK_H

#ifndef TILE_H
#include "Tile.h"
#endif // TILE_H

#ifndef WORD_H
#include "Word.h"
#endif // WORD_H

#ifndef TRIE_H
#include "Trie.h"
#endif // TRIE_H

#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <tuple>


class Rack {
public:
    Rack();
    Rack(int size);
    Rack(std::vector<Tile>& tiles);
    Rack(std::vector<Tile>&& tiles);
    Rack(std::vector<Tile>& tiles, int size);

    inline void add_tile(const Tile& tile) {
        this->tiles.push_back(tile);
    };
    inline void remove_tile(const Tile& tile) {
        auto it = std::find(this->tiles.begin(), this->tiles.end(), tile);
        if (it != this->tiles.end()) {
            this->tiles.erase(it);
        }
    };
    void regenerate(int gem, bool random);
    std::vector<Tile> get_tiles() const;
    std::set<Word> generate_wordlist(
        const Trie &trie, 
        int num_top_words
    );
    void play(Word word, bool regen);
    double incomplete_rack_score(
        int gem,
        bool random,
        const Trie &trie, 
        int num_top_words, 
        int num_simulations
    );
    std::pair<Word, double> best_word(
        const Trie &trie, 
        int num_top_words, 
        int num_simulations
    );
    
private:
    int size;
    std::vector<Tile> tiles;
    void find_words_in_trie(
        const Trie& trie,
        int curr_node,
        // TrieNode *curr_node, 
        std::vector<Tile> &curr_word,
        Rack &curr_rack,
        std::set<Word> &valid_words, 
        int num_top_words, 
        std::unordered_set<std::string> &cache
    );
};

#endif // RACK_H