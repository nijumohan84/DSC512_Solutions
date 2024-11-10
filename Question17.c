/*
Create a doubly linked circular list. Delete the last element in the doubly linked circular list.

 

Sample Input/Output
 

Input
    84 19 32 45 25 39 -999    
Output
    84 19 32 45 25
*/

#include <stdio.h>
#include <stdlib.h>

//typedef for doubly linked list with type alias
typedef struct listNode{
    int data;
    struct listNode* nextPtr;
    struct listNode* prePtr;
}listNodeType;

listNodeType* gStartPtr;//global variable for start of the linked list

//function to input data and create circular doubly linked list
int createLinkedList()
{
    int inputData, count = 0;
    scanf("%d", &inputData);
    while(inputData != -999)
    {
        listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
        newNode->data = inputData;
        
        if(gStartPtr == 0)
        {
            gStartPtr = newNode;
            newNode->prePtr = newNode;
            newNode->nextPtr = newNode;
        }
        else
        {
            gStartPtr->prePtr->nextPtr = newNode;
            newNode->prePtr = gStartPtr->prePtr;
            gStartPtr->prePtr = newNode;
            newNode->nextPtr = gStartPtr;
        }
        count++;
        scanf("%d",&inputData);
    }
    return count;
}

//function to traverse the linked list
void traverseLinkedList()
{
    listNodeType* nextNode = gStartPtr;
    
    if(gStartPtr == 0)
    {
        printf("Empty Linked list");
        return;
    }
    
    do
    {
        printf("%d ",nextNode->data);
        nextNode=nextNode->nextPtr;
    }while(nextNode != gStartPtr);
    
}

//function to delete last element
void deleteLastElement()
{
    listNodeType* nextNode = gStartPtr;
    listNodeType* temp;
    if(gStartPtr != 0)
    {
        if(gStartPtr->prePtr == gStartPtr)
        {
            temp = gStartPtr;
            gStartPtr = 0;
        }
        else
        {
            temp = gStartPtr->prePtr;
            gStartPtr->prePtr->prePtr->nextPtr = gStartPtr;
            gStartPtr->prePtr = gStartPtr->prePtr->prePtr;
        }
        free(temp);
    }

}

int main()
{
    if(createLinkedList() != 0)
    {
        deleteLastElement();
        traverseLinkedList();
    }
    else
    {
        printf("Underflow !!! Empty Linked list.");
    }
    
}