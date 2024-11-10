/*
Read an array of ‘n’ integers from the user and do the following operations:

 

Delete an element from the array.
 

Sample Input/Output
 

Input:
    5
    17 42 16 18 39
    3
Output
  17 42 18 39
  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number_of_elements, index, delIndex;
    scanf("%d", &number_of_elements);
    int *array = malloc(number_of_elements * sizeof(int));
    
    for(index = 0; index < number_of_elements; index++)
    {
        scanf("%d", &array[index]);
    }
    
    scanf("%d",&delIndex);
    
    if((delIndex > number_of_elements)||(delIndex < 1))
    {
        printf("Out of bound");
        return 0;
    }
    
    for(index = delIndex - 1; index < number_of_elements; index++)
    {
        array[index] = array[index+1];
    }
    
    array = realloc(array, (number_of_elements -1) * sizeof(int));
    
    for(index = 0; index < number_of_elements-1; index++)
    {
        printf("%d ", array[index]);
    }
    
}