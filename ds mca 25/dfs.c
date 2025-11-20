#include <stdio.h>
#include <stdlib.h>
struct graph
{
    int **adjmatrix;
    int num_vertex;
    int *visited;
};

struct graph *CreateGraph(int vertex)
{
    struct graph *Graph = (struct graph *)malloc(sizeof(struct graph));
    Graph->num_vertex = vertex;
    Graph->adjmatrix = (int **)malloc(vertex * sizeof(int *));
    Graph->visited = (int *)malloc(vertex * sizeof(int));
    for (int i = 0; i < vertex; i++)
    {
        Graph->adjmatrix[i] = (int *)malloc(vertex * sizeof(int));
        Graph->visited[i] = 0;
        for (int j = 0; j < vertex; j++)
        {
            Graph->adjmatrix[i][j] = 0;
        }
    }
    return Graph;
}
void addedge(struct graph *Graph, int src, int dest)
{
    Graph->adjmatrix[src][dest] = 1;
    Graph->adjmatrix[dest][src] = 1;
}

void DFS(struct graph *Graph, int src)
{
    Graph->visited[src] = 1;
    printf("%d\t", src);
    
    for (int i = 0; i < Graph->num_vertex; i++)
    {
        if (Graph->adjmatrix[i][src] == 1 && Graph->visited[i] == 0)
        {
            DFS(Graph, i);
        }
    }
}

void main()
{
    int nVertex, choice, src, dest, start;
    printf("Ente the Number of Vertex");
    scanf("%d", &nVertex);
    struct graph *Graph = CreateGraph(nVertex);
    while (1)
    {
        printf("\nEnter Choice\n1.Add Edge\n2.DFS\n3.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Start Vertex and End Vertex(adding spaces)");
            scanf("%d%d", &src, &dest);
            if(src>=Graph->num_vertex || dest>=nVertex)
            {
                printf("no such vertex");
                break;
            }
            addedge(Graph, src, dest);
            printf("Edges Added");
            break;
        case 2:
            printf("\nEnter Starting Location");
            scanf("%d", &start);
            if (start >= Graph->num_vertex)
            {
                printf("No such Vertex");
                break;
            }
            printf("\n***********Displaying DFS**********\n");
            DFS(Graph, start);
            break;

        case 3:
            printf("\n**********Exititng*********\n");
            return ;
        }
    }
}