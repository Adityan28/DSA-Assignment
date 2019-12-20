#include<stdio.h>

#define MEMORYSIZE 3000
#define STACKSIZE 1000

struct doublylinkedlist
{
 int count;
 int first;
};

int* memArr;
int* stackArr;

struct doublylinkedlist* listHeadArray[STACKSIZE];
int listHeadArrayIndex=-1;
int currentListHeadIndex=-1;


void insertElement(struct doublylinkedlist* head, int ele);
void deleteElement(struct doublylinkedlist* head, int ele);
void printList(struct doublylinkedlist* head, int pInd);
void totalElementsOfAList(struct doublylinkedlist* head, int pInd);
int createNewList();
int compareWithStack(int x);
void defragmentMemory();
void shiftMemoryElements();
void leftShift(int x, int finalInd);
void regenStack();
