#include "tile.h"
#include "chess_definition.h"
using namespace chess;

Tile::Tile() {
	position_ = std::make_pair(0, 0);
	label_ = new QLabel;
}

Tile::Tile(int x, int y) { position_ = std::make_pair(x, y); }

std::pair<int, int> Tile::getPos() { return position_; }

int Tile::getPosX() { return position_.first; }

int Tile::getPosY() { return position_.second; }

void Tile::setPos(int x, int y) {
    position_.first = x;
    position_.second = y;
}

Tile::~Tile() {
    delete label_;
    label_ = nullptr;
}
