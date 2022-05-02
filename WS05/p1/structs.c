#define MAX_LENGTH 70
#define MIN_LENGTH 10
struct player
{
	char symbol;
	int lifes;
	int treasures;
	int pos[MAX_LENGTH];

};

struct gamePlay
{
	int bombs[MAX_LENGTH];
	int treasures[MAX_LENGTH];
	int movements;
	int length;
};