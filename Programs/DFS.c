#include<stdio.h>

void DFS(int);
int G[30][30],visited[30],n;    //n is no of vertices and graph is sorted in array G[10][10]

int main()
{
    int start;
    int i,j;
    //read n, the number of vertices
    printf("Enter number of vertices:");
    scanf("%d",&n);

    //read the adjecency matrix, the matrix will be of size nxn, so will be filled accordingly
    printf("\nEnter graph data in matrix form: \n");
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    //visited array of all is is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;

    printf("Enter starting index\n");
    scanf("\n%d", &start);

    DFS(start); //DFS is started from start vertex specified by user
    return 0;
}

void DFS(int i)
{
    int j;
    printf("\n%d",i); //prints source vertex
    visited[i]=1; //marks it as visited

    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1) //checks adjacent vertex if they haven't been visited and if there exists edge
            DFS(j); //recursively calls dfs for the adjacent edge.
}
