#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define player structure
struct Player {
    char name[50];
    int health;
};

// Function to initialize player
void initializePlayer(struct Player* player, const char* playerName) {
    strcpy(player->name, playerName);
    player->health = 100;
}

// Function to simulate an encounter
void encounter(struct Player* player) {
    printf("\nYou encounter a fearsome dragon!\n");
    printf("What will you do?\n");
    printf("1. Attack\n");
    printf("2. Run\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You swing your sword at the dragon!\n");
            player->health -= 20;
            break;
        case 2:
            printf("You flee from the dragon!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    struct Player player;
    char playerName[50];

    printf("Welcome to the Text Adventure Game!\n");
    printf("Enter your character's name: ");
    scanf("%s", playerName);

    initializePlayer(&player, playerName);

    while (player.health > 0) {
        printf("\n%s, you find yourself in a dark forest.\n", player.name);
        printf("Your health: %d\n", player.health);

        encounter(&player);

        printf("\n%s, your health now: %d\n", player.name, player.health);
    }

    printf("\nGame over! You have succumbed to your injuries.\n");

    return 0;
}
