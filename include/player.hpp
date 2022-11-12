#pragma once
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#include <iostream>
using namespace std;

class Player {
    private:
        char symbol;
        int wins;
    public:
        char getSymbol() { return symbol; };
        Player(char c) {
            symbol = c;
        };
        Player();
        virtual string getName() {};
        virtual int getPos() {};
        int getWins() { return wins; };
        void addWins() { wins++; };
};