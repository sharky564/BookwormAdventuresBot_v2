#include "Trie.h"

#include <functional>


Trie::Trie() {
    this->root = new TrieNode();
}

Trie::Trie(TrieNode* root) {
    this->root = root;
}

TrieNode* Trie::get_root() {
    return this->root;
}

void Trie::add_word(const std::string &word) {
    TrieNode* current_node = this->root;
    for (char letter : word) {
        int child_index = (int)(letter - 'A');
        // check if the children vector at the child_index of the letter is empty
        if (current_node->children[child_index] == nullptr) {
            current_node->children[child_index] = new TrieNode();
        }
        current_node = current_node->children[child_index];
    }
    current_node->word_finished = true;
}

bool Trie::is_word(const std::string &word) {
    TrieNode* current_node = this->root;
    for (char letter : word) {
        int child_index = (int)(letter - 'A');
        if (current_node->children[child_index] == nullptr) {
            return false;
        }
        current_node = current_node->children[letter];
    }
    return current_node->word_finished;
}

std::string Trie::to_string() {
    std::function<std::string(TrieNode*, std::string)> recur = [&](TrieNode* node, std::string indent) -> std::string { // recursive function to print the trie
        std::string result = "";
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                result += indent + (char)('A' + i) + "\n";
                result += recur(node->children[i], indent + "  ");
            }
        }
        return result;
    };
    return recur(root, "");
}