#include<stdio.h>
#include<stdlib.h>
# define max 10
int visited[max]={0};
void dfs(int n,int a[][max],int vertex)
{
  printf("%d",vertex);
  visited[vertex]=1;
   for(int i=0;i<n;i++)
   {
    if(a[vertex][i]==1 && !visited[i])
    {
      dfs(n,a,i);  
    }
   }
}
void main()
{
    int n,a[max][max]={0},i,j,vertex,edges,strt,end;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the no of edges");
    scanf("%d",&edges);
    for(i=0;i<edges;i++)
    {
      printf("enter the starting and end vertex of the edge\n");
      scanf("%d%d",&strt,&end);
      a[strt][end]=a[end][strt]=1;
    }
    printf("enter the starting vertex\n");
    scanf("%d",&vertex);
    dfs(n,a,vertex);
}
