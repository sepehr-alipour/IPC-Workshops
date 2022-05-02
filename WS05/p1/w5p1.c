/*
        ==================================================
        Workshop #5 (Part-1):
        ==================================================
        Name   : Sepehr Alipour
        ID     : 107296212
        Email  : salipour2@myseneca.ca
        Section: IPC 144 NMM
*/
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAXIMUM_MOVES 26
#define MAXIMUM_PATH_LENGTH 70
#define MAXIMUM_LIVES 10
#define MINIMUM_PATH_LENGTH 10
#define MINIMUM_MOVES 3
#define MINIMUM_LIVES 1
#define DIVISION 5

struct PlayerInfo
{
    char character;
    int lives;
    int treasureCounts;
    int positions[MAXIMUM_PATH_LENGTH];

} playerInfo;

struct GameInfo
{
    int bombs[MAXIMUM_PATH_LENGTH];
    int treasures[MAXIMUM_PATH_LENGTH];
    int moves;
    int pathLength;
}gameInfo;

void playerConfig();
void gameConfig();
void bombConfig();
void treasureConfig();
void playGame();

int main()
{
    printf("================================\n");
    printf("         Treasure Hunt!         ");
    printf("\n================================\n\n");
    playerConfig();
    gameConfig();
    bombConfig();
    treasureConfig();
    playGame();
    return 0;
}

void playerConfig()
{
    printf("PLAYER Configuration\n--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf_s("%c", &playerInfo.character);
    do {
        printf("Set the number of lives: ");
        scanf_s("%d", &playerInfo.lives);
        if (playerInfo.lives < MINIMUM_LIVES || playerInfo.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (playerInfo.lives<MINIMUM_LIVES || playerInfo.lives > MAXIMUM_LIVES);
    printf("Player configuration set-up is complete\n\n");
    return;
}
void gameConfig()
{
    printf("GAME Configuration\n------------------\n");
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", DIVISION, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
        scanf_s("%d", &gameInfo.pathLength);
        if (gameInfo.pathLength < MINIMUM_PATH_LENGTH || gameInfo.pathLength > MAXIMUM_PATH_LENGTH || gameInfo.pathLength % DIVISION != 0)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", DIVISION, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
        }

    } while (gameInfo.pathLength < MINIMUM_PATH_LENGTH || gameInfo.pathLength > MAXIMUM_PATH_LENGTH || gameInfo.pathLength % DIVISION != 0);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf_s("%d", &gameInfo.moves);
        if (gameInfo.moves < MINIMUM_MOVES || gameInfo.moves > MAXIMUM_MOVES)
        {
            printf("    Value must be between %d and %d\n", MINIMUM_MOVES, MAXIMUM_MOVES);
        }
    } while (gameInfo.moves < MINIMUM_MOVES || gameInfo.moves > MAXIMUM_MOVES);

    printf("\nBOMB Placement\n--------------\n");
    return;

}
void bombConfig()
{
    int i, j;
    printf("Enter the bomb positions in sets of %d where a value\n", DIVISION);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.pathLength);
    for (i = 0; i < gameInfo.pathLength; i += DIVISION)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + DIVISION);

        for (j = i; j < DIVISION + i; j++)
        {
            scanf_s("%d", &gameInfo.bombs[j]);
        }
    }
    printf("BOMB placement set\n");
    return;

}
void treasureConfig()
{
    int i, j;
    printf("\nTREASURE Placement\n------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", DIVISION);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.pathLength);
    for (i = 0; i < gameInfo.pathLength; i += DIVISION)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + DIVISION);

        for (j = i; j < DIVISION + i; j++)
        {
            scanf_s("%d", &gameInfo.treasures[j]);
        }
    }
    printf("TREASURE placement set\n");
    return;
}
void playGame()
{
    int i;
    printf("\nGAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", playerInfo.character);
    printf("   Lives      : %d\n", playerInfo.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]");
    printf("\n\nGame:\n");
    printf("   Path Length: %d\n", gameInfo.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < gameInfo.pathLength; i++)
    {
        printf("%d", gameInfo.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < gameInfo.pathLength; i++)
    {
        printf("%d", gameInfo.treasures[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return;

}