#include <iostream>
#include "../include/grid.hpp"
#include "../include/bot.hpp"
#include "../include/player.hpp"
#include "../include/human.hpp"

using namespace std;

Player* test(int mode, char symbol) {
    if(mode==2)
        if(symbol=='X')
            return new Human(symbol);
        else return new Bot(symbol);
    if(mode==3) 
        return new Bot(symbol);
    return new Human(symbol); 
}

int main() {
    cout << "Bienvenue à TICTACTOE !!" << endl;
    int mode;
    cout << "Quel mode souhaitez vous faire ?\n1. 1v1\n2. 1vBot\n3. BotvBot\n" 
        << "Votre choix : ", cin >> mode;
    if(mode!=1 && mode != 2 && mode != 3) {
       cout << "Fermeture du Jeu" << endl;
       return 0;
    }

    int rounds;
    cout << "Combien de manches voulez vous faire : ", cin >> rounds;
    if(rounds == 0) return 0;

    Player* players[2];
    players[0] = test(mode,'X');
    players[1] = test(mode,'O');
    Grid grid;

    for(int i = 0; i < rounds; i++) {
        cout << "Début de la manche " << i+1 << "/" << rounds << endl;
        int j=1;
        do {
            j=j==0?1:0;
            cout << "C'est le tour du joueur : " << players[j]->getName()
            << "\nPlace ton " << players[j]->getSymbol() << endl;
            while(!grid.placePlay(players[j])) {}
        } while(!grid.win(players[j]) && !grid.isFull());
    }
    
    int x_wins = players[0]->getWins(), o_wins = players[1]->getWins(); 
    if(x_wins != o_wins) {
        if(x_wins < o_wins)
            cout << "Le gagnant final est " << players[1]->getName() << "!!\n" <<
            "Il/Elle jouait : " << players[1]->getSymbol() << endl;
        else cout << "Le gagnant final est " << players[0]->getName() << "!!\n" <<
            "Il/Elle jouait : " << players[0]->getSymbol() << endl;
    } else cout << "Nous n'avons pas de gagnant" << endl;

    return 0;
}
