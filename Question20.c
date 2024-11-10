/*
Write a C program for parenthesis checking using linked list implementation of stack.

Sample Input/Output I
Input
    [56 + 29 {a – b (m + n) * u} + 89]    
Output
    Parenthesis Matched.
 
Sample Input/Output II
Input
    [ p + q {m + 8 ] * c { -4 / b ) }    
Output
    Parenthesis Mismatched.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//type definition for linked list node
typedef struct listNode{
    char data;
    struct listNode* nextPtr;
}listNodeType;

listNodeType* startPtr = 0;

char pop()
{
    char retData = 0;
    if(startPtr != 0)
    {
        listNodeType* temp = startPtr;
        retData = startPtr->data;
        //printf("pop: %c\n", startPtr->data);
        startPtr = startPtr->nextPtr;
        free(temp);
        
    }
    return retData;
}

void push(char inputData)
{
    listNodeType* newNode = (listNodeType*)malloc(sizeof(listNodeType));
    newNode->data = inputData;
    //printf("push: %c\n", inputData);
    newNode->nextPtr = startPtr;
    startPtr = newNode;
}

void main()
{
    char inputString[100];
    int index = 0, flag = 0, count = 0;
    //scanf("%s",inputString);
    fgets(inputString, 100, stdin);
    
    for(index = 0; index<strlen(inputString); index++)
    {
        switch(inputString[index])
        {
            case '{':
            push('{');
            count++;
            break;
            case '}':
            if(pop()!='{')
                flag = 1;
            break;
            case '[':
            push('[');
            count++;
            break;
            case ']':
            if(pop()!='[')
                flag = 1;
            break;
            case '(':
            push('(');
            count++;
            break;
            case ')':
            if(pop()!='(')
                flag = 1;
            break;
            default:
            break;
        }
    }
    
    if(count == 0)
    {
        printf("No Parenthesis found.");
    }
    else if(flag == 0)
    {
        printf("Parenthesis Matched.");
    }
    else
    {
        printf("Parenthesis Mismatched.");
    }
}