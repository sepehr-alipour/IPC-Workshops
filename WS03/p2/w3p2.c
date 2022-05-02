/*
        ==================================================
        Workshop #3 (Part-2):
        ==================================================
        Name   : Sepehr Alipour
        ID     : 107296212
        Email  : salipour2@myseneca.ca
        Section: IPC 144 NMM
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MIN_RATE 0.0
#define MAX_YEAR 2021
#define MAX_RATE 5.0
#define LOG_DAYS 3

int main()
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month, i;
    int errors = 0;
    double morningRate = 0.0;
    double eveningRate = 0.0;
    double morningTotal = 0.0;
    double eveningTotal = 0.0;
    double avgOveralTotal = 0.0;

    printf("General Well-being Log\n======================\n");
    do
    {
        errors = 0;
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf_s("%d %d", &year, &month);
        if (year > MAX_YEAR || year < MIN_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            errors++;
        }
        if (month > DEC || month < JAN)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            errors++;

        }

    } while (errors > 0);
    printf("\n*** Log date set! ***\n");
    for (i = 1; i < LOG_DAYS + 1; i++)
    {
        switch (month) {
        case 1:
            printf("\n%d-%s-%02d\n", year, "JAN", i);
            break;
        case 2:
            printf("\n%d-%s-%02d\n", year, "FEB", i);
            break;
        case 3:
            printf("\n%d-%s-%02d\n", year, "MAR", i);
            break;
        case 4:
            printf("\n%d-%s-%02d\n", year, "APR", i);
            break;
        case 5:
            printf("\n%d-%s-%02d\n", year, "MAY", i);
            break;
        case 6:
            printf("\n%d-%s-%02d\n", year, "JUN", i);
            break;
        case 7:
            printf("\n%d-%s-%02d\n", year, "JUL", i);
            break;
        case 8:
            printf("\n%d-%s-%02d\n", year, "AUG", i);
            break;
        case 9:
            printf("\n%d-%s-%02d\n", year, "SEP", i);
            break;
        case 10:
            printf("\n%d-%s-%02d\n", year, "OCT", i);
            break;
        case 11:
            printf("\n%d-%s-%02d\n", year, "NOV", i);
            break;
        case 12:
            printf("\n%d-%s-%02d\n", year, "DEC", i);
            break;
        default:
            break;
        }
        do
        {
            errors = 0;
            printf("   Morning rating (0.0-5.0): ");
            scanf_s("%lf", &morningRate);
            if (morningRate > MAX_RATE || morningRate < MIN_RATE)
            {
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n", MIN_RATE, MAX_RATE);
                errors++;
            }
            else {
                morningTotal += morningRate;
            }


        } while (errors > 0);
        do
        {
            errors = 0;
            printf("   Evening rating (0.0-5.0): ");
            scanf_s("%lf", &eveningRate);
            if (eveningRate > MAX_RATE || eveningRate < MIN_RATE)
            {
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n", MIN_RATE, MAX_RATE);
                errors++;
            }
            else {
                eveningTotal += eveningRate;
            }


        } while (errors > 0);



    }
    printf("\nSummary\n=======\n");
    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating: %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningTotal + eveningTotal);
    printf("Average morning rating:  %.1lf\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    avgOveralTotal = ((morningTotal / LOG_DAYS) + (eveningTotal / LOG_DAYS)) / 2;
    printf("Average overall rating:  %.1lf", avgOveralTotal);
    return 0;
}