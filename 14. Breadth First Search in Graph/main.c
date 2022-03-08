#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct queue {
    int items[MAX];
    int front;
    int rear;
};
struct queue* createQueue();
struct node {
    int vertex;
    struct node* next;
};
struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};
void bfs(struct Graph* graph, int startVertex) {
    struct queue* q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);
        struct node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
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
    int i;
    for (i = 0; i < vertices; i++) {
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
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is Full!!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } 
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}
void printQueue(struct queue* q) {
    int i = q->front;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue contains \n");
        for (i = q->front; i < q->rear + 1; i++)
            printf("%d ", q->items[i]);
    }
}
void main() {
    int N, s, d, i, v;
    printf("Enter the number of vertices : ");
    scanf("%d",&N);
    struct Graph* graph = createGraph(N);
    for(i=0;i<N;i++){
        printf("Enter source : ");
        scanf("%d",&s);
        printf("Enter destination : ");
        scanf("%d",&d);
        addEdge(graph, s, d);
    }
    printf("Enter Start Vertex for BFS : ");
    scanf("%d", &v);
    printf("BFS of graph : ");
    bfs(graph, v);
    printf("\n");
}