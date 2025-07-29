classejeux::Cavalier::Cavalier(const classejeux::Jeux& jeux) : Piece(jeux) {
	characterBlanc_ = "♘";
	characterNoir_ = "♞";
	mangeable = true;
}

std::string classejeux::Cavalier::avoirCharNoir() {
	return characterNoir_;
}

std::string classejeux::Cavalier::avoirCharBlanc() {
	return characterBlanc_;
}

std::vector<std::shared_ptr<classejeux::Case>> classejeux::Cavalier::mouvementsValide(Jeux jeu, Joueur& joueur, Joueur& autreJoueur) {
	std::vector<std::shared_ptr<Case>> v;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (autrePieceAmis(jeu.echiquier_[i][j], joueur)) { continue; }
			// Aux cotes de la piece
			if (jeu.echiquier_[i][j]->avoirPositionX() + 2  == position_->avoirPositionX()) { // Gauche de la piece
				if (jeu.echiquier_[i][j]->avoirPositionY() + 1 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
				if (jeu.echiquier_[i][j]->avoirPositionY() - 1 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() + 1 == position_->avoirPositionX()) { // Gauche de la piece
				if (jeu.echiquier_[i][j]->avoirPositionY() + 2 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
				if (jeu.echiquier_[i][j]->avoirPositionY() - 2 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() - 1 == position_->avoirPositionX()) { // Gauche de la piece
				if (jeu.echiquier_[i][j]->avoirPositionY() + 2 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
				if (jeu.echiquier_[i][j]->avoirPositionY() - 2 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
			}
			if (jeu.echiquier_[i][j]->avoirPositionX() - 2 == position_->avoirPositionX()) { // Gauche de la piece
				if (jeu.echiquier_[i][j]->avoirPositionY() + 1 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
				if (jeu.echiquier_[i][j]->avoirPositionY() - 1 == position_->avoirPositionY()) {
					v.push_back(jeu.avoirCase(i, j));
				}
			}

		}
	}
	return v;
}
