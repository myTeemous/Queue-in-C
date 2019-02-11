/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 10
int myQueue[CAPACITY];
int front = 0;
int rear = -1;
int count = 0;

bool isEmpty();
bool isFull();
int getCurrentCount();
void insertNum(int num);
int removeNum();


int main()
{
    int choice = 0, number = 0, input = 0;
    
    do
    {
        printf("1 - Insert\n\n2 - Remove\n\n3 - Check if the queue is empty\n\n");
        printf("4 - Check if queue is full\n\n5 - Check how many numbers are in the queue\n\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &input);
                insertNum(input);
                printf("\n\n");
                break;
            case 2:
                number = removeNum();
                if(number == -1)
                {
                    break;
                }
                else
                {
                    printf("%d", number);
                    printf(" has been removed from the queue\n\n");
                    break;
                }
            case 3:
                if(isEmpty())
                {
                    printf("\n\nThe queue is empty\n\n");
                }
                else if(!isEmpty())
                {
                    printf("\n\nThe queue is not empty\n\n");
                }
                break;
            case 4:
                if(isFull())
                {
                    printf("\n\nThe queue is full\n\n");
                }
                else if(!isFull())
                {
                    printf("\n\nThe queue is not full\n\n");
                }
                break;
            case 5:
                number = getCurrentCount();
                printf("\n\nThere are ");
                printf("%d", number);
                printf(" in the queue\n\n");
                break;
            case -1:
                printf("\n\nNow exiting\n\n");
                break;
            default:
                printf("\n\nInvalid choice\n\n");
        }
        
    }while(choice != -1);

    return 0;
}

void insertNum(int num)
{
    if(isFull())
    {
        printf("queue is full");
        return;
    }
    
    if(rear == CAPACITY - 1)
    {
        rear = -1;
    }
    
    ++rear;
    myQueue[rear] = num;
    ++count;
}

int removeNum()
{
    if(isEmpty())
    {
        printf("queue is empty");
        return -1;
    }
    
    int num = myQueue[front];
    ++front;
    
    if(front == CAPACITY)
    {
        front = 0;
    }
    
    --count;
    return num;
}

bool isFull()
{
    return count == CAPACITY;
}

bool isEmpty()
{
    return count == 0;
}

int getCurrentCount()
{
    return count;
}