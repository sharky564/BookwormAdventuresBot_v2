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

#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <tuple>


class Rack {
public:
    Rack();
    Rack(int size);
    Rack(const std::unordered_multiset<Tile>& tiles);
    Rack(const std::unordered_multiset<Tile>& tiles, int size);

    void add_tile(const Tile& tile);
    void remove_tile(const Tile& tile);
    void regenerate();
    std::unordered_multiset<Tile> get_tiles() const;
    std::set<Word> generate_wordlist(
        Trie &trie, 
        int num_top_words
    );
    void play(Word word, bool regen);
    double incomplete_rack_score(
        Trie &trie, 
        int num_top_words, 
        int num_simulations
    );
    std::pair<Word, double> best_word(
        Trie &trie, 
        int num_top_words, 
        int num_simulations
    );
    
private:
    int size;
    std::unordered_multiset<Tile> tiles;
    void find_words_in_trie(
        TrieNode *curr_node, 
        std::vector<Tile> &curr_word, 
        Rack &curr_rack, 
        std::set<Word> &valid_words, 
        int num_top_words, 
        std::unordered_set<std::string> &cache
    );
};

#endif // RACK_H