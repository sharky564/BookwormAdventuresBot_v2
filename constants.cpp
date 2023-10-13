#include "constants.h"

extern const int BA1_FLAG = 1;
extern const int GEM_FLAG = 1;
extern const int RAINBOW_FLAG = 0;

extern const std::unordered_map<char, int> max_letter_counts = {
    {'A', 4}, {'B', 3}, {'C', 3}, {'D', 4}, {'E', 4}, {'F', 3}, {'G', 4}, {'H', 3}, {'I', 4}, {'J', 2}, {'K', 2}, {'L', 4}, {'M', 3}, {'N', 4}, {'O', 3}, {'P', 4}, {'Q', 2}, {'R', 4}, {'S', 4}, {'T', 4}, {'U', 4}, {'V', 3}, {'W', 3}, {'X', 2}, {'Y', 3}, {'Z', 2}, {'?', 16}
};
// extern const std::map<char, double> letter_freq_dict = {
//     {'A', 0.0932}, {'B', 0.0171}, {'C', 0.0218}, {'D', 0.0376}, {'E', 0.13}, {'F', 0.0235}, {'G', 0.0257}, {'H', 0.0252}, {'I', 0.0723}, {'J', 0.0077}, {'K', 0.0056}, {'L', 0.0466}, {'M', 0.0214}, {'N', 0.0547}, {'O', 0.0663}, {'P', 0.0261}, {'Q', 0.0115}, {'R', 0.0752}, {'S', 0.0594}, {'T', 0.0684}, {'U', 0.0428}, {'V', 0.0171}, {'W', 0.0154}, {'X', 0.006}, {'Y', 0.0252}, {'Z', 0.0042}
// };
extern const std::vector<double> letter_cumulative_distribution = {0.0932, 0.1103, 0.1321, 0.1697, 0.2997, 0.3232, 0.3489, 0.3741, 0.4464, 0.4541, 0.4597, 0.5063, 0.5277, 0.5824, 0.6487, 0.6748, 0.6863, 0.7615, 0.8209, 0.8893, 0.9321, 0.9492, 0.9646, 0.9706, 0.9958, 1, 1};

// std::discrete_distribution<int> letter_distribution = std::discrete_distribution<int>(letter_probability_distribution.begin(), letter_probability_distribution.end());
std::mt19937 generator = std::mt19937(std::chrono::system_clock::now().time_since_epoch().count());
// std::mt19937 generator = std::mt19937(std::random_device{}());

// extern const std::unordered_map<char, double> letter_equivalent_letters = {
//     {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2}, {'Y', 1.5}, {'Z', 2}, {'?', 1}
// };
// extern const std::unordered_map<char, double> letter_equivalent_letters = {
//     {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 2.5}, {'Y', 2.5}, {'Z', 2.5}, {'?', 1}
// };
// extern const std::unordered_map<char, double> letter_equivalent_letters = {
//     {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 3}, {'Y', 3}, {'Z', 3}, {'?', 1}
// };
extern const std::unordered_map<char, double> letter_equivalent_letters = {
    {'A', 1}, {'B', 1.25}, {'C', 1.25}, {'D', 1}, {'E', 1}, {'F', 1.25}, {'G', 1}, {'H', 1.25}, {'I', 1}, {'J', 1.75}, {'K', 1.75}, {'L', 1}, {'M', 1.25}, {'N', 1}, {'O', 1}, {'P', 1.25}, {'Q', 2.75}, {'R', 2}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 1.5}, {'W', 1.5}, {'X', 3}, {'Y', 3}, {'Z', 3}, {'?', 1}
};
extern const int quarter_hearts_table[15] = {1, 2, 3, 4, 6, 8, 11, 14, 18, 22, 27, 32, 38, 44, 52};


extern const std::unordered_map<char, int> gem_int_conversion = {
    {'n', 0}, {'a', 1}, {'e', 2}, {'s', 3}, {'g', 4}, {'r', 5}, {'c', 6}, {'d', 7}
};

extern const std::unordered_map<int, char> int_gem_conversion = {
    {0, 'n'}, {1, 'a'}, {2, 'e'}, {3, 's'}, {4, 'g'}, {5, 'r'}, {6, 'c'}, {7, 'd'}
};

extern const std::vector<std::string> gem_names = {
    "None", "Amethyst", "Emerald", "Sapphire", "Garnet", "Ruby", "Crystal", "Diamond"
};

extern const std::unordered_map<int, double> gem_power = {
    {1, 0.15}, {2, 0.2}, {3, 0.25}, {4, 0.3}, {5, 0.35}, {6, 0.5}, {7, 1}
};
extern const std::map<int, int> gem_equivalent_letters = {
    {1, 6}, {2, 7}, {3, 9}, {4, 8}, {5, 10}, {6, 11}, {7, 16}
};

// TO ADD: OVERKILL, TREASURE
// extern const std::map<char, std::tuple<double, double>> gem_overkill_thresholds = {
//     {'a', {2, 3}}, {'e', {3.25, 5}}, {'s', {8.25, 11}}, {'g', {5.25, 8}}, {'r', {11.25, 14}}, {'c', {14.25, 20}}, {'d', {20.25, 30}}
// };