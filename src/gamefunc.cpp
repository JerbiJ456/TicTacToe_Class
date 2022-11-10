#include <iostream>
#include "../include/gamefunc.hpp"
using namespace std;

Grid::Grid() {
    clearGrid();
    showGrid();
}

void Grid::showGrid() {
    for(int i = 0; i < 3; i++) {
        cout << "   |   |" << endl;
        for(int j = 0; j < 3; j++) {
            if (j != 1) {
                if(grid[i][j] == ' ')  
                    cout << " " << j+1+(3*i) << " "; 
                else cout << " " << grid[i][j] << " "; 
            } else {
                if(grid[i][j] == ' ') 
                    cout << "| " << j+1+(3*i) << " |";
                else cout << "| " << grid[i][j] << " |"; 
            }
        } 
        cout << "\n   |   |" << endl;
        if(i != 2) cout << "-- -- -- --" << endl;
    }
}

void Grid::clearGrid() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            grid[i][j] = ' ';
        }
    }
}

bool Grid::placePlay(int pos, char player) {
    int posj = (pos-1)%3;
    int posi = (pos-1)/3;
    if(grid[posi][posj] != ' ') {
        cout << "Cet emplacement est déjà rempli" << endl; 
        return false;
    }
    grid[posi][posj] = player;
    showGrid();
    return true;
}

bool Grid::win(char player) {
    for(int i = 0; i < 3; i++) {
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == player)  
                count++;
            else break;
        }
        if(count == 3) return true;
    }
    for(int i = 0; i < 3; i++) {
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if(grid[j][i] == player) 
                count++;
            else break;
        }
        if(count == 3) return true;
    }
    if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) return true;
    if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) return true;
    return false;
}

bool Grid::isFull() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(grid[i][j] == ' ') return false;
        }
    }
    return true;
}