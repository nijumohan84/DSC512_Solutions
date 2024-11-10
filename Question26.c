/*
Write a C program to read a binary tree from the user and perform Pre-order Traversal.

Sample Input/Output

Input

Sample Input for the binary tree given below will be

Image

A  -999

A B C -999     [Comment: A is the parent, B is the left child and C is the right child ]

B D E -999

C NULL F -999  [Comment: NULL is entered because C does not have a left child and F is the right child]

D G H -999

F I J -999

H NULL L -999

J K NULL -999

-999

Output

Pre-order Traversal: A, B, D, G, H, L, E, C, F, I, J, K,

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUGMODE

typedef struct treeNode
{
    char data;
    struct treeNode* leftLeaf;
    struct treeNode* rightLeaf;
}treeNodeType;

treeNodeType* root = NULL;

treeNodeType* createNode(char data)
{
    treeNodeType* newNode = (treeNodeType*)malloc(sizeof(treeNodeType));
    newNode->data = data;
    newNode->leftLeaf = NULL;
    newNode->rightLeaf = NULL;
    
    #ifdef DEBUGMODE
    printf("createNode: %c\n", data);
    #endif
    return newNode;
}

treeNodeType* getNode(treeNodeType* rootNode, char data)
{
    treeNodeType* foundNode;
    
    if(rootNode == NULL)
        return NULL;
    
    if(rootNode->data == data)
        return rootNode;
        
    foundNode = getNode(rootNode->leftLeaf, data);
    
    if(foundNode == (treeNodeType*)NULL)
        foundNode = getNode(rootNode->rightLeaf, data);
        
    
    #ifdef DEBUGMODE
    //printf("found node: %c\n", foundNode->data);
    #endif
    return foundNode;
}

void preOrderTraversal(treeNodeType* node)
{
    if(node == (treeNodeType*)NULL)
    {
        return;
    }
    
    printf("%c, ", node->data);
    
    preOrderTraversal(node->leftLeaf);
    preOrderTraversal(node->rightLeaf);
}



void main()
{
    char rootData[10], leftData[10], rightData[10];
    
    scanf("%s", rootData);
        #ifdef DEBUGMODE
        printf("checkpoiunt 1: %s\n", rootData);
        #endif
    while(strcmp(rootData, "-999") != 0)
    {    
        
        if(root == NULL)
        {
            root = createNode(rootData[0]);
        }
        else
        {
            scanf("%s %s", leftData, rightData);
        
            treeNodeType* rootNode = getNode(root, rootData[0]);
            
            if(strcmp(leftData, "NULL") != 0)
            {
                rootNode->leftLeaf = createNode(leftData[0]);
            }
            #ifdef DEBUGMODE
            else
                printf("left: -999");
            #endif
            
            if(strcmp(rightData, "NULL") != 0)
            {
                rootNode->rightLeaf = createNode(rightData[0]);
            }
            #ifdef DEBUGMODE
            else
                printf("right: -999");
            #endif
        }
        scanf("%s", rootData);
        #ifdef DEBUGMODE
        printf("checkpoiunt 2: %s\n", rootData);
        #endif
        
        
        scanf("%s", rootData);
        #ifdef DEBUGMODE
        printf("checkpoiunt 3: %s\n", rootData);
        #endif
    }
    
    if(root == NULL)
    {
        printf("Empty Tree");
    }
    else
    {
        printf("Pre-order Traversal: ");
        preOrderTraversal(root);
    }
    
}