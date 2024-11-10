/*
Write a C program to read a string from the user and check whether the string is a pangram or not.

A pangram is a sentence containing every letter in the English alphabet. If the sentence is not a pangram print the alphabets that are missing that will make the sentence a pangram.

For example, the sentence, “The quick brown fox jumps over the lazy dog” is a pangram as it contains all the characters from ‘a’ to ‘z’. The sentence “The quick brown fox jumps over the dog” is not a pangram because the characters ‘a’, ‘l’, ‘z’ and ‘y’ are missing.

 

Sample Input/Output
    Input:
    The five boxing wizards jump quickly
    Output
    Pangram
    Input:
    bcdefghijklmnopqrstuvwxz.
    Output
    Not Pangram
    a y
*/

#include<stdio.h>
#include<string.h>

int main()
{
    const char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//array of all letters for reference
    char leftOver[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//array to keep track of letters found in the sentence
    char inString[100];//input string
    int i= 0, j=0, letterCount=26;
    
    //scanf("%s", inString);
    fgets(inString, 100, stdin);
    

    //loop over each alphabet
    for(j=0; j<26; j++)
    {
        //loop over the string letter by letter
        for(i=0; i<strlen(inString);i++)
        {
            //check if the character matches the letter small or capital
            if((inString[i] == letters[j])||(inString[i] == letters[j]-32))
            {
                //mark the position and jump to the next character in the string
                leftOver[j] = 0;
                letterCount--;
                break;
            }
            
        }
    }
    
    //check if all letters were found
    if(letterCount == 0)
    {
        printf("Pangram");
    }
    else
    {
        printf("Not Pangram\n");
        for(j=0; j<26; j++)
        {
            //go over each letter and printout if not marked found
            if(leftOver[j] != 0)
            {
                printf("%c ", leftOver[j]);
            }
            
        }
        
    }
    
    return 0;
}