#include "lab9.h"
#include "./utils/utils.h"

extern const int MAX;

int menu()
{
   int num;
   do
   {
   	printf("Please choose from the following\n");
   	printf("1) Sort by Symbol\n");
   	printf("2) Sort by Company Name\n");
   	printf("3) Sort by Price\n");
   	printf("4) Quit\n");
   	printf("Choice --> ");
   	scanf("%d", &num);
	   while(fgetc(stdin) != '\n');
   }while(num < 1 || num > 4);

   return num;
}// end menu




Stock * fillArray(FILE * fin, int total) {
	char temp[256];  // Temporary buffer for reading input
	Stock *array = (Stock *)malloc(sizeof(Stock) * total);

	// printf("We are filling the ARRAY. Total: %d\n", total);

	if (array == NULL) {
		printf("Memory allocation error\n");
		exit(1);
	}

	for (int i = 0; i < total; i++) {
		// Read the stock symbol (single word)
		fscanf(fin, "%s", temp);
		array[i].symbol = strdup(temp);  // Allocate memory and copy string
		// printf("Symbol %d: %s\n", i, array[i].symbol);

		// Consume the newline after `fscanf`
		fgetc(fin);

		// Read the full line for name
		fgets(temp, sizeof(temp), fin);
		temp[strcspn(temp, "\n")] = '\0';  // Remove newline
		array[i].name = strdup(temp);  // Allocate memory and copy
		// printf("Name %d: %s\n", i, array[i].name);

		// Read the price
		fscanf(fin, "%lf", &array[i].price);
		// printf("Price %d: %.2f\n", i, array[i].price);



		// THIS IS THE SAFER WAY
		// if (fscanf(fin, "%lf", &array[i].price) != 1) {
		// 	printf("Error reading price\n");
		// 	free(array[i].symbol);
		// 	free(array[i].name);
		// 	free(array);
		// 	exit(1);
		// }

	}

	return array;
}



void symbolSort(Stock array[], int total) {
	Stock temp;
	for(int sortedIndex = 0; sortedIndex < total; sortedIndex++){

		for(int checkSortIndex = 0; checkSortIndex < total - sortedIndex - 1; checkSortIndex++){
			if(strcmp(array[checkSortIndex].symbol, array[checkSortIndex + 1].symbol) > 0){
				temp = array[checkSortIndex];
				array[checkSortIndex] = array[checkSortIndex + 1];
				array[checkSortIndex + 1] = temp;

			}

		}



	}


	// printf("The sorted array is for symbol:\n");


}


void printArray(Stock array[], int total){
   int x;
	printf("\n");
   for(x = 0; x < total; x++)
      printf("%s - %s - $%.2lf\n\n", array[x].name, array[x].symbol, array[x].price);

}


void companySort(Stock array[], int total)
{
	Stock temp;
	for(int i = 0; i < total; i++) {
		for(int j = 0; j < total - i - 1; j++) {

			// this compares strings and returns 1 if compared as something
			if(strcmp(array[j].name, array[j + 1].name) > 0) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

			}
		}
	}

	// printf("The sorted array is for company:\n");



}// end companySort


void priceSort(int total, Stock array[])
{
	Stock temp;
	for(int sortedI = 0; sortedI < total; sortedI++) {

		for(int toSortI = 0; toSortI < total - sortedI - 1; toSortI++) {
			if(array[toSortI].price > array[toSortI + 1].price) {
				temp = array[toSortI];
				array[toSortI] = array[toSortI + 1];
				array[toSortI + 1] = temp;

			}
		}
	}
	// printf("The sorted array is for price:\n");

}// end priceSort


void cleanUp(Stock * array, int total)
{
	for(int i = 0; i < total; i++) {
		free(array[i].name);
		free(array[i].symbol);
		array[i].name = NULL;
		array[i].symbol = NULL;
		array[i].price = 0;
	}

}// end cleanUp