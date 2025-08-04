#include "manager.h"
#include <memory>
using namespace chess;
#include "tile.h"

Manager::Manager(std::map<Color, std::string> players) {
    players_ = players;
}

void Manager::addPieceToTile(int x, int y, std::unique_ptr<Piece>& piece, Tiles tiles) {
    int index = x*8 + y;
    ((std::shared_ptr<Tile>)tiles[index])->setPieceAtTile(piece);
}

std::map<Color, std::string> Manager::getPlayers() {
    return players_;
}

ClickState Manager::getState() {
    return state_;
}

void Manager::selectTile(Tiles board, std::pair<int, int> pos) {
    if (board[pos.first*8 + pos.second]->getPieceAtTile() == nullptr) return;
    selectedTile_.reset();
    selectedTile_ = board[pos.first*8 + pos.second];
    state_ = ClickState::TILESELECTED;
}

// std::shared_ptr<classejeux::Piece> classejeux::Manager::pieceTrouvee(int positionX, int positionY) {
// 	for (auto& piece : pieces_) {
// 		if (piece->position_->avoirPositionX() == positionX && piece->position_->avoirPositionY() == positionY) {
// 			return piece;
// 		}
// 	}
// 	return nullptr;
// }

// void classejeux::Manager::modifierPosition(int nouveauX, int nouveauY, int ancienX, int ancienY) {
// 	for (auto& piece : pieces_) {
// 		if (ancienX == piece->avoirPosition()->avoirPositionX() && ancienY == piece->avoirPosition()->avoirPositionY()) {
// 			piece->avoirPosition()->changerX(nouveauX);
// 			piece->avoirPosition()->changerY(nouveauY);
// 		}
// 	}
// }

// void classejeux::Manager::retirerPiece(std::shared_ptr<Piece> pieceRetire) {
// 	auto it = std::find(pieces_.begin(), pieces_.end(), pieceRetire);
// 	pieces_.erase(it);
// }

// std::shared_ptr<classejeux::Case> classejeux::Manager::avoirPosRoi() {
// 	for (auto&& p : pieces_) {
// 		if (!p->estMangeable()) {
// 			return p->position_;
// 		}
// 	}
// 	return nullptr;
// }

// bool classejeux::Manager::roiEnEchec(Jeux jeu, Manager adversaire, int x, int y) { // Roi en echec :
// 	if (adversaire.pieceTrouvee(x, y)) {
// 		adversaire.retirerPiece(adversaire.pieceTrouvee(x, y));
// 	}
// 	for (auto&& piece : adversaire.avoirPieces()) {	// Chaque piece de l'adversaire
// 		for (std::shared_ptr<Case> cas : piece->mouvementsValide(jeu, adversaire, *this)) {
// 			if (cas->avoirPositionX() == avoirPosRoi()->avoirPositionX() && cas->avoirPositionY() == avoirPosRoi()->avoirPositionY()) {
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// bool classejeux::Manager::echecMat(Jeux jeu, Manager adversaire) {
// 	int xp = 0;
// 	int yp = 0;
// 	for (auto&& i : avoirPieces()) {
// 		std::cout << "Piece ###" << std::endl;
// 		for (auto&& j : i->mouvementsValide(jeu, *this, adversaire)) {
// 			std::cout << "X: " << j->avoirPositionX() << std::endl;
// 			std::cout << "Y: " << j->avoirPositionY() << std::endl;
// 			std::cout << std::endl;
// 			xp = i->avoirPosition()->avoirPositionX();
// 			yp = i->avoirPosition()->avoirPositionY();
// 			i->avoirPosition()->changerX(j->avoirPositionX());
// 			i->avoirPosition()->changerY(j->avoirPositionY());
// 			if (!roiEnEchec(jeu, adversaire, j->avoirPositionX(), j->avoirPositionY())) {
// 				i->avoirPosition()->changerX(xp);
// 				i->avoirPosition()->changerY(yp);
// 				return false;
// 			}
// 			i->avoirPosition()->changerX(xp);
// 			i->avoirPosition()->changerY(yp);

// 		}

// 	}
// 	return true;
// }
