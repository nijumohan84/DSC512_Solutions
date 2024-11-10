/*
Create a doubly linked list. Make sure one of the entered elements is 42.

Delete an element before the existing linked list element 42. If there are more than one occurrence of 42, give user the choice where the new element must be deleted.

 

Sample Input/Output 1
 

Input
    42 19 32 45 42 39 -999
Output
    2 occurrence of 42 found. Where should the deletion occur?
Input
    2
Output
    42 19 32 42 39
 
Sample Input/Output 2
 

Input
    42 19 32 45 42 39 -999
Output
    2 occurrence of 42 found. Where should the deletion occur?
Input
    1
Output
    No element before 42
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

//function to input data and create doubly linked list
int createLinkedList()
{
    int inputData, flag = 0;
    scanf("%d",&inputData);
    while(inputData != -999)
    {
        if(inputData == 42)
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

//function to delete element before index
int deleteElement(int deleteIndex)
{
    int index = deleteIndex;
    listNodeType* nextNode = gStartPtr;
    listNodeType* temp;
    while((nextNode != 0)&&(index != 0))
    {
        if(nextNode->data == 42)
        {
            index--;
        }
        
        if(index!=0)
        {
            nextNode = nextNode->nextPtr;
        }
    }
    
    if(nextNode->prePtr != 0)
    {
        temp = nextNode->prePtr;
        if(temp == gStartPtr)
        {
            gStartPtr = nextNode;
            nextNode->prePtr = 0;
        }
        else
        {
            temp->prePtr->nextPtr = nextNode;
            nextNode->prePtr = temp->prePtr;
        }
        free(temp);
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int count, deleteIndex;
    if(createLinkedList() == 0)
    {
        printf("At least one element must be 42.");
        return 0;
    }
    count = searchElement(42);
    switch(count)
    {
        case 0:
            printf("Error: No instance of 42 in the linked list");
            return 0;
            break;
        case 1:
            if(deleteElement(1)==0)
            {
                traverseLinkedList();
            }
            else
            {
                printf("No element before 42");
            }
            break;
        default:
            printf("%d occurrence of 42 found. Where should the deletion occur?", count);
            scanf("%d",&deleteIndex);
            if(deleteElement(deleteIndex)==0)
            {
                traverseLinkedList();
            }
            else
            {
                printf("No element before 42");
            }
            break;
    }
    return 0;
}
