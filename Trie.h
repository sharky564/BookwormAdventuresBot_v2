#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

#include "TrieNode.h"


const int MAXN = 1e6;
#include <bitset>

class Trie {
private:
    int next = 1;
public:
    int nodes[MAXN][26]; // nodes of the trie, stored as an adjacency list of sorts
    std::bitset<MAXN> word_finished;

    Trie();
    void add_word(std::string&& word);
    bool is_word(const std::string& word) const;
    constexpr int get_root() const {
        return 0;
    };
    std::string to_string() const;
};

#endif // TRIE_H