/*
        ==================================================
        Workshop #3 (Part-1):
        ==================================================
    Name   : Sepehr Alipour
    ID     : 107296212
    Email  : salipour2@myseneca.ca
    Section: IPC 144 NMM
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main()
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    int errors = 0;
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
    printf("\n*** Log date set! ***\n\n");
    switch (month)
    {
    case 1:
        printf("Log starting date: %d-%s-01\n", year, "JAN");
        break;
    case 2:
        printf("Log starting date: %d-%s-01\n", year, "FEB");
        break;
    case 3:
        printf("Log starting date: %d-%s-01\n", year, "MAR");
        break;
    case 4:
        printf("Log starting date: %d-%s-01\n", year, "APR");
        break;
    case 5:
        printf("Log starting date: %d-%s-01\n", year, "MAY");
        break;
    case 6:
        printf("Log starting date: %d-%s-01\n", year, "JUN");
        break;
    case 7:
        printf("Log starting date: %d-%s-01\n", year, "JUL");
        break;
    case 8:
        printf("Log starting date: %d-%s-01\n", year, "AUG");
        break;
    case 9:
        printf("Log starting date: %d-%s-01\n", year, "SEP");
        break;
    case 10:
        printf("Log starting date: %d-%s-01\n", year, "OCT");
        break;
    case 11:
        printf("Log starting date: %d-%s-01\n", year, "NOV");
        break;
    case 12:
        printf("Log starting date: %d-%s-01\n", year, "DEC");
        break;
    default:
        break;
    }

    return 0;
}