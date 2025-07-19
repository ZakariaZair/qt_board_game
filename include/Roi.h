/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Roi.h
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#pragma once

#include "Piece.h"
#include "Jeux.h"
#include <string>

namespace classejeux {
	class Joueur;
	class Piece;
	class Jeux;
	class Case;
	class Cavalier;
	class Roi;
	class Tour;
}

class classejeux::Roi : public classejeux::Piece {
public:
	Roi(const classejeux::Jeux jeux);
	virtual std::string avoirCharNoir();
	virtual std::string avoirCharBlanc();
	static int avoirCompteur() { return compteur_; }
	virtual std::vector<std::shared_ptr<Case>> mouvementsValide(Jeux jeu, Joueur& joueur, Joueur& autreJoueur) override;
	
private:
	std::string characterBlanc_;
	std::string characterNoir_;
	static int compteur_;
};

