/*
                ==================================================
                Workshop #5 (Part-2):
                ==================================================
                Name   : Sepehr Alipour
                ID     : 107296212
                Email  : salipour2@myseneca.ca
                Section: IPC 144 NMM
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAXIMUM_PATH_LENGTH 70
#define MAXIMUM_LIVES 10
#define MINIMUM_PATH_LENGTH 10
#define MINIMUM_LIVES 1
#define DIVISION 5

struct PlayerInfo
{
    char character;
    int lives;
    int treasureCounts;
    int moves;
    char positions[MAXIMUM_PATH_LENGTH];
    int currentPos;

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
void showBoard();
void getMove();
void gameOver();
void checkPath();

int main()
{
    int i;
    //reset curret poition
    playerInfo.currentPos = -1;

    printf("================================\n");
    printf("         Treasure Hunt!         ");
    printf("\n================================\n\n");

    playerConfig();
    gameConfig();
    bombConfig();
    treasureConfig();
    playGame();


    printf("\n");

    //Fill all positions with '-'
    for (i = 0; i < gameInfo.pathLength; i++)
    {
        playerInfo.positions[i] = '-';
    }

    while (playerInfo.lives > 0 && gameInfo.moves - playerInfo.moves > 0)
    {
        showBoard();
        getMove();
        checkPath();

    }

    gameOver();

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
            printf("     Must be between %d and %d!\n", MINIMUM_LIVES, MAXIMUM_LIVES);
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

    // no more than %75 of path length
    int maximumMoves = gameInfo.pathLength * 0.75;

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf_s("%d", &gameInfo.moves);
        if (gameInfo.moves < playerInfo.lives || gameInfo.moves > maximumMoves)
        {
            printf("    Value must be between %d and %d\n", playerInfo.lives, maximumMoves);
        }
    } while (gameInfo.moves < playerInfo.lives || gameInfo.moves > maximumMoves);

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
    printf("====================================");
    return;

}
void showBoard()
{
    int i, j = 0;

    if (playerInfo.currentPos >= 0) {
        printf("\n  ");

        for (i = 0; i < gameInfo.pathLength; i++)
        {
            if (i == playerInfo.currentPos)
                printf("%c", playerInfo.character);
            else
                printf("%c", ' ');

        }
    }
    printf("\n  ");
    for (i = 0; i < gameInfo.pathLength; i++)
    {
        printf("%c", playerInfo.positions[i]);

    }
    printf("\n  ");
    for (i = 1; i < gameInfo.pathLength + 1; i++)
    {
        if (i % 10 == 0)
            printf("%d", j += 1);
        else
            printf("|");
    }
    printf("\n  ");
    for (i = 1; i < gameInfo.pathLength + 1; i++)
    {
        printf("%d", i % 10);

    }

    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d", playerInfo.lives, playerInfo.treasureCounts, gameInfo.moves - playerInfo.moves);
    printf("\n+---------------------------------------------------+\n");

}
void getMove() {
    do {
        printf("Next Move [%d-%d]: ", 1, gameInfo.pathLength);
        scanf_s("%d", &playerInfo.currentPos);
        if (playerInfo.currentPos < 1 || playerInfo.currentPos > gameInfo.pathLength)
        {
            printf("  Out of Range!!!\n");
        }
    } while (playerInfo.currentPos < 1 || playerInfo.currentPos > gameInfo.pathLength);

    //change to index of array
    playerInfo.currentPos--;
    playerInfo.moves++;
}
void checkPath() {
    if (playerInfo.positions[playerInfo.currentPos] != '-')
    {
        //undo movement
        playerInfo.moves--;
        printf("\n===============> Dope! You've been here before!");
    }
    else {
        if (gameInfo.bombs[playerInfo.currentPos] == 1 && gameInfo.treasures[playerInfo.currentPos] == 1)
        {
            playerInfo.positions[playerInfo.currentPos] = '&';
            playerInfo.lives--;
            playerInfo.treasureCounts++;
            printf("\n===============> [%c] !!! BOOOOOM !!! [%c]", playerInfo.positions[playerInfo.currentPos], playerInfo.positions[playerInfo.currentPos]);
            printf("\n===============> [%c] $$$ Life Insurance Payout!!! [%c]", playerInfo.positions[playerInfo.currentPos], playerInfo.positions[playerInfo.currentPos]);

        }
        else if (gameInfo.treasures[playerInfo.currentPos] == 1)
        {
            playerInfo.positions[playerInfo.currentPos] = '$';
            playerInfo.treasureCounts++;
            printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]", playerInfo.positions[playerInfo.currentPos], playerInfo.positions[playerInfo.currentPos]);

        }
        else if (gameInfo.bombs[playerInfo.currentPos] == 1)
        {
            playerInfo.positions[playerInfo.currentPos] = '!';
            playerInfo.lives--;
            printf("\n===============> [%c] !!! BOOOOOM !!! [%c]", playerInfo.positions[playerInfo.currentPos], playerInfo.positions[playerInfo.currentPos]);
        }

        else
        {
            playerInfo.positions[playerInfo.currentPos] = '.';

            printf("\n===============> [%c] ...Nothing found here... [%c]", playerInfo.positions[playerInfo.currentPos], playerInfo.positions[playerInfo.currentPos]);
        }
    }
    printf("\n");

}
void gameOver()
{
    printf("\nNo more LIVES remaining!\n");
    showBoard();
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\nYou should play again and try to beat your score!");
}