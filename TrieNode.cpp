#include "TrieNode.h"

TrieNode::TrieNode() : children(std::unordered_map<char, TrieNode*>()), word_finished(false) {}

TrieNode::TrieNode(std::unordered_map<char, TrieNode*> children, bool word_finished) : children(children), word_finished(word_finished) {}