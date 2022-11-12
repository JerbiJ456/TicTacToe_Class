#pragma once
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "player.hpp"
using namespace std;

class Bot : public Player {
    private:
        string name = "bot";
    public:
        int getPos();
        string getName() { return name; };
        Bot(char c) : Player(c) {
            cout << "";
        };
        Bot();
};