/*
Write a C program to convert Infix expression to Postfix expression using linked list implementation of stacks.

Sample Input/Output I

Input
    A – (B / C + (D % E * F) / G) * H   
Output
    A B C / D E % F * G / + H * -
 
Sample Input/Output II
Input
    ( A + B * ( C - D ) ) / E   
Output
    A B C D - * + E /
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//type definition for linked list node
typedef struct listNode {
    char data;
    struct listNode* nextPtr;
} listNodeType;

listNodeType* startPtr = 0;

char postfixString[100];
int postfixIndex = 0;

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

void addToPostfix(char addChar)
{
    postfixString[postfixIndex] = addChar;
    postfixIndex++;
    postfixString[postfixIndex] = ' ';
    postfixIndex++;
    postfixString[postfixIndex] = '\0';
}

char peek()
{
    if(startPtr != 0)
    {
        return startPtr->data;
    }
    else
    {
        return 0;
    }
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
            if((op2 == '*')||(op2 == '/')||(op2 == '%')||(op2 == '^'))
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
            if((op2 == '*')||(op2 == '/')||(op2 == '%')||(op2 == '^')||(op2 == '+')||(op2 == '-'))
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
    while(nextNode != 0)
    {
        printf("%c", nextNode->data);
        nextNode = nextNode->nextPtr;
    }
    printf("\n");
}

void main()
{
    char infixString[100], temp = 0;
    
    int index = 0, postfixIndex = 0;
    fgets(infixString, 100, stdin);
    
    if(strlen(infixString) == 1)
    {
        printf("No Input detected");
        return;
    }
    
    //printf("%d\n",strlen(infixString));
    
    for(index = 0; index<strlen(infixString); index++)
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
                    addToPostfix(pop());
                }
                pop();
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while(compareOps(infixString[index],peek()))
                {
                    addToPostfix(pop());
                }
                push(infixString[index]);
                break;
            default:
                addToPostfix(infixString[index]);
                break;
        }
        
        //printf("in char: %c\n", infixString[index]);
        //printf("stack: ");
        //traverseStack();
        //printf("postfix: %s\n\n", postfixString);
    }
    

    while(peek()!=0)
    {
        addToPostfix(pop());
    }
    
    //addToPostfix('\0');
    if(strlen(postfixString) == 0)
    {
        printf("Invalid input.");
        return;
    }
    else
    {
        printf("%s",postfixString);
    }
}