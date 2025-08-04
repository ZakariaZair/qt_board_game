#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "chess_definition.h"

namespace chess {
    class Manager {
    public:
       	Manager(std::map<Color, std::string> players);
        void addPieceToTile(int x, int y, std::unique_ptr<Piece>& piece, Tiles tiles);
        void selectTile(Tiles board, std::pair<int, int> pos);
        void checkSelectedTile();
       	// std::shared_ptr<Piece> pieceTrouvee(int x, int y);
       	// void modifierPosition(int nouveauX, int nouveauY, int ancienX, int ancienY);
       	// bool roiEnEchec(int x, int y);
       	// bool echecMat();
       	// void retirerPiece(std::shared_ptr<Piece> pieceRetire);
       	// std::string avoirNom();
       	// std::shared_ptr<Tile> avoirPosRoi();
       	// Pieces getPieces();
        ClickState getState();
        std::map<Color, std::string> getPlayers();
    private:
        std::shared_ptr<Tile> selectedTile_;
       	std::map<Color, std::string> players_;
        ClickState state_;
    };
}
