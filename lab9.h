#ifndef LAB9_H
#define LAB9_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock
{
   char *symbol;
   char *name;
   double price;

};

typedef struct stock Stock;


/**
 * Creates the array of Stocks and then fills the array with Stocks.
 * Reading from the file.  Note the file  * contains 3 lines per Stock.
 * You are guaranteed the file is well-formed
 * @parma fin Representing an open and valid FILE pointer
 * @param total Representing the number of stocks in the array
 * @return Stock * Representing the array of Stocks
 */
Stock * fillArray(FILE * fin, int total);

/** 
 * The menu method provided by me
 * NOTE the input buffer is cleared by the end
 * of this function
 * @return int Representing the menu choice
 */
int menu();

/**
 * The symbolSort sorts the Stock array purely by the String for
 * the symbol
 * <br> You must write the selectionSort for this
 * @param array Representing the Stock array
 * @param total Representing the total items in the array
 */
void symbolSort(Stock array[], int total);


/**
 * The companySort sorts the Stock array purely by the String for
 * the company name
 * <br> You must write the selectionSort for this
 * @param array Representing the Stock array
 * @param total Representing the total items in the array
 */
void companySort(Stock array[], int total);

/**
 * The priceSort sorts the Stock array purely by the double for
 * the price
 * <br> You must write the selectionSort for this
 * @param array Representing the Stock array
 * @param total Representing the total items in the array
 */
void priceSort(int total, Stock array[]);

/** 
 * Prints the company name - symbol - $price to two decimal places
 * @param array Representing the Stock array
 * @param total Representing the total items in the array
 */
void printArray(Stock array[], int total);

/**
 * Cleans up the dynamic memory allocated in the array for sybmol and name
 * @param array Representing the Stock array
 * @param total Representing the total items in the array
 */
void cleanUp(Stock * array, int total);

#endif
