#include "Trie.h"

#include <functional>


// Trie::Trie() {
//     this->root = new TrieNode();
// }

const int MAXN = 1e6;

Trie::Trie() {
    this->x = std::vector<std::vector<int>>(MAXN, std::vector<int>(26, -1));
}

// Trie::Trie(TrieNode* root) {
//     this->root = root;
// }

// TrieNode* Trie::get_root() {
//     return this->root;
// }

inline constexpr int Trie::get_root() {
    return 0;
}

// void Trie::add_word(std::string&& word) {
//     TrieNode* curr = this->root;
//     for (char letter: word) {
//         int child_index = (int)(letter - 'A');
//         // check if the children vector at the child_index of the letter is empty
//         if (curr->children[child_index] == nullptr) [[unlikely]] {
//             curr->children[child_index] = new TrieNode();
//         }
//         curr = curr->children[child_index];
//     }
//     curr->word_finished = true;
// }

void Trie::add_word(std::string&& word) {
    int curr_state = 0;
    for(char c: word) {
        int idx = c - 'A';
        if(this->x[curr_state][idx] == -1)
            curr_state = x[curr_state][idx] = this->next++;
        else
            curr_state = x[curr_state][idx];
    }
}

// bool Trie::is_word(const std::string &word) {
//     TrieNode* curr = this->root;
//     for (char letter : word) {
//         int child_index = (int)(letter - 'A');
//         if (curr->children[child_index] == nullptr) [[unlikely]] {
//             return false;
//         }
//         curr = curr->children[letter];
//     }
//     return curr->word_finished;
// }

bool Trie::is_word(const std::string& word) {
    int curr_state = 0;
    for(char c: word) {
        int idx = c - 'A';
        if(this->x[curr_state][idx] == -1)
            return false;
        curr_state = x[curr_state][idx];
    }
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

int main() {
    
}