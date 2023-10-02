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
<<<<<<< Updated upstream
        trie->add_word(word);
=======
        trie->add_word(std::move(word));
>>>>>>> Stashed changes
    }
    file.close();
    std::cout << "Initialised trie." << std::endl;
    
    std::string initial_rack = "ERSHDLATAFPEYFEO";
    // std::cout << "Enter rack: ";
    // std::cin >> initial_rack;
    Rack rack(16);

    for (char letter : initial_rack) {
<<<<<<< Updated upstream
        rack.add_tile(std::move(Tile(letter)));
=======
        rack.add_tile(Tile(letter));
>>>>>>> Stashed changes
    }

    // print the current rack
    std::cout << "Current rack: ";
    for (Tile tile : rack.get_tiles()) {
        std::cout << tile.letter << " ";
    }
    std::cout << std::endl;
<<<<<<< Updated upstream
    
    auto start = std::chrono::high_resolution_clock::now();
    std::pair<Word, double> best_word = rack.best_word(*trie, 10, 100);
    auto end = std::chrono::high_resolution_clock::now();
=======

    // auto start = std::chrono::high_resolution_clock::now();
    // clock_t tStart = clock();
    // /* Do your stuff here */
    // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    // return 0;

    clock_t t_start = clock();

    std::pair<Word, double> best_word = rack.best_word(*trie, 10, 100);

    // auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken: " << 
        // std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << 
        (double)(clock() - t_start) / CLOCKS_PER_SEC
    << "s" << std::endl;
>>>>>>> Stashed changes
    std::cout << "Best word: " << best_word.first.get_word_str() << std::endl;
    std::cout << "Best word score: " << best_word.first.word_dmg() << std::endl;
    
    return 0;
}