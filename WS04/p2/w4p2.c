/*
		==================================================
		Workshop #4 (Part-2):
		==================================================
		Name   : Sepehr Alipour
		ID     : 107296212
		Email  : salipour2@myseneca.ca
		Section: IPC 144 NMM
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAXIMUM_ITEMS 10
#include <stdio.h>
void clearStandardInputBuffer(void) {
	while (getchar() != '\n') {
		; // On purpose: do nothing 
	}
}
double getDouble() {
	char returnChar;
	double number;
	do {
		scanf("%lf%c", &number, &returnChar);
		if (returnChar != '\n')
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (returnChar != '\n');
	return number;
}
int getInteger() {
	char returnChar = '0';
	int number;
	do {
		scanf("%d%c", &number, &returnChar);
		if (returnChar == '\n')
			return number;
		else {
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} while (returnChar != '\n');

	return number;
}
int main()
{
	const double MINIMUM_INCOME = 500;
	const double MINIMUM_COST = 100;
	const double MAXIMUM_INCOME = 400000;
	double userIncome = 0;
	double sum = 0;
	int priorities[MAXIMUM_ITEMS] = { 0 };
	char financing[MAXIMUM_ITEMS] = { 0 };
	double costs[MAXIMUM_ITEMS] = { 0 };
	int priority = 0, userItems = 0, isValidated = 0, hasFinance = 0, state = 0, i = 0, option = 0;

	printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n");
	while (isValidated != 1)
	{
		switch (state)
		{

		case 0:

			printf("\nEnter your monthly NET income: $");
			userIncome = getDouble();
			if (userIncome < MINIMUM_INCOME)
			{
				printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MINIMUM_INCOME);
				state = 0;// stay at user income state
			}
			else if (userIncome > MAXIMUM_INCOME)
			{
				printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAXIMUM_INCOME);
				state = 0;// stay at user income state

			}
			else
			{
				state = 1; // gotto next state (get items)
			}
			break;
		case 1:

			printf("\nHow many wish list items do you want to forecast?: ");
			userItems = getInteger();

			if (userItems > MAXIMUM_ITEMS || userItems < 1)
			{
				printf("ERROR: List is restricted to between 1 and %d items.\n", MAXIMUM_ITEMS);
				state = 1; // stay at get items state
			}
			else
			{
				isValidated = 1;// validated
			}
			break;


		default:
			break;
		}

	}

	for (i = 0; i < userItems; i++)
	{
		isValidated = 0;
		state = 0;
		printf("\nItem-%d Details:", i + 1);
		while (isValidated != 1)
		{
			switch (state)
			{
			case 0:
				printf("\n   Item cost: $");
				costs[i] = getDouble();
				if (costs[i] < MINIMUM_COST)
				{
					printf("      ERROR: Cost must be at least $%.2lf", MINIMUM_COST);
					state = 0; //stay at item cost state
				}
				else
				{
					state = 1; //goto next state (priority)
				}
				break;
			case 1:
				printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
				priorities[i] = getInteger();

				if (priorities[i] > 3 || priorities[i] < 1)
				{
					printf("      ERROR: Value must be between 1 and 3\n");
					state = 1;// stay at priority state
				}
				else
				{
					state = 2;// goto next state (financing)
				}
				break;
			case 2:
				printf("   Does this item have financing options? [y/n]: ");
				scanf_s(" %c", &financing[i]);

				if (financing[i] == 'n' || financing[i] == 'y')
				{
					isValidated = 1; // validated

				}
				else
				{
					printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
					state = 2; // stay at financing state


				}
				break;
			default:
				break;
			}
		}

	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < userItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priorities[i], financing[i], costs[i]);
		sum += costs[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", sum);

	isValidated = 0;

	while (isValidated != 1)
	{
		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		option = getInteger();
		hasFinance = 0;

		switch (option)
		{
		case 1:
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", sum);
			printf("Forecast: %d years, %d months\n", (int)(sum / userIncome) / 12, (int)((sum / userIncome) + 1) % 12);
			for (i = 0; i < userItems; i++)
			{
				if (financing[i] == 'y') {

					hasFinance = 1; //set 1 to show notes
				}


			}
			if (hasFinance == 1)
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
			printf("====================================================\n");
			break;
		case 2:

			do
			{
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				priority = getInteger();
				if (priority < 1 || priority>3)
				{
					printf("ERROR: Value must be between 1 and 3\n");
				}
			} while ((priority < 1 || priority>3));

			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", priority);
			double prioritySum = 0;
			for (i = 0; i < userItems; i++)
			{
				if (priorities[i] == priority)
				{
					prioritySum += costs[i];

				}
				if (priorities[i] == priority && financing[i] == 'y') {

					hasFinance = 1;
				}

			}

			printf("Amount:   $%1.2lf\n", prioritySum);
			printf("Forecast: %d years, %d months\n", (int)(prioritySum / userIncome) / 12, (int)((prioritySum / userIncome) + 1) % 12);
			if (hasFinance == 1)
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");

			printf("====================================================\n");
			break;
		case 0:
			printf("\nBest of luck in all your future endeavours!");
			isValidated = 1;
			break;


		default:
			printf("\nERROR: Invalid menu selection.\n");
			break;
		}
	}


	return 0;
}