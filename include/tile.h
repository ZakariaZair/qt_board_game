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
        QLabel* getLabel();

       	void setPos(int x, int y);
        void setLabel(QLabel* label);

    private:
       	std::pair<int, int> position_;
        QLabel* label_;
    };
}
