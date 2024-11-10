/*
Create a Doubly linked list and Traverse it in forward and backward direction.

 

Sample Input/Output
 

Input:
    17 42 16 18 39 -999
Output
    17 42 16 18 39 
    39 18 16 42 17   
*/

#include <stdio.h>
#include <stdlib.h>

//type for doubly linked list node with type alias
typedef struct listNode {
    int data;
    struct listNode* nextPtr;
    struct listNode* prePtr;
    
}listNodeType;

listNodeType* gStartPtr = 0;//global variable for head of the linked list

listNodeType* getLastNode()
{
    listNodeType* nextNode = gStartPtr;
    while(nextNode->nextPtr != 0)
    {
        nextNode = nextNode->nextPtr;
    }
    return nextNode;
}

//function to input data for doubly linked list
void createLinkedList()
{
    int inputData;
    scanf("%d", &inputData);
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
        scanf("%d",&inputData);
    }
}

void traverseLinkedList()
{
    listNodeType* nextNode = gStartPtr;
    if(gStartPtr!=0)
    {
        printf("%d ",nextNode->data);
        while(nextNode->nextPtr != 0)
        {
            printf("%d ",nextNode->nextPtr->data);
            nextNode = nextNode->nextPtr;
        }
        printf("\n");
        while(nextNode != 0)
        {
            printf("%d ",nextNode->data);
            nextNode = nextNode->prePtr;
        }
        
    }
    else
    {
        printf("Underflow");
    }

    
}

int main()
{
    createLinkedList();
    traverseLinkedList();
    return 0;
}