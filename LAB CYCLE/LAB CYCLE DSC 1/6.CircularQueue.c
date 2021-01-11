//iii.Implement circular queue using arrays
#include <stdio.h>
#define size 100 
void insert(int[], int);
void delete(int[]);
void display(int[]);
int front=-1;
int rear=-1;
int main()
{
    int n,ch;
    int queue[size];
    while(1)
    {
        printf("\n1. Insert/Enqueue \n2. Delete/Dequeue \n3. Display");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                insert(queue,n);
                break;
            case 2:
                delete(queue);
                break;
            case 3:
                display(queue);
                break;
        }
    }
}


void insert(int queue[], int item)
{
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("Queue Overflow");
        return;
    }
    else if(rear==-1)
    {
        rear++;
        front++;
    }
    else if (rear==size-1&&front>0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
}

void display(int queue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for(i=front; i < size; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else if(front==rear)
		{
			printf("Queue underflow");
		}
	else 
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
	
}

void delete(int queue[])
{
    if (front ==  - 1)
    {
        printf("Queue underflow ");
    }
    else if (front == rear)
    {
        printf("\nDeleted element :%d", queue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\nDeleted Element :%d", queue[front]);
        front++;
    }
}

