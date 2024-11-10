/*
Write a C program to convert Infix expression to Prefix expression using linked list implementation of stacks.

Sample Input/Output I
Input

    A – (B / C + (D % E * F) / G) * H   
Output
    - A * + / B C / % D * E F G H
 
Sample Input/Output II
Input
    ( A + B * ( C - D ) ) / E   
Output
    / + A * B - C D E
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//type definition for linked list node
typedef struct listNode {
    char data;
    struct listNode* nextPtr;
}listNodeType;

listNodeType *startPtr = 0;

char prefixString[100];
//char prefixString[100];
char infixString[100];
int prefixIndex = 0;

char pop()
{
    char retData = 0;
    
    if(startPtr != 0)
    {
        listNodeType* temp = startPtr;
        retData = startPtr->data;
        startPtr = startPtr->nextPtr;
        free(temp);
    }
    return retData;
}

void addToPrefix(char addChar)
{
    prefixString[prefixIndex] = addChar;
    prefixIndex++;
    prefixString[prefixIndex] = ' ';
    prefixIndex++;
    prefixString[prefixIndex] = '\0';
}

char peek()
{
    if(startPtr != 0)
    {
        return startPtr->data;
    }
    return 0;
}

void push(char inputData)
{
    listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
    newNode->data = inputData;
    newNode->nextPtr = startPtr;
    startPtr = newNode;
}

bool compareOps(char op1, char op2)
{
    switch(op1)
    {
        case '^':
            if(op2 == '^')
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case '*':
        case '/':
        case '%':
            if((op2 == '^')||(op2 == '*')||(op2 == '/')||(op2 == '%'))
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case '+':
        case '-':
            if((op2 == '^')||(op2 == '*')||(op2 == '/')||(op2 == '%')||(op2 == '+')||(op2 == '-'))
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
            break;
    }
    return false;
}

void traverseStack()
{
    listNodeType* nextNode = startPtr;
    while(nextNode!=0)
    {
        printf("%c", nextNode->data);
        nextNode = nextNode->nextPtr;
    }
    printf("\n");
}

void revString(char* inString)
{
    int strLength = strlen(inString)-1, revIndex = 0;
    //char retString[100];
    char temp;
    //printf("1. instring; %s, %d\n", inString, strLength);
    for(revIndex = 0; revIndex <strLength/2; revIndex++)
    {
        if(inString[revIndex] == '(')
            inString[revIndex] = ')';
        else if(inString[revIndex] == ')')
            inString[revIndex] = '(';
        
    //printf("2. revString; %s,%d\n", inString,revIndex);
    
        if(inString[strLength-revIndex-1] == '(')
            inString[strLength-revIndex-1] = ')';
        else if(inString[strLength-revIndex-1] == ')')
            inString[strLength-revIndex-1] = '(';

    //printf("3. revString; %s, %d\n", inString, revIndex);
        temp = inString[revIndex];
        inString[revIndex] = inString[strLength-revIndex-1];
        inString[strLength-revIndex-1] = temp;
    }
    //printf("4. revString; %s\n", inString);
    //return inString;
}


void main()
{
    char temp = 0;
    int index = 0, prefixIndex = 0;
    fgets(infixString, 100, stdin);
    
    if(strlen(infixString) == 1)
    {
        printf("No Input detected");
        return;
    }
    
    //printf("checkpoint 1");
    
    revString(infixString);
    
    //printf("checkpoint 2");
    
    for(index = 0; index < strlen(infixString); index++)
    {
        switch(infixString[index])
        {
            case ' ':
            case 10:
                break;
            case '(':
                push(infixString[index]);
                break;
            case ')':
                while(peek()!='(')
                {
                    addToPrefix(pop());
                }
                pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(compareOps(infixString[index],peek()))
                {
                    addToPrefix(pop());
                }
                push(infixString[index]);
                break;
            default:
                addToPrefix(infixString[index]);
                break;
        }
    }
    
    while(peek() != 0)
    {
        addToPrefix(pop());
    }

    if(strlen(prefixString) == 0)
    {
        printf("Invalid input.");
        return;
    }
    else
    {
        revString(prefixString);
        printf("%s", prefixString);
    }
    
    
}