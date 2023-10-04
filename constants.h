#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <vector>
#include <unordered_map>
#include <random>

extern const int BA1_FLAG;
extern const int GEM_FLAG;

extern const std::unordered_map<char, int> max_letter_counts;
extern const std::vector<double> letter_freq;

extern std::discrete_distribution<int> letter_distribution;
extern std::mt19937 generator;

extern const std::unordered_map<char, double> letter_equivalent_letters;
extern const int quarter_hearts_table[15];

extern const std::unordered_map<char, int> gem_int_conversion;
extern const std::unordered_map<int, char> int_gem_conversion;

extern const std::unordered_map<int, double> gem_power;
extern const std::map<int, std::tuple<double, double>> gem_equivalent_letters;

// TO ADD: OVERKILL, TREASURES
// const std::map<char, std::tuple<double, double>> gem_overkill_thresholds;

#endif // CONSTANTS_H