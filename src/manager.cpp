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

void Manager::moveToTarget(Tiles board, std::pair<int, int> clic) {
    int targetIndex = clic.first*8 + clic.second;
    if (board[targetIndex] == selectedTile_) return;
    selectedTile_->refreshRepresentation();

    Tiles validTiles = selectedTile_->getPieceAtTile()->getValidMoves(board, selectedTile_->getPos());
    if (selectedTile_->getPieceAtTile()->getSymbol() == "♔") {
        removeRiskyMoves(board, validTiles);
    };
    for (std::shared_ptr<Tile> tile : validTiles) tile->refreshRepresentation();
    bool isValid = false;
    for (std::shared_ptr<Tile> tile : validTiles) if (board[targetIndex] == tile) isValid = true;
    if (!isValid) {state_ = ClickState::SELECTION; return;}

    if (isKingCheck(board, targetIndex)) {state_ = ClickState::SELECTION; return;}
    board[targetIndex]->setPieceAtTile(selectedTile_->getPieceAtTile());
    board[targetIndex]->refreshRepresentation();
    selectedTile_->refreshRepresentation();
    state_ = ClickState::SELECTION;
    isOpponentCheckmate(board);

    nextTurnColor();
    selectedTile_.reset();
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

std::shared_ptr<Tile> Manager::getKingTile(Tiles board, Color color) {
    std::shared_ptr<Tile> kingTile;
    for (auto tile: board) if (tile->getPieceAtTile() != nullptr && tile->getPieceAtTile()->getSymbol() == "♔" && tile->getPieceAtTile()->getColor() == color) kingTile = tile;
    return kingTile;
}

bool Manager::isKingCheck(Tiles board, int index) {
    bool simulationCheck = simulateSingleStepCheck(board, selectedTile_, board[index], turnColor_);
    std::shared_ptr<Tile> kingTile = getKingTile(board, turnColor_);
    kingTile == selectedTile_ ? selectedTile_->checkRepresentation() : kingTile->checkRepresentation();
    return simulationCheck;
}

bool Manager::isOpponentCheckmate(Tiles board) {
    std::shared_ptr<Tile> kingTile = getKingTile(board, turnColor_ == Color::WHITE ? Color::BLACK : Color::WHITE);
    std::set<std::shared_ptr<Tile>> opponentValidTiles = {};
    for (auto tile: board) {
        if (tile->getPieceAtTile() == nullptr) continue;
        if (tile->getPieceAtTile()->getColor() != turnColor_) continue;
        Tiles currentPieceValidTiles = tile->getPieceAtTile()->getValidMoves(board, tile->getPos());
        opponentValidTiles.insert(currentPieceValidTiles.begin(), currentPieceValidTiles.end());
    }

    if (opponentValidTiles.find(kingTile) != opponentValidTiles.end()) {
        kingTile->checkRepresentation();
        Tiles kingValidTiles = kingTile->getPieceAtTile()->getValidMoves(board, kingTile->getPos());
        bool canMoveToSafety = false;
        for (auto kingValidTile: kingValidTiles) if (opponentValidTiles.find(kingValidTile) == opponentValidTiles.end()) canMoveToSafety = true;
        if (!canMoveToSafety) {
            std::cout << "cannot move to safety !!!" << std::endl;
            // bool canBeProtected = false;
            // for (auto kingValidTile: kingValidTiles) if (opponentValidTiles.find(kingTile) != opponentValidTiles.end()) ;
            // if (can)
        }
        return true;
    }
    return false;
}

bool Manager::simulateSingleStepCheck(Tiles board, std::shared_ptr<Tile> sourceTile, std::shared_ptr<Tile> targetTile, Color color) {
    std::shared_ptr<Tile> kingTile = getKingTile(board, color);
    std::set<std::shared_ptr<Tile>> opponentValidTiles = {};

    Tile simulationTempTile = Tile();
    simulationTempTile.setPieceAtTile(targetTile->getPieceAtTile());
    targetTile->setPieceAtTile(sourceTile->getPieceAtTile());

    for (auto tile: board) {
        if (tile->getPieceAtTile() == nullptr) continue;
        if (tile->getPieceAtTile()->getColor() == turnColor_) continue;
        Tiles currentPieceValidTiles = tile->getPieceAtTile()->getValidMoves(board, tile->getPos());
        opponentValidTiles.insert(currentPieceValidTiles.begin(), currentPieceValidTiles.end());
    }

    sourceTile->setPieceAtTile(targetTile->getPieceAtTile());
    if (simulationTempTile.getPieceAtTile() != nullptr) targetTile->setPieceAtTile(simulationTempTile.getPieceAtTile());

    if (opponentValidTiles.find(kingTile) != opponentValidTiles.end()) {
        return true;
    }
    return false;
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
