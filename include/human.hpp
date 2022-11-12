#pragma once
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#include <iostream>
#include "player.hpp"
using namespace std;

class Human : public Player {
    private:
        string name;
    public:
        int getPos();
        string getName() { return name; };
        Human(char c) : Player(c) { 
            cout << "Name to use in game : ", cin >> name;
            cout << "Tu seras le : " << c << endl;
        };
        Human();
};