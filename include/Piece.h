#pragma once

#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "chess_definition.h"

namespace chess {
    class Piece {
    public:
       	Piece();
       	Piece(const Board board);
       	virtual ~Piece() = default;
       	static std::pair<int, int> initialPosition;
       	std::shared_ptr<Tile> avoirPosition();
       	bool estMangeable() { return edible_; }
       	virtual std::string avoirChar() = 0;
       	virtual std::vector<std::shared_ptr<Tile>> validMoves(Board jeu, Player& joueur, Player& autreJoueur) = 0;
       	bool autrePieceAmis(std::shared_ptr<Tile> cas, Player joueur);
       	bool autrePieceEnnemi(std::shared_ptr<Tile> cas, Player joueur);
       	std::shared_ptr<Tile> position_;
       	void afficherPos();

    protected:
       	std::string character_;
       	bool edible_;
    };
}
