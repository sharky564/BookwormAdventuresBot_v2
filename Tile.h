#ifndef TILE_H
#define TILE_H

#ifndef CONSTANTS_H
#include "constants.h"
#endif // CONSTANTS_H

#include <functional>

struct Tile {
    char letter;
    double pointScore;

    Tile(char letter);

    bool operator==(const Tile &other) const;
};

template<> struct std::hash<Tile> {
    inline size_t operator()(const Tile &tile) const noexcept {
        // return std::hash<char>()(tile.letter);
        return tile.letter;
    };
};


#endif // TILE_H