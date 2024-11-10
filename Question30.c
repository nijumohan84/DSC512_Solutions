/*
Write a C program to build a Binary Search Tree using the following elements: 45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81

Do In-order Traversal on the constructed Binary Search Tree.

Sample Input/Output

Input

45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81, -999

Output 

In-order Traversal of the Binary Search Tree Constructed: 10, 12, 32, 34, 39, 45, 54, 56, 67, 78, 81, 89
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct treeNode
{
    int data;
    struct treeNode* leftLeaf;
    struct treeNode* rightLeaf;
}treeNodeType;

treeNodeType* root = NULL;

treeNodeType* createNode(int data)
{
   treeNodeType* newNode = (treeNodeType*)malloc(sizeof(treeNodeType));
   newNode->data = data;
   newNode->leftLeaf = NULL;
   newNode->rightLeaf = NULL;
   
   return newNode;
}

treeNodeType* insertNode(treeNodeType* node, int data)
{
    if(node == NULL)
        return createNode(data);
        
    if(node->data == data)
        return node;
        
    if(node->data < data)
        node->rightLeaf = insertNode(node->rightLeaf, data);
    else
        node->leftLeaf = insertNode(node->leftLeaf, data);
        
    return node;
}

void inorderTraversal(treeNodeType* root)
{
    if(root != NULL)
    {
        inorderTraversal(root->leftLeaf);
        printf("%d, ", root->data);
        inorderTraversal(root->rightLeaf);
    }
}

void main()
{
    int input;
    char dummyComma;
    scanf("%d", &input);
    
    while(input != -999)
    {
        
        scanf("%c", &dummyComma);
        root = insertNode(root, input);
        
        scanf("%d", &input);
    }
    
    printf("In-order Traversal of the Binary Search Tree Constructed: ");
    inorderTraversal(root);
}