#include<stdio.h>
// #include<conio.h>

int adj[30][30],queue[30],visited[30],n,i,j,f=0,r=-1;
// adjacency matrix 'adj' defined
// a visited array stores whether the vertex has been visited or not
// queue array stores the corresponding sequence of verices to be taken into account
// n is no of vertices

//a recursive bfs function is defined
void bfs(int v) {
	for (i=1;i<=n;i++) //for all given n vertices
	  if(adj[v][i] && !visited[i]) //if they have an adjacent edge with source vertex and have not been visited
	   queue[++r]=i; //added into queue for further processing
	if(f<=r) { //until we reach end of the queue
		visited[queue[f]]=1; //mark each vertex selected from queue as visited
		bfs(queue[f++]); //run bfs for that vertex
	}
}
int main() {
	int v; //temporary variable for getting user choice
	// clrscr();

  //number of vertices specified
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);

  // each vertex is initialized by setting visted and queue to 0
  for (i=1;i<=n;i++) {
		queue[i]=0;
		visited[i]=0;
	}

  // graph is enterd in nxn format
	printf("\n Enter graph data in matrix form:\n");

	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&adj[i][j]);

  //starting vertex v is specified
  printf("\n Enter the starting vertex:");
	scanf("%d",&v);

  //bfs is called for the starting vertex
  bfs(v);

  //print reachable nodes after bfs is done
  printf("\n The node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(visited[i]) //if visited is true, that means the vertex was reachable
	   printf("%d\t",i); else
	   printf("\n Bfs is not possible"); //if if false, graph is disconnected and searching fails


  // getch();
	printf("\n");
  return 0;
}
