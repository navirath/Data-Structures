#include<stdio.h>


void bfs(int adj[][100],int start,int visited[],int max)
{
    int queue[max],front=-1,rear=-1;
    for (int i=0;i<max;i++)
    {
        visited[i]=0;
    }

    queue[++rear]=start;
    front++;
    visited[start]=1;

    while (rear>=front)
    {
        start=queue[front++];
        printf("%d ",start);
        for (int i=0;i<max;i++)
        {
            if (adj[start][i] && visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}


void dfs(int adj[][100],int visited[],int start,int max)
{
    int stack[max],top=-1;
    for (int i=0;i<max;i++)
    {
        visited[i]=0;
    }
    stack[++top]=start;
    visited[start]=1;

    while (top!=-1)
    {
        start=stack[top--];
        printf("%d ",start);
        for (int i=0;i<max;i++)
        {
            if (adj[start][i] && visited[i]==0)
            {
                stack[++top]=i;
                visited[i]=1;
                break;
            }
        }
   }
}


int main()
{
    int start;
    int max;
    printf("enter the number of vertices : ");
    scanf("%d",&max);
    int adj[100][100];
    int visited[100];
    printf("enter the starting value of the graph : ");
    scanf("%d",&start);
    printf("enter the adjacency matrix \n");
    for (int i=0;i<max;i++)
    {
        for (int j=0;j<max;j++)
        {
            printf("enter the value of %d%d ",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("bfs : ");
    bfs(adj,start,visited,max);
     
    for (int i=0;i<max;i++)
    {
        visited[i]=0;
    }
    printf("dfs : ");
    dfs(adj,visited,start,max);
    return 0;

}