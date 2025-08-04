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
        pos.first += direction.first*8;
        pos.second += direction.second;
        bool accepted = inOfBounds(pos)
            && board[pos.first*8+pos.second]
            && board[pos.first*8+pos.second]->getPieceAtTile() == nullptr;
        if (isMoveRepetitive_) {
            // while
            while(accepted) {
                validTiles.push_back(board[pos.first*8+pos.second]);
                pos.first += direction.first*8;
                pos.second += direction.second;
                accepted = inOfBounds(pos)
                    && board[pos.first*8+pos.second]
                    && board[pos.first*8+pos.second]->getPieceAtTile() == nullptr;
            }
        } else {
            // no while
            if (accepted) validTiles.push_back(board[pos.first*8+pos.second]);
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

// bool Piece::autrePieceAmis(std::shared_ptr<Tile> cas, Player joueur) {
// 	for (auto&& piece : joueur.avoirPieces()) {
// 		int posX = piece->avoirPosition()->avoirPositionX();
// 		int posY = piece->avoirPosition()->avoirPositionY();
// 		if (posX == cas->avoirPositionX() && posY == cas->avoirPositionY()) {
// 			return true;
// 		}

// 		if (position_->avoirPositionY() == posY) {
// 			if (position_->avoirPositionX() < posX && cas->avoirPositionX() > posX) { return true; }

// 			else if (position_->avoirPositionX() > posX && cas->avoirPositionX() < posX) { return true; }
// 		}

// 		if (position_->avoirPositionX() == posX) {
// 			if (position_->avoirPositionY() < posY && cas->avoirPositionY() > posY) { return true; }

// 			else if (position_->avoirPositionY() > posY && cas->avoirPositionY() < posY) { return true; }
// 		}
// 	}
// 	return false;
// }

// bool classejeux::Piece::autrePieceEnnemi(std::shared_ptr<Case> cas, Joueur joueur) {
// 	for (auto&& piece : joueur.avoirPieces()) {
// 		int posX = piece->avoirPosition()->avoirPositionX();
// 		int posY = piece->avoirPosition()->avoirPositionY();

// 		if (posX == cas->avoirPositionX() && posY == cas->avoirPositionY()) {
// 			return false;
// 		}

// 		if (position_->avoirPositionY() == posY) {
// 			if (position_->avoirPositionX() < posX && cas->avoirPositionX() > posX) { return true; }

// 			else if (position_->avoirPositionX() > posX && cas->avoirPositionX() < posX) { return true; }
// 		}

// 		if (position_->avoirPositionX() == posX) {
// 			if (position_->avoirPositionY() < posY && cas->avoirPositionY() > posY) { return true; }

// 			else if (position_->avoirPositionY() > posY && cas->avoirPositionY() < posY) { return true; }
// 		}
// 	}
// 	return false;
// }
