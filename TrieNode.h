#ifndef TRIENODE_H
#define TRIENODE_H

#include <cstdio>
#include <cstring>

// struct TrieNode {
//     TrieNode* children[26];
//     bool word_finished;
//     // std::vector<TrieNode*> children;
//     TrieNode();
// };

struct TrieNode {
    int val;
    bool word_finished;
};

#endif // TRIENODE_H