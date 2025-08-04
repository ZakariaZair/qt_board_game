#include "chess_definition.h"
#include "king.h"
using namespace chess;

int King::count_ = 0;
int King::maxCount_ = 2;

King::King(Color color) : Piece(color) {
	if (count_ >= maxCount_)
		throw std::logic_error("No more than two King!");

	symbol_ = "♔";
	directions_ = {
	    std::make_pair(1,0),
	    std::make_pair(-1,0),
	    std::make_pair(0,1),
	    std::make_pair(0,-1),
	    std::make_pair(1,1),
	    std::make_pair(-1,1),
	    std::make_pair(-1,-1),
	    std::make_pair(1,-1),
	};
	isMoveRepetitive_ = false;
	count_++;
}
