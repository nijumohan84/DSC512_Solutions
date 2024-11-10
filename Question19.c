/*
Write a C program to implement stack data structure using linked lists.

Do the following operations:

PUSH a few elements into the stack. (Minimum 4 elements)
Do a PEEK operation.
Do three consecutive POP operations and display the elements.
Display the entire contents of the remaining Stack.
Sample Input/Output

Input

    42 19 32 45 42 39 45 25 36 -999

Output
   Peek: 36
   POP operations: 36 25 45
   Contents of the remaining Stack: 39 42 45 32 19 42
*/

#include <stdio.h>
#include <stdlib.h>

//type definition for linked list node
typedef struct listNode {
    int data;
    struct listNode* nextPtr;
}listNodeType;

listNodeType* startPtr = 0;

void peek()
{
    if(startPtr != 0)
        printf("Peek: %d\n", startPtr->data);
}

void pop()
{
    if(startPtr != 0)
    {
        listNodeType* temp = startPtr;
        printf("%d ", startPtr->data);
        startPtr = startPtr->nextPtr;
        free(temp);
    }
}

int createLinkedList()
{
    int inputData, count = 0;
    listNodeType* nextNode;
    scanf("%d",&inputData);
    while(inputData != -999)
    {
        listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
        newNode->data = inputData;
        newNode->nextPtr = startPtr;
        startPtr = newNode;
        count++;
        scanf("%d", &inputData);
    }
    return count;
}

void traverseLinkedList()
{
    listNodeType* nextNode = startPtr;
    while(nextNode != 0)
    {
        printf("%d ", nextNode->data);
        nextNode = nextNode->nextPtr;
    }
}

void main()
{
    if(createLinkedList()>=4)
    {
        peek();
        printf("POP operations: ");
        pop();
        pop();
        pop();
        printf("\n");
        printf("Contents of the remaining Stack: ");
        traverseLinkedList();
    }
    else
    {
        printf("Minimum 4 elements must be entered.");
    }

}