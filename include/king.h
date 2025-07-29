#pragma once

#include <string>
#include <vector>
#include "chess_definition.h"
#include "piece.h"

namespace chess {
    class King : public Piece {
    public:
    	King(const Board board);
    	static int avoirCompteur() { return compteur_; }
    	virtual std::string avoirChar() override;
    	virtual std::vector<std::shared_ptr<Tile>> validMoves(Board jeu, Player& joueur, Player& autreJoueur) override;

    private:
    	static int compteur_;
    };
}
