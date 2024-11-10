/*
Create a doubly linked list. 

Add 3 elements at the beginning of the linked list. Display the elements of the resulting doubly linked list in reverse order.

 

Sample Input/Output
 

Input
    84 19 32 45 25 39 -999
    -5 -12 -68
Output
    39 25 45 32 19 84 -5 -12 -68
*/

#include <stdio.h>
#include <stdlib.h>

//type for doubly linked list node with type alias
typedef struct listNode {
    int data;
    struct listNode* nextPtr;
    struct listNode* prePtr;
}listNodeType;

listNodeType* gStartPtr = 0; //global variable for head of the linked list

//function to get the last node of the linked list
listNodeType* getLastNode()
{
    listNodeType* nextNode = gStartPtr;
    while(nextNode->nextPtr != 0)
    {
        nextNode = nextNode->nextPtr;
    }
    return nextNode;
}

//function to input data and create doubly linked list
void createLinkedList()
{
    int inputData;
    scanf("%d",&inputData);
    while(inputData != -999)
    {
        listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
        newNode->data = inputData;
        
        if(gStartPtr == 0)
        {
            gStartPtr = newNode;
            newNode->prePtr = 0;
        }
        else
        {
            listNodeType* lastNode;
            lastNode = getLastNode();
            newNode->prePtr = lastNode;
            lastNode->nextPtr = newNode;
            newNode->nextPtr = 0;
        }
        scanf("%d", &inputData);
    }
}

//function to traverse and print the linked list in reverse
void revTravrseLinkedList()
{
    listNodeType* preNode = getLastNode();
    while(preNode != 0)
    {
        printf("%d ",preNode->data);
        preNode = preNode->prePtr;
    }
    //printf("\n");
}

//function to insert 3 elements in the beginning
void insertElements(int* inputData)
{
    int i;
    listNodeType* lastNewNode=0;
    
    for(i=0; i<3; i++)
    {
        listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
        newNode->data = inputData[i];
        newNode->nextPtr = gStartPtr;
        newNode->prePtr = 0;
        //printf("checkpoint");
        if(gStartPtr!=0)
        {
            gStartPtr->prePtr=newNode;
        }
        gStartPtr = newNode;
    }
}

int main()
{
    int inputData[3];
    createLinkedList();
    if(scanf("%d %d %d",inputData, inputData+1,inputData+2) == 3)
    {
        insertElements(inputData);
        revTravrseLinkedList();
    }
    else
    {
        printf("Error!! Three elements must be inserted.");
    }
}