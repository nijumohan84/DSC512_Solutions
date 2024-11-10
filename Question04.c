/*
Write a C program to generate prime numbers which has two equidistant prime numbers from it within a given range.

For example, 5 is one such number because we have two prime numbers 3 and 7 both of which are equidistant from 5. The distance in this case would be 2.

Can you generate all such numbers in ascending order within a given range along with their corresponding two prime numbers and distance?

 

Sample Input/Output
    Input:
    2 10
    Output
    3 5 7 2

    Input
    10 30
    Output
    11 17 23 6                                                                                                                                                     
    17 23 29 6
    */

#include<stdio.h>
#include<stdbool.h>

//function to check if a number is prime
bool checkPrime(int number)
{
    for(int i = 2; i<number; i++)
    {
        if((number%i)==0)
        {
            //input number is divisible by i
            return false;
        }
    }
    //input number not divisible by any other number, hence prime
    return true;
}

int main()
{
    int lowerBound, upperBound, i, j;
    
    //input lower and upper bounds
    scanf("%d %d",&lowerBound, &upperBound);
    
    //check if the bounds are valid and limit the range
    lowerBound = lowerBound<2?2:lowerBound;
    upperBound = upperBound<2?2:upperBound;
    
    //loop over each number in the range
    for(i = lowerBound; i <=upperBound; i++)
    {
        if(checkPrime(i))
        {
            //if the number is prime, check for other prime numbers in the range
            for(j=i+1; j+j-i<=upperBound; j++)
            {
                //if a prime is found check if the equidistant number is prime as well 
                if(checkPrime(j)&&checkPrime(j+(j-i)))
                {
                    //print the result
                    printf("%d %d %d %d\n", i, j, j+j-i, j-i);
                }
            }
        }
    }
    
    return 0;
}