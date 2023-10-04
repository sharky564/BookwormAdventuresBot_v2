#include "Tile.h"

Tile::Tile() {}

Tile::Tile(char letter) : letter(letter), gem(0), pointScore(letter_equivalent_letters.at(letter)), used_in_word(false) {}

Tile::Tile(char letter, int gem) : letter(letter), gem(gem), pointScore(letter_equivalent_letters.at(letter)), used_in_word(false) {}

bool Tile::operator==(const Tile &other) const {
    return this->letter == other.letter;
}

bool Tile::is_gem() const {
    return this->gem != 0;
}