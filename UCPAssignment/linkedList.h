/*
 * header file for linkedList
 * AUTHOR: Kei Sum Wang, student id: 19126089
 */

#define DONT_FREE_DATA 0
#define FREE_DATA 1

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    void *data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
}LinkedListNode;

typedef struct
{
    LinkedListNode *head;
    LinkedListNode *tail;
    int length;/*track length of list*/
}LinkedList;

LinkedList* createLinkedList();
void insertFirst(LinkedList* list, void *data);
void insertLast(LinkedList *list, void *data);
void insertMid(LinkedList *list, void *data);
void* deleteFirst(LinkedList *list);
void* deleteLast(LinkedList *list);
void* deleteMid(LinkedList *list);
int getLength(LinkedList *list);
void* getElement(LinkedList *list, int index);
void* peekFirst(LinkedList *list);
void* peekLast(LinkedList *list);
void* peekMid(LinkedList *list);
void displayList(LinkedList *list, void (*printLLPtr)(void *data));
void storeIntoArray(LinkedList *list, void **array, int length);
void freeLinkedList(LinkedList* list, int dataFree);

#endif
