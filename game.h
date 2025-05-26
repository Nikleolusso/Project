//For function declarations, structs, #define,
/*This project is open source.
Kryzelle Manabat, Mat. Nr.
Nik Albrecht, Mat. Nr. */

#ifndef GAME_H
#define GAME_H

//Constants
const int CARDS_PER_PLAYER = 12;
const int NUM_PLAYERS = 4;
const int DECK_SIZE = 64;
const char *sequence[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza"};
const char *cards[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza", "HTWG"};

//Deck
#define REPEAT11(x) x, x, x, x, x, x, x, x, x, x, x //standard cards exist 11 times
#define REPEAT3(x) x, x, x //special cards three times
const char* deck[] = {
    REPEAT11("Taco"),
    REPEAT11("Goat"),
    REPEAT11("Cheese"),
    REPEAT11("Pizza"),
    REPEAT3("Gorilla"),
    REPEAT3("Groundhog"),
    REPEAT3("Narwhal")
};

//Player struct
typedef struct {
    const char* hand[CARDS_PER_PLAYER];
    int cardCount;
    int id;
    int cards;
    char name[MAX_NAME_LEN];
    int slap_time;
} Player;

Player players[NUM_PLAYERS];

//Function declarations
void swap(const char** a, const char** b);
void shuffleDeck(const char* deck[], int DECK_SIZE);
void dealCards(Player players[], const char* deck[], int numPlayers, int cardsPerPlayer);

#endif
