/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
		Name   : 
		ID     : 
		Email  : 
		Section: IPC 144 NMM
*/

#define _CRT_SECURE_NO_WARNINGS



// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"


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
	, const	double* weight) {

	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// 7. Logic entry point
void start() {
	int i, j;
	struct CatFoodInfo foods[MAXIMUM_PRODUCT_NUMBERS];
	openingMessage(MAXIMUM_PRODUCT_NUMBERS);
	for (i = 0; i < MAXIMUM_PRODUCT_NUMBERS; i++)
	{
		foods[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (j = 0; j < MAXIMUM_PRODUCT_NUMBERS; j++)
	{
		displayCatFoodData(foods[j].sku, &foods[j].price, foods[j].calories, &foods[j].weight);
	}
}