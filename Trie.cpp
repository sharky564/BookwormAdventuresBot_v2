#include "Trie.h"

#include <functional>


Trie::Trie() {
    this->root = new TrieNode();
}

Trie::Trie(std::unordered_map<char, TrieNode*> children, bool word_finished) {
    this->root = new TrieNode(children, word_finished);
}

TrieNode* Trie::get_root() {
    return this->root;
}

void Trie::add_word(const std::string &word) {
    TrieNode* current_node = this->root;
    for (char letter : word) {
        if (current_node->children.find(letter) == current_node->children.end()) {
            current_node->children[letter] = new TrieNode();
        }
        current_node = current_node->children[letter];
    }
    current_node->word_finished = true;
}

bool Trie::is_word(const std::string &word) {
    TrieNode* current_node = this->root;
    for (char letter : word) {
        if (current_node->children.find(letter) == current_node->children.end()) {
            return false;
        }
        current_node = current_node->children[letter];
    }
    return current_node->word_finished;
}

std::string Trie::to_string() {
    std::function<std::string(TrieNode*, std::string)> recur = [&](TrieNode* node, std::string indent) -> std::string { // recursive function to print the trie
        std::string result = "";
        for (auto child : node->children) { // iterate through the children of the node
            result += indent + child.first + (child.second->word_finished ? "$" : "") + "\n" + recur(child.second, indent + "  ");
        }
        return result;
    };
    return recur(root, "");
}