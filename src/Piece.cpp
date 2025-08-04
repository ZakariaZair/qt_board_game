#include "piece.h"
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

Tiles Piece::getValidMoves(Tiles tiles) {
    Tiles validTiles = {};
    for (std::pair<int, int> direction : directions_) {
        int index = ;
        if (isMoveRepetitive_) {
            // while
        } else {
            // no while
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
