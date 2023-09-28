#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <vector>
#include <unordered_map>
#include <random>

extern const std::unordered_map<char, int> max_letter_counts;
extern const std::vector<double> letter_freq;

extern std::discrete_distribution<int> letter_distribution;
extern std::mt19937 generator;

extern const std::unordered_map<char, double> letter_equivalent_letters;
extern const int quarter_hearts_table[15];

// TO ADD: GEMS, IMPURE TILES, TREASURES
// const std::map<std::string, double> gem_power;
// const std::map<std::string, std::tuple<double, double>> gem_equivalent_letters;
// const std::map<std::string, std::tuple<double, double>> gem_overkill_thresholds;

#endif // CONSTANTS_H