#include<stdio.h>


void enqueue (int ele,int queue[],int max,int *front,int *rear)
{
    if (*rear==max-1)
    {
        printf("queue is full\n");
        
    }
    else if (*rear==-1 && *front==-1)
    {
        *rear=*front=0;
        queue[*rear]=ele;
    }
    else
    {
        (*rear)++;
        queue[*rear]=ele;
    }

}

void dequeue (int queue[],int max,int *front,int *rear)
{
    if (*front==-1 && *rear==-1)
    {
        printf("queue is empty\n");
    }
    else if (*front==*rear)
    {
        printf("%d element is dequeued \n",queue[*front]);
        *front=*rear=-1;
    }
    else
    {
        printf("%d element is dequeued \n",queue[*front]);
        (*front)++;
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
        for (int i=front; i<=rear;i++)
        {
                printf ("%d",queue[i]);
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
    int ele;
    int choice;
    int front =-1,rear=-1;
    while(1)
    {
        printf("enter 1 to enqueue \n");
        printf("enter 2 to dequeue\n");
        printf("enter 3 to display\n");
        printf("enter 4 to exit : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("enter the element to be enqueued  : ");
                        scanf("%d",&ele);
                        enqueue(ele,queue,max,&front,&rear);
                        break;
            case 2 : dequeue(queue,max,&front,&rear);
                        break;
            case 3  : display(queue,max,front,rear);
                        break;
            case 4  : return 0;
            default : printf("enter a valid choice");
            
        }

    }
    return 0;
}