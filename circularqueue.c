#include<stdio.h>


void enqueue(int ele,int queue[],int max,int *front,int *rear)
{
    if ((*rear+1)%max==*front)
    {
        printf("queue is full\n");

    }
    else if (*front==-1 && *rear==-1)
    {
        *front=*rear=0;
        queue[*rear]=ele;
    }
    else
    {
        *rear=(*rear+1)%max;
        queue[*rear]=ele;
    }
}


void dequeue(int queue[],int max,int *front,int*rear)
{
    if (*front==-1 && *rear==-1)
    {
        printf("queue is empty\n");
    }
    else if (*front==*rear)
    {
        printf("%d element is dequed\n",queue[*front]);
         *front=*rear=-1;
    }
    else
    {
        printf("%d element is dequed\n",queue[*front]);
        *front=(*front+1)%max;

    }
}


void display(int queue[],int max,int front,int rear)
{
    if (front==-1 && rear==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue elements are  : ");
        int i= front;
        while(1)
        {
            printf("%d",queue[i]);
            if (i==rear)
            {
                break;
            }

            i=(i+1)%max;
        }
        printf("\n");
    }
}


int main()
{
    int max;
    printf("enter the maximum size of the queue : ");
    scanf("%d",&max);
    int queue[max];
    int front=-1,rear=-1;
    int choice,ele;


    while(1)
    {
        printf("enter 1 to enqueue\n");
        printf("enter 2 to dequeue\n");
        printf("enetr 3 to display\n");
        printf("enetr 4 to exit  : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1  :printf("enter the element : ");
                    scanf("%d",&ele);
                    enqueue(ele,queue,max,&front,&rear);
                    break;

            case 2 : dequeue(queue,max,&front,&rear);
                    break;

            case 3 : display(queue,max,front,rear);
                    break;

            case 4  : return 0;

            default : printf("enter a valid choice ");
        }
    }
    return 0;
}