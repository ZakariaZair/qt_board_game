#pragma once
#include <vector>
#include <memory>

namespace chess {
    class King;
    class Knight;
    class Manager;
    class Piece;
    class Rook;
    class Tile;
    enum Color {
        WHITE = 0,
        BLACK = 1
    };
    typedef std::vector<std::shared_ptr<Tile>> Tiles;
}
