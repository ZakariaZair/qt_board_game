/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Roi.cpp
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#include "Joueur.h"
#include "Roi.h"
#include <stdexcept>

int classejeux::Roi::compteur_ = 0;

classejeux::Roi::Roi(const classejeux::Jeux jeux) : Piece(jeux) {
	// Question 2
	if (compteur_ >= 2) 
		throw std::logic_error("Plus de deux roi!");

	characterBlanc_ = "♔";
	characterNoir_ = "♚";
	mangeable = false;
	compteur_++;
}

std::string classejeux::Roi::avoirCharNoir() {
	return characterNoir_;
}

std::string classejeux::Roi::avoirCharBlanc() {
	return characterBlanc_;
}

std::vector<std::shared_ptr<classejeux::Case>> classejeux::Roi::mouvementsValide(Jeux jeu, Joueur& joueur, Joueur& autreJoueur) {
	std::vector<std::shared_ptr<Case>> v;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (autrePieceAmis(jeu.echiquier_[i][j], joueur)) { continue; }
			if (autrePieceEnnemi(jeu.echiquier_[i][j], autreJoueur)) { continue; }
			// Aux cotes de la piece
			if (jeu.echiquier_[i][j]->avoirPositionX() + 1 == position_->avoirPositionX() && jeu.echiquier_[i][j]->avoirPositionY() == position_->avoirPositionY()) { // Gauche de la piece
				v.push_back(jeu.avoirCase(i, j));
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() - 1 == position_->avoirPositionX() && jeu.echiquier_[i][j]->avoirPositionY() == position_->avoirPositionY()) { // Droite
				v.push_back(jeu.avoirCase(i, j));
			}
			if (jeu.echiquier_[i][j]->avoirPositionY() + 1 == position_->avoirPositionY() && jeu.echiquier_[i][j]->avoirPositionX() == position_->avoirPositionX()) { // Bas
				v.push_back(jeu.avoirCase(i, j));
			}
			if (jeu.echiquier_[i][j]->avoirPositionY() - 1 == position_->avoirPositionY() && jeu.echiquier_[i][j]->avoirPositionX() == position_->avoirPositionX()) { // Haut
				v.push_back(jeu.avoirCase(i, j));
			}

			// Aux diagonales de la piece
			if (jeu.echiquier_[i][j]->avoirPositionX() + 1 == position_->avoirPositionX() && jeu.echiquier_[i][j]->avoirPositionY() + 1 == position_->avoirPositionY()) { // Gauche et bas
				v.push_back(jeu.avoirCase(i, j));
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() + 1 == position_->avoirPositionX() && jeu.echiquier_[i][j]->avoirPositionY() - 1 == position_->avoirPositionY()) { // Gauche et haut
				v.push_back(jeu.avoirCase(i, j));
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() - 1 == position_->avoirPositionX() && jeu.echiquier_[i][j]->avoirPositionY() + 1 == position_->avoirPositionY()) { // Droite et bas
				v.push_back(jeu.avoirCase(i, j));
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() - 1 == position_->avoirPositionX() && jeu.echiquier_[i][j]->avoirPositionY() - 1 == position_->avoirPositionY()) { // Droite et haut
				v.push_back(jeu.avoirCase(i, j));
			}

		}
	}
	return v;
}
