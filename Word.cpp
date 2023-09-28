#include "Word.h"

Word::Word(const std::vector<Tile>& tiles) : tiles(tiles) {
    for (auto tile : tiles) {
        this->word_str += tile.letter;
        this->equivalent_letters += tile.pointScore;
    }
}

std::vector<Tile> Word::get_tiles() const {
    return this->tiles;
}

std::string Word::get_word_str() const {
    return this->word_str;
}

int Word::quarter_hearts() const {
    int rounded_equivalent_letters = _round(this->equivalent_letters);
    return quarter_hearts_table[_max(2, _min(rounded_equivalent_letters, 16)) - 2];
}

int Word::word_dmg() const {
    int quarterhearts = this->quarter_hearts();
    double overall_dmg = quarterhearts;
    return (int)overall_dmg;
}

bool Word::operator==(const Word &other) const {
    return this->tiles == other.tiles;
}

bool Word::operator<(const Word &other) const {
    if (this->word_dmg() == other.word_dmg()) {
        if (this->get_word_str().length() == other.get_word_str().length()) {
            return this->get_word_str() < other.get_word_str();
        } else {
            return this->get_word_str().length() > other.get_word_str().length();
        }
        // return this->get_word_str().length() < other.get_word_str().length();
    }
    return this->word_dmg() > other.word_dmg();
}