#include <iostream>
#include "piece.h"
#include "king.h"
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
    int index = 0;
    for (std::pair<int, int> direction : directions_) {
        std::pair<int, int> move = pos;
        move.first += direction.first;
        move.second += direction.second;
        index = move.first*8+move.second;
        bool accepted = inOfBounds(move)
            && (board[index]->getPieceAtTile() == nullptr
            || isEnemy(board[index]->getPieceAtTile()));
        if (isMoveRepetitive_) {
            while (accepted) {
                validTiles.push_back(board[index]);
                if (board[index]->getPieceAtTile() != nullptr && isEnemy(board[index]->getPieceAtTile())) break;
                move.first += direction.first;
                move.second += direction.second;
                index = move.first*8+move.second;
                accepted = inOfBounds(move)
                    && (board[index]->getPieceAtTile() == nullptr
                    || isEnemy(board[index]->getPieceAtTile()));
            }
        } else {
            if (accepted) validTiles.push_back(board[index]);
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
