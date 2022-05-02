//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX_PATH 70
//
//struct PlayerInfo
//{
//	int numLives;
//	char charecterSymbol;
//	int numTreasure;
//	int positions[MAX_PATH];
//
//};
//struct GameInfo
//{
//	int maxNumMove;
//	int pathLength;
//	int bombs[MAX_PATH];
//	int tearesure[MAX_PATH];
//
//};
//
//int main() {
//	struct PlayerInfo player;
//	struct GameInfo game;
//
//	printf("================================\n");
//	printf("         Treasure Hunt!         ");
//	printf("\n================================\n\n");
//	printf("PLAYER Configuration\n");
//	printf("--------------------\n");
//	printf("Enter a single character to represent the player: ");
//	scanf("%c", &player.charecterSymbol);
//	do
//	{
//		printf("Set the number of lives: ");
//		scanf("%d", &player.numLives);
//		if (player.numLives < 1 || player.numLives > 10)
//		{
//			printf("     Must be between 1 and 10!\n");
//
//		}
//
//	} while (player.numLives < 1 || player.numLives > 10);
//	printf("Player configuration set-up is complete\n\n");
//	printf("GAME Configuration\n");
//	printf("------------------\n");
//	do
//	{
//		printf("Set the path length (a multiple of 5 between 10-70): ");
//		scanf("%d", &game.pathLength);
//		if (game.pathLength < 10 || game.pathLength > 70 || game.pathLength % 5 != 0)
//		{
//			printf("     Must be a multiple of 5 and between 10-70!!!\n");
//		}
//
//	} while (game.pathLength <10 || game.pathLength > 70 || game.pathLength % 5 != 0);
//
//	do
//	{
//		printf("Set the limit for number of moves allowed: ");
//		scanf("%d", &game.maxNumMove);
//		if (game.maxNumMove < 3 || game.maxNumMove > 26)
//		{
//			printf("    Value must be between 3 and 26\n");
//		}
//	} while (game.maxNumMove < 3 || game.maxNumMove > 26 );
//
//	printf("\nBOMB Placement\n");
//	printf("--------------\n");
//	printf("Enter the bomb positions in sets of 5 where a value\n");
//	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
//	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
//	int i;
//	for ( i = 0; i < game.pathLength; i+=5)
//	{
//		printf("   Positions [%2d-%2d]: ",i+1 , i+5);
//		int j;
//		for ( j = i; j < i + 5; j++)
//		{
//			scanf("%d", &game.bombs[j]);
//		}
//	}
//	printf("BOMB placement set\n");
//	printf("\nTREASURE Placement\n");
//	printf("------------------\n");
//	printf("Enter the treasure placements in sets of 5 where a value\n");
//	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
//	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
//	for ( i = 0; i < game.pathLength; i+= 5)
//	{
//		int j;
//		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
//		for ( j = i; j < i+5; j++)
//		{
//			scanf("%d", &game.tearesure[j]);
//		}
//	}
//	printf("TREASURE placement set\n");
//	printf("\nGAME configuration set-up is complete...\n");
//	printf("\n------------------------------------\n");
//	printf("TREASURE HUNT Configuration Settings\n");
//	printf("------------------------------------\n");
//	printf("Player:\n");
//	printf("   Symbol     : %c\n", player.charecterSymbol);
//	printf("   Lives      : %d\n", player.numLives);
//	printf("   Treasure   : [ready for gameplay]\n");
//	printf("   History    : [ready for gameplay]\n");
//	printf("\nGame:\n");
//	printf("   Path Length: %d\n", game.pathLength);
//	printf("   Bombs      : ");
//	for ( i = 0; i < game.pathLength; i++)
//	{
//		printf("%d", game.bombs[i]);
//	}
//	printf("\n   Treasure   : ");
//	for (i = 0; i < game.pathLength; i++)
//	{
//		printf("%d", game.tearesure[i]);
//	}
//	printf("\n\n====================================");
//	printf("\n~ Get ready to play TREASURE HUNT! ~\n");
//	printf("====================================\n");
//
//	return 0;
//
//
//}