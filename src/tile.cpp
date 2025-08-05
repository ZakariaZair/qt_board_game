#include "tile.h"
#include "piece.h"
#include <memory>
using namespace chess;

Tile::Tile() {
	position_ = std::make_pair(-1, -1);
	label_ = new QLabel;
    QFont qfont("Times New Roman", 72);
    qfont.bold();
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
}

QLabel* Tile::getLabel() { return label_; }

void Tile::setLabel(QLabel* label) {
    label_ = label;
}

void Tile::setPieceAtTile(std::unique_ptr<Piece>& piece) {
    pieceAtTile_ = std::move(piece);
}

std::unique_ptr<Piece>& Tile::getPieceAtTile() {
    return pieceAtTile_;
}

void Tile::refreshRepresentation() {
    std::string colorStyle = "color: ";
    label_->setText(QString::fromStdString(""));
    if (pieceAtTile_) {
        colorStyle += pieceAtTile_->getColor() == Color::WHITE ? "white;" : "black;";
        label_->setText(QString::fromStdString(pieceAtTile_->getSymbol()));
    }
    (position_.first + position_.second) % 2 == 0 ?
    label_->setStyleSheet(QString::fromStdString("background-color: burlywood;" + colorStyle)):
    label_->setStyleSheet(QString::fromStdString("background-color: beige;" + colorStyle));
}

void Tile::validMoveRepresentation() {
    std::string colorStyle = "color: ";
    if (pieceAtTile_) {
        colorStyle += pieceAtTile_->getColor() == Color::WHITE ? "white;" : "black;";
    }
    std::string borderStyle = (position_.first + position_.second) % 2 == 0 ?
    "border-style: solid; border-width: 5px; border-color: burlywood;":
    "border-style: solid; border-width: 5px; border-color: beige;";
    label_->setStyleSheet(QString::fromStdString("background-color: gold;" + borderStyle + colorStyle));
}

void Tile::selectedRepresentation() {
    std::string colorStyle = "color: ";
    if (pieceAtTile_) {
        colorStyle += pieceAtTile_->getColor() == Color::WHITE ? "white;" : "black;";
    }
    std::string borderStyle = "border-style: outset; border-width: 5px; border-color: gold;";
    (position_.first + position_.second) % 2 == 0 ?
    label_->setStyleSheet(QString::fromStdString("background-color: burlywood;" + borderStyle + colorStyle)):
    label_->setStyleSheet(QString::fromStdString("background-color: beige;" + borderStyle + colorStyle));
}

void Tile::checkRepresentation() {
    std::string colorStyle = "color: ";
    if (pieceAtTile_) {
        colorStyle += pieceAtTile_->getColor() == Color::WHITE ? "white;" : "black;";
    }
    std::string borderStyle = "border-style: outset; border-width: 5px; border-color: firebrick;";
    (position_.first + position_.second) % 2 == 0 ?
    label_->setStyleSheet(QString::fromStdString("background-color: burlywood;" + borderStyle + colorStyle)):
    label_->setStyleSheet(QString::fromStdString("background-color: beige;" + borderStyle + colorStyle));
}
