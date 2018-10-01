/*
 * file header file
 */
#include "linkedList.h"
#include "data.h"

void storeFileContent(char *fileName, LinkedList *list);
void writeToFile(char *fileName, TVShow **guide, int length);
int validateFormat(FILE *file);
