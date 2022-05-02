#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    double userInput;
    int tonnie = 200;
    int loonie = 100;
    int quarter = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    float serviceFee;
    int balance;
    float remaining;
    int coinNumber;


    printf("Change Maker Machine\n====================\n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &userInput);
    userInput *= 100; // convert to cent
    serviceFee = (userInput * 5) / 100; //5% of payment
    printf("Service fee (5.0 percent): %.2f\n", serviceFee / 100);//show as dollar
    balance = userInput - serviceFee;
    printf("Balance to dispense: $%.2lf", (float)balance / 100);
    printf("\n");

    remaining = balance % tonnie;
    printf("\n$%.2lf Toonies  X %d (remaining: $%.2lf)\n", (float)tonnie / 100, balance / tonnie, remaining / 100);

    coinNumber = remaining / loonie;
    remaining = (int)remaining % loonie;
    printf("$%.2lf Loonies  X %d (remaining: $%.2lf)\n", (float)loonie / 100, coinNumber, remaining / 100);

    coinNumber = remaining / quarter;
    remaining = (int)remaining % quarter;
    printf("$%.2lf Quarters X %d (remaining: $%.2lf)\n", (float)quarter / 100, coinNumber, remaining / 100);

    coinNumber = remaining / dimes;
    remaining = (int)remaining % dimes;
    printf("$%.2lf Dimes    X %d (remaining: $%.2lf)\n", (float)dimes / 100, coinNumber, remaining / 100);

    coinNumber = remaining / nickels;
    remaining = (int)remaining % nickels;
    printf("$%.2lf Nickels  X %d (remaining: $%.2lf)\n", (float)nickels / 100, coinNumber, remaining / 100);

    coinNumber = remaining / pennies;
    remaining = (int)remaining % pennies;
    printf("$%.2lf Pennies  X %d (remaining: $%.2lf)\n", (float)pennies / 100, coinNumber, remaining / 100);

    printf("\nAll coins dispensed!\n");

    return 0;
}