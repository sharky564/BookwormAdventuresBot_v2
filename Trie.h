#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>

#include "TrieNode.h"

class Trie {
    public:
        Trie();
        Trie(std::unordered_map<char, TrieNode*> children, bool word_finished);
        void add_word(std::string&& word);
        bool is_word(const std::string &word);
        TrieNode* get_root();
        std::string to_string();
    private:
        TrieNode* root;
};

#endif // TRIE_H