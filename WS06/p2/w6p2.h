/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
		Name   : 
		ID     : 
		Email  : 
		Section: IPC 144 NMM
*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAXIMUM_PRODUCT_NUMBERS 3
#define NUMBER_OF_GRAMS 64
#define KG_METRIC_UNIT 2.20462

// ----------------------------------------------------------------------------
// structures
struct ReportData {
	int sku;
	double price;
	int calories;
	int grWeight;
	double lbsWeight;
	double kgWeight;
	double totalServing;
	double costServing;
	double costCalories;
};
struct CatFoodInfo {
	int sku;
	double price;
	int calories;
	double weight;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* weight, double* convRes);

// 9. convert lbs: g
int convertLbsG(const double* weight, int* convRes);


// 10. convert lbs: kg / g
void convertLbs(const double* weight, double* kgConvRes, int* grConvRes);


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalWeight, double* resultRes);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total, double* resultRes);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* resultRes);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int record);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo CatFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();
