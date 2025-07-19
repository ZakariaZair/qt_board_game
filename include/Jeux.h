/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Jeux.h
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#pragma once

#include "Case.h"
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

class classejeux::Jeux {
public:
	Jeux();
	std::shared_ptr<Case> echiquier_[8][8];
	std::shared_ptr<Case> avoirCase(int x, int y) const;
};