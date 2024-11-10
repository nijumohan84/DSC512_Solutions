/*
Create a doubly linked circular list. 

Delete the 3rd element in the doubly linked circular list. Display the elements of the resulting linked list in reverse order.

 

Sample Input/Output
 

Input
    84 19 32 45 25 39 -999    
Output
    39 25 45 19 84
*/

#include <stdio.h>
#include <stdlib.h>

//typedef for doubly linked list with type alias
typedef struct listNode{
    int data;
    struct listNode* nextPtr;
    struct listNode* prePtr;
}listNodeType;

listNodeType* gStartPtr;//global var for start of the linked list

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

//function to traverse linked list in reverse
void revTraverseLinkedList()
{
    listNodeType* nextNode = gStartPtr;
    
    if(gStartPtr == 0)
    {
        return;
    }
    
    do
    {
        nextNode=nextNode->prePtr;
        printf("%d ",nextNode->data);
    }while(nextNode != gStartPtr);
    
    //printf("%d ",nextNode->data);
}

//function to delete the third element
int delete3rdElement()
{
    int index = 0;
    listNodeType* nextNode = gStartPtr;
    do
    {
        index++;
        if(index == 3)
        {
            nextNode->prePtr->nextPtr = nextNode->nextPtr;
            nextNode->nextPtr->prePtr = nextNode->prePtr;
            free(nextNode);
            return 1;
        }
        nextNode=nextNode->nextPtr;
    }while(nextNode != gStartPtr);
    if(index<3)
    {
        printf("Underflow !!! Minimum 3 elements must be entered.");
        return 0;
    }
}

int main()
{
    if(createLinkedList()>=3)
    {    
        if(delete3rdElement())
        {
            revTraverseLinkedList();
        }
    }
    else
    {
        printf("Underflow !!! Minimum 3 elements must be entered.");
    }

    return 0;
}