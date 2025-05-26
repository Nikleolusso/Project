//For function declarations, structs, #define,
/*This project is open source.
Kryzelle Manabat, Mat. Nr.
Nik Albrecht, Mat. Nr. */

#ifndef GAME_H
#define GAME_H

//Constants
#define SEQUENCE_LENGTH 5
#define MAX_NAME_LEN 10
const int HAND_SIZE = 12;
const int NUM_PLAYERS = 4;
const int DECK_SIZE = 64;
const char *sequence[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza"};
const char *cards[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza", "HTWG"};
extern int current_deck_position;



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

//Player data
typedef struct {
    int cardCount;
    int id;
    int slap_time;
    char name[MAX_NAME_LEN];
    char hand[HAND_SIZE];
} Player;

//Function declarations
void swap(const char** a, const char** b);
void shuffleDeck(const char* deck[], int DECK_SIZE);
void dealCards(Player players[], const char* deck[], int numPlayers, int cardsPerPlayer);

#endif
