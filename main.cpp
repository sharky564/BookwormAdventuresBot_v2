#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include "Trie.h"
#include "Rack.h"

#include <iostream>
#include <fstream>
#include <chrono>

Trie* trie;

void load_words_to_trie(int version) {
    std::ifstream file;
    if (version == 1) {
        file.open("ba1-dictionary-playable.txt");
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
    std::cout << "Initialised trie of words for BA" << version << std::endl;
}


void initialise_constants(int version, int book, int chapter) {
    int level = 10 * book + chapter;
    if (version == 1) {
        const int RAINBOW_FLAG = 0;
        if (level == 11) {
            const int PRE_SCRAMBLE_FLAG = 1;
            const int GEM_FLAG = 0;
            const std::unordered_map<char, double> letter_equivalent_letters = {
                {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2}, {'Y', 1.5}, {'Z', 2}, {'?', 1}
            };
        }
        else if (level <= 13) {
            const int PRE_SCRAMBLE_FLAG = 1;
            const int GEM_FLAG = 0;
            const std::unordered_map<char, double> letter_equivalent_letters = {
                {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2.5}, {'Y', 2.5}, {'Z', 2.5}, {'?', 1}
            };
        }
        else if (level == 14) {
            const int PRE_SCRAMBLE_FLAG = 0;
            const int GEM_FLAG = 0;
            const std::unordered_map<char, double> letter_equivalent_letters = {
                {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2.5}, {'Y', 2.5}, {'Z', 2.5}, {'?', 1}
            };
        }
        else if (level <= 16) {
            const int PRE_SCRAMBLE_FLAG = 0;
            const int GEM_FLAG = 1;
            const std::unordered_map<char, double> letter_equivalent_letters = {
                {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2.5}, {'Y', 2.5}, {'Z', 2.5}, {'?', 1}
            };
        }
        else if (level <= 25) {
            const int PRE_SCRAMBLE_FLAG = 0;
            const int GEM_FLAG = 1;
            const std::unordered_map<char, double> letter_equivalent_letters = {
                {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 3}, {'Y', 3}, {'Z', 3}, {'?', 1}
            };
        }
        else {
            const int PRE_SCRAMBLE_FLAG = 0;
            const int GEM_FLAG = 1;
            const std::unordered_map<char, double> letter_equivalent_letters = {
                {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 2}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 3}, {'Y', 3}, {'Z', 3}, {'?', 1}
            };
        }
    }
    else {
        const int PRE_SCRAMBLE_FLAG = 0;
        const int GEM_FLAG = 1;
        const std::unordered_map<char, double> letter_equivalent_letters = {
            {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2}, {'Y', 1.5}, {'Z', 2}, {'?', 1}
        };
        if (level <= 15) {
            const int RAINBOW_FLAG = 0;
        }
        else {
            const int RAINBOW_FLAG = 1;
        }
    }
}


void play_game(int book, int chapter) {
    while (true) {
        std::string initial_rack;
        std::string gems;
        int monster;
        int health;
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
        std::cout << "Enter monster number: ";
        std::cin >> monster;
        std::cout << "Enter health remaining: ";
        std::cin >> health;
        double power = power_table[book - 1][chapter - 1][monster - 1];

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
        std::pair<Word, double> best_word = rack.best_word_health(*trie, health, power, 20, 500);
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
    // generate num_tiles randomly from 2 to 14
    for (int i = 0; i < num_simulations; i++) {
        int num_tiles = ((double)rand() / RAND_MAX) * 13 + 2;
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
        double score = rack.incomplete_rack_score(0, false, *trie, 10, 1000);
        std::cout << rack_str << " " << score << std::endl;
        file << rack_str << " " << score << std::endl;
    }
    file.close();
}


void frequent_words(int num_simulations, std::string file_name) {
    Rack rack;
    std::map<std::string, int> word_freq;
    for (int i = 0; i < num_simulations; i++) {
        rack = Rack();
        rack.regenerate(0, false);
        std::set<Word> wordlist = rack.generate_wordlist(*trie, 10);
        for (Word word : wordlist) {
            word_freq[word.get_word_str()]++;
        }
        if (i % 1000 == 0) {
            std::cout << i << std::endl;
        }
    }
    // sort the map by value
    std::vector<std::pair<std::string, int>> word_freq_vec(word_freq.begin(), word_freq.end());
    std::sort(word_freq_vec.begin(), word_freq_vec.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
        return a.second > b.second;
    });
    std::ofstream file;
    file.open(file_name);
    for (auto word_freq : word_freq_vec) {
        if (word_freq.second >= 200) {
            file << word_freq.first << " " << word_freq.second << std::endl;
        }
    }
}


int main(int argc, char** argv) {
    int version = atoi(argv[1]);
    int book = atoi(argv[2]);
    int chapter = atoi(argv[3]);
    
    load_words_to_trie(version);
    initialise_constants(version, book, chapter);

    play_game(book, chapter);
    return 0;
}