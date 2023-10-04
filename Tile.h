#ifndef TILE_H
#define TILE_H

#ifndef CONSTANTS_H
#include "constants.h"
#endif // CONSTANTS_H

#include <functional>

struct Tile {
    char letter;
    int gem;
    double pointScore;
    bool used_in_word;

    Tile();
    Tile(char letter);
    Tile(char letter, int gem);

    bool operator==(const Tile &other) const;
    bool is_gem() const;
};

template<> struct std::hash<Tile> {
    inline size_t operator()(const Tile &tile) const noexcept {
        return tile.letter, tile.gem;
    };
};


#endif // TILE_H