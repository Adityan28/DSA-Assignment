#include<stdio.h>
#include<stdlib.h>
#include "doublylinkedlist.c"

int main()
{
 memArr = (int*)malloc(sizeof(int)*MEMORYSIZE);
 stackArr = (int*)malloc(sizeof(int)*STACKSIZE);

 int i, j;
 j=MEMORYSIZE-3;
 for(i=0;i<STACKSIZE;i++)
 {
  push(stackArr, j);
  j -= 3;
 }
 
 int option, listNo, key, lst;
 do
 {
  printf("1. Create a new list\n");
  printf("2. Insert a new element in a given list in sorted order\n");
  printf("3. Delete an element from a given list\n");
  printf("4. Count total elements excluding free list\n");
  printf("5. Count total elements of a list\n");
  printf("6. Display all lists\n");
  printf("7. Display free list\n");
  printf("8. Perform defragmentation\n");
  printf("9. Press 0 to exit\n");
  printf("\nSelect an option: ");
  if(scanf("%d", &option)!=1)
  {
   printf("\nOption should be between 0 and 8 only.\n");
   break;
  }
  
  printf("\nOption %d selected\n", option);
  switch(option)
  {
  
   case 0:
    printf("You just exited the menu\n");
    break;
    
   case 1:
    lst = createList();
    if(lst==-1) continue;
    printf("The sequence number of the newly created list is: %d\n", currentListHeadIndex+1);
    printf("Enter key value to be inserted in the newly created list %d:",currentListHeadIndex+1);
    if(scanf("%d", &key)!=1)
    {
     printf("\nInvalid Input\n");
     break;
    }
    insertElement(listHeadArray[currentListHeadIndex], key);
    break;
    
   case 2:
    printf("List you want to insert in: ");
    if(scanf("%d", &listNo)!=1)
    {
     printf("\nInvalid Input\n");
     break;
    }
    currentListHeadIndex=listNo-1;
    if(currentListHeadIndex<0 || currentListHeadIndex>999)
    {
     printf("Invalid list number specified.Valid numbers: 1-1000\n");
     continue; 
    }
    printf("Enter the key value: ");
    if(scanf("%d",&key)!=1)
    {
     printf("\nInvalid Input\n");
     break;
    }
    insertElement(listHeadArray[currentListHeadIndex], key);
    break;
    
   case 3:
    printf("List you want to delete from: ");
    if(scanf("%d", &listNo)!=1)
    {
     printf("\nInvalid Input\n");
     break;
    }
    currentListHeadIndex=listNo-1;
    if(currentListHeadIndex<0 || currentListHeadIndex>999)
    {
     printf("Invalid list number specified.Valid numbers: 1-1000\n");
     continue; 
    }
    printf("Enter the key value: ");
    if(scanf("%d",&key)!=1)
    {
     printf("\nInvalid Input\n");
     break;
    }
    deleteElement(listHeadArray[currentListHeadIndex], key);
    break;
    
   case 4:
    totalElements(stackArr);
    break;
    
   case 5:
    printf("Enter the list number: ");
    if(scanf("%d", &listNo)!=1)
    {
     printf("\nInvalid Input\n");
     break;
    }
    currentListHeadIndex = listNo-1;
    if(currentListHeadIndex<0 || currentListHeadIndex>999)
    {
     printf("Invalid list number specified.Valid numbers: 1-1000\n");
     continue; 
    }
    totalElementsOfAList(listHeadArray[currentListHeadIndex], listNo);
    break;
    
   case 6:
    printf("\n");
    int pInd = 0;
    while(listHeadArray[pInd]!=NULL)
    {
     printList(listHeadArray[pInd], pInd);
     pInd++;
    }
    break;
    
   case 7:
    printf("Elements of free list are:\n");
    printStack(stackArr);
    break;
    
   case 8:
    defragmentMemory();
    break;
    
   default:
    printf("You must enter an option between 0-8\n");
  }
 }while(option!=0);
 
 printf("\nMemory Array: \n");
 for(i=0;i<MEMORYSIZE;i++)
 {
  printf("%d, ", memArr[i]);
 }

}
