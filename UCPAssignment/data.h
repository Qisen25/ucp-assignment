/*
 * declares struct for TVShows
 * and other structs TVShow may need
 *
 * by Kei Sum Wang, student id: 19126089
 */

#ifndef DATA_H
#define DATA_H

#define MAX_CHAR_DAY 11
#define MAX_CHAR_TIME 6
#define MAX_CHAR_TV 100


typedef struct Time
{
    int hours;
    int mins;
}Time;

typedef struct TVShow
{
    Time time;/*struct use Time struct to contain time field*/
    char day[MAX_CHAR_DAY];
    char name[MAX_CHAR_TV];
}TVShow;

#endif
