/*
        ==================================================
        Workshop #6 (Part-2):
        ==================================================
                Name   : 
                ID     : 
                Email  : 
                Section: IPC 144 NMM
*/

#define _CRT_SECURE_NO_WARNINGS
// System Libraries
#include <stdio.h>


// User-Defined Libraries
#include "w6p2.h"


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* positiveNumber) {
    int number;
    do {
        scanf("%d", &number);
        if (number <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (number <= 0);
    if (positiveNumber != NULL)
        *positiveNumber = number;

    return number;

}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* positiveNumber) {
    double number;
    do {

        scanf("%lf", &number);
        if (number <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (number <= 0);
    if (positiveNumber != NULL)
        *positiveNumber = number;

    return number;

}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int productNumbers) {

    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", productNumbers);
    printf("NOTE: A 'serving' is %dg\n", NUMBER_OF_GRAMS);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productSequences) {
    struct CatFoodInfo catFoodInfo;
    printf("\nCat Food Product #%d\n", productSequences);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&catFoodInfo.sku);
    printf("PRICE         : $");
    getDoublePositive(&catFoodInfo.price);
    printf("WEIGHT (LBS)  : ");
    catFoodInfo.weight = getDoublePositive(&catFoodInfo.weight);
    printf("CALORIES/SERV.: ");
    catFoodInfo.calories = getIntPositive(&catFoodInfo.calories);
    return catFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("\n");
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku
    , const double* price
    , const int calories
    , const double* weight) {

    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* weight, double* convRes) {
    double result = *weight / KG_METRIC_UNIT;

    if (convRes != NULL) {
        *convRes = result;
    }

    return result;

}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* weight, int* convRes) {
    int result = (int)(*weight / KG_METRIC_UNIT * 1000);
    if (convRes != NULL) {

        *convRes = result;
    }
    return result;
}

// 10. convert lbs: kg and g
void convertLbs(const double* weight, double* kgConvRes, int* grConvRes) {
    convertLbsKg(weight, kgConvRes);
    convertLbsG(weight, grConvRes);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalWeight, double* resultRes) {
    double result = (double)totalWeight / (double)servingSize;
    if (resultRes != NULL) {
        *resultRes = result;
    }
    return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total, double* resultRes) {
    double result = *price / *total;
    if (resultRes != NULL) {
        *resultRes = result;
    }
    return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* servingPrice, const double* calories, double* resultRes) {
    double result = *servingPrice / *calories;
    if (resultRes != NULL) {
        *resultRes = result;
    }
    return result;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo) {
    struct ReportData reportData;
    reportData.sku = catFoodInfo.sku;
    reportData.calories = catFoodInfo.calories;
    reportData.lbsWeight = catFoodInfo.weight;
    reportData.price = catFoodInfo.price;
    convertLbsG(&catFoodInfo.weight, &reportData.grWeight);
    convertLbsKg(&catFoodInfo.weight, &reportData.kgWeight);
    calculateServings(NUMBER_OF_GRAMS, reportData.grWeight, &reportData.totalServing);
    calculateCostPerServing(&catFoodInfo.price, &reportData.totalServing, &reportData.costServing);
    double calories = catFoodInfo.calories;
    calculateCostPerCal(&reportData.costServing, &calories, &reportData.costCalories);
    return reportData;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("\nAnalysis Report (Note: Serving = %dg\n", NUMBER_OF_GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int record) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
        reportData.sku,
        reportData.price,
        reportData.lbsWeight,
        reportData.kgWeight,
        reportData.grWeight,
        reportData.calories,
        reportData.totalServing,
        reportData.costServing,
        reportData.costCalories);
    if (record > 0)
        printf(" ***");
    printf("\n");

}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo CatFoodInfo) {
    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n", CatFoodInfo.sku, CatFoodInfo.price);
    printf("\nHappy shopping!");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start() {
    int i;
    struct CatFoodInfo foods[MAXIMUM_PRODUCT_NUMBERS];
    struct ReportData reportData[MAXIMUM_PRODUCT_NUMBERS];
    double  cheapest = 1;
    int index = 0;

    openingMessage(MAXIMUM_PRODUCT_NUMBERS);
    for (i = 0; i < MAXIMUM_PRODUCT_NUMBERS; i++)
    {
        foods[i] = getCatFoodInfo(i + 1);
    }
    displayCatFoodHeader();
    for (i = 0; i < MAXIMUM_PRODUCT_NUMBERS; i++)
    {
        displayCatFoodData(foods[i].sku, &foods[i].price, foods[i].calories, &foods[i].weight);
    }
    displayReportHeader();
    for (i = 0; i < MAXIMUM_PRODUCT_NUMBERS; i++)
    {
        reportData[i] = calculateReportData(foods[i]);
        if (reportData[i].costCalories < cheapest) {

            cheapest = reportData[i].costCalories;
            index = i;
        }

    }
    for (i = 0; i < MAXIMUM_PRODUCT_NUMBERS; i++)
    {
        displayReportData(reportData[i], i == index ? index + 1 : 0);
    }
    displayFinalAnalysis(foods[index]);
}