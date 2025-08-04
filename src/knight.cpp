#include "knight.h"
#include "chess_definition.h"
using namespace chess;

Knight::Knight(Color color) : Piece(color) {
	symbol_ = "♞";
	directions_ = {
	    std::make_pair(2,1),
	    std::make_pair(2,-1),
	    std::make_pair(-2,1),
	    std::make_pair(-2,-1),
	    std::make_pair(1,2),
	    std::make_pair(1,-2),
	    std::make_pair(-1,2),
	    std::make_pair(-1,-2),
	};
	isMoveRepetitive_ = false;
}
