#pragma once
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#include "player.hpp"

class Grid {
    private:
        char grid[3][3];
        void clearGrid();
    public:
        Grid();
        void showGrid();
        bool placePlay(Player* player);
        bool win(Player* player);
        bool isFull();
};