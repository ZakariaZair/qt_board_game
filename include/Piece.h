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

       	virtual std::string getSymbol();
       	virtual std::vector<std::shared_ptr<Tile>> validMoves(Board jeu, Player& joueur, Player& autreJoueur) = 0;
       	std::shared_ptr<Tile> getTile();

       	bool isEdible() { return edible_; }
       	bool isFriend(std::shared_ptr<Tile> cas, Player joueur);
       	bool isEnnemi(std::shared_ptr<Tile> cas, Player joueur);

       	void showPosition();
    private:
        std::vector<std::pair<int, int>> directions_;
        std::pair<int, int> position_;
       	std::string symbol_;
       	bool edible_;
    };
}
