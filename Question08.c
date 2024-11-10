/*
Create a linked list and Traverse it.

 

Sample Input/Output
 

Input:
    17 42 16 18 39 -999
Output
    17 42 16 18 39    
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
    scanf("%d",&InputData);
    while(InputData != -999)
    {
        struct ListNode *NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        NewNode->Data = InputData;
        
        if(startPtr == 0)
        {
            startPtr = NewNode;
        }
        else{        
            NextNode = startPtr;
        
            while(NextNode->nextPtr != 0)
            {
                NextNode = NextNode->nextPtr;
            }
            NextNode->nextPtr = NewNode;
        }
        NewNode->nextPtr = 0;
        scanf("%d",&InputData);
        
    }
}

void TraverseLinkedList()
{
    struct ListNode* NextNode = startPtr;
    
    if(startPtr == 0)
    {
        printf("Underflow");
    }
    else{
        while(NextNode != 0)
        {
            printf("%d ",NextNode->Data);
            NextNode = NextNode->nextPtr;
        }
    }
}

int main()
{
    CreateLinkedList();
    TraverseLinkedList();
    
    
    return 0;
}