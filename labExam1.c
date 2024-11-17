/*
Write a C program to create a Queue using linked list with a capacity of 4 elements. Read 4 elements from the user [4 elements must be read into the queue].

If the fifth element has to be inserted, remove the element at the Front and insert the new element at the Rear of the Queue.

Negative numbers are not allowed in the queue.

Print the Final Queue.

Sample Input/Output I

Input:

12 44 91 82 -999
83 -999

Output:

Queue elements:44 91 82 83

Sample Input/Output II
Input:

20 40 90 80 -999
30 60 -999

Output:

Queue elements:90 80 30 60

Sample Input/Output III
Input:

21 41 -999
36 -999

Output:

Minimum 4 elements needed in queue

Sample Input/Output IV
Input:

28 46 -44 78 -999
32 -999

Output:

Negative elements are not allowed in queue
*/

/* Test case 6 has only 3 elements entered in the original queue*/
#include <stdio.h>
#include <stdlib.h>

//data type for queue node
typedef struct queueNode
{
    int data;
    struct queueNode* next;
}queueNodeType;

//data type for queue
typedef struct queue
{
    struct queueNode* front;
    struct queueNode* rear;
    int size;
}queueType;

//pointer to queue
queueType* queuePtr = NULL;

//function to create queue node
queueNodeType* createNode(int data)
{
    queueNodeType* newNode = (queueNodeType*)malloc(sizeof(queueNodeType));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to create empty queue
void createQueue()
{
    queuePtr = (queueType*)malloc(sizeof(queueType));
    queuePtr->front = NULL;
    queuePtr->rear = NULL;
}

//function to enqueue an element
void enqueue(int data)
{
    queueNodeType* newNode = createNode(data);
    
    //check if queue is already full
    if(queuePtr->size == 4)
    {
        queueNodeType* temp = queuePtr->front;
        queuePtr->front = queuePtr->front->next;//move front to the second element
        free(temp);//dequeue the front element
        queuePtr->size--;
    }
    
    //check if queue is initialized
    if(queuePtr->rear == NULL)
    {
        queuePtr->front = queuePtr->rear = newNode;//point both front and rear to the first element
    }
    else
    {
        queuePtr->rear->next = newNode;//point current rear to the new element
        queuePtr->rear = newNode;//set the new element as rear
    }
    queuePtr->size++;//increase queue size
}

void printQueue()
{
    queueNodeType* currentNode = queuePtr->front;
    printf("Queue elements:");
    
    //loop over queue elements
    while(currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}


void main()
{
    int input, count = 0;
    createQueue();
    
    //scan inputs until -999 is encountered
    scanf("%d", &input);
    while(input != -999)
    {
        if(input<0)//check for negative elements
        {
            printf("Negative elements are not allowed in queue");
            return;
        }
        
        enqueue(input);
        count++;
        scanf("%d", &input);//scan the next elemeent
    }
    
    if(count<4)//check if at least 4 elements are entered
    {
        printf("Minimum 4 elements needed in queue");
        return;
    }
    
    //scan inputs until -999 is encountered
    scanf("%d", &input);
    while(input != -999)
    {
        if(input<0)//check for negative elements
        {
            printf("Negative elements are not allowed in queue");
            return;
        }
        
        enqueue(input);
        scanf("%d", &input);//scan the next element
    }
    
    //print queue
    printQueue();
}