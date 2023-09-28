#include "Tile.h"

Tile::Tile(char letter) : letter(letter), pointScore(letter_equivalent_letters.at(letter)) {}

bool Tile::operator==(const Tile &other) const {
    return this->letter == other.letter;
}