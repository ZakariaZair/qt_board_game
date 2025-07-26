/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Cavalier.h
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#pragma once

#include "Piece.h"
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

class classejeux::Cavalier : public classejeux::Piece {
public:
	Cavalier(const classejeux::Jeux& jeux);
	virtual std::string avoirCharNoir() override;
	virtual std::string avoirCharBlanc() override;
	virtual std::vector<std::shared_ptr<Case>> mouvementsValide(Jeux jeu, Joueur& joueur, Joueur& autreJoueur) override;
	//virtual void deplacer();

private:
	std::string characterBlanc_;
	std::string characterNoir_;
};
