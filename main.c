//For Player interactions
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"

int main() {

//Game preparation (shuffleing and dealing cards)
srand((unsigned int)time(NULL)); //create seed for shuffle function
shuffleDeck(deck, DECK_SIZE); //call shuffle function
dealCards(players, deck, NUM_PLAYERS, CARDS_PER_PLAYER);

return 0;
}
