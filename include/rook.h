/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Tour.h
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Créé le 9 avril 2022
*/

#pragma once

#include "Piece.h"
#include <string>

class classejeux::Tour : public classejeux::Piece {
public:
	Tour(const classejeux::Jeux jeux);
	virtual std::string avoirCharNoir();
	virtual std::string avoirCharBlanc();
	virtual std::vector<std::shared_ptr<Case>> mouvementsValide(Jeux jeu, Joueur& joueur, Joueur& autreJoueur) override;
private:
	std::string characterBlanc_;
	std::string characterNoir_;
};

