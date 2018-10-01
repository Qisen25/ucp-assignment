/*
 * interface code for input and outputing on screen
 * by Kei Sum Wang, student id: 19126089
 *
 * (reference:) found on function description indicates code that is based 
 *              on external code.
 *
 * file - 19126089UCP_P4.tar.gz main.c contains function
 *        converting to uppercase 
 */
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "boolean.h"

/*
 * dayInput
 * IMPORTS: imports character pointer day
 * PURPOSE: prompts user to enter a day
 *          if day is not valid then keep prompting
 *          user to until input is correct
 */
void dayInput(char *day)
{
    printf("Enter a day of the week:\n");
    scanf("%s", day);
    upperFirstLetter(day);/*makes sure day string first letter is Uppercase
                            followed the rest lowercase, day can be correct
                            but have different capitalisation, this ensures
                            day is desired format eg. mONday will be Monday
                            */

    /* using EQUAL for readability when comparing strings, its value is zero
     * can be found in boolean.h
     */
    while (checkDayInput(day) != EQUAL) /*keep asking for input until match*/
    {
        printf("Invalid day input, try again\n");
        scanf("%s", day);
        upperFirstLetter(day);/*format input to make sure it is in upperFirstLetter format
                                when using checkDayInput to match*/
    }
}

/*
 * sortInput
 * IMPORTS: imports character pointer sort
 * PURPOSE: prompts user to enter a sort
 *          if sort is not time or name then keep prompting
 *          user to until input is correct
 */
void sortInput(char *sort)
{
    printf("Sort by time or name:\n");
    scanf("%s", sort);
    convertLower(sort, 0);/*makes sure sort string input is all lower case
                            this is for convenience, right word but different
                            captilisation will be converted and accepted*/

    while (strcmp(sort, "name") != EQUAL && strcmp(sort, "time") != EQUAL)
    {
        printf("Invalid sort, try again\n");
        scanf("%s", sort);
        convertLower(sort, 0);/*format input to lowercase for comparison
                                of strings above*/
    }
}

/*
 * checkDayInput
 * IMPORTS: imports char pointer day
 * PURPOSE: checks if the import matches the days of the week
 *          then it should return 0 to indicate match
 *          otherwise integer other than 0 if not match
 */
int checkDayInput(char *day)
{
    int valid;
    valid = strcmp(day, "Monday") != EQUAL && 
            strcmp(day, "Tuesday") != EQUAL &&
            strcmp(day, "Wednesday") != EQUAL && 
            strcmp(day, "Thursday") != EQUAL &&
            strcmp(day, "Friday") != EQUAL && 
            strcmp(day, "Saturday") != EQUAL && 
            strcmp(day, "Sunday") != EQUAL;

    return valid;
}

/*
 * upperFirstLetter
 * IMPORTS: imports string 
 * PURPOSE: convert first letter to uppercase
 *          and convert following letters to lower case
 *
 * reference: this code is based off UCP prac 4 Q.6
 *            converting string to uppercase
 */
void upperFirstLetter(char* array)
{
    if (array[0] > 96 && array[0] < 123)/*checks if first letter is lowercase*/
    {
        array[0] = array[0] - 32;/*converts if is lowercase*/
    }

    convertLower(array, 1);/*convert anything to lowercase starting
                             at second character*/
}

/*
 * convertLower
 * IMPORTS: imports string and integer index 
 * PURPOSE: converts all letters to lower case
 *          starting from ith index position
 *
 * reference: this code is based off UCP prac 4 Q.6
 *            converting strings to uppercase
 */
void convertLower(char* array, int i)
{
    int k, len;

    len = strlen(array);
    for (k = i; k < len; k++)
    {
        if (array[k] < 96)/*character not lower case values
                            then convert*/
        {
            array[k] = array[k] + 32;/*add 32 to convert to lower case
                                       this is based off ASCII values*/
        }
    }
}

/*
 * display
 * IMPORTS: guide(Array), length of guide, string for sort and day 
 * PURPOSE: prints content of guide it is assumed that guide 
 *          is already sorted depending on day and sort, 
 *          thus also printing the selected indicated day and sort          
 */
void display(TVShow **guide, int length, char *sort, char *day)
{
    int i;
    
    if (length > 0)/*guide must contain atleast one show in order to print guide*/
    {
        printf("\n==== Shows on %s ====\n", day);
        printf("==== Sort by %s =========\n", sort);
        for(i = 0; i < length; i++)
        {
            /*hours and minutes should only have 2 digits,
              if it is single digit then just add zero
              at the front*/ 
            printf("%02d:%02d - %s", guide[i]->time.hours, guide[i]->time.mins, guide[i]->name);
        }
    }
    else/*if there a no shows tell user none found*/
    {
        printf("No shows found\n");
    }
}
