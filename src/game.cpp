#include <iostream>
#include "../include/gamefunc.hpp"

using namespace std;

int main() {

    int rounds;
    cout << "Combien de manches voulez vous faire : ", cin >> rounds;
    if(rounds == 0) return 0;
    int x_wins, o_wins;
    x_wins = o_wins = 0;
    
    for(int i = 0; i < rounds; i++) {
        cout << "Début de la manche " << i+1 << "/" << rounds << endl;
        Grid* grid = new Grid;
        char player;
        bool full = false;
        bool end = false;
        while(!end && !full) {
            player = player != 'X'?'X':'O';
            cout << "C'est le tour du joueur : " << player << endl;
            int pos;
            do {
		        do {
                	cout << "Où voulez vous vous placer : ", cin >> pos, cout << endl;
			        cin.clear();
			        cin.ignore(256,'\n');
			    } while(!pos);	
            } while(!grid->placePlay(pos,player));
            full = grid->isFull();
            end = grid->win(player); 
        }
        if(end)
            cout << "Le joueur " << player << " a gangé cette partie" << endl;
        else cout << "Nous avons une égalité" << endl;
        if(player == 'O') 
            o_wins++;
        else x_wins++;
        delete grid;
    }

    if(x_wins != o_wins) {
        if(x_wins < o_wins)
            cout << "Le gagnant final est O !!" << endl;
        else cout <<  "Le gagnant final est X !!" << endl;
    } else cout << "Nous n'avons pas de gagnant" << endl;
    return 0;
}
