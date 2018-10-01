/*
 * file dealing with file io
 * by Kei Sum Wang, student id: 19126089
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileIO.h"
#include "boolean.h"
#include "interface.h"

#define MAX_CHARS 100

/*
 * processFile
 * IMPORTS: string fileName, and a pointer to LinkedList.
 * PURPOSE: reads if file format is all correct
 *          and stores name, day and time fields of 
 *          allocated TVShow struct. Each Allocated TVShow struct
 *          is stored into a list.
 */
void storeFileContent(char *fileName, LinkedList *list)
{
    FILE *file = fopen(fileName, "r");
    char str[MAX_CHARS];
    int validFormat;
    TVShow *show;

    validFormat = validateFormat(file);/*checks if file is valid and returns 
                                         an integer*/

    if (file == NULL && validFormat != TRUE)/*if file does not exist, it is also not valid*/
    {
        perror("Error reading file");
    }
    else if (validFormat != TRUE)/*file could exist but format may not be valid*/
    {
        printf("Invalid file, please check the input file.\n");
        printf("In the file make sure there is a name for the TV show.\n"); 
        printf("The line after the name of TV show should have,\n"); 
        printf("a valid day of the week and time in 24 hour format (00:00).\n");

        fclose(file);/*close file since it the file exist*/
    }
    else
    { 
        while (fgets(str, MAX_CHARS, file) != NULL)
        {
            show = (TVShow*)malloc(sizeof(TVShow));/*every loop allocates 
                                                          a new TVShow struct*/
                                     
            strncpy(show->name, str, MAX_CHARS);/*get name assign it to struct name field 
                                                  must copy string when assigning str*/
            fgets(str, MAX_CHARS, file);/*read line after to get day and time */
            sscanf(str, "%11s %2d:%2d", show->day, &(show->time.hours), &(show->time.mins));/*store day, hours and mins*/

            upperFirstLetter(show->day);/*if day is correct but wrong capitalisation format
                                          just convert to correct format*/
         
            insertLast(list, show);/*insert last into linked list for ascending order*/        
       
        }

        if (ferror(file))/*check if any error when read*/
        {
            printf("Error reading file\n");
        }

        fclose(file);
    }

}

/*
 * writeToFile
 * IMPORTS: string fileName, pointer to pointer struct TVShow
 *          and length, 
 * PURPOSE: writes content of tvshow guide to file
 */
void writeToFile(char *fileName, TVShow **guide, int length)
{
    FILE *file = fopen(fileName, "w");
    int i;


    if (file == NULL)
    {
        printf("\n");
        perror("Error writing to file");
    }
    else if (length < 1)/*at least 1 show should be in guide in order to write to file*/
    {
        printf("nothing to write to file: %s\n", fileName);
        fclose(file);
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            /*hours and minutes should only have 2 digits,
              if it is single digit then just add zero
              at the front*/ 
            fprintf(file, "%02d:%02d - %s", guide[i]->time.hours, guide[i]->time.mins, guide[i]->name);
        }

        if (ferror(file))
        {
            printf("Error writing to file");/*if error found, print error*/
        }
        else
        {
            printf("\nWrite to file: %s success\n", fileName);/*print success if no error found when writing*/
        }

        fclose(file);
    }

}

/*
 * validateFormat
 * IMPORTS: FILE pointer 
 * PURPOSE: checks if file formated correctly
 *          exports TRUE if file is valid otherwise FALSE.
 *          look in boolean.h to see values of boolean MACROS
 */
int validateFormat(FILE *file)
{
    char checkStr[MAX_CHARS];
    char day[MAX_CHAR_DAY];
    int hrs, mins, correctFormat, totalShows, valid;

    totalShows = 0;
    correctFormat = 0;

    if (file == NULL)
    {
        valid = FALSE;/*if FILE pointer is NULL then file not valid*/
    }
    else
    {
        while (fgets(checkStr, MAX_CHARS, file) != NULL)/*read until no more lines*/
        {

            fgets(checkStr, MAX_CHARS, file);/*skips line containing name of show
                                               no need to validate name since name 
                                               could be anything*/

            /*no need for conversion specification on sscanf since
              we want to take into account of any invalid content
              on the lines*/                                   
            if (sscanf(checkStr, "%s %d:%d", day, &hrs, &mins) == 3)/*checkStr should have the line that contains day and time*/
            {
                if ((hrs < 24 && hrs > -1) && (mins < 60 && mins > -1))/*hours must be between -1 and 24 exclusive, 
                                                                         mins must between -1 and 60 exclusive*/
                {
                    upperFirstLetter(day);/*converts day to correct capitalisation format
                                            using function from interface.h*/

                    if (checkDayInput(day) == EQUAL)/*checks if day is a valid day of the week
                                                       using function from interface.h*/
                    {
                        correctFormat = correctFormat + 1;/*if all if statements pass then increment correctFormat*/
                    }
                }
            }

            if (ferror(file))/*check if any error when read*/
            {
                printf("Error reading file\n");
            }

            totalShows = totalShows + 1;/*increments based on total show names found*/
        }

        if (correctFormat == totalShows)/*correctFormat and totalShows must match to be valid*/
        {
            valid = TRUE;
        }
        else
        {
            valid = FALSE;
        }

        rewind(file);
    }

    return valid;
}
