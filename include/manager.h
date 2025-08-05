#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "chess_definition.h"

namespace chess {
    class Manager {
    public:
       	Manager(std::map<Color, std::string> players);
        void addPieceToTile(int x, int y, std::unique_ptr<Piece>& piece, Tiles board);
        void selectTile(Tiles board, std::pair<int, int> clic);
        void move(Tiles board, std::pair<int, int> clic);
        void removeRiskyMoves(Tiles board, Tiles& validTiles);
        
        bool isKingCheck(Tiles board, int index);
        bool isOpponentKingCheck(Tiles board);
        
        void toggleValidMoves(Tiles board);
        void toggleValidMoves(Tiles board, Color color);
        void resetToggles(Tiles board);
        
        void nextTurnColor();
        ClickState getState();
        std::map<Color, std::string> getPlayers();
    private:
        std::shared_ptr<Tile> selectedTile_;
       	std::map<Color, std::string> players_;
        ClickState state_;
        Color turnColor_ = Color::WHITE;
    };
}
