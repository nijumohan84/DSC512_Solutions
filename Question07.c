/*
Read an array of ‘n’ integers from the user and do the following operations:

 

Sort the array in ascending order.
Sort the array in descending order.
 

Sample Input/Output
    Input:
    5
    17 42 16 18 39
    Output
    16 17 18 39 42
    42 39 18 17 16
 */

#include <stdio.h>
#include <stdlib.h>

void bubbleSortAscending(int* arrayPtr, int number)
{
    int i,j,k;
    for(i = 0; i < number; i++)
    {
        for(j=0; j<number-i-1;j++)
        {
            if(arrayPtr[j]>arrayPtr[j+1])
            {
                int temp = arrayPtr[j];
                arrayPtr[j] = arrayPtr[j+1];
                arrayPtr[j+1] = temp;
            }
                
            //printf("%d %d\n", i, j);
            
            /*for(k = 0; k < number; k++)
            {
                printf("%d ", arrayPtr[k]);
            }*/
            //printf("\n");
        }
    }
    
    //printf("%d %d\n", i, j);
}


void bubbleSortDescending(int* arrayPtr, int number)
{
    int i,j,k;
    for(i = 0; i < number; i++)
    {
        for(j=0; j<number-i-1;j++)
        {
            if(arrayPtr[j]<arrayPtr[j+1])
            {
                int temp = arrayPtr[j];
                arrayPtr[j] = arrayPtr[j+1];
                arrayPtr[j+1] = temp;
            }
                
            //printf("%d %d\n", i, j);
            
            /*for(k = 0; k < number; k++)
            {
                printf("%d ", arrayPtr[k]);
            }*/
            //printf("\n");
        }
    }
    
    //printf("%d %d\n", i, j);
}

int main()
{
    int number_of_elements,index;
    
    scanf("%d", &number_of_elements);
    
    int *array = malloc(number_of_elements * sizeof(int));
    
    for(index = 0; index < number_of_elements; index++)
    {
        scanf("%d", &array[index]);
    }
    
    bubbleSortAscending(array, number_of_elements);
    
    for(index = 0; index < number_of_elements; index++)
    {
        printf("%d ", array[index]);
    }
    
    printf("\n");
    
    bubbleSortDescending(array, number_of_elements);
    
    for(index = 0; index < number_of_elements; index++)
    {
        printf("%d ", array[index]);
    }
    
    return 0;
}