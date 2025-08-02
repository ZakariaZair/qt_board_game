#pragma once

#include <vector>
#include <string>
#include <memory>
#include "chess_definition.h"

namespace chess {
    enum PlayerColor {
        WHITE = 0,
        BLACK = 1
    };

    class Player {
    public:
       	Player(std::string nom);
       	void ajouterPiece(std::shared_ptr<Piece> piece);
       	void modifierPosition(int nouveauX, int nouveauY, int ancienX, int ancienY);
       	bool roiEnEchec(Board jeu, Player adversaire, int x, int y);
       	bool echecMat(Board jeu, Player adversaire);
       	void retirerPiece(std::shared_ptr<Piece> pieceRetire);
       	std::string avoirNom();
       	std::shared_ptr<Piece> pieceTrouvee(int x, int y);
       	std::shared_ptr<Tile> avoirPosRoi();
       	std::vector<std::shared_ptr<Piece>> getPieces();
    private:
       	std::string nom_;
       	std::vector<std::shared_ptr<Piece>> pieces_;
    };
}
