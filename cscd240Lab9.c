#include "lab9.h"
#include "./utils/fileUtils.h"
#include "lab9.c"
#include "./utils/fileUtils.c"

const int MAX = 100;

int main(int argc, char ** argv)
{
	FILE * fin = NULL;
	int total, choice;
	Stock *array = NULL;

	fin = openInputFile();
	total = countRecords(fin, 3);
	rewind(fin);

	array = fillArray(fin, total);
	fclose(fin);

	do
	{
		choice = menu();
	    switch(choice)
	    {
	    	case 1:	symbolSort(array, total);
					printArray(array, total);
					break;

			case 2:	companySort(array, total);
					printArray(array, total);
					break;

		   case 3:	priceSort(total, array);
					printArray(array, total);
					break;

		   case 4:	printf("all done\n");

	     }// end switch

	   }while(choice != 4);

	   cleanUp(array, total);
	   free(array);
	   array = NULL;

	   return 0;

}// end main
