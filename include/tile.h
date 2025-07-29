#pragma once

#include <utility>
#include "chess_definition.h"

namespace chess {
    class Tile {
    public:
       	Tile();
       	Tile(int x, int y);
       	int getPos();
       	void setPos(int x, int y);
    private:
       	std::pair<int, int> position_;
    };
}
