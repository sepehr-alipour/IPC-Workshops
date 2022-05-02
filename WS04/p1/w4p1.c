/*
        ==================================================
        Workshop #4 (Part-1):
        ==================================================
        Name   : Sepehr Alipour
    ID     : 107296212
    Email  : salipour2@myseneca.ca
    Section: IPC 144 NMM
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAXIMUM_ITEMS 10
#include <stdio.h>

int main()
{
    const double MINIMUM_INCOME = 500;
    const double MINIMUM_COST = 100;
    const double MAXIMUM_INCOME = 400000;
    double userIncome = 0;
    int userItems = 0;
    int isValidated = 0;
    int state = 0;
    int priorities[MAXIMUM_ITEMS];
    char financing[MAXIMUM_ITEMS];
    double costs[MAXIMUM_ITEMS];
    double sum = 0;
    int i = 0;
    printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n");

    while (isValidated != 1)
    {
        switch (state)
        {
        case 0:

            printf("\nEnter your monthly NET income: $");
            scanf("%lf", &userIncome);
            if (userIncome < MINIMUM_INCOME)
            {
                printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MINIMUM_INCOME);
                state = 0;//user income
            }
            else if (userIncome > MAXIMUM_INCOME)
            {
                printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAXIMUM_INCOME);
                state = 0;// user income

            }
            else
            {
                state = 1; //got to next state (items)
            }
            break;
        case 1:

            printf("\nHow many wish list items do you want to forecast?: ");
            scanf("%d", &userItems);

            if (userItems > MAXIMUM_ITEMS || userItems < 1)
            {
                printf("ERROR: List is restricted to between 1 and %d items.\n", MAXIMUM_ITEMS);
                state = 1; //items
            }
            else
            {
                isValidated = 1;
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
                scanf("%lf", &costs[i]);
                if (costs[i] < MINIMUM_COST)
                {
                    printf("      ERROR: Cost must be at least $%.2lf", MINIMUM_COST);
                    state = 0;
                }
                else
                {
                    state = 1;
                }
                break;
            case 1:
                printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                scanf("%d", &priorities[i]);

                if (priorities[i] > 3 || priorities[i] < 1)
                {
                    printf("      ERROR: Value must be between 1 and 3\n");
                    state = 1;
                }
                else
                {
                    state = 2;
                }
                break;
            case 2:
                printf("   Does this item have financing options? [y/n]: ");
                scanf(" %c", &financing[i]);

                if (financing[i] == 'n' || financing[i] == 'y')
                {
                    isValidated = 1;

                }
                else
                {
                    printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                    state = 2;


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
    printf("\nBest of luck in all your future endeavours!");
    return 0;
}