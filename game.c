//For Functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

//Swap two cards (for shuffle function)
void swap(const char** a, const char** b) {
    const char* temp = *a;
    *a = *b;
    *b = temp;
}

// Fisher-Yates shuffle
void shuffleDeck(const char* deck[], int DECK_SIZE) {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&deck[i], &deck[j]);
    }

}

//Deal cards
void dealCards(Player players[], const char* deck[], int numPlayers, int cardsPerPlayer) {
    int index = 0;
    for(int i, i < cardsPerPlayer, i++) {
        for(int j, j < numPlayers, j++) {
        players[j].hand[i] = deck[index++];
        players.cardCount++;
        }
    }
} 
