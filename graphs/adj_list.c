#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 20

typedef struct node{
    int vertex;
    struct node* link;
}node;

typedef struct Graph{
    int nvertices;
    int* visited;
    struct node** adj_list;
}Graph;

typedef struct {
    int items[size];
    int front;
    int rear;
} queue;

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

queue* createQueue(){
    queue* q=malloc(sizeof(queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

bool IsEmpty(queue* q){
    return(q->front==-1 && q->rear==-1);
}

void enque(queue* q,int v){

    if(q->rear==size-1){
        printf("queue is full\n");
    }
    else {
        if(q->front==-1)q->front=0;
        q->rear++;
        q->items[q->rear]=v;
        } 
}

int deque(queue* q) { //write care fully deque fuction keeping edge-cases in mind
  int item;
  if (IsEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}


void BFS(Graph* graph,int vertex){
    queue* q = createQueue();
    enque(q,vertex);
        graph->visited[vertex]=1;
    while(!IsEmpty(q)){
        int currentVertex=deque(q);
        printf("Visited %d\n",currentVertex);
        node* temp=graph->adj_list[currentVertex];
        while(temp){
            int adj_vertex=temp->vertex;
            if(graph->visited[adj_vertex]==0){
                enque(q,adj_vertex);
                graph->visited[adj_vertex]=1;
            }
            temp=temp->link;
        }
    }
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
struct Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  BFS(graph, 0);
  return 0;
}


