/*
 * Unit test for linked list
 *
 * by Kei Sum Wang, student id: 19126089
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void printFormat(void* data);
void testFirstOps(LinkedList *list);
void testLastOps(LinkedList *list);
void testMidOps(LinkedList *list);
void testFMLOps(LinkedList *list);

int main()
{
    LinkedList *list = createLinkedList();

    printf("====TEST HARNESS FOR DOUBLE ENDED DOUBLY LINKED LINKEDLIST=======\n");

    printf("\n====Test creation of LINKEDLIST=======\n");
    if (list->head == NULL && list->tail == NULL && list->length == 0)
    {
        printf("list creation success\n");
    }
    else
    {
        printf("creation of list failed\n");
    }

    printf("\n==========TESTING FIRST OPERATIONS=============\n");
    testFirstOps(list);
    printf("\n==========TESTING LAST OPERATIONS=============\n");
    testLastOps(list);
    printf("\n==========TESTING MIDDLE OPERATIONS=============\n");
    testMidOps(list);
    printf("\n==========TESTING FIRST MIDDLE LAST OPERATIONS=============\n");
    testFMLOps(list);
    
    freeLinkedList(list, FREE_DATA);

    return 0;
}

void testFirstOps(LinkedList *list)
{
    int a = 3, b = 2, c = 1;
    int *p1, *p2, *p3, *top, *mid, *end;

    printf("\n====insertFirst. values %d, %d, %d\n", a, b, c);
    insertFirst(list, &a);
    insertFirst(list, &b);
    insertFirst(list, &c);

    printf("===check first and last values and length with lists peekFirst(), peekMid(), peekLast() and length field===\n");
    top = peekFirst(list);
    mid = peekMid(list);
    end = peekLast(list);

    printf("peekFirst %d\n", *top);
    printf("peekMid %d\n", *mid);
    printf("peekLast %d\n", *end);
    printf("insert length %d\n", list->length);

    printf("===display expected order: values %d, %d, %d ===\n", c, b, a);
    displayList(list, &printFormat);

    printf("====deleteFirst. expected order of delete 1, 2, 3\n");
    p1 = deleteFirst(list);
    printf("delete %d\n", *p1);
    p2 = deleteFirst(list);
    printf("delete %d\n", *p2);
    p3 = deleteFirst(list);
    printf("delete %d\n", *p3);
    printf("%d was last deletion next delete will indicate nothing to delete\n", *p3);
    deleteFirst(list);
    
    printf("delete length %d\n", list->length);
}

void testLastOps(LinkedList *list)
{
    int d = 4, e = 5, f = 6;
    int *p1, *p2, *p3, *top, *mid, *end;

    printf("\n====insertLast. values %d, %d, %d\n", d, e, f);
    insertLast(list, &d);
    insertLast(list, &e);
    insertLast(list, &f);

    printf("===check first and last values and length with lists peekFirst(), peekMid(), peekLast() and length field===\n");
    top = peekFirst(list);
    mid = peekMid(list);
    end = peekLast(list);


    printf("peekFirst %d\n", *top);
    printf("peekMid %d\n", *mid);
    printf("peekLast %d\n", *end);
    printf("insert length %d\n", list->length);

    printf("===display expected order: values %d, %d, %d ===\n", d, e, f);
    displayList(list, &printFormat);
    
    printf("====deleteLast. expected order of delete 6, 5, 4\n");
    p1 = deleteLast(list);
    printf("delete %d\n", *p1);
    p2 = deleteLast(list);
    printf("delete %d\n", *p2);
    p3 = deleteLast(list);
    printf("delete %d\n", *p3);
    printf("%d was last deletion next delete will indicate nothing to delete\n", *p3);
    deleteLast(list);

    printf("delete length %d\n", list->length);
}

void testMidOps(LinkedList *list)
{
    int m = 7, n = 10, o = 9, a = 3;
    int *p1, *p2, *p3, *p4, *top, *mid, *end;

    printf("\n===insert Middle: values %d, %d, %d, %d ===\n", m, n, o, a);
    insertMid(list, &m);
    insertMid(list, &n);
    insertMid(list, &o);
    insertMid(list, &a);


    printf("===check first and last values and length with lists peekFirst(), peekMid(), peekLast() and length field===\n");
    top = peekFirst(list);
    mid = peekMid(list);
    end = peekLast(list);

    printf("peekFirst %d\n", *top);
    printf("peekMid %d\n", *mid);
    printf("peekLast %d\n", *end);
    printf("insert length %d\n", list->length);

    printf("===display expected order: values %d, %d, %d, %d ===\n", m, o, a, n);
    displayList(list, &printFormat);

    printf("===deleting Middle expected order of delete 3, 9, 10, 7\n");
    p1 = deleteMid(list);
    printf("delete %d\n", *p1);
    p2 = deleteMid(list);
    printf("delete %d\n", *p2);
    p3 = deleteMid(list);
    printf("delete %d\n", *p3);
    p4 = deleteMid(list);
    printf("delete %d\n", *p4);
    printf("%d was last deletion next delete will indicate nothing to delete\n", *p4);
    deleteMid(list);

    printf("delete length %d\n", list->length);
}

void testFMLOps(LinkedList *list)
{
    int m = 100, n = 10, o = -9, s = 3, q = 1111, r = 0;
    int *p1, *p2, *p3, *p4, *p5, *p6, *top, *mid, *end;

    printf("\n===insert Middle: values %d, %d, %d, %d, %d, %d ===\n", m, n, o, s, q, r);
    printf("Insert First %d\n", m);
    insertFirst(list, &m);
    printf("Insert Last %d\n", n);
    insertLast(list, &n);
    printf("Insert Mid %d\n", o);
    insertMid(list, &o);
    printf("Insert First %d\n", s);
    insertFirst(list, &s);
    printf("Insert Last %d\n", q);
    insertLast(list, &q);
    printf("Insert Mid %d\n", r);
    insertMid(list, &r);


    printf("===check first and last values and length with lists peekFirst(), peekMid(), peekLast() and length field===\n");
    top = peekFirst(list);
    mid = peekMid(list);
    end = peekLast(list);

    printf("peekFirst %d\n", *top);
    printf("peekMid %d\n", *mid);
    printf("peekLast %d\n", *end);
    printf("insert length %d\n", list->length);

    printf("===display expected order: values %d, %d, %d, %d, %d, %d ===\n", s, m, o, r, n, q);
    displayList(list, &printFormat);

    printf("===deleting in First Last Mid order expected order of delete 3, 1111, 0, 100, 10, -9 \n");
    p1 = deleteFirst(list);
    printf("delete First %d\n", *p1);
    p2 = deleteLast(list);
    printf("delete Last  %d\n", *p2);
    p3 = deleteMid(list);
    printf("delete Mid %d\n", *p3);
    p4 = deleteFirst(list);
    printf("delete First %d\n", *p4);
    p5 = deleteLast(list);
    printf("delete Last %d\n", *p5);
    p6 = deleteMid(list);
    printf("delete Mid %d\n", *p6);
    printf("%d was last deletion next delete will indicate nothing to delete\n", *p6);
    deleteMid(list);

    printf("delete length %d\n", list->length);
}

/*print function for linkedlist displayList method*/
void printFormat(void* data)
{
    int *num;

    num = (int*)data;

    printf("%d\n", *num);
}
