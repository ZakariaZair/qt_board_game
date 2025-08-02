#include "tile.h"
#include "chess_definition.h"
using namespace chess;

Tile::Tile() {
	position_ = std::make_pair(0, 0);
	label_ = new QLabel;
}

Tile::~Tile() {
    delete label_;
    label_ = nullptr;
}

Tile::Tile(int x, int y) { position_ = std::make_pair(x, y); }

std::pair<int, int> Tile::getPos() { return position_; }

QLabel* Tile::getLabel() { return label_; }

void Tile::setPos(int x, int y) {
    position_.first = x;
    position_.second = y;
}

void Tile::setLabel(QLabel* label) {
    label_ = label;
}
