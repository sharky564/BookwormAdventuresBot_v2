#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include "Trie.h"
#include "Rack.h"


#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>


int main() {
    std::ifstream file; 
    file.open("ba2-dictionary-playable-anagram.txt");
    std::string word;
    Trie* trie = new Trie();
    while (file >> word) {
        trie->add_word(std::move(word));
    }
    file.close();
    std::cout << "Initialised trie." << std::endl;
    
    std::string initial_rack = "ERSHDLATAFPEYFEO";
    // std::cout << "Enter rack: ";
    // std::cin >> initial_rack;
    Rack rack(16);

    for (char letter : initial_rack) {
        rack.add_tile(Tile(letter));
    }

    // print the current rack
    std::cout << "Current rack: ";
    for (Tile tile : rack.get_tiles()) {
        std::cout << tile.letter << " ";
    }
    std::cout << std::endl;

    clock_t t_start = clock();
    std::pair<Word, double> best_word = rack.best_word(*trie, 10, 100);
    std::cout << "Time taken: " << 
        (double)(clock() - t_start) / CLOCKS_PER_SEC
    << "s" << std::endl;

    std::cout << "Best word: " << best_word.first.get_word_str() << std::endl;
    std::cout << "Best word score: " << best_word.first.word_dmg() << std::endl;
    
    return 0;
}