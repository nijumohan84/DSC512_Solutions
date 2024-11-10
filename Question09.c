/*
Create a linked list and Insert an element after a particular element. If there are more than one similar elements in the linked list, add the element after the first occurrence.

 

Sample Input/Output
 

Input:
    17 42 16 18 39 -999
    16 87
Output
    17 42 16 87 18 39
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int Data;
    struct ListNode* nextPtr;
};

struct ListNode* startPtr = 0;

void CreateLinkedList()
{
    int InputData;
    struct ListNode* NextNode;
    scanf("%d", &InputData);
    while(InputData != -999)
    {
        struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        NewNode->Data = InputData;
        
        if(startPtr == 0)
        {
            startPtr = NewNode;
        }
        else
        {
            NextNode = startPtr;
            
            while(NextNode->nextPtr != 0)
            {
                NextNode = NextNode->nextPtr;
            }
            NextNode->nextPtr = NewNode;
        }
        NewNode->nextPtr = 0;
        scanf("%d", &InputData);
    }
}

void TraverseLinkedList()
{
    struct ListNode* NextNode = startPtr;
    while(NextNode != 0)
    {
        printf("%d ", NextNode->Data);
        NextNode = NextNode->nextPtr;
    }
}

void InsertAfterElement()
{
    struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* NextNode = startPtr;
    int newElement,afterElement;
    scanf("%d %d",&afterElement,&newElement);
    while(NextNode->Data != afterElement)
    {
        NextNode = NextNode->nextPtr;
        if(NextNode==0)
            break;
    }
    
    if(NextNode == 0)
    {
        printf("Not Found");
    }
    else
    {
        NewNode->nextPtr=NextNode->nextPtr;
        NewNode->Data=newElement;
        NextNode->nextPtr = NewNode;
        
        
        TraverseLinkedList();
    }
    
}

int main()
{
    CreateLinkedList();
    InsertAfterElement();
}