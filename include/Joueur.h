/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Joueur.h
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#pragma once

#include "Piece.h"
#include <vector>
#include <string>
#include <memory>

namespace classejeux {
	class Joueur;
	class Piece;
	class Jeux;
	class Case;
	class Cavalier;
	class Roi;
	class Tour;
}

class classejeux::Joueur {
public:
	Joueur(std::string nom);
	void ajouterPiece(std::shared_ptr<Piece> piece);
	std::shared_ptr<Piece> pieceTrouvee(int positionX, int positionY);
	std::string avoirNom();
	void modifierPosition(int nouveauX, int nouveauY, int ancienX, int ancienY);
	std::vector<std::shared_ptr<Piece>> avoirPieces() { return pieces_; }
	void retirerPiece(std::shared_ptr<Piece> pieceRetire);
	bool roiEnEchec(Jeux jeu, Joueur adversaire, int x, int y);
	bool echecMat(Jeux jeu, Joueur adversaire);
	std::shared_ptr<Case> avoirPosRoi();

private:
	std::string nom_;
	// Question 3
	std::vector<std::shared_ptr<Piece>> pieces_;
};