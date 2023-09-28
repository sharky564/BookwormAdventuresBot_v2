#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool word_finished;
    TrieNode();
    TrieNode(std::unordered_map<char, TrieNode*> children, bool word_finished);
};

#endif // TRIENODE_H