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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h> // Windows only (_kbhit and _getch)

#define NUM_PLAYERS 4
#define HAND_SIZE 10
#define MAX_NAME_LEN 50
#define SEQUENCE_LENGTH 5
#define SPECIAL_CARD_INDEX 5

const char *sequence[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza"};
const char *cards[] = {"Taco", "Cat", "Goat", "Cheese", "Pizza", "HTWG"};

typedef struct {
    int id;
    int cards;
    char name[MAX_NAME_LEN];
    int slap_time;
} Player;

void press_to_continue() {
    printf("\nPress Enter to continue...\n");
    while (getchar() != '\n');
}

int get_random_card() {
    return rand() % 6; // Includes special card HTWG
}

void display_player_status(Player players[]) {
    printf("\n--- Card Counts ---\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d cards\n", players[i].name, players[i].cards);
    }
    printf("-------------------\n");
}

int get_npc_slap_time() {
    return 300 + rand() % 1700;
}

void wait_ms(int milliseconds) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int perform_htwg_combo() {
    char expected[] = {'H', 'T', 'W', 'G'};
    printf("Special card HTWG! Enter the sequence: H T W G (uppercase only)\n");

    for (int i = 0; i < 4; i++) {
        printf("Press '%c': ", expected[i]);
        char ch = _getch();
        printf("%c\n", ch);
        if (ch != expected[i]) {
            printf("Wrong key! You failed the combo.\n");
            return 0; // failed
        }
    }

    printf("✅ You successfully completed the combo!\n");
    return 1; // success
}

int npc_perform_htwg_combo(Player *npc) {
    int success = rand() % 2; // 50% chance
    if (success) {
        printf("%s completed the HTWG combo successfully!\n", npc->name);
    } else {
        printf("%s failed the HTWG combo!\n", npc->name);
        npc->cards++;
    }
    return success;
}

int main() {
    srand(time(NULL));
    Player players[NUM_PLAYERS];
    int current_word_index = 0;
    int current_turn = 0;
    char player_name[MAX_NAME_LEN];

    printf("Welcome to Taco, Cat, Goat, Cheese, Pizza - HTWG Edition (with Special Cards)\n");
    printf("Enter your name: ");
    fgets(player_name, MAX_NAME_LEN, stdin);
    player_name[strcspn(player_name, "\n")] = '\0';

    // Initialize players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].id = i;
        players[i].cards = HAND_SIZE;
        players[i].slap_time = -1;

        if (i == 0)
            strncpy(players[i].name, player_name, MAX_NAME_LEN);
        else
            snprintf(players[i].name, MAX_NAME_LEN, "NPC Player %d", i + 1);
    }

    press_to_continue();

    while (1) {
        system("cls"); // Use "clear" on macOS/Linux

        display_player_status(players);

        printf("\nTurn: %s\n", players[current_turn].name);
        printf("Saying: %s\n", sequence[current_word_index]);

        int drawn_card = get_random_card();
        printf("Card played: %s\n", cards[drawn_card]);

        int match = strcmp(sequence[current_word_index], cards[drawn_card]) == 0;

        // Handle special card HTWG
        if (drawn_card == SPECIAL_CARD_INDEX) {
            printf("\n🎓 Special HTWG card drawn!\n");
            if (current_turn == 0) {
                if (!perform_htwg_combo()) {
                    players[0].cards++;
                }
            } else {
                npc_perform_htwg_combo(&players[current_turn]);
            }
        }
        // Handle matching card (slap!)
        else if (match) {
            printf("\n>>> MATCH! Everyone must slap! <<<\n");

            clock_t start = clock();
            int human_slapped = 0;

            for (int i = 1; i < NUM_PLAYERS; i++) {
                players[i].slap_time = get_npc_slap_time();
            }

            while ((clock() - start) * 1000 / CLOCKS_PER_SEC < 2000) {
                if (!human_slapped && _kbhit()) {
                    char ch = _getch();
                    if (ch == ' ') {
                        players[0].slap_time = (clock() - start) * 1000 / CLOCKS_PER_SEC;
                        printf("%s slapped in %d ms\n", players[0].name, players[0].slap_time);
                        human_slapped = 1;
                    }
                }
            }

            if (!human_slapped) {
                players[0].slap_time = 2500;
                printf("%s did NOT slap!\n", players[0].name);
            }

            for (int i = 1; i < NUM_PLAYERS; i++) {
                wait_ms(players[i].slap_time);
                printf("%s slapped in %d ms\n", players[i].name, players[i].slap_time);
            }

            int slowest_index = 0;
            int max_time = players[0].slap_time;
            for (int i = 1; i < NUM_PLAYERS; i++) {
                if (players[i].slap_time > max_time) {
                    max_time = players[i].slap_time;
                    slowest_index = i;
                }
            }

            printf("\n👎 %s was the last to slap and gets a penalty card!\n", players[slowest_index].name);
            players[slowest_index].cards++;
        }

        if (players[current_turn].cards > 0)
            players[current_turn].cards--;

        // Check for win
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (players[i].cards <= 0) {
                printf("\n🎉 %s has won the game! 🎉\n", players[i].name);
                return 0;
            }
        }

        // Reset slap times
        for (int i = 0; i < NUM_PLAYERS; i++)
            players[i].slap_time = -1;

        current_turn = (current_turn + 1) % NUM_PLAYERS;
        current_word_index = (current_word_index + 1) % SEQUENCE_LENGTH;

        press_to_continue();
    }

    return 0;
}


return 0;
}
