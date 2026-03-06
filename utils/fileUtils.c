#include "fileUtils.h"
#include "utils.h"
#include "utils.c"

void readFileName(char * fn)
{
    printf("Please enter the name of the file ");
    fgets(fn, MAXIMUM, stdin);
    strip(fn);

}// end readFileName

FILE * openInputFile()
{
    char fn[MAXIMUM];
    FILE * inf =NULL;
    do
    {
        readFileName((fn));
        inf = fopen(fn, "r");

    }while(inf == NULL);

    return inf;
}

int countRecords(FILE * fin, const int linesPerRecord)
{
    char temp[MAXIMUM];
    int count = 0;

    while(fgets(temp, MAXIMUM, fin)) {
        count++;

    }

    // printf("Number of records: %d\n", count);
    // printf("Number of lines: %d\n", linesPerRecord);

    return count / linesPerRecord;


}

