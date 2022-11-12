#include "../include/human.hpp"
#include "../include/player.hpp"

int Human::getPos() {
    int pos;
	do {
    	cout << "Où voulez vous vous placer : ", cin >> pos, cout << endl;
	        cin.clear();
	        cin.ignore(256,'\n');
	} while(!pos);	
    return pos;
}