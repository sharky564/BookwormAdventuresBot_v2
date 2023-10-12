#include "Word.h"
#include <iostream>

Word::Word() {
    tiles = std::vector<Tile>();
}
Word::Word(const std::vector<Tile>& tiles) : tiles(tiles) {
    this->word_str = "";
    this->equivalent_letters = 0;
    // std::cout << "Before: " << this->word_str << " " << this->equivalent_letters << std::endl;
    for (auto tile : tiles) {
        this->word_str += tile.letter;
        this->equivalent_letters += tile.pointScore;
    }
    // std::cout << "After: " << this->word_str << " " << this->equivalent_letters << std::endl;
}

std::vector<Tile> Word::get_tiles() const {
    return this->tiles;
}

std::string Word::get_word_str() const {
    return this->word_str;
}

double Word::get_equivalent_letters() const {
    return this->equivalent_letters;
}

int Word::quarter_hearts() const {
    int rounded_equivalent_letters = _round(this->equivalent_letters);
    return quarter_hearts_table[_max(2, _min(rounded_equivalent_letters, 16)) - 2];
}

int Word::word_dmg() const {
    int quarterhearts = this->quarter_hearts();
    double gem_power_buff = 0;
    for (auto& tile : this->tiles) {
        if (tile.is_gem()) {
            gem_power_buff += /*static_cast<int>(tile.is_gem) **/ gem_power.at(tile.gem);
        }
    }
    double overall_dmg = quarterhearts + _ceil(gem_power_buff * quarterhearts);
    return static_cast<int>(overall_dmg);
}

bool Word::operator==(const Word &other) const {
    return this->tiles == other.tiles;
}

bool Word::operator<(const Word &other) const {
    if (this->word_dmg() == other.word_dmg()) {
        if (this->get_word_str().length() == other.get_word_str().length()) {
            return this->get_word_str() < other.get_word_str();
        }
        return this->get_word_str().length() > other.get_word_str().length();
        // return this->get_word_str().length() < other.get_word_str().length();
    }
    return this->word_dmg() > other.word_dmg();
}