#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>
#include <vector>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool word_finished;
    // std::vector<TrieNode*> children;
    TrieNode();
    TrieNode(
        std::unordered_map<char, TrieNode*> children, 
        bool word_finished
    );
};

#endif // TRIENODE_H