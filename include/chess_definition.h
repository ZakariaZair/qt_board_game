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
    enum Color { WHITE = 0, BLACK = 1};
    enum ClickState { SELECTION, NORMAL_MOVE, RISKKING, CAREFUL_MOVE};
    typedef std::vector<std::shared_ptr<Tile>> Tiles;
}
