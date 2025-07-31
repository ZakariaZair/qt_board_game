#pragma once

#include <utility>
#include <QLabel>
#include "chess_definition.h"

namespace chess {
    class Tile {
    public:
       	Tile();
       	Tile(int x, int y);
        ~Tile();
       	std::pair<int, int> getPos();
        int getPosX();
        int getPosY();
       	void setPos(int x, int y);
    private:
       	std::pair<int, int> position_;
        QLabel* label_;
    };
}
