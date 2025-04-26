#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int vertex;
    struct node* link;
}node;

typedef struct Graph{
    int nvertices;
    int* visited;
    struct node** adj_list;
}Graph;

node* createNode(int vertex){
    node* newNode=malloc(sizeof(node));
    newNode->vertex=vertex;
    newNode->link=NULL;
    return newNode;
}

Graph* createGraph(int nvertices){
    Graph* graph=malloc(sizeof(Graph));
    graph->nvertices=nvertices;
    graph->adj_list=(node**)(malloc(sizeof(node*)*nvertices));
    graph->visited=malloc(sizeof(int)*nvertices);
    for(int i=0;i<nvertices;i++){
        graph->adj_list[i]=NULL;
        graph->visited[i]=0;
    }
return graph;
}

void DFS(Graph* graph,int vertex){
    node* temp =graph->adj_list[vertex];
    graph->visited[vertex]=1;
    printf("\n Adjacency list of vertex %d\n",vertex);
   while(temp){ 
    int adj=temp->vertex;
    if(graph->visited[adj]==0){
        DFS(graph,adj);
        }
    temp=temp->link;
    }
}

void addEdge(Graph* graph,int src,int des){
    node* newNode=createNode(src);
    newNode->link=graph->adj_list[des];
    graph->adj_list[des]=newNode;
    // undir graph
     newNode=createNode(des);
    newNode->link=graph->adj_list[src];
    graph->adj_list[src]=newNode;
}

void printGraph(Graph* graph){
    for(int v=0;v<graph->nvertices;v++){ 
        node* temp=graph->adj_list[v];
        while(temp){
        printf("%d",temp->vertex);
        temp=temp->link;
        }
        printf("\n");
    }
}

int main() {
  struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
   DFS( graph, 2);
  return 0;
}


