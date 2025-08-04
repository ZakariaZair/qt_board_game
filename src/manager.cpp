#include <iostream>
#include "manager.h"
#include <memory>
using namespace chess;
#include "tile.h"
#include "piece.h"

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

void Manager::selectTile(Tiles board, std::pair<int, int> clic) {
    int index = clic.first*8 + clic.second;
    if (board[index]->getPieceAtTile() == nullptr) return;

    state_ = ClickState::TILESELECTED;
    selectedTile_.reset();
    selectedTile_ = board[index];
    selectedTile_->selectedRepresentation();
    Tiles validTiles = selectedTile_->getPieceAtTile()->getValidMoves(board, selectedTile_->getPos());
    for (std::shared_ptr<Tile> tile : validTiles) tile->validMoveRepresentation();
}

void Manager::movePiece(Tiles board, std::pair<int, int> clic) {
    int index = clic.first*8 + clic.second;
    if (board[index] == selectedTile_) return;
    selectedTile_->refreshRepresentation();

    Tiles validTiles = selectedTile_->getPieceAtTile()->getValidMoves(board, selectedTile_->getPos());
    for (std::shared_ptr<Tile> tile : validTiles) tile->refreshRepresentation();
    bool isValid = false;
    for (std::shared_ptr<Tile> tile : validTiles) {if ( board[index] == tile) isValid = true; }
    if (!isValid) { state_ = ClickState::NOTHING; return;}

    if (board[index]->getPieceAtTile() == nullptr) {
        // performer des check avant ex: roi en echec
        board[index]->setPieceAtTile(selectedTile_->getPieceAtTile());
        board[index]->refreshRepresentation();
        selectedTile_->refreshRepresentation();
    }
    selectedTile_.reset();
    state_ = ClickState::NOTHING;
}

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
