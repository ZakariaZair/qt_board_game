#include "tile.h"
#include "piece.h"
#include <memory>
using namespace chess;

Tile::Tile() {
	position_ = std::make_pair(-1, -1);
	label_ = new QLabel;
    QFont qfont("Times", 60);
    label_->setFont(qfont);
    label_->setAlignment(Qt::AlignCenter);
}

Tile::~Tile() {
    delete label_;
    label_ = nullptr;
}

std::pair<int, int> Tile::getPos() { return position_; }

void Tile::setPos(int x, int y) {
    position_.first = x;
    position_.second = y;
    refreshRepresentation();
}

QLabel* Tile::getLabel() { return label_; }

void Tile::setLabel(QLabel* label) {
    label_ = label;
}

void Tile::setPieceAtTile(std::unique_ptr<Piece>& piece) {
    pieceAtTile_ = std::move(piece);
    label_->setText(QString::fromStdString(pieceAtTile_->getSymbol()));
    refreshRepresentation();
}

std::unique_ptr<Piece>& Tile::getPieceAtTile() {
    return pieceAtTile_;
}

void Tile::refreshRepresentation() {
    std::string colorStyle = "color: ";
    if (pieceAtTile_) {
        colorStyle += pieceAtTile_->getColor() == Color::WHITE ? "white;" : "black;";
    }
    (position_.first + position_.second) % 2 == 0 ?
    label_->setStyleSheet(QString::fromStdString("background-color: burlywood;" + colorStyle)):
    label_->setStyleSheet(QString::fromStdString("background-color: beige;" + colorStyle));
}
