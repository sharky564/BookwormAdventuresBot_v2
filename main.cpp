#include "Trie.h"
#include "Rack.h"


#include <iostream>
#include <fstream>
#include <chrono>


int main() {
    std::ifstream file; 
    file.open("ba2-dictionary-playable-anagram.txt");
    std::string word;
    Trie* trie = new Trie();
    if (file.is_open()) {
        while (file >> word) {
            trie->add_word(word);
        }
    }
    file.close();
    std::cout << "Initialised trie." << std::endl;
    
    std::string initial_rack = "ERSHDLATAFPEYFEO";
    // std::cout << "Enter rack: ";
    // std::cin >> initial_rack;
    Rack* rack = new Rack(16);

    for (char letter : initial_rack) {
        rack->add_tile(Tile(letter));
    }

    // print the current rack
    std::cout << "Current rack: ";
    for (Tile tile : rack->get_tiles()) {
        std::cout << tile.letter << " ";
    }
    std::cout << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    std::pair<Word, double> best_word = rack->best_word(*trie, 10, 100);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Best word: " << best_word.first.get_word_str() << std::endl;
    std::cout << "Best word score: " << best_word.first.word_dmg() << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    
    return 0;
}