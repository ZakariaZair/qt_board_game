#pragma once

#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "chess_definition.h"

namespace chess {
    class Piece {
    public:
        Piece();
       	Piece(Color color);
       	~Piece() = default;

        Tiles getValidMoves(Tiles board, std::pair<int, int> pos);
        std::string getSymbol();
        Color getColor();

        bool inOfBounds(std::pair<int, int> move);

    protected:
        std::vector<std::pair<int, int>> directions_;
       	std::string symbol_;
        Color color_;
        bool isMoveRepetitive_;
    };
}
