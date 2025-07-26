/**
* TD6 Exceptions, espace de nom, variables de classe
* \file   Case.cpp
* \author Alexis LeBlanc et Zakaria Zair
* \date	21 avril 2022
* Cree le 9 avril 2022
*/

#include "Case.h"

classejeux::Case::Case() {
	positionX_ = 0;
	positionY_ = 0;
}

classejeux::Case::Case(int posX, int posY) {
	positionX_ = posX;
	positionY_ = posY;
}

int classejeux::Case::avoirPositionX() {
	return positionX_;
}

int classejeux::Case::avoirPositionY() {
	return positionY_;
}

void classejeux::Case::changerX(int x) {
	positionX_ = x;
}

void classejeux::Case::changerY(int y) {
	positionY_ = y;
}
