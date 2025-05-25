//For Player interactions
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"

int main() {
    
const char* deck[] = {
    // 11 Taco cards
    "Taco", "Taco", "Taco", "Taco", "Taco", "Taco", "Taco", "Taco", "Taco", "Taco", "Taco",

    // 11 Cat cards
    "Cat", "Cat", "Cat", "Cat", "Cat", "Cat", "Cat", "Cat", "Cat", "Cat", "Cat",

    // 11 Goat cards
    "Goat", "Goat", "Goat", "Goat", "Goat", "Goat", "Goat", "Goat", "Goat", "Goat", "Goat",

    // 11 Cheese cards
    "Cheese", "Cheese", "Cheese", "Cheese", "Cheese", "Cheese", "Cheese", "Cheese", "Cheese", "Cheese", "Cheese",

    // 11 Pizza cards
    "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza", "Pizza",

    // 3 Gorilla cards
    "Gorilla", "Gorilla", "Gorilla",

    // 3 Groundhog cards
    "Groundhog", "Groundhog", "Groundhog",

    // 3 Narwhal cards
    "Narwhal", "Narwhal", "Narwhal"
};

//Game preparation (shuffleing and dealing cards)
srand((unsigned int)time(NULL)); //create seed for shuffle function
shuffleDeck(deck, DECK_SIZE); //call shuffle function
dealCards(players, deck, NUM_PLAYERS, CARDS_PER_PLAYER);

return 0;
}
