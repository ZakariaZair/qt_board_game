/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Tour.cpp
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#include "Joueur.h"
#include "Tour.h"

classejeux::Tour::Tour(const classejeux::Jeux jeux) : Piece(jeux) {
	characterBlanc_ = "♖";
	characterNoir_ = "♜";
	mangeable = true;
}

std::string classejeux::Tour::avoirCharNoir() {
	return characterNoir_;
}

std::string classejeux::Tour::avoirCharBlanc() {
	return characterBlanc_;
}

//implémenter mouvement
std::vector<std::shared_ptr<classejeux::Case>> classejeux::Tour::mouvementsValide(Jeux jeu, Joueur& joueur, Joueur& autreJoueur) {
	std::vector<std::shared_ptr<Case>> v;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (autrePieceEnnemi(jeu.echiquier_[i][j], autreJoueur)) { continue; }
			if (autrePieceAmis(jeu.echiquier_[i][j], joueur)) { continue; }
			
			if (jeu.echiquier_[i][j]->avoirPositionX() == position_->avoirPositionX() || jeu.echiquier_[i][j]->avoirPositionY() == position_->avoirPositionY()) {
				if (jeu.echiquier_[i][j]->avoirPositionX() != position_->avoirPositionX() || jeu.echiquier_[i][j]->avoirPositionY() != position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
			}

		}
	}
	
	return v;
}