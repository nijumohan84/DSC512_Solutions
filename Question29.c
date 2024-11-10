/*
Write C program to find the Huffman encoding for a given String.

Note: Result will be evaluated manually for this question.

Sample Input/Output

Input

sseasoseoeaieiestseossieiaeiuiaieeiaeueaiuiasaeieauasisess

Output [Note: Huffman Code must be displayed in alphabetical order to match with the test cases]

a = 111

e = 10

i = 00

o = 11001

s = 01

t = 11000

u = 1101
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG_MODE

char inputString[100];

typedef struct treeNode
{
    char data;
    struct treeNode* leftLeaf;
    struct treeNode* rightLeaf;
    int freq;
}treeNodeType;

typedef struct huffcodeList
{
    char alphabet;
    int freq;
    char code[10];
}huffListType;

huffListType alphabets[27];

treeNodeType* root = NULL;

treeNodeType* createNode(char data, int freq)
{
    treeNodeType* newNode = (treeNodeType*)malloc(sizeof(treeNodeType));
    newNode->data = data;
    newNode->freq = freq;
    newNode->leftLeaf = NULL;
    newNode->rightLeaf = NULL;
}

void swapAlphabets(huffListType* a, huffListType* b)
{
    huffListType temp;
    
    temp.alphabet = a->alphabet;
    temp.freq = a->freq;
    
    a->alphabet = b->alphabet;
    a->freq = b->freq;
    
    b->alphabet = temp.alphabet;
    b->freq = temp.freq;
    
}

int insertChar(char inChar)
{
    int i, flag = 0;
    static int count = 0;
    for(i=0; i<26; i++)
    {
        if(alphabets[i].alphabet == inChar)
        {
            alphabets[i].freq++;
            i=26;
            flag = 1;
        }
    }
    
    if(flag == 0)
    {
        alphabets[count].alphabet = inChar;
        //alphabets[i].alphabet = inChar;
        alphabets[count].freq = 1;
        count++;
    }
    
#ifdef DEBUG_MODE
    for(i=0; i<count; i++)
    {
        printf("char: %c, freq: %d\n", alphabets[i].alphabet, alphabets[i].freq );
    }
    
    printf("\n" );
#endif

    return count;
}

void sortFreq(int count)
{
    int i,j;
    
#ifdef DEBUG_MODE
    printf("Count: %d\n", count );
#endif
    
    for(i=0; i<count-1; i++)
    {
        for(j=0; j<count-i-1; j++)
        {
            if(alphabets[j].freq>alphabets[j+1].freq)
            {
                swapAlphabets(alphabets+j,alphabets+j+1);
            }
        }
    }
}

void printList(int count)
{
    int i;
    printf("Char List:\n" );
    for(i=0; i<count; i++)
    {
        printf("char: %c, freq: %d\n", alphabets[i].alphabet, alphabets[i].freq );
    }
}

void sortAlphabetical()
{
    
}

void inorderTraversal(treeNodeType* node)
{
    if(node == (treeNodeType*)NULL)
    {
        return;
    }
    
    inorderTraversal(node->leftLeaf);
    printf("%c", node->data);
    inorderTraversal(node->rightLeaf);
}

void main()
{
    int i, charCount;
    scanf("%s", inputString);
    //alphabets[0].alphabet = 0;
    
    for(i=0; inputString[i]!='\0'; i++)
    {
        charCount = insertChar(inputString[i]);
    }
    
    sortFreq(charCount);
    printList(charCount);
    
}