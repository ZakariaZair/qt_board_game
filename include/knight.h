#pragma once

#include <string>
#include "chess_definition.h"
#include "piece.h"

namespace chess {
    class Knight : public Piece {
    public:
    	Knight(const Board& jeux);
    	virtual std::string avoirChar() override;
    	virtual std::vector<std::shared_ptr<Tile>> mouvementsValide(Board jeu, Joueur& joueur, Joueur& autreJoueur) override;

    private:
    	std::string characterBlanc_;
    	std::string characterNoir_;
    };
}
