#include<stdio.h>
#include<stdlib.h>
#include "stackByArray.h"

void push(int *arr, int ele)
{
 if(arr==NULL)
 {
  printf("\nStack is NULL.\n");
  return;
 }
 top++;
 if(top<STACKSIZE)
 {
  arr[top] = ele;
 }
 else
 {
  printf("Stack Overflow! Capacity Exceeded.\n");
  exit(1);
 }
}

int pop(int* arr)
{
 if(arr==NULL)
 {
  printf("\nStack is NULL.\n");
  return -1;
 }
 if(top<0)
 {
  return -1;
 }
 
 int delEle = arr[top];
 top--;
 return delEle;
}

void printStack(int* arr)
{
 if(arr==NULL)
 {
  printf("\nStack is NULL.\n");
  return;
 }
 int i;
 printf("[");
 for(i=0;i<=top;i++)
 {
  printf("%d", arr[i]);
  if(i!=top)printf(", ");
 }
 printf("]\n");
}

void totalElements(int* arr)
{
 if(arr==NULL)
 {
  printf("\nStack is NULL.\n");
  return;
 }
 int totEle = 0;
 int i;
 for(i=0;i<top+1;i++)
 {
  totEle++;
 } 
 printf("\nTotal number of nodes in all lists are %d\n", STACKSIZE-totEle);
}

