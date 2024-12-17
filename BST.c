#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int data;
    struct node*left;
    struct node*right;
};


struct node*createNode(int value)
{
    struct node*newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node *insertNode(struct node*root,int value)
{   
    struct node*newNode=createNode(value);

    if(root==NULL)
    {
        return createNode(value);
    }
    if (value<root->data)
    {
        root->left=insertNode(root->left,value);
    }
    if (value>root->data)
    {
        root->right=insertNode(root->right,value);
    }
    return root;
}


void preorder(struct node*root)
{
    if (root!=NULL)
    {printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(struct node*root)
{
    if (root!=NULL)
    {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
}

void postorder(struct node*root)
{
    if (root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
    }
}

int main()
{
    struct node*root=NULL;
    root=insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,80);

    printf("preorder : \n");
    preorder(root);
    printf("\n");

    printf("Inorder : \n");
    inorder(root);
    printf("\n");


    printf("postoder : \n");
    postorder(root);
    printf("\n");

    return 0;


}
