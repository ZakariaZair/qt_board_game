/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Joueur.cpp
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Cree le 9 avril 2022
*/

#include <iostream>
#include <string>
#include "Joueur.h"

classejeux::Joueur::Joueur(std::string nom) {
	nom_ = nom;
}

std::string classejeux::Joueur::avoirNom() {
	return nom_;
}

void classejeux::Joueur::ajouterPiece(std::shared_ptr<Piece> piece) {
 	pieces_.push_back(move(piece));
}

std::shared_ptr<classejeux::Piece> classejeux::Joueur::pieceTrouvee(int positionX, int positionY) {
	for (auto& piece : pieces_) {
		if (piece->position_->avoirPositionX() == positionX && piece->position_->avoirPositionY() == positionY) {
			return piece;
		}
	}
	return nullptr;
}

void classejeux::Joueur::modifierPosition(int nouveauX, int nouveauY, int ancienX, int ancienY) {
	for (auto& piece : pieces_) {
		if (ancienX == piece->avoirPosition()->avoirPositionX() && ancienY == piece->avoirPosition()->avoirPositionY()) {
			piece->avoirPosition()->changerX(nouveauX);
			piece->avoirPosition()->changerY(nouveauY);
		}
	}
}

void classejeux::Joueur::retirerPiece(std::shared_ptr<Piece> pieceRetire) {
	auto it = std::find(pieces_.begin(), pieces_.end(), pieceRetire);
	pieces_.erase(it);
}

std::shared_ptr<classejeux::Case> classejeux::Joueur::avoirPosRoi() {
	for (auto&& p : pieces_) {
		if (!p->estMangeable()) {
			return p->position_;
		}
	}
	return nullptr;
}

bool classejeux::Joueur::roiEnEchec(Jeux jeu, Joueur adversaire, int x, int y) { // Roi en echec : 
	if (adversaire.pieceTrouvee(x, y)) {
		adversaire.retirerPiece(adversaire.pieceTrouvee(x, y));
	}
	for (auto&& piece : adversaire.avoirPieces()) {	// Chaque piece de l'adversaire
		for (std::shared_ptr<Case> cas : piece->mouvementsValide(jeu, adversaire, *this)) {
			if (cas->avoirPositionX() == avoirPosRoi()->avoirPositionX() && cas->avoirPositionY() == avoirPosRoi()->avoirPositionY()) {
				return true;
			}
		}
	}
	return false;
}

bool classejeux::Joueur::echecMat(Jeux jeu, Joueur adversaire) {
	int xp = 0;
	int yp = 0;
	for (auto&& i : avoirPieces()) {
		std::cout << "Piece ###" << std::endl;
		for (auto&& j : i->mouvementsValide(jeu, *this, adversaire)) {
			std::cout << "X: " << j->avoirPositionX() << std::endl;
			std::cout << "Y: " << j->avoirPositionY() << std::endl;
			std::cout << std::endl;
			xp = i->avoirPosition()->avoirPositionX();
			yp = i->avoirPosition()->avoirPositionY();
			i->avoirPosition()->changerX(j->avoirPositionX());
			i->avoirPosition()->changerY(j->avoirPositionY());
			if (!roiEnEchec(jeu, adversaire, j->avoirPositionX(), j->avoirPositionY())) {
				i->avoirPosition()->changerX(xp);
				i->avoirPosition()->changerY(yp);
				return false;
			}
			i->avoirPosition()->changerX(xp);
			i->avoirPosition()->changerY(yp);
			
		}

	}
	return true;
}
