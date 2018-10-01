/*
 * comparison functions for qsort to use
 * by Kei Sum Wang, student id: 19126089
 *
 * ref1: *Sort comparison algorithms based on linux programmer's manual
 *        access by man qsort on terminal*
 *
 * ref2: *Sort comparison algorithms based on cplusplus.com, "function qsort"
 *        http://www.cplusplus.com/reference/cstdlib/qsort/
 *        (Accessed on 9 May 2018)*
 *  
 */
#include <string.h>
#include "comparison.h"
#include "data.h"

/*
 * compareTime function
 * IMPORTS: void pointers
 * PURPOSE: receives void pointers which points to data
 *          used by data structure, this specifically
 *          compares time values and exports 1, 0, -1 depending
 *          on comparison.
 *          Function is intended to be used as a parameter for qsort
 */
int compareTime(const void *x, const void *y)
{
    int check, xTotal, yTotal;

    /*cast imports into pointer to TVShow*/
    TVShow *xcopy = *(TVShow**)x;   
    TVShow *ycopy = *(TVShow**)y;

    /*convert hours to minutes and add it to corresponding minutes*/
    xTotal = (xcopy->time.hours * 60) + xcopy->time.mins;

    yTotal = (ycopy->time.hours * 60) + ycopy->time.mins;

    if (xTotal > yTotal)
    {
        check = 1; 
    }
    else if (xTotal == yTotal)
    {
        check = 0;
    }
    else /*if none of the above then xTotal is smaller*/
    {
        check = -1;
    }

    return check;
}

/*
 * compareName function
 * IMPORTS: void pointers to data
 * PURPOSE: to compare string alphabetically
 *          using standard c function strcmp.
 *          Function is intended to be used as a parameter for qsort
 */
int compareName(const void *a, const void *b)
{ 
    /*cast imports into pointer to TVShow*/
    TVShow *acopy = *(TVShow**)a;   
    TVShow *bcopy = *(TVShow**)b;
     
    return strcmp(acopy->name, bcopy->name);/*return 1,0 and -1 depending 
                                              on precedence of characters in the names*/
}
