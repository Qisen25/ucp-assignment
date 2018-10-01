/*
 * tvguide c file 
 * AUTHOR: Kei Sum Wang, student ID: 19126089
 *
 * handles main and implements included function
 * from c files in current directory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tvguide.h"

#define MAX_CHAR_SORT 5

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        /*arg1 is input file name and arg2 is output filename*/
        printf("Please enter an input file and output file\n");
    }
    else if (argc > 3)
    {
        /*arg1 is input file name and arg2 is output filename*/
        printf("Too many arguments, only one input file and one output file is required\n");
    }
    else
    {
        process(argv);
    }

    return 0;
}

/*
 * process
 * IMPORTS: command arg array.
 * PURPOSE: to deal with and bundle use of functions from
 *          the current directory's source codes included.
 */
void process(char *argv[])
{
    int length, filterLength;
    char day[MAX_CHAR_DAY];/*MAX_CHAR_DAY is from data.h*/
    char sort[MAX_CHAR_SORT];
    TVShow **guide;
    LinkedList *list; 
    
    list = createLinkedList();/*initialise linked list*/

    storeFileContent(argv[1], list);/*call fileIO processFile function to read and store file content
                                 arg1 is input file name*/

    length = list->length;/*retrieve length from list struct field*/

    if (length < 1)/*list must be greater than 0 in order to process*/
    {
        printf("Error: no data to process (empty list)\n");
    }
    else
    {
        dayInput(day);/*call interface.c input function to get day*/
        sortInput(sort);/*call interface.c input function to get sort type*/
        
        guide = (TVShow**)malloc(length * sizeof(TVShow*));/*allocate heap memory for pointer to pointer guide*/
        memset(guide, 0, length * sizeof(TVShow*));/*this makes sure there is nothing in guides memory*/

        storeIntoArray(list, (void**)guide, length);/*call linkedlist's storeIntoArray func 
                                                      to store list in guide array.
                                                      Must typecast guide to void pointer to pointer
                                                      since the function takes void pointer to pointer*/

        filterLength = 0;
        sortGuides(guide, sort, length);
        filterByDay(guide, day, length, &filterLength);/*filter guide based on day*/

        display(guide, filterLength, sort, day);/*display filter guide to screen*/
        writeToFile(argv[2], guide, filterLength);/*write filtered guide to file 
                                                            arg2 is out filename*/
       
        free(guide);
    }
    
    freeLinkedList(list, FREE_DATA);/*free linked list, import FREE_DATA to indicate free of data
                                      FREE_DATA(has integer value 1) is a macro defined in linkedList.h*/
}

/*
 * sortGuide
 * IMPORTS: array of pointers TVShow guide, string for sort
 *          and length of list 
 * PURPOSE: handles sorting of guide array based on name or time
 */
void sortGuides(TVShow **guide, char *sort, int length)
{
    if(strcmp(sort, "name") == EQUAL)/*EQUAL is macro from boolean.h*/
    {
        /*compareName parameter is a function from comparison.c file*/
        qsort(guide, length, sizeof(TVShow*), compareName);
    }
    else if(strcmp(sort, "time") == EQUAL)
    {
        /*compareTime parameter is a function from comparison.c file*/
        qsort(guide, length, sizeof(TVShow*), compareTime);
    }  
}

/*
 * filterByDay
 * IMPORTS: array of pointers TVShow guide, string day, length and integer pointer filterLength
 * PURPOSE: to filter entries of specified day in imported guide array and remove entries from guide
 *          that are not of specified day. The end result for guide array will only contain
 *          entries of specified day. 
 */
void filterByDay(TVShow **guide, char *day, int length, int *filterLength)
{
    int i, j;
    TVShow *temp;

    i = 0;
    for(j = 0; j < length; j++)
    {
        /*only store entries into filtered array if entry
          contains day selected by user*/
        if (strcmp(day, guide[j]->day) == EQUAL)
        {
            temp = guide[j];/*Temporary TVShow pointer point to entry jth position*/
            guide[j] = NULL;/*remove jth element to prevent duplicate tv shows*/
            guide[i] = temp;/*move matching entry to ith position*/
            i++;/*only increment i if selected day matches*/
        }
        else
        {
            guide[j] = NULL;/*get rid of entries that are not of specified day*/
        }
    }

    *filterLength = i;/*filter length will be length ith times match day found*/
}
