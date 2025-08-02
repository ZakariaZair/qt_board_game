#pragma once

#include <string>
#include "chess_definition.h"
#include "piece.h"

namespace chess {
    class Knight : public Piece {
    public:
    	Knight(const Board& jeux);
    	virtual std::string getSymbol() override;
    	virtual std::vector<std::shared_ptr<Tile>> validMoves(Board jeu, Player& joueur, Player& autreJoueur) override;
    private:
    	std::string characterBlanc_;
    	std::string characterNoir_;
    };
}
