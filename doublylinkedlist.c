#include<stdio.h>
#include<stdlib.h>
#include "doublylinkedlist.h"
#include "stackByArray.c"

void insertElement(struct doublylinkedlist* head, int ele)
{
  if(head==NULL)
  {
   printf("Head is NULL.\n");
   return;
  }
  if(head->count==0)
  {
   head->first = pop(stackArr);
   if(head->first==-1)
   {
    printf("\nFAILURE: MEMORY NOT AVAILABLE\n");
    return;
   }

   memArr[head->first] = ele;
   memArr[head->first+1] = -1;
   memArr[head->first+2] = -1;
   head->count++;
  }
  else
  {
   int j = pop(stackArr);
   if(j==-1)
   {
    printf("\nFAILURE: MEMORY NOT AVAILABLE\n");
    return;
   }
  
   memArr[j] = ele;
   int temp = head->first;
   while(temp!=-1)
   {
    if(ele<=memArr[temp])break;
    if(memArr[temp+1]==-1)break;
    temp = memArr[temp+1];
   }
   if(memArr[temp+1]==-1)
   {

    if(temp==head->first)
    {
     if(ele<=memArr[temp])
     {
      memArr[j+1] = temp;
      memArr[j+2] = -1;
      memArr[head->first+2] = j;
      head->first = j;
     }
     else
     {
      memArr[j+1]=-1;
      memArr[j+2]=temp;
      memArr[temp+1] = j;
     }
    }
    else
    {
     if(ele<=memArr[temp])
     {
      memArr[j+1] = temp;
      memArr[j+2] = memArr[temp+2];
      memArr[temp+2] = j;
      memArr[memArr[j+2]+1] = j;
     }
     else
     {
      memArr[j+1]=-1;
      memArr[j+2]=temp;
      memArr[temp+1] = j;
     }
    }
   }
   else
   {
    memArr[j+1] = temp;
    memArr[j+2] = memArr[temp+2];
    memArr[temp+2] = j;
    if(memArr[j+2]==-1)
    {
        memArr[head->first+2] = j;
        head->first = j;

    }
    else
    {
        memArr[memArr[j+2]+1] = j;
    }
   }

   head->count++;
  }
  printf("\nSUCCESS\n");
}

void deleteElement(struct doublylinkedlist* head, int ele)
{
 if(head==NULL)
  {
   printf("Head is NULL.\n");
   return;
  }
  if(head->count==0)
  {
   printf("\nFAILURE: LIST EMPTY\n");
   return;
  }
  int temp = head->first;
  while(temp!=-1)
  {
   if(memArr[temp]==ele)break;
   temp = memArr[temp+1];
  }
  if(temp==-1)
   {
    printf("\nFAILURE: ELEMENT NOT THERE\n");
    return;
   }
  push(stackArr, temp);
  if(memArr[temp+2]==-1)
  {
   head->first=memArr[temp+1];
   if(head->first==-1)
   {
    memArr[temp]=0;
    memArr[temp+1]=0;
    memArr[temp+2]=0;
   }
   else
   {
    memArr[head->first+2]=-1;
    memArr[temp]=0;
    memArr[temp+1]=0;
    memArr[temp+2]=0;
   }
   head->count--;
   printf("\nSUCCESS\n");
   return;
  }
  memArr[memArr[temp+2] + 1] = memArr[temp+1];
  if(memArr[temp+1]==-1)
  {
   printf("\nSUCCESS\n");
   memArr[temp]=0;
   memArr[temp+1]=0;
   memArr[temp+2]=0;
   return;
  }
  memArr[memArr[temp+1] + 2] = memArr[temp+2];
  memArr[temp]=0;
  memArr[temp+1]=0;
  memArr[temp+2]=0;
  head->count--;
  printf("\nSUCCESS\n");
}

void printList(struct doublylinkedlist* head, int pInd)
{
 int temp = head->first;
 if(temp==-1)
 {
  printf("Doubly linkedlist is Empty!\n");
  return;
 }
 printf("Elements of list-%d are:\n", pInd+1);
 printf("key   next   prev\n");
 while(temp!=-1)
 {
  if(memArr[temp+1]==-1 && memArr[temp+2]==-1)
  {
   printf("%d    NIL    NIL\n", memArr[temp]); 
  }
  else if(memArr[temp+1]==-1)
  {
   printf("%d    NIL    %d\n", memArr[temp],memArr[temp+2]);
  }
  else if(memArr[temp+2]==-1)
  {
   printf("%d    %d    NIL\n", memArr[temp],memArr[temp+1]);
  }
  else
  {
   printf("%d    %d    %d\n", memArr[temp],memArr[temp+1],memArr[temp+2]);
  }
  if(memArr[temp+1]==-1)
  {
   return;
  }
  temp = memArr[temp+1];
 }
 printf("\n");
}

void totalElementsOfAList(struct doublylinkedlist* head, int pInd)
{
 if(head==NULL)
 {
  printf("Head is NULL.\n");
  return;
 }
 int temp = head->first;
 int noOfEle=0;
 while(temp!=-1)
 {
  temp = memArr[temp+1];
  noOfEle++;
 }
 printf("\nTotal Number of nodes in list %d are %d\n", pInd, noOfEle);
}

int createList()
{
 listHeadArrayIndex++;
 if(listHeadArrayIndex>=STACKSIZE)
 {
  printf("\nFAILURE: MEMORY NOT AVAILABLE TO CREATE MORE LISTS\n");
  return -1;
 }
 listHeadArray[listHeadArrayIndex] = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
 currentListHeadIndex=listHeadArrayIndex;
 listHeadArray[listHeadArrayIndex]->count=0;
 listHeadArray[listHeadArrayIndex]->first=-1;
 return 0;
}

int compareWithStack(int x)
{
 int f;
 int count=0;
 for(f=0;f<=top;f++)
 {
  if(x>stackArr[f])
   count++;
 }
 count *= 3;
 return count;
}

void leftShift(int x, int finalInd)
{
 int h;
 for(h=x;h<finalInd;h++)
 {
  memArr[h-3] = memArr[h];
 }
}

void shiftMemoryElements()
{
 int si, mi, check,track,tid, safety,endflag;
 mi=0;
 endflag=0;
 int memInd=MEMORYSIZE;
 for(si=0;si<=top;si++)
 {
  check=0;
  track=0;
  safety=mi;
  while(mi<memInd)
  {
   while(memArr[mi]==0 && memArr[mi+1]==0 && memArr[mi+2]==0)
   {
    leftShift(mi+3,memInd);
    safety += 3;
    if(safety>=MEMORYSIZE)
    {
     endflag=1;
     break;
    } 
   }
   if(endflag==1)break;
   mi += 3;
   if(check==1)break;
  }
  if(endflag==1)break;
  for(tid=1;tid<=track;tid++)
   memArr[memInd-tid]=0;
  memInd -= track;
 }
}

void regenStack()
{
 int totEle=top+1;
 int z=0;
 for(z=0;z<totEle;z++)
 {
  pop(stackArr);
 }
 z = (STACKSIZE-totEle)*3;
 while(z<MEMORYSIZE)
 {
  push(stackArr,z);
  z+=3;
 }
}

int nextNo, prevNo;
void defragmentMemory()
{
 if(top>=STACKSIZE)
 {
  printf("Memory is empty.");
  return;
 }
 int r=0;
 while(r<MEMORYSIZE)
 {
  if(memArr[r]!=0 || memArr[r+1]!=0 || memArr[r+2]!=0)
  {
   nextNo = compareWithStack(memArr[r+1]);
   memArr[r+1] -= nextNo;
   
   prevNo = compareWithStack(memArr[r+2]);
   memArr[r+2] -= prevNo;
   
   if(memArr[r+2]==-1)
   {
    int y=0;
    while(listHeadArray[y]!=NULL)
    {
     if(listHeadArray[y]->first==r)
     {
      int htemp = compareWithStack(r);
      listHeadArray[y]->first=r-htemp;
      break;
     }
     y++;
    }
   }
  }
  r += 3;
 }
 shiftMemoryElements();
 regenStack();
 printf("\nSUCCESS\n");
 printf("\nMemory Array: \n");
 int maI;
 for(maI=0;maI<MEMORYSIZE;maI++)
 {
  printf("%d, ", memArr[maI]);
 }
 printf("\n");
}

