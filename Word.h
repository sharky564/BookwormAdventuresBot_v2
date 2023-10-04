#ifndef WORD_H
#define WORD_H

#ifndef TILE_H
#include "Tile.h"
#endif // TILE_H

#ifndef UTILS_H
#include "utils.h"
#endif // UTILS_H

#ifndef CONSTANTS_H
#include "constants.h"
#endif // CONSTANTS_H

#include <string>
#include <vector>

class Word {
    public:
        Word();
        Word(const std::vector<Tile>& tiles); // Constructor
        int word_dmg() const; // Returns the damage of the word
        std::string get_word_str() const; // Returns the string of the word
        double get_equivalent_letters() const; // Returns the equivalent letters of the word
        std::vector<Tile> get_tiles() const; // Returns the tiles of the word
        bool operator==(const Word &other) const; // Overloads the == operator
        bool operator<(const Word &other) const; // Overloads the < operator
    private:
        std::vector<Tile> tiles;
        int quarter_hearts() const; // Returns the quarter hearts of the word
        std::string word_str;
        double equivalent_letters;
};

template<> struct std::hash<Word> {
    inline size_t operator()(const Word &word) const noexcept {
        return std::hash<std::string>()(word.get_word_str());
    };
};

#endif // WORD_H