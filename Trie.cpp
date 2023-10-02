#include "Trie.h"

#include <functional>

Trie::Trie() {
    for(int i=0;i<MAXN;i++) {
        for(int j=0;j<26;j++)
            x[i][j] = -1;
        word_finished[i] = false;
    }
}

constexpr int Trie::get_root() const {
    return 0;
}

void Trie::add_word(std::string&& word) {
    int curr_state = 0;
    for(char c: word) {
        int idx = c - 'A';
        if(this->x[curr_state][idx] == -1)
            curr_state = x[curr_state][idx] = this->next++;
        else
            curr_state = x[curr_state][idx];
    }
    this->word_finished[curr_state] = true;
}

bool Trie::is_word(const std::string& word) const {
    int curr_state = 0;
    for(char c: word) {
        int idx = c - 'A';
        if(this->x[curr_state][idx] == -1)
            return false;
        curr_state = x[curr_state][idx];
    }
    return this->word_finished[curr_state];
}

std::string Trie::to_string() const {
    std::function<std::string(int, std::string)> recur = [&](int node, std::string indent) -> std::string { // recursive function to print the trie
        std::string result = "";
        for (int i = 0; i < 26; i++) {
            if (this->x[node][i] != -1) {
                result += indent + (char)('A' + i) + "\n";
                result += recur(this->x[node][i], indent + "  ");
            }
        }
        return result;
    };
    return recur(this->get_root(), "");
}
/*
#include <iostream>

int main() {
    Trie trie;
    trie.add_word("FUCK");
    trie.add_word("FFS");
    trie.add_word("SHIT");

    std::cout << trie.to_string() << "\n"; return 0;
}
*/