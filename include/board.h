#pragma once

#include <memory>
#include "chess_definition.h"

namespace chess {
    class Board {
    public:
       	Board();
       	std::shared_ptr<Tile> getTile(int x, int y) const;

    private:
       	std::shared_ptr<Tile> board_[8][8];
};
}
