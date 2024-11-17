/*
Write a C program to build a Binary Search Tree using the following elements (read in the given order from left to right): 45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81

Do In-order Traversal on the constructed Binary Search Tree.

Sample Input/Output

Input

45, 39, 56, 12, 34, 78, 32, 10, 89, 54, 67, 81, -999

Output 

In-order Traversal of the Binary Search Tree Constructed: 10, 12, 32, 34, 39, 45, 54, 56, 67, 78, 81, 89
*/

/*
Test case 8 has a comma missing after the last entered element
*/
#include <stdio.h>
#include <stdlib.h>

//type for a node in the binary search tree
typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNodeType;

//pointer to root
treeNodeType* root = NULL;

//function to create new node with entered data
treeNodeType* createNode(int data)
{
    treeNodeType* newNode = (treeNodeType*)malloc(sizeof(treeNodeType));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//function to insert a node at the correct location in the tree
treeNodeType* insertNode(treeNodeType* root, int data)
{
    //check if tree is not yet initialized
    if(root == NULL)
    {
        return createNode(data);
    }
    
    //if new data is less than current root, insert on the left branch
    if(data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data)//if new data is greater than current root, insert on the right branch
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

//function to perform inorder traversal
void inorderTraversal(treeNodeType* root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d, ", root->data);
        inorderTraversal(root->right);
    }
}

void main()
{
    int data;
    char buffer;
    
    scanf("%d", &data);
    //scan elements until -999 is encountered
    while(data != -999)
    {
        root = insertNode(root, data);
        scanf("%c",&buffer);//to catch the comma and space
        scanf("%d",&data);
    }
    printf("In-order Traversal of the Binary Search Tree Constructed: ");
    inorderTraversal(root);//print tree
}