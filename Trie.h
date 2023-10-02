#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

#include "TrieNode.h"

class Trie {
    public:
        Trie();
        Trie(TrieNode* root);
        void add_word(const std::string &word);
        bool is_word(const std::string &word);
        TrieNode* get_root();
        std::string to_string();
    private:
        TrieNode* root;
};

#endif // TRIE_H