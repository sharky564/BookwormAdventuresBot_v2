#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include "Trie.h"
#include "Rack.h"

#include <iostream>
#include <fstream>
#include <chrono>

Trie* trie;

void load_words_to_trie() {
    std::ifstream file;
    if (BA1_FLAG == 1) {
        file.open("ba1-dictionary-playable-anagram.txt");
    }
    else {
        file.open("ba2-dictionary-playable-anagram.txt");
    }
    std::string word;
    trie = new Trie();
    if (file.is_open()) {
        while (file >> word) {
            trie->add_word(std::move(word));
        }
    }
    file.close();
    std::cout << "Initialised trie." << std::endl;
}

void play_game() {
    while (true) {
        std::string initial_rack;
        std::string gems;
        std::cout << "Enter rack: ";
        std::cin >> initial_rack;
        if (GEM_FLAG == 1) {
            std::cout << "Enter gems: ";
            std::cin >> gems;
        }
        else {
            for (int i = 0; i < initial_rack.size(); i++) {
                gems += "n";
            }
        }

        std::vector<Tile> tiles;
        for (int i = 0; i < initial_rack.size(); i++) {
            tiles.emplace_back(Tile(initial_rack[i], gem_int_conversion.at(gems[i])));
        }

        Rack rack(std::move(tiles));

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
        if (GEM_FLAG == 1) {
            std::cout << "Gems:      ";
            for (Tile tile : best_word.first.get_tiles()) {
                std::cout << int_gem_conversion.at(tile.gem);
            }
            std::cout << std::endl;
            std::cout << "Expected gem: " << gem_names[best_word.first.expected_gem()] << std::endl;
        }
        std::cout << "Best word score: " << best_word.first.word_dmg() << std::endl;
    }
}


void generate_data(int num_simulations) {
    // function that will generate random incomplete rack scores and write them to a file
    // this will be used as training data
    Rack rack;
    std::ofstream file;
    file.open("generated_data_2.txt");
    std::unordered_set<std::string> seen_racks;
    // generate num_tiles randomly from 2 to 15
    for (int i = 0; i < num_simulations; i++) {
        int num_tiles = ((double)rand() / RAND_MAX) * 14 + 2;
        std::cout << "i = " << i << ", num_tiles = " << num_tiles << std::endl;
        rack = Rack();
        std::unordered_map<char, int> letter_freq;
        for (int i = 0; i < num_tiles; i++) {
            double random_num = (double)generator() / generator.max();
            int letter_index_to_add = 0;
            while (letter_cumulative_distribution[letter_index_to_add] < random_num) {
                letter_index_to_add++;
            }
            char letter_to_add = 'A' + letter_index_to_add;
            if (letter_freq[letter_to_add] < max_letter_counts.at(letter_to_add)) {
                rack.add_tile(Tile(letter_to_add));
                letter_freq[letter_to_add]++;
            } else {
                i--;
            }
        }
        std::string rack_str = rack.get_rack_str();
        if (seen_racks.find(rack_str) != seen_racks.end()) {
            i--;
            continue;
        }
        seen_racks.insert(rack_str);
        double score = rack.incomplete_rack_score(0, false, *trie, 50, 1000);
        std::cout << rack_str << " " << score << std::endl;
        file << rack_str << " " << score << std::endl;
    }
    file.close();
}


int main() {
    load_words_to_trie();
    // play_game();
    generate_data(10000);
    return 0;
}