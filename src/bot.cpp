#include "../include/bot.hpp"
#include "../include/player.hpp"

int Bot::getPos() { 
    return 1 + (rand() % 9); 
}