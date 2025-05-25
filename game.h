//For function declarations, structs, #define,
/*This project is open source.
Kryzelle Manabat, Mat. Nr.
Nik Albrecht, Mat. Nr. 313910 */

#ifndef GAME_H
#define GAME_H

//Constants
const int CARDS_PER_PLAYER 12;
const int NUM_PLAYERS 4;
const int DECK_SIZE 64;

//Player struct
typedef struct {
    const char* hand[CARDS_PER_PLAYER];
    int cardCount;
} Player;

//Function declarations
void swap(const char** a, const char** b);
void shuffleDeck(const char* deck[], int DECK_SIZE);
void dealCards(Player players[], const char* deck[], int numPlayers, int cardsPerPlayer);

#endif
