#include "constants.h"

extern const std::unordered_map<char, int> max_letter_counts = {
    {'A', 4}, {'B', 3}, {'C', 3}, {'D', 4}, {'E', 4}, {'F', 3}, {'G', 4}, {'H', 3}, {'I', 4}, {'J', 2}, {'K', 2}, {'L', 4}, {'M', 3}, {'N', 4}, {'O', 3}, {'P', 4}, {'Q', 2}, {'R', 4}, {'S', 4}, {'T', 4}, {'U', 4}, {'V', 3}, {'W', 3}, {'X', 2}, {'Y', 3}, {'Z', 2}, {'?', 16}
};
// extern const std::map<char, double> letter_freq_dict = {
//     {'A', 0.0932}, {'B', 0.0171}, {'C', 0.0218}, {'D', 0.0376}, {'E', 0.13}, {'F', 0.0235}, {'G', 0.0257}, {'H', 0.0252}, {'I', 0.0723}, {'J', 0.0077}, {'K', 0.0056}, {'L', 0.0466}, {'M', 0.0214}, {'N', 0.0547}, {'O', 0.0663}, {'P', 0.0261}, {'Q', 0.0115}, {'R', 0.0752}, {'S', 0.0594}, {'T', 0.0684}, {'U', 0.0428}, {'V', 0.0171}, {'W', 0.0154}, {'X', 0.006}, {'Y', 0.0252}, {'Z', 0.0042}
// };
extern const std::vector<double> letter_freq = {0.0932, 0.0171, 0.0218, 0.0376, 0.13, 0.0235, 0.0257, 0.0252, 0.0077, 0.0056, 0.0466, 0.0214, 0.0547, 0.0663, 0.0261, 0.0115, 0.0752, 0.0594, 0.0684, 0.0428, 0.0171, 0.0154, 0.006, 0.0252, 0.0042, 0};
// get individual probabilities for each letter

extern std::discrete_distribution<int> letter_distribution = std::discrete_distribution<int>(letter_freq.begin(), letter_freq.end());
extern std::mt19937 generator = std::mt19937(std::random_device()());

extern const std::unordered_map<char, double> letter_equivalent_letters = {
    {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2}, {'Y', 1.5}, {'Z', 2}, {'?', 1}
};
extern const int quarter_hearts_table[15] = {1, 2, 3, 4, 6, 8, 11, 14, 18, 22, 27, 32, 38, 44, 52};


// TO ADD: GEMS, IMPURE TILES, TREASURES
// const std::map<std::string, double> gem_power = {
//     {"Amethyst", 0.15}, {"Emerald", 0.2}, {"Sapphire", 0.25}, {"Garnet", 0.3}, {"Ruby", 0.35}, {"Crystal", 0.5}, {"Diamond", 1}
// };
// const std::map<std::string, std::tuple<double, double>> gem_equivalent_letters = {
//     {"Amethyst", {5.25, 6}}, {"Emerald", {6.25, 7}}, {"Sapphire", {8.25, 9}}, {"Garnet", {7.25, 8}}, {"Ruby", {9.25, 10}}, {"Crystal", {10.25, 11}}, {"Diamond", {11.25, 12}}
// };
// const std::map<std::string, std::tuple<double, double>> gem_overkill_thresholds = {
//     {"Amethyst", {2, 3}}, {"Emerald", {3.25, 5}}, {"Sapphire", {8.25, 11}}, {"Garnet", {5.25, 8}}, {"Ruby", {11.25, 14}}, {"Crystal", {14.25, 20}}, {"Diamond", {20.25, 30}}
// };
