/*
Write a C program to read an integer from the user and check whether it is a palindrome or not. The program should output the number and say whether it is a palindrome or not.

After printing it, can you reverse the order of digits in the number the user has just entered. E.g. 1234 should become 4321. Display the result on the screen in an easily understandable format.
 
Sample Input/Output
    Input:
    121
    Output
    Palindrome
    121

    Input
    1143
    Output
    Not Palindrome
    3411
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char inString[100],invString[100];
    int neg=0,i,compareFlag=1;
    scanf("%s",inString);
    if(inString[0]=='-')
    {
        neg=1;
        invString[0]='-';
    }
    const unsigned int strngLen = strlen(inString);
    
    for(i=neg; i<strngLen; i++)
    {
        invString[strngLen+neg-i-1] = inString[i];
    }
        
    for(i=0; i<strngLen; i++)
    {
        if(invString[i] != inString[i])
        {
            compareFlag = 0;
        }
    }
    
    invString[i] = '\0';
    
    if(compareFlag == 1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
    
    printf("%s", invString);
    
    return 0;
}