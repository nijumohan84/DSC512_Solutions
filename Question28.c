/*
Write a C program to read a binary tree from the user and perform Post-order Traversal.

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

Post-order Traversal: G, L, H, D, E, B, I, K, J, F, C, A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}

void postOrderTraversal(treeNodeType* node)
{
    if(node == (treeNodeType*)NULL)
    {
        return;
    }
    
    
    postOrderTraversal(node->leftLeaf);
    postOrderTraversal(node->rightLeaf);
    printf("%c, ", node->data);
}

void main()
{
    char rootData[10], leftData[10], rightData[10];
    
    scanf("%s", rootData);
    
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
            
            if(strcmp(rightData, "NULL") != 0)
            {
                rootNode->rightLeaf = createNode(rightData[0]);
            }
        }
        
        scanf("%s", rootData);
        scanf("%s", rootData);
    }
    
    if(root == NULL)
        printf("Empty Tree");
    else
    {
        printf("Post-order Traversal: ");
        postOrderTraversal(root);
    }
}