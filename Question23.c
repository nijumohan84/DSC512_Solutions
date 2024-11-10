/*
Write a C program to implement Queue data structure using linked lists.

Do the following operations:

Insert few elements into the queue. (Minimum 4 elements)
Display the element at the front of the queue (Do not remove it from the Queue).
Remove and display three elements from the Queue.
Display the entire contents of the remaining Queue.
Sample Input/Output

Input

42 77 88 9 3 66 -999

Output

Element at the front of the queue: 42

Remove and display three elements: 42 77 88

Contents of the remaining queue: 9 3 66

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int data;
    struct listNode* nextPtr;
}listNodeType;

listNodeType* startPtr = 0;


void enqueue(int inData)
{
    listNodeType* nextNode = startPtr;
    listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
    
    newNode->nextPtr = 0;
    newNode->data = inData;
    
    if(nextNode == 0)
    {
        startPtr = newNode;
        return;
    }
    
    while(nextNode->nextPtr != 0)
    {
        nextNode = nextNode->nextPtr;
    }
    
    nextNode->nextPtr = newNode;
}

int dequeue()
{
    int retData = -999;
    listNodeType* temp = startPtr;
    if(startPtr != 0)
    {
        retData = startPtr->data;
        startPtr = startPtr->nextPtr;
        free(temp);  
    }

    return retData;
}

int peek()
{
    int retData = -999;
    if(startPtr != 0)
    {
        retData = startPtr->data;
    }

    return retData;
}


int createQueue()
{
    int count = 0;
    int inputData;
    listNodeType* nextNode;
    
    scanf("%d",&inputData);
    
    while(inputData != -999)
    {
        count++;
        enqueue(inputData); 
        scanf("%d", &inputData);
    }
    return count;
}


void main()
{
    int index;
    if(createQueue()>=4)
    {
        printf("Element at the front of the queue: %d\n", peek());
        
        printf("Remove and display three elements: ");
        for(index = 0; index<3; index++)
        {
            printf("%d ", dequeue());
        }
        printf("\n");
        
        printf("Contents of the remaining queue: ");
        while(peek() != -999)
        {
            printf("%d ", dequeue());
        }        
    }
    else
    {
        printf("Minimum 4 elements must be entered.");
    }

}