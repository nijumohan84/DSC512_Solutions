/*
Create a singly linked list and Delete an element before a particular element. If there are more than one similar elements in the linked list, delete the element before the last occurrence.

 

Sample Input/Output
 

Input:
    17 42 16 18 39 -999
    16
Output
    17 16 18 39    
    
*/

#include <stdio.h>
#include <stdlib.h>

//type for linked list node with type alias
typedef struct ListNode {
  int data;
  struct ListNode* nextPtr;
}ListNodeType;

//type for element search to delete
typedef enum
{
    ELEMENT_FOUND,
    OUT_OF_BOUND,
    ELEMENT_NOT_FOUND
}DelElReturnType;

ListNodeType* gStartPtr = 0;//global variable for head of the linked list

//function to get the last node of the linked list
ListNodeType* getLastNode()
{
    ListNodeType* nextNode = gStartPtr;
    while(nextNode->nextPtr != 0)
    {
        nextNode =  nextNode->nextPtr;
    }
    return nextNode;
}

//function to input data and create doubly linked list
void createLinkedList()
{
    int inputData;
    scanf("%d", &inputData);
    while(inputData != -999)
    {
        ListNodeType *NewNode = (ListNodeType*)malloc(sizeof(ListNodeType));
        NewNode->data = inputData;
        
        if(gStartPtr == 0)
        {
            gStartPtr = NewNode;
        }
        else
        {
            ListNodeType* LastNode;
            LastNode = getLastNode();
            LastNode->nextPtr = NewNode;
            NewNode->nextPtr = 0;
        }
        scanf("%d",&inputData);
    }
}

//function to traverse and print linked list
void traverseLinkedList()
{
    ListNodeType* nextNode = gStartPtr;
    while(nextNode != 0)
    {
        printf("%d ",nextNode->data);
        nextNode =  nextNode->nextPtr;
    }
    printf("\n");
}

//function to intake element and delete the node before that
int deleteBeforeNode()
{
    ListNodeType* temp;
    ListNodeType* nextNode = gStartPtr;
    int beforeElement;
    ListNodeType* foundPreNode = 0;
    scanf("%d",&beforeElement);
    
    if(nextNode != 0)
    {
        if(nextNode->data == beforeElement)
        {
            return OUT_OF_BOUND;
        }
        while(nextNode->nextPtr != 0)
        {
            if(nextNode->nextPtr->data == beforeElement)
            {
                foundPreNode = nextNode;
            }
            nextNode = nextNode->nextPtr;
        }
    }
    
    nextNode = gStartPtr;
    
    if(foundPreNode == 0)
    {
        return ELEMENT_NOT_FOUND;
    }
    else
    {
        if(foundPreNode == gStartPtr)
        {
            temp = gStartPtr;
            gStartPtr = foundPreNode->nextPtr;
        }
        else
        {
            while(nextNode->nextPtr != foundPreNode)
            {
                nextNode = nextNode->nextPtr;
            }
            temp = nextNode->nextPtr;
            nextNode->nextPtr = nextNode->nextPtr->nextPtr;
        }
        free(temp);
        return ELEMENT_FOUND;
    }
}

int main()
{
    createLinkedList();
    switch(deleteBeforeNode())
    {
        case ELEMENT_FOUND:
            traverseLinkedList();
            break;
        case ELEMENT_NOT_FOUND:
            printf("Not Found");
            break;
        case OUT_OF_BOUND:
            printf("Out of bound");
            break;
    }
    return 0;
}