#pragma once

#include "chess_definition.h"
#include "piece.h"

namespace chess {
    class Rook : public Piece {
    public:
    	Rook(const Board jeux);
    	virtual std::string avoirChar() override;
    	virtual std::vector<std::shared_ptr<Tile>> validMoves(Board board, Player& playerWhite, Player& autreJoueur) override;
    private:
    	std::string characterBlanc_;
    	std::string characterNoir_;
    };
}
