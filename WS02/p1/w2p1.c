#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double amount;
    float tonnie = 2.00;
    float loonie = 1.00;
    float quarter = 0.25;
    int division;


    printf("Change Maker Machine\n====================\n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &amount);
    printf("\n");
    division = amount / tonnie;
    amount = amount - (division * tonnie);
    printf("$%.2lf Toonies  X %d (remaining: $%.2lf)\n", tonnie, division, amount);
    division = amount / loonie;
    amount = amount - (division * loonie);
    printf("$%.2lf Loonies  X %d (remaining: $%.2lf)\n", loonie, division, amount);
    division = amount / quarter;
    amount = amount - (division * quarter);
    printf("$%.2lf Quarters X %d (remaining: $%.2lf)\n", quarter, division, amount);

    printf("\nMachine error! Thank you for letting me keep $%.2lf!\n", amount);

    return 0;
}