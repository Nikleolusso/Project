//For function declarations, structs, #define,
/*This project is open source.
Kryzelle Manabat, Mat. Nr.
Nik Albrecht, Mat. Nr. */

#ifndef GAME_H
#define GAME_H

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

//Constants
const int CARDS_PER_PLAYER 12;
const int NUM_PLAYERS 4;
const int DECK_SIZE 64;
Player players[NUM_PLAYERS];

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
