/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
		Name   : 
		ID     : 
		Email  : 
		Section: IPC 144 NMM
*/

#define MAXIMUM_PRODUCT_NUMBERS 3
#define NUMBER_OF_GRAMS 64
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
	int sku;
	double price;
	int calories;
	double weight;
};



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* positiveNumber);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* positiveNumber);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNumbers);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productSequences);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku
	, const double* price
	, const int calories
	, const	double* weight);

// 7. Logic entry point
void start();

