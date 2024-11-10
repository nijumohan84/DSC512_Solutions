/*
Create a doubly linked list. 

Delete 3 elements from the end of the linked list. Display the elements of the resulting doubly linked list in reverse order.

 

Sample Input/Output
 

Input
    84 19 32 45 25 39 -999    
Output
    32 19 84
*/

#include <stdio.h>
#include <stdlib.h>

//type for doubly linked list node with type aliad
typedef struct listNode {
    int data;
    struct listNode* nextPtr;
    struct listNode* prePtr;
}listNodeType;

listNodeType* gStartPtr = 0; //global variable for head of the linked list

//function to to get the last node of the linked list
listNodeType* getLastNode()
{
    listNodeType* nextNode = gStartPtr;
    if(gStartPtr == 0)
    {
        return 0;
    }
    while(nextNode->nextPtr != 0)
    {
        nextNode = nextNode->nextPtr;
    }
    return nextNode;
}

//function to input data and reate double linked list
int createLinkedList()
{
    int inputData,count = 0;
    scanf("%d",&inputData);
        //printf("checkpoint");
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
        count++;
    }
    return count;
}

//function to traverse and print the linked list in reverse
void revTraverseLinkedList()
{
    listNodeType* preNode = getLastNode();
    
    //printf("Last Node: %d\n", (int)preNode);
    
    if(preNode == 0)
    {
        printf("NULL");
        return;
    }
    while(preNode != 0)
    {
        printf("%d ",preNode->data);
        preNode = preNode->prePtr;
    }
}

//function to delete 3 elements at the end
int deleteElements()
{
    int i=0;
    listNodeType* preNode = getLastNode();
    listNodeType* tempPtr;
    
    while((preNode!=0)&&(i<3))
    {
        i++;
        tempPtr = preNode;
        if(preNode->prePtr!=0)
        {
            preNode->prePtr->nextPtr = 0;
        }
        else
        {
            gStartPtr = 0;
        }
        preNode = preNode->prePtr;
        free(tempPtr);
    }
    return i;
}

int main()
{
    if(createLinkedList()>=3)
    {
        if(deleteElements()==3)
        {
            revTraverseLinkedList();
        }
        else
        {
            printf("Error");
        }
    }
    else
    {
        printf("Error!! Underflow, Minimum 3 elements are required.");
    }

}