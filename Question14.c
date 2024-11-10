/*
Create a doubly linked list. Make sure one of the entered elements is 24.

Insert a new element after the existing linked list element 24. If there are more than one occurrence of 24, give user the choice where the new element must be inserted.

 

Sample Input/Output
 

Input
    24 19 32 45 24 39 -999
     -56
Output
    2 occurrence of 24 found. Where should the insertion occur?
Input
    1
Output
    24 -56 19 32 45 24 39
    
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
int createLinkedList()
{
    int inputData, flag = 0;
    scanf("%d",&inputData);
    while(inputData != -999)
    {
        if(inputData == 24)
        {
            flag = 1;
        }
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
    return flag;
}

//function to traverse and print linked list
void traverseLinkedList()
{
    listNodeType* nextNode = gStartPtr;
    while(nextNode != 0)
    {
        printf("%d ",nextNode->data);
        nextNode = nextNode->nextPtr;
    }
}

//function to get count of element
int searchElement(int element)
{
    int count = 0;
    listNodeType* nextNode = gStartPtr;
    while(nextNode != 0)
    {
        if(nextNode->data == element)
        {
            count++;
        }
        nextNode = nextNode->nextPtr;
    }
    return count;
}

//function to insert and element after nth instance
void insertElement(int insertIndex, int insertElement)
{
    int index = insertIndex;
    listNodeType* nextNode = gStartPtr;
    while((nextNode != 0)&&(index != 0))
    {
        if(nextNode->data == 24)
        {
            index--;
        }
        
        if(index != 0)
        {
            nextNode = nextNode->nextPtr;
        }
    }
    

    listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
    newNode->data = insertElement;
    newNode->nextPtr = nextNode->nextPtr;
    newNode->prePtr = nextNode;
    
    if(newNode->nextPtr != 0)
    {
        newNode->nextPtr->prePtr = newNode;
    }
    nextNode->nextPtr = newNode;
}

int main()
{
    int count,insertNum,insertIndex;
    if(createLinkedList() == 0)
    {
        printf("At least one element must be 24.");
        return 0;
    }
    scanf("%d",&insertNum);
    count = searchElement(24);
    switch(count)
    {
        case 0:
            printf("Error: No instance of 24 in the linked list");
            return 0;
            break;
        case 1:
            insertElement(1, insertNum);
            break;
        default:
            printf("%d occurrence of 24 found. Where should the insertion occur?",count);
            scanf("%d",&insertIndex);
            insertElement(insertIndex,insertNum);
            break;
    }
    traverseLinkedList();
}