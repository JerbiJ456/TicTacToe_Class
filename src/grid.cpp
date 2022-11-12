#include <iostream>
#include "../include/grid.hpp"
#include "../include/bot.hpp"
#include "../include/player.hpp"
#include "../include/human.hpp"
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

bool Grid::placePlay(Player* player) {
    int pos = player->getPos();
    int posj = (pos-1)%3;
    int posi = (pos-1)/3;
    if(grid[posi][posj] != ' ') {
        if(player->getName() != "bot") 
            cout << "Cet emplacement est déjà rempli" << endl; 
        return false;
    }
    grid[posi][posj] = player->getSymbol();
    showGrid();
    return true;
}

bool Grid::win(Player* player) {
    char symbol = player->getSymbol();
    string name = player->getName();
    for(int i = 0; i < 3; i++) {
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == symbol)  
                count++;
            else break;
        }
        if(count == 3) {
            cout << "Le Gagnant de cette manche est " << name << endl;
            player->addWins(); 
            clearGrid();
            return true;
        }
    }
    for(int i = 0; i < 3; i++) {
        int count = 0;
        for(int j = 0; j < 3; j++) {
            if(grid[j][i] == symbol) 
                count++;
            else break;
        }
        if(count == 3) {
            cout << "Le Gagnant de cette manche est " << name << endl;
            player->addWins(); 
            clearGrid();
            return true;
        }
    }
    if(grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol){
        cout << "Le Gagnant de cette manche est " << name << endl;
        player->addWins(); 
        clearGrid();
        return true;
    }
    if(grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol){
        cout << "Le Gagnant de cette manche est " << name << endl;
        player->addWins(); 
        clearGrid();
        return true;
    }
    return false;
}

bool Grid::isFull() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(grid[i][j] == ' ') return false;
        }
    }
    clearGrid();
    cout << "Manche nulle";
    return true;
}