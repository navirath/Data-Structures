#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node * createNode(struct node **head, int value)
{
    struct node*newNode= (struct node*) malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}


void insertAtHead(struct node**head,int value)
{
    struct node*newNode=createNode(head,value);
    if (*head==NULL)
    {
        *head=newNode;
        return;
    }

    newNode->next=*head;
    *head=newNode;
}


void insertAtTail(struct node **head,int value)
{
    struct node * newNode=createNode(head,value);
    if (*head==NULL)
    {
        *head=newNode;
        return;
    }

    struct node *temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
}


void insertAtPosition(struct node**head,int value,int position)
{
    struct node*newNode=createNode(head,value);
    if (position<1)
    {
        printf("posiotion cannot be less than one\n");
        return;
    }

    if (position==1)
    {
        insertAtHead(head,value);
        return;
    }

    struct node*temp=*head;

    for (int i=1;i<position-1;i++)
    {
        if (temp==NULL)
        {
            printf("invalid position\n");
            return;
        }
        temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next=newNode;

}


void deleteAtHead(struct node**head)
{
    if (*head==NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    struct node*temp=*head;
    *head=(*head)->next;
    free(temp);
}

void deleteAtTail(struct node**head)
{
    if (*head==NULL)
    {
        printf("linked list is empty\n");
    }

    struct node*temp=*head;

    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }

    free(temp->next);
    temp->next=NULL;

}


void deleteAtPosition(struct node**head,int position)
{
    if (*head==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if (position==1)
    {
        deleteAtHead(head);
        return;
    }

    struct node*temp=*head;

    for (int i=1;i<position-1;i++)
    {
        if (temp==NULL || temp->next==NULL)
        {
            printf("invalid postion\n");
            return;
        }
        temp=temp->next;
    }

    struct node*nodeToDelete=temp->next;
    temp->next=nodeToDelete->next;
    free(nodeToDelete);
}


void display(struct node *head)
{
    if (head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");


}


int main()
{
    struct node*head=NULL;
    int choice,value,position;
    while(1)
    {
        printf("enter 1 insert at head\n");
        printf("enter 2 to insert at tail\n");
        printf("enter 3 to insert at a position\n");
        printf("enter 4 to delete at head\n");
        printf("enter 5 to delete at tail\n");
        printf("enter 6 to delete at position\n");
        printf("enter 7 to display \n");
        printf("enter 8 to exit : ");
        scanf("%d",&choice);

    switch(choice)
    {
        case 1 : printf("enter the element : ");
                scanf("%d",&value);
                insertAtHead(&head,value);
                break;

        case 2 : printf("enter the element : ");
                scanf("%d",&value);
                insertAtTail(&head,value);
                break;
            
        case 3 : printf("enter the element : ");
                scanf("%d",&value);
                printf("enter the position :");
                scanf("%d",&position);
                insertAtPosition(&head,value,position);
                break;

        case 4 : deleteAtHead(&head);
                break;

        case 5 : deleteAtTail(&head);
                break;
            
        case 6 : printf("enter the position  : ");
                scanf("%d",&position);
                deleteAtPosition(&head,position);
                break;
            
        case 7: display(head);
                break;

        case 8: return 0;

        default : printf("enter a valid choice\n");


    }
    }


}
 
