#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

#include "TrieNode.h"

// class Trie {
//     public:
//         Trie();
//         Trie(TrieNode* root);
//         void add_word(std::string&& word);
//         bool is_word(const std::string &word);
//         TrieNode* get_root();
//         std::string to_string();
//     private:
//         TrieNode* root;
// };

const int MAXN = 1e6;
#include <bitset>

class Trie {
private:
    int next = 1;
public:
    int x[MAXN][26];
    std::bitset<MAXN> word_finished;

    Trie();
    void add_word(std::string&& word);
    bool is_word(const std::string& word) const;
    // bool is_word_finished(int x) const;
    constexpr int get_root() const;
    std::string to_string() const;
};

#endif // TRIE_H