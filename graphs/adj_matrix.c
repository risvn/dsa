#include<stdio.h>
#include<stdlib.h>

typedef struct {

    int vertices;
    int** adj_matrix;
} Graph ;

//Dynamically allocating 2d-array
Graph* create_graph(int vertices){
    Graph* graph=malloc(sizeof(Graph));
    graph->vertices=vertices;
    graph->adj_matrix=(int**)malloc(sizeof(int*)*vertices);
    for(int i=0;i<vertices;i++) {
        graph->adj_matrix[i]=malloc(sizeof(int)*vertices);
    }
    return graph ;
}

void addEdge(Graph* graph,int src,int des){
    if (src>graph->vertices||des>graph->vertices){
        printf("invalid vertices\n");
        return;
    }
    //adding weights/edges(un-directional graphs)
    graph->adj_matrix[src][des]=1;
    graph->adj_matrix[des][src]=1;
}

void print_graph(Graph* graph){
    for(int i=0;i<graph->vertices;i++){ 
        for(int j=0;j<graph->vertices;j++){
        printf("%d",graph->adj_matrix[i][j]);
        }
printf("\n");
    }
        }


// Function to free the allocated memory for the graph
void freeGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

int main()
{
    int vertices = 5;

    // Create a graph
    Graph* graph = create_graph(vertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display the adjacency matrix
   print_graph(graph);

    // Free the allocated memory
    freeGraph(graph);

    return 0;
}
