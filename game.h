//For function declarations, structs, #define,
/*This project is open source.
Kryzelle Manabat, Mat. Nr.
Nik Albrecht, Mat. Nr. */

#ifndef GAME_H
#define GAME_H

//Constants
#define SEQUENCE_LENGTH 5
#define MAX_NAME_LEN 10
#define HAND_SIZE 12
#define NUM_PLAYERS 4
#define DECK_SIZE 64

const char *sequence[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza"};
extern int current_deck_position;



//Deck
#define REPEAT11(x) x, x, x, x, x, x, x, x, x, x, x //standard cards exist 11 times
#define REPEAT3(x) x, x, x //special cards three times
const char* deck[] = {
    REPEAT11("Taco"),
    REPEAT11("Goat"),
    REPEAT11("Cheese"),
    REPEAT11("Pizza"),
    REPEAT11("Cat"),
    REPEAT3("HTWG"),
    REPEAT3("Groundhog"),
    REPEAT3("Narwhal")
};

//Player data
typedef struct {
    int cardCount; //current cards in hand
    int id;
    int slap_time; 
    char name[MAX_NAME_LEN]; //Player name
    const char* hand[HAND_SIZE]; //holds each players hand
} Player;

//Function declarations
void swap(const char** a, const char** b);
void shuffleDeck(const char* deck[], int deck_size);
void dealCards(Player players[], const char* deck[], int numPlayers, int cardsPerPlayer);
void press_to_continue();
const char* draw_from_deck();
void display_player_status(Player players[]);
int get_npc_slap_time();
void wait_ms(int milliseconds);
int perform_htwg_combo();
int npc_perform_htwg_combo(Player *npc);

#endif
