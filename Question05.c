/*
Read an array of ‘n’ integers from the user and do the following operations:

 

Search for a specific element in the array.
 

Sample Input/Output
 

Input:
    5
    17 42 16 18 39
    18
Output
    Element Found  at position 4
*/

#include <stdio.h>
#include <stdlib.h>

int variableArray(int number)
{
    int index = 0, searchNumber, count = 0;
    int *array = malloc(number * sizeof(int));
    int *indexArray = malloc(number * sizeof(int));
    
    for(index = 0; index < number; index ++)
    {
        scanf("%d", &array[index]);
    }
    
    scanf("%d", &searchNumber);
    
    count = 0;
    for(index = 0; index < number; index++)
    {
        if(array[index] == searchNumber)
        {
            //printf("Element Found at position %d, count=%d\n", index + 1, count);
            indexArray[count] = index +1;
            count ++;
            //return 0;
        }
    }
    switch(count)
    {
        case 0:
            printf("Element not Found");
            break;
        case 1:
            printf("Element Found at position %d", indexArray[0]);
            break;
        default:
            printf("Element Found at positions ");
            for(index = 0; index <count; index++)
            {
                printf("%d", indexArray[index]);
                if(index < count -1)
                {
                    printf(",");
                }
            }
    }
    
    
    //printf("Element not Found");
    
    
}

int main()
{
    int number_of_elements;
    scanf("%d", &number_of_elements);
    variableArray(number_of_elements);
    return 0;
}