#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char answer[MAX];
char stack[MAX];
int top=-1;

int isFull()
{
  return top==MAX-1;
}

int isEmpty()
{
  return top==-1;
}


void push(char c)
{
  if(isFull())
  {
    printf("Stack is full\n");
    return ;
  }

  stack[++top]=c;
}

char pop()
{
  if(isEmpty())
  {
    printf("Stack is empty\n");
    return 0;
  }
    return stack[top--];
}


int priority(char c)
{
  if (c=='^')
  {
    return 3;
  }
  if (c=='*' || c=='/')
  {
    return 2;
  }
  if (c=='+' || c=='-')
  {
    return 1;
  }
  return 0;
}


void infixToPostfix(char infix[MAX])
{
  int k=0;
  for (int i=0;i<strlen(infix);i++)
  {
    if (isalnum(infix[i]))
    {
      answer[k++]=infix[i];
    }

    else if (infix[i]=='(')
    {
      push(infix[i]);
    }

    else if (infix[i]==')')
    {
      while (!isEmpty() && stack[top]!='(')
      {
        answer[k++]=pop();
      }
      pop();
    }
    else
    {
      while (!isEmpty() && priority(infix[i])<=priority(stack[top]))
      {
        answer[k++]=pop();
      }
    push(infix[i]);
    }
  

}
  while (!isEmpty())
  {
    answer[k++]=pop();
  }
  answer[k]='\0';

}

int main()
{
  char infix[MAX];
  printf("enter the infix expression : ");
  scanf("%s",infix);
  infixToPostfix(infix);
  printf("postfix expression : %s",answer);
  return 0;
}