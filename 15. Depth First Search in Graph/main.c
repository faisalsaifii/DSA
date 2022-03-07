#include <stdio.h>
#include <stdlib.h>
struct node {
int vertex;
struct node* next;
};
struct Graph {
int numVertices;
int* visited;
struct node** adjLists;
};
struct node* createNode(int v);
void DFS(struct Graph* graph, int vertex) {
struct node* adjList = graph->adjLists[vertex];
struct node* temp = adjList;
graph->visited[vertex] = 1;
printf("Visited %d \n", vertex);
while (temp != NULL)
{
int connectedVertex = temp->vertex;
if (graph->visited[connectedVertex] == 0)
DFS(graph, connectedVertex);
temp = temp->next;
}
}
struct node* createNode(int v) {
struct node* newNode = malloc(sizeof(struct node));
newNode->vertex = v;
newNode->next = NULL;
return newNode;
}
struct Graph* createGraph(int vertices) {
struct Graph* graph = malloc(sizeof(struct Graph));
graph->numVertices = vertices;
graph->adjLists = malloc(vertices * sizeof(struct node*));
graph->visited = malloc(vertices * sizeof(int));
for (int i = 0; i < vertices; i++)
{
graph->adjLists[i] = NULL;
graph->visited[i] = 0;
}
return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
struct node* newNode = createNode(dest);
newNode->next = graph->adjLists[src];
graph->adjLists[src] = newNode;
newNode = createNode(src);
newNode->next = graph->adjLists[dest];
graph->adjLists[dest] = newNode;
}
void printGraph(struct Graph* graph) {
for (int v = 0; v < graph->numVertices; v++)
{
struct node* temp = graph->adjLists[v];
printf("Adjacency list of vertex %d\n", v);
while (temp)
{
printf("-> %d ", temp->vertex);
temp = temp->next;
}
printf("\n");
}
}
void main() {
int N,E,i,s,d,v;
printf("Enter the number of vertices : ");
scanf("%d",&N);
printf("Enter the number of edges : ");
scanf("%d",&E);
struct Graph* graph = createGraph(E);
for(i=0;i<E;i++)
{
printf("Enter source : ");
scanf("%d",&s);
printf("Enter destination : ");
scanf("%d",&d);
addEdge(graph, s, d);
}
printGraph(graph);
printf("Enter Start vertex of DFS : ");
scanf("%d", &v);
printf("DFS of graph : \n");
DFS(graph, v);
}