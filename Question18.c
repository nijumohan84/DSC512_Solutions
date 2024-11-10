/*
Write a C program to read name and total marks of students in a batch.

The program must sort student names in alphabetical order. The program must also sort student list based on descending order of marks. 

You must use multi-linked lists with various links following descending ordered marks and alphabetically ordered records.

If two students have same marks display them alphabetically. If two students have the same name display the details of the student with highest marks first.

Note: Marks cannot be negative. The name of a student only consists of capital and small English alphabets.

 

Sample Input/Output
 

Input
    James
    56
    Paul
    39
    Augustine
    12
    William
    85
    Kishan
    35
    Rithi Sing
    85
    Kishan
    55
    -999    
Output
    Descending order of Marks: Rithi Sing 85, William 85, James 56, Kishan 55, Paul 39, Kishan 35, Augustine 12,
    Alphabetical Order: Augustine 12, James 56, Kishan 55, Kishan 35, Paul 39, Rithi Sing 85, William 85,
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef for multi linked list with type alias
typedef struct multiListNode{
    int marks;
    char name[20];
    struct multiListNode* nextMarksNodePtr;
    struct multiListNode* nextNameNodePtr;
}multiListNodeType;

multiListNodeType* gMarksStartNodePtr = 0;//global variable for start of the linked list based on marks
multiListNodeType* gNamesStartNodePtr = 0;//global variable for start of the linked list based on name

//function to traverse and print both paths of the multi linked list
void traverseLinkedList()
{
    multiListNodeType* nextNode = gMarksStartNodePtr;
    printf("Descending order of Marks: ");
    while(nextNode != 0)
    {
        printf("%s ",nextNode->name);
        printf("%d,",nextNode->marks);
        nextNode = nextNode->nextMarksNodePtr;
    }
    nextNode = gNamesStartNodePtr;
    printf("\nAlphabetical Order: ");
    while(nextNode != 0)
    {
        printf("%s ",nextNode->name);
        printf("%d,",nextNode->marks);
        nextNode = nextNode->nextNameNodePtr;
    }
}

//function to validate input name
int validateName(char* name)
{
    int index = 0;
    while(name[index] != '\0')
    {
        if(((name[index]<65)||(name[index]>122)||((name[index]>90)&&(name[index]<97)))&&(name[index]!=32))
        {
            //printf("exit char; %d\n",name[index]);
            return 1;//return 1 if there is a non character or space in the name
        }
        index++;
    }
    return 0;//name is valid
}

//function to input data and create multi linked list
int createLinkedList()
{
    int inputMarks, count=0;
    char inputName[100];
    //fgets(inputName,sizeof(inputName),stdin);
    scanf(" %[^\n]%*c",inputName);
    
    while(strcmp(inputName,"-999")!=0)
    {
        count++;
        multiListNodeType* newNode = (multiListNodeType*)malloc(sizeof(multiListNodeType));
        
        if(validateName(inputName) == 1)
        {
            return -3;//invalid name
        }
        
        if(scanf("%d",&inputMarks) != 1)
        {
            return -2;//non-number input for marks
        }
        if(inputMarks<0)
        {
            return -1;//negative marks input
        }
        strcpy(newNode->name,inputName);
        newNode->marks = inputMarks;
        
        if((gMarksStartNodePtr == 0)&&(gNamesStartNodePtr == 0))//this is the first node of the linked list
        {
            gNamesStartNodePtr = newNode;
            gMarksStartNodePtr = newNode;
            newNode->nextMarksNodePtr = 0;
            newNode->nextNameNodePtr = 0;
        }
        else
        {
            multiListNodeType* postNode = gMarksStartNodePtr;
            multiListNodeType* preNode = 0;
            while((postNode!=0)&&(inputMarks < postNode->marks))
            {
                preNode = postNode;
                postNode = postNode->nextMarksNodePtr;
            }//new node to be inserted between preNode and postNode
            
            if((postNode!=0)&&(inputMarks==postNode->marks))//check for equal marks
            {
                if(strcmp(inputName,postNode->name)>0)
                {
                    preNode = postNode;
                    postNode = postNode->nextMarksNodePtr;
                }
            }
            if(postNode == 0)
            {
                preNode->nextMarksNodePtr = newNode;
                newNode->nextMarksNodePtr = 0;
            }
            else if(preNode != 0)
            {
                newNode->nextMarksNodePtr = preNode->nextMarksNodePtr;
                preNode->nextMarksNodePtr = newNode;
            }
            else
            {
                newNode->nextMarksNodePtr = gMarksStartNodePtr;
                gMarksStartNodePtr = newNode;
            }
            
            postNode = gNamesStartNodePtr;
            preNode = 0;
            while(((postNode!=0)&&strcmp(inputName,postNode->name)>0))
            {
                preNode = postNode;
                postNode = postNode->nextNameNodePtr;
            }//new node to be inserted between preNode and postNode
            
            if((postNode!=0)&&(strcmp(inputName,postNode->name)==0))//check for same name
            {
                if(inputMarks<postNode->marks)
                {
                    preNode = postNode;
                    postNode = postNode->nextNameNodePtr;
                }
            }
            if(postNode == 0)
            {
                preNode->nextNameNodePtr = newNode;
                newNode->nextNameNodePtr = 0;
            }
            else if(preNode != 0)
            {
                newNode->nextNameNodePtr = preNode->nextNameNodePtr;
                preNode->nextNameNodePtr = newNode;
            }
            else
            {
                newNode->nextNameNodePtr = gNamesStartNodePtr;
                gNamesStartNodePtr = newNode;
            }
        }
        scanf(" %[^\n]%*c",inputName);
    }
    return count;
}


int main()
{
    int createResult = createLinkedList();
    if(createResult > 0)
    {
        traverseLinkedList();
    }
    else if(createResult == 0)
    {
        printf("You must enter atleast one student.");
    }
    else if(createResult == -1)
    {
        printf("Marks cannot be negative.");
    }
    else if(createResult == -2)
    {
        printf("Input Error!!! Marks Missing");
    }
    else if(createResult == -3)
    {
        printf("Input Error!!! Name of a student should only have alphabets.");
    }
}
