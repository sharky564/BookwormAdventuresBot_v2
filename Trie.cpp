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

void Trie::add_word(std::string&& word) {
    TrieNode* curr = this->root;
    for (char letter: word) {
        if (curr->children.find(letter) == curr->children.end()) {
            curr->children[letter] = new TrieNode();
        }
        curr = curr->children[letter];
    }
    curr->word_finished = true;
}

bool Trie::is_word(const std::string &word) {
    TrieNode* curr = this->root;
    for (char letter : word) {
        if (curr->children.find(letter) == curr->children.end()) {
            return false;
        }
        curr = curr->children[letter];
    }
    return curr->word_finished;
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