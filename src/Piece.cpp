

classejeux::Piece::Piece(const Jeux& jeux) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::shared_ptr<Case> pos = jeux.echiquier_[i][j];
			if (pos->avoirPositionX() == positionInitialeX && pos->avoirPositionY() == positionInitialeY) {
				position_ = std::make_shared<Case>(*pos);
			}
		}
	}
}

std::shared_ptr<classejeux::Case> classejeux::Piece::avoirPosition() {
	return position_;
}

void classejeux::Piece::afficherPos() {
	std::cout << "X: " << position_->avoirPositionX() << std::endl;
	std::cout << "Y: " << position_->avoirPositionY() << std::endl;
}

bool classejeux::Piece::autrePieceAmis(std::shared_ptr<Case> cas, Joueur joueur) {
	for (auto&& piece : joueur.avoirPieces()) {
		int posX = piece->avoirPosition()->avoirPositionX();
		int posY = piece->avoirPosition()->avoirPositionY();
		if (posX == cas->avoirPositionX() && posY == cas->avoirPositionY()) {
			return true;
		}

		if (position_->avoirPositionY() == posY) {
			if (position_->avoirPositionX() < posX && cas->avoirPositionX() > posX) { return true; }

			else if (position_->avoirPositionX() > posX && cas->avoirPositionX() < posX) { return true; }
		}

		if (position_->avoirPositionX() == posX) {
			if (position_->avoirPositionY() < posY && cas->avoirPositionY() > posY) { return true; }

			else if (position_->avoirPositionY() > posY && cas->avoirPositionY() < posY) { return true; }
		}
	}
	return false;
}

bool classejeux::Piece::autrePieceEnnemi(std::shared_ptr<Case> cas, Joueur joueur) {
	for (auto&& piece : joueur.avoirPieces()) {
		int posX = piece->avoirPosition()->avoirPositionX();
		int posY = piece->avoirPosition()->avoirPositionY();

		if (posX == cas->avoirPositionX() && posY == cas->avoirPositionY()) {
			return false;
		}

		if (position_->avoirPositionY() == posY) {
			if (position_->avoirPositionX() < posX && cas->avoirPositionX() > posX) { return true; }

			else if (position_->avoirPositionX() > posX && cas->avoirPositionX() < posX) { return true; }
		}

		if (position_->avoirPositionX() == posX) {
			if (position_->avoirPositionY() < posY && cas->avoirPositionY() > posY) { return true; }

			else if (position_->avoirPositionY() > posY && cas->avoirPositionY() < posY) { return true; }
		}
	}
	return false;
}
