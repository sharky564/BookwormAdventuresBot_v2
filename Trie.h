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

class Trie {
private:
    int next = 1;
    std::vector<std::vector<int>> x;
public:
    Trie();
    void add_word(std::string&& word);
    bool is_word(const std::string& word);
    int get_root();
    std::string to_string();
}

#endif // TRIE_H