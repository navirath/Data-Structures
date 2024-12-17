#include<stdio.h>
#include<stdbool.h>
#include <string.h>


bool valid(char s[])
{
  int n=strlen(s);
  char stack[n];
  int top=-1;
  int i=0;
  while (i<n)
  {
    char c =s[i];
    if (c=='('  || c=='[' || c=='{')
    {
      stack[++top]=c;
    }
    else
    {
      if (top==-1)
      {
        return false;
      }

      char topchar=stack[top--];
        if ( (c==')' && topchar!='(')  ||
             (c==']' && topchar!='[')  ||
             (c=='}'   &&  topchar!='{')  )
             {
              return false;
             }
      
    }
    i++;
  }
    return top==-1;
}


int main()
{
  int max=100;
  char s[max];
  printf("enter the paranthesis : ");
  scanf("%s",s);

  if(valid(s))
  {
      printf("its a valid parantehsis\n");
  }
  else
  {
    printf("not a valid paranthesis\n");
  }
  return 0;
}