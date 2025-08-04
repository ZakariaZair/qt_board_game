#include <iostream>
#include "piece.h"
#include "tile.h"
#include "chess_definition.h"
#include <cstddef>
#include <utility>
using namespace chess;

Piece::Piece() :
symbol_("WRONG"),
directions_({}) {
}

Piece::Piece(Color color) :
color_(color),
symbol_("WRONG"),
directions_({}) {
}

Tiles Piece::getValidMoves(Tiles board, std::pair<int,int> pos) {
    Tiles validTiles = {};
    for (std::pair<int, int> direction : directions_) {
        std::pair<int, int> move = pos;
        move.first += direction.first;
        move.second += direction.second;
        bool accepted = inOfBounds(move)
            && (board[move.first*8+move.second]->getPieceAtTile() == nullptr
            || isEnemy(board[move.first*8+move.second]->getPieceAtTile()));
        if (isMoveRepetitive_) {
            while (accepted) {
                validTiles.push_back(board[move.first*8+move.second]);
                move.first += direction.first;
                move.second += direction.second;
                accepted = inOfBounds(move)
                    && (board[move.first*8+move.second]->getPieceAtTile() == nullptr
                    || isEnemy(board[move.first*8+move.second]->getPieceAtTile()));
            }
        } else {
            if (accepted) validTiles.push_back(board[move.first*8+move.second]);
        }
    }
    return validTiles;
}

std::string Piece::getSymbol() {
    return symbol_;
}

Color Piece::getColor() {
    return color_;
}

bool Piece::inOfBounds(std::pair<int,int> move) {
    return 0 <= move.first && move.first < 8 && 0 <= move.second && move.second < 8;
}

bool Piece::isEnemy(std::unique_ptr<Piece>& piece) {
    return color_ != piece->getColor();
}
