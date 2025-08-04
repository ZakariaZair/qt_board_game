
#include "rook.h"
#include "chess_definition.h"
using namespace chess;

Rook::Rook(Color color) : Piece(color) {
	symbol_ = "♜";
	directions_ = {
        std::make_pair(1,0),
        std::make_pair(-1,0),
        std::make_pair(0,1),
        std::make_pair(0,-1),
	};
	isMoveRepetitive_ = true;
}
