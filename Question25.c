/*
Write a C program to implement priority queue using sorted linked list. 

Insert a minimum of five elements.  Display the priority queue.

Remove two elements and display the queue.

The input format is: Data followed by Priority value

Sample Input/Output

Input

25 9 85 6 -89 2 145 4 30 2 -999

Output

-89-->2, 30-->2, 145-->4, 85-->6, 25-->9

After removing two elements: 145-->4 85-->6 25-->9

*/

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG_MODE

typedef struct listNode
{
    int data;
    int prio;
    struct listNode* nextPtr;
}listNodeType;

listNodeType* startPtr = 0;

void printQueue()
{
    listNodeType* nextNode = startPtr;
    
    while(nextNode != 0)
    {
        printf("%d-->%d",nextNode->data, nextNode->prio);
        nextNode = nextNode->nextPtr;
        
        
        if(nextNode != 0)
            printf(", ");
    }
}


int peek()
{
    return (startPtr != 0)?startPtr->data:-999;
}

int dequeue()
{
    int retValue = -999;
    listNodeType* temp = startPtr;
    
    if(startPtr != 0)
    {
        retValue = startPtr->data;
        startPtr = startPtr->nextPtr;
        free(temp);
    }
    
    return retValue;
}


void enqueue(int inData, int prio)
{
    listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
    listNodeType* nextNode = startPtr;
    
    newNode->data = inData;
    newNode->prio = prio;
    newNode->nextPtr = 0;
    
    #ifdef DEBUG_MODE
    printf("\nEnqueue: %d, %d\n", inData, prio);
    #endif
    
    if(startPtr == 0)
    {
        startPtr = newNode;
        return;
    }
    else if(startPtr->prio > newNode->prio)
    {
        newNode->nextPtr = startPtr;
        startPtr = newNode;
        return;
    }
    
    while((nextNode->nextPtr != 0)&&(newNode->prio>=nextNode->nextPtr->prio))
    {
        nextNode = nextNode->nextPtr;
    }
    
    newNode->nextPtr = nextNode->nextPtr;
    nextNode->nextPtr = newNode;
    
    #ifdef DEBUG_MODE
    printQueue();
    #endif
}

int createQueue()
{
    int count = 0,inputData, inputPrio;
    
    scanf("%d",&inputData);
    
    while(inputData != -999)
    {
        count++;
        scanf("%d", &inputPrio);
        enqueue(inputData, inputPrio);
        scanf("%d", &inputData);
    }
    
    #ifdef DEBUG_MODE
    printQueue();
    #endif
    
    return count;
}

void main()
{
    if(createQueue() < 5)
    {
        printf("Insert 5 elements");
    }
    else
    {
        printQueue();
        dequeue();
        dequeue();
        
        
        printf("\nAfter removing two elements: ");
        
        printQueue();
    }
}