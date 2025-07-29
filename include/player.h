#pragma once

#include <vector>
#include <string>
#include <memory>
#include "chess_definition.h"

namespace chess {
    class Player {
    public:
       	Player(std::string nom);
       	void ajouterPiece(std::shared_ptr<Piece> piece);
       	std::shared_ptr<Piece> pieceTrouvee(int positionX, int positionY);
       	std::string avoirNom();
       	void modifierPosition(int nouveauX, int nouveauY, int ancienX, int ancienY);
       	std::vector<std::shared_ptr<Piece>> avoirPieces() { return pieces_; }
       	void retirerPiece(std::shared_ptr<Piece> pieceRetire);
       	bool roiEnEchec(Board jeu, Player adversaire, int x, int y);
       	bool echecMat(Board jeu, Player adversaire);
       	std::shared_ptr<Tile> avoirPosRoi();
    private:
       	std::string nom_;
       	std::vector<std::shared_ptr<Piece>> pieces_;
    };
}
