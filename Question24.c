/*
Write C program for array implementation of circular queue with maximum size of six.

Remove three elements from the circular queue and display the queue. Display the value of FRONT and REAR.

Add two elements into the circular queue and display the queue. Display the value of FRONT and REAR.

Sample Input/Output

Input

42 77 88 9 3 66 -999

Output

Circular Queue: 9 3 66

FRONT = 3, REAR = 5

Contents of the remaining queue: 9 3 66

Input

-89 -63

Output

9 3 66 -89 -63

FRONT = 3, REAR = 1
*/

#include <stdio.h>
#include <stdbool.h>

#define QUEUE_SIZE 6

int cirQueue[QUEUE_SIZE];
int head = -1, rear = -1;

int getNextIndex(int index)
{
    return (index + 1) % QUEUE_SIZE;
}

bool checkFull()
{
    return getNextIndex(rear) == head;

}

bool checkEmpty()
{
    return (rear == -1);
}

//int dequeue();

void printQueue()
{
    int i = head;
    
    while(i!=rear)
    {
        printf("%d ",cirQueue[i]);
        
        i = getNextIndex(i);
    }
    printf("%d\n",cirQueue[i]);
    
    
}

void enqueue(int inputData)
{
    if(checkFull())
    {
        printf("Full");
        return;
    }
    
    if(head == -1)
    {    
        head = 0;
    }
    
    rear = getNextIndex(rear);
    cirQueue[rear] = inputData;
    
    //printf("\nEnqueue:\n");
    //printQueue();
}

int dequeue()
{

    if(checkEmpty())
    {
        printf("QUEUE Empty");
    }
    
    
    int retVal = cirQueue[head]; 
    
    if(head == rear)
    {
        head = -1;
        rear = -1;
    }
    else
    {
        head = getNextIndex(head);
    }
    
    return retVal;
}

int createQueue()
{
    int count = 0, inputData;
    
    scanf("%d",&inputData);
    
    while(inputData != -999)
    {
        count++;
        if(count>6)
        {
            return count;
        }
        enqueue(inputData);
        scanf("%d",&inputData);
    }
    return count;
}

void main()
{
    int i = 0, inputData, count;
    
    count = createQueue();
    if(count < 3)
    {
        printf("Empty Queue. Three elements should be deleted.");
        return;
    }
    else if(count > 6)
    {
        printf("Out of bound");
        return;
    }
    
     
    for(i = 0; i<3; i++)
    {
        dequeue();
    }   
    
    printf("Circular Queue: ");
    printQueue();
    
    printf("FRONT = %d, REAR = %d\n", head, rear);

        
    printf("Contents of the remaining queue: ");
    printQueue();
    
    for(i = 0; i<2; i++)
    {
        scanf("%d",&inputData);
        enqueue(inputData);
    }
    printQueue();
    
    printf("\nFRONT = %d, REAR = %d\n", head, rear);

    
}