#ifndef FILEUTILS_H
#define FILEUTILS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXIMUM 100

/**
 * Read File name uses fgets to read the filename from the keyboard
 * Once the filename is read, the carriage return is stripped by calling
 * strip in utils.c
 * @param fn Representing the name of the file to be read
 */
void readFileName(char * fn);

/**
 * OpenInputFile calls readFileName to obtain the file name.
 * It then tries to open the file. It ensures the file is open
 * @return FILE * Representing the open file.
 */
FILE * openInputFile();

/**
 * Count Records counts the lines in the file and then returns the number of lines
 * divided by linesPerRecord.
 * @param fin Representing the open input file
 * @param linesPerRecord Representing the number of lines per record
 * @return int Representing the true number of records in the file.
 */
int countRecords(FILE * fin, const int linesPerRecord);

#endif
