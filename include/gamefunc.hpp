#pragma once

class Grid {
    private:
        char grid[3][3];
        void showGrid();
        void clearGrid();
    public:
        Grid();
        bool placePlay(int pos, char player);
        bool win(char player);
        bool isFull();
};