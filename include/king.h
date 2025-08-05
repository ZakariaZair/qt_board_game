#pragma once

#include <string>
#include <vector>
#include "chess_definition.h"
#include "piece.h"

namespace chess {
    class King : public Piece {
    public:
    	King(Color color);
        
    	static int getCount() { return count_; }
    private:
    	static int count_;
        static int maxCount_;
    };
}
