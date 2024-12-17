#include<stdio.h>
#include<stdlib.h>

void push (int ele, int max, int stack[],int *top)
{
    
    
    if (*top==max-1)
    {
        printf("stack is full\n");
        return;
    }
    stack[++(*top)]=ele;
}

void pop (int stack[],int *top)
{
    if (*top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("%d element is popped\n",stack[*top]);

    (*top)--;
}

void display (int max,int stack[],int top)
{
    if (top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("elements in the stack are : ");
    for (int i=top;i>=0;i--)
    {
        printf("%d",stack[i]);
        printf("\n");
    }
}

int main()
{
    int max;
    printf("enter the maximum size of the stack : ");
    scanf("%d",&max);
    int stack[max];
    int top=-1;
    int choice;
    int ele;
    while(1)
    {
        printf("enter 1 for push\n");
        printf("enter 2 for pop the element\n");
        printf("enter 3 for display the stack elements\n");
        printf("enter 4 to exit : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 : printf("enter the element to pushed : ");
                      scanf("%d",&ele);
                      push (ele,max,stack,&top);
                      break;

            case 2  : pop(stack,&top);
                        break;

            case 3 : display(max,stack,top);
                        break;
            case 4 : return 0;

            default : printf ("enter a valid choice\n");  
        }

    }
    return 0;
}