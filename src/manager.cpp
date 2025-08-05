#include <iostream>
#include "manager.h"
#include <memory>
using namespace chess;
#include "tile.h"
#include "piece.h"

Manager::Manager(std::map<Color, std::string> players) {
    players_ = players;
}

void Manager::addPieceToTile(int x, int y, std::unique_ptr<Piece>& piece, Tiles board) {
    int index = x*8 + y;
    (board[index])->setPieceAtTile(piece);
}

std::map<Color, std::string> Manager::getPlayers() {
    return players_;
}

ClickState Manager::getState() {
    return state_;
}

void Manager::nextTurnColor() {
    turnColor_ = turnColor_ == Color::WHITE ? Color::BLACK : Color::WHITE;
}

void Manager::selectTile(Tiles board, std::pair<int, int> clic) {
    int index = clic.first*8 + clic.second;
    if (board[index]->getPieceAtTile() == nullptr || board[index]->getPieceAtTile()->getColor() != turnColor_) return;

    state_ = ClickState::NORMAL_MOVE;
    selectedTile_ = board[index];
    selectedTile_->selectedRepresentation();
    Tiles validTiles = selectedTile_->getPieceAtTile()->getValidMoves(board, selectedTile_->getPos());
    if (selectedTile_->getPieceAtTile()->getSymbol() == "♔") {
        removeRiskyMoves(board, validTiles);
    };
    for (std::shared_ptr<Tile> tile : validTiles) tile->validMoveRepresentation();
}

void Manager::move(Tiles board, std::pair<int, int> clic) {
    int index = clic.first*8 + clic.second;
    if (board[index] == selectedTile_) return;
    selectedTile_->refreshRepresentation();

    Tiles validTiles = selectedTile_->getPieceAtTile()->getValidMoves(board, selectedTile_->getPos());
    if (selectedTile_->getPieceAtTile()->getSymbol() == "♔") {
        removeRiskyMoves(board, validTiles);
    };
    for (std::shared_ptr<Tile> tile : validTiles) tile->refreshRepresentation();
    bool isValid = false;
    for (std::shared_ptr<Tile> tile : validTiles) if (board[index] == tile) isValid = true;
    if (!isValid) {state_ = ClickState::SELECTION; return;}

    if (isKingCheck(board, index)) return;
    board[index]->setPieceAtTile(selectedTile_->getPieceAtTile());
    board[index]->refreshRepresentation();
    selectedTile_->refreshRepresentation();
    // isOpponentKingCheck(board);

    nextTurnColor();
    selectedTile_.reset();
    state_ = ClickState::SELECTION;
}

void Manager::removeRiskyMoves(Tiles board, Tiles& validTiles) {
    std::set<std::shared_ptr<Tile>> toRemove = {};
    for (auto tile: board) {
        if (tile->getPieceAtTile() == nullptr) continue;
        if (tile->getPieceAtTile()->getColor() == turnColor_) continue;
        Tiles currentPieceValidTiles = tile->getPieceAtTile()->getValidMoves(board, tile->getPos());
        toRemove.insert(currentPieceValidTiles.begin(), currentPieceValidTiles.end());
    }
    auto it = validTiles.begin();
    while (it != validTiles.end()) {
        if (toRemove.find(*it) != toRemove.end()) {
            validTiles.erase(it);
        } else {
            it++;
        }
    }
}


bool Manager::isKingCheck(Tiles board, int index) {
    board[index]->setPieceAtTile(selectedTile_->getPieceAtTile());
    std::shared_ptr<Tile> kingTile;
    std::set<std::shared_ptr<Tile>> opponentValidTiles = {};
    for (auto tile: board) {
        if (tile->getPieceAtTile() == nullptr) continue;
        if (tile->getPieceAtTile()->getSymbol() == "♔" && tile->getPieceAtTile()->getColor() == turnColor_) kingTile = tile;
        if (tile->getPieceAtTile()->getColor() == turnColor_) continue;
        Tiles currentPieceValidTiles = tile->getPieceAtTile()->getValidMoves(board, tile->getPos());
        opponentValidTiles.insert(currentPieceValidTiles.begin(), currentPieceValidTiles.end());
    }
    selectedTile_->setPieceAtTile(board[index]->getPieceAtTile());

    if (opponentValidTiles.find(kingTile) != opponentValidTiles.end()) {
        kingTile->checkRepresentation();
        return true;
    }
    return false;
}

bool Manager::isOpponentKingCheck(Tiles board) {

}



void Manager::toggleValidMoves(Tiles board) {
    for (auto tile: board) {
        if (tile->getPieceAtTile() == nullptr) continue;
        Tiles currentPieceValidTiles = tile->getPieceAtTile()->getValidMoves(board, tile->getPos());
        for (auto& currentPieceValidTile: currentPieceValidTiles) currentPieceValidTile->validMoveRepresentation();
    }
}

void Manager::toggleValidMoves(Tiles board, Color color) {
    for (auto tile: board) {
        if (tile->getPieceAtTile() == nullptr) continue;
        if (tile->getPieceAtTile()->getColor() != color) continue;
        tile->selectedRepresentation();
        Tiles currentPieceValidTiles = tile->getPieceAtTile()->getValidMoves(board, tile->getPos());
        for (auto& currentPieceValidTile: currentPieceValidTiles) currentPieceValidTile->validMoveRepresentation();
    }
}

void Manager::resetToggles(Tiles board){
    for (auto tile: board) {
        tile->refreshRepresentation();
    }
}
