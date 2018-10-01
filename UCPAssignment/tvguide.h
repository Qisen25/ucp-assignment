/*
 * tvguide header file
 */

#include "fileIO.h"
#include "interface.h"
#include "comparison.h"
#include "boolean.h"

void process(char *argv[]);
void filterByDay(TVShow **guide, char *day, int length, int *filterLength);
void sortGuides(TVShow **guide, char *sort, int length);
