#pragma once

#include <memory>
#include <utility>
#include <QLabel>
#include "chess_definition.h"

namespace chess {
    class Tile {
    public:
       	Tile();
        ~Tile();

       	std::pair<int, int> getPos();
        QLabel* getLabel();

       	void setPos(int x, int y);
        void setLabel(QLabel* label);

        void setPieceAtTile(std::unique_ptr<Piece>& piece);
        std::unique_ptr<Piece>& getPieceAtTile();
        void refreshRepresentation();
        void validMoveRepresentation();

    private:
        std::unique_ptr<Piece> pieceAtTile_;
       	std::pair<int, int> position_;
        QLabel* label_;
    };
}
