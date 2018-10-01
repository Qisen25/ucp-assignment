/*
 * linkedList c file 
 * AUTHOR: Kei Sum Wang, student ID: 19126089
 *
 * Part of this file comprises of externally obtained code
 *
 * *code is based off UCP Prac 6 linked List
 * however code has been modified to fulfill the assignment
 * requirement for a generic linked list*
 * file - 19126089UCP_P6.tar.gz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/*
 * function to create linked list and return it
 * */
LinkedList* createLinkedList()
{
    LinkedList *list;

    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

/*
 * insertFirst
 * IMPORTS: list
 * PURPOSE: To insert at front of list
 *          (this resembles pushing items on stack)
 *
 * "this algorithm is obtained from DSA Prac 4 Linked Lists"
 * "(accessed on 8 May 2018) file 19126089_DSA_P4.tar.gz"
 * */
void insertFirst(LinkedList *list, void *data)
{
    LinkedListNode *newNode;
    /*make sure next and prev are NULL
     * this is important when adding latest item since its next field must 
     * point to NULL otherwise we get a runtime error and may not be be able to use
     * item-> next field
     * */
    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->data = data;/*assign imported data to node data*/
   
    if (list->head == NULL)/*list is empty then assign node to head and tail*/
    {
        list->tail = newNode;
    }
    else
    {
        list->head->prev = newNode;/*assign new node previous to head*/
        newNode->next = list->head;/*head will be after new node*/
    }
    list->head = newNode;/*make sure head points new node*/

    list->length = list->length + 1;/*increment length field when inserting*/

}

/*
 * insertLast
 * IMPORTS: list
 * PURPOSE: To insert at end of list
 *          (this resemebles a queue)
 *
 * "this algorithm is obtained from DSA Prac 4 Linked Lists"
 * "(accessed on 8 May 2018) file 19126089_DSA_P4.tar.gz"
 * */
void insertLast(LinkedList *list, void *data)
{
    LinkedListNode *newNode;

    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->data = data;
   
    if (list->head == NULL)/*if list empty assign new node to head and tail*/
    {
        list->head = newNode;
    }
    else
    {
        list->tail->next = newNode;/*assign new node after tail*/
        newNode->prev = list->tail;/*assign tail to previous of new node*/
    }
    list->tail = newNode;/*make sure tail points to new node*/

    list->length = list->length + 1;/*increment length field when inserting*/
}

/*
 * insertMid
 * IMPORTS: list
 * PURPOSE: To insert at middle of list
 *
 * *function added for generic linked list requirement*
 */
void insertMid(LinkedList *list, void *data)
{
    int i, mid;
    LinkedListNode *newNode, *cur;

    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    cur = list->head;
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->data = data;
   
    if (list->head == NULL && list->length == 0)/*if list empty assign 
                                                  new node to head and tail*/
    {
        list->head = newNode;
        list->tail = newNode;
    }
    /*node exists at head and it is the only node then just add new node
      after head and link it back to head and make sure it is the tail*/
    else if (list->head != NULL && (list->length < 2 && list->length > 0))
    {
        newNode->prev = cur;/*link new node after head*/
        cur->next = newNode;/*make sure head next node is new node*/       
        list->tail = newNode;/*make sure new node is the tail of the list*/
    }
    else if(list->length > 1)
    {
        /* list length must be greater than 2
         * to get next node, it doesn't make sense
         * to get next node with only 2 nodes since
         * you will end up writing afer the tail(heads next node)
         * thus just stay at head and insert between after head
         * and before tail.
         */
        mid = list->length / 2;
        if (list->length > 2)
        {
            /*increment to half the length of list
              this will be the middle*/
            for (i = 0; i < mid; i++)
            {
                cur = cur->next; /*increment until middle node reached*/
            }
        }

        /* Algorithm obtained from coding freaks
         * "Adding a node at the middle of the list"
         * http://codingfreak.blogspot.com/2012/02/implementation-of-doubly-linked-list.html
         * (Accessed on 10 May 2018)
         */
        newNode->prev = cur; /*new node link to cur node*/
        newNode->next = cur->next;/*new node link to cur next node*/
        newNode->next->prev = newNode;/*cur next node previous node will be
                                        new node*/
        cur->next = newNode;/*make sure cur link to new node*/
    }

    list->length = list->length + 1;/*increment length field when inserting*/
}

/*
 * deleteFirst
 * IMPORTS: list
 * PURPOSE: To delete from front of list
 * EXPORTS: value (data at the node to be deleted)
 *
 * "this algorithm is obtained and based from DSA Prac 4 Linked Lists"
 * "(accessed on 8 May 2018) file 19126089_DSA_P4.tar.gz"
 * */
void* deleteFirst(LinkedList *list)
{
    LinkedListNode *currH;
    void* value;
   
    currH = list->head;

    if (list->length == 0)/*if list is empty value is null*/
    {
        value = NULL;
        printf("nothing to delete: empty list\n");
    }
    else
    {
        value = currH->data;
        if (currH->next == NULL)
        {    
            /*current tail will be NULL 
              if current head next is NULL,
              can set tail to NULL since we only care
              about the head, tail will not exist anyway if head doesn't*/
            list->tail = NULL;
        }
        else/*otherwise head previous will be assigned NULL */
        {
            currH->prev = NULL;
        }

        list->head = currH->next;/*make sure head points after current head*/

        list->length = list->length - 1;/*decrement list length field when deleting*/
    }
    free(currH);

    return value;
}

/*
 * deleteLast
 * IMPORTS: list
 * PURPOSE: To delete from end of list
 * EXPORTS: value (data at the node to be deleted)
 *
 * "this algorithm is obtained and based from DSA Prac 4 Linked Lists"
 * "(accessed on 8 May 2018) file 19126089_DSA_P4.tar.gz"
 * */
void* deleteLast(LinkedList *list)
{
    LinkedListNode *currH, *currT;
    void* value;
   
    currH = list->head;
    currT = list->tail;

    if (list->length == 0)/*if list is empty value returned will be NULL*/
    {
        value = NULL;
        printf("nothing to delete: empty list\n");
    }
    else
    {
        value = currT->data;

        if (currH->next == NULL)/*current head will be NULL if head next is NULL*/
        {
            list->head = NULL;
        }
        else/*otherwise current tail previous's next value will be NULL(destroy next link)*/
        {
            currT->prev->next = NULL;
        }

        list->tail = currT->prev;/*make sure tail now points to current tail previous*/
        list->length = list->length - 1;/*decrement list length field when deleting*/
    }
    free(currT);


    return value;
}

/*
 * deleteMid
 * IMPORTS: list
 * PURPOSE: to delete node from the middle of list
 * EXPORTS: value (data at the node to be deleted)
 *
 * * function added for generic linked list requirement*
 * */
void* deleteMid(LinkedList *list)
{
    LinkedListNode *cur;
    void* value;
    int i, mid;
   
    cur = list->head;

    if (list->length == 0)/*if list is empty value returned will be NULL*/
    {
        value = NULL;
        printf("nothing to delete: empty list\n");
    }
    else if (list->head != NULL && (list->length < 3 && list->length > 0))
    {
        value = deleteLast(list);/*just call delete last function to delete 
                                   if list has 1 or 2 nodes*/
    }
    else if(list->length > 2)
    {
        /* list length must be greater than 2
         * to get next node, it doesn't make sense
         * to get next node with only 2 nodes since
         * you will end up deleting after the tail(heads next node)
         */
        mid = list->length / 2;
        for (i = 0; i < mid; i++)
        {
            cur = cur->next; /*increment until middle node reached*/
        }

        value = cur->data;/*get nodes data*/

        /* Algorithm obtained from coding freaks
         * "Deleting Middle Node from the list"
         * http://codingfreak.blogspot.com/2012/03/implementation-of-doubly-linked-list.html
         * (Accessed on 10 May 2018)
         */
        cur->prev->next = cur->next; /*node before current point to the node after current*/
        cur->next->prev = cur->prev;/*node after current point back to node before current*/

        list->length = list->length - 1;/*decrement list length field when deleting*/
        free(cur);
        
    }

    return value;
}

/*
 * getLength
 * IMPORTS: list
 * PURPOSE: get length of list by traversing
 *          list and counting until there is
 *          no more nodes.
 * EXPORTS: length
 *
 * "this code is obtained from UCP lecture 6: Structs pg 52"
 */
int getLength(LinkedList *list)
{
    int length = 0;
    LinkedListNode *cur;

    cur = list->head;

    while (cur != NULL)/*loop until the end of list*/
    {
        length = length + 1;/*count the list until no more nodes*/
        cur = cur->next;/*get next node*/
    }

    return length;
}

/*
 * getElemement
 * IMPORTS: list, index
 * PURPOSE: traverse through list until given index
 *          is reached and export data at that current node
 * EXPORTS: value
 * */
void* getElement(LinkedList *list, int index)
{
    int i;
    int max;
    void* value;
    LinkedListNode *cur;

    max = list->length;
    cur = list->head;

    if (index >= max)/*index exceeding list length gives null value*/
    {
        value = NULL;
    }
    else
    {
        i = 0;
        while (i <= index && cur != NULL)/*loops until index is reached 
                                             and curr node not NULL retrieves value*/
        {
            i = i + 1;
            value = cur->data;
            cur = cur->next;/*get next node*/
        }
    }

    return value;
}

/*
 * peekFirst
 * IMPORTS: list 
 * PURPOSE: if list has data then export 
 *          the data at head otherwise export NULL
 * EXPORTS: value
 *
 * *function added for generic linked list requirement*
 * "this algorithm is obtained from DSA Prac 4 Linked Lists"
 * "(accessed on 8 May 2018) file 19126089_DSA_P4.tar.gz"
 */
void* peekFirst(LinkedList *list)
{
    void* value;

    if (list->length == 0)
    {
        value = NULL;
    }
    else
    {
        value = list->head->data;
    }

    return value;
}

/*
 * peekLast
 * IMPORTS: list, 
 * PURPOSE: if list has data then export 
 *          the data at tail otherwise export NULL
 * EXPORTS: value
 *
 * *function added for generic linked list requirement*
 * "this algorithm is obtained from DSA Prac 4 Linked Lists"
 * "(accessed on 8 May 2018) file 19126089_DSA_P4.tar.gz"
 */
void* peekLast(LinkedList *list)
{
    void* value;

    if (list->length == 0)
    {
        value = NULL;
    }
    else
    {
        value = list->tail->data;
    }

    return value;
}

/*
 * peekMid
 * IMPORTS: list 
 * PURPOSE: if list has data then export 
 *          the data at middle of list otherwise export NULL
 * EXPORTS: value
 *
 *  *added function for generic linked list requirement*
 *
 */
void* peekMid(LinkedList *list)
{
    int mid, i;
    void* value;
    LinkedListNode *cur;

    cur = list->head;
    
    /*if length of list is 2 or less
      then no middle node exists.
      Otherwise if 3 or more
      middle definitely exists*/
    if (list->length < 3)
    {
        value = NULL;/*data should not exist*/
    }
    else
    {
        mid = list->length / 2;/*get the middle index of length*/
        for(i = 0; i < mid; i++)
        {
            cur = cur->next;/*iterate until middle is reached*/
        }

        value = cur->data;/*value will be data found*/
    }

    return value;
}

/*
 * displayList
 * IMPORTS: list and a pointer to function,
 * PURPOSE: To traverses through the list passing each nodes
 *          data into the imported function that should handle
 *          print format and output to screen. 
 *          (Implementer must implement print func)
 *
 * *function added for generic linked list requirement*
 */
void displayList(LinkedList *list, void (*printLLPtr)(void *data))
{
    LinkedListNode *cur;

    cur = list->head;

    while (cur != NULL)/*loop until the end of list*/
    {
        printLLPtr(cur->data);/*prints data by calling imported func.
                                printLLPtr must be implemented*/ 
        cur = cur->next;/*get next node*/
    }
}

/*
 * storeIntoArray
 * IMPORTS: pointer to LinkedList, void pointer to pointer(array of pointers)
 *          and length of list, 
 * PURPOSE: store contents of list into array 
 *          looping until max list length reached while storing list elements
 *          into array by calling LinkedLists getElement function.
 *          note: Array of pointers is void for generic purposes
 *
 * *function added for storing linked list contents into array
 *  for step 4 of the UCP assignment*          
 */
void storeIntoArray(LinkedList *list, void **array, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        array[i] = getElement(list,i);/*call lists getElement function retrieving at index i
                                        and storing it at ith place of array*/
    }
}

/*
 * freeLinkedList
 * IMPORTS: list and an integer to indicate whether
 *          there is a need to free data (0 if not needed or any num if needed)
 * PURPOSE: to free linked list /and free potential data stored in list
 *
 * "this code is obtained from UCP lecture 6: Structs pg 58"
 * *modified code for generic linked list requirement*
 *
 * *added integer dataFree to act as a switch for implementer to 
 *  decide whether it is appropriate to free data.
 *  linkedList.h contains macros FREE_DATA(value 1) and DONT_FREE_DATA(value 0)
 *  
 */
void freeLinkedList(LinkedList* list, int dataFree)
{
    LinkedListNode *node, *nextNode;
    
    node = list->head;/*start at front of list*/
    while (node != NULL)
    {
        nextNode = node->next;/*get next node*/
        if (dataFree == FREE_DATA)/*if dataFree is FREE_DATA
                                    then free the data. 
                                    Otherwise don't free data*/
        {
            free(node->data);/*free malloced data*/
        }
        free(node);
        node = nextNode;/*make sure current is the next node*/
    }

    free(list);
}
