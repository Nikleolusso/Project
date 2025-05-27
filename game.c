//For Functions
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Swap two cards (for shuffle function)
void swap(const char** a, const char** b) {
    const char* temp = *a;
    *a = *b;
    *b = temp;
}

// Fisher-Yates shuffle
void shuffleDeck(const char* deck[], int deck_size) {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&deck[i], &deck[j]);
    }

}

//Deal cards
void dealCards(Player players[], const char* deck[], int numPlayers, int cardsPerPlayer) {
    for(int i = 0; i < numPlayers; i++) {
        for(int j = 0; j < cardsPerPlayer; j++) {
        players[i].hand[j] = deck[i * cardsPerPlayer + j];
        }
        players[i].cardCount = cardsPerPlayer;
    }
    current_deck_position = numPlayers * cardsPerPlayer;
}

void press_to_continue() {
    printf("\nPress Enter to continue...\n");
    while (getchar() != '\n');
}

const char* draw_from_deck() {
    if (current_deck_position >= DECK_SIZE) {
        printf("Reshuffling deck!\n");
        shuffleDeck(deck, DECK_SIZE);
        current_deck_position = 0;
    }
    return deck[current_deck_position++];
}

void display_player_status(Player players[]) {
    printf("\n--- Card Counts ---\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d cards\n", players[i].name, players[i].cardCount);
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
        npc->cardCount++;
    }
    return success;
}
