#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Graph structure
struct Graph {
    int numVertices;
    int adjMatrix[MAX][MAX];
    int visited[MAX];
};

// Create a graph with given vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // For undirected graph
}

// Reset visited array before each BFS
void resetVisited(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// Print the BFS traversal
void bfs(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && graph->visited[i] == 0) {
                graph->visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

// Main function with menu-driven switch-case
int main() {
    int vertices, choice, src, dest, startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    do {
        printf("\n\n--- Graph Operations Menu ---\n");
        printf("1. Add an edge\n");
        printf("2. Perform BFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the source and destination vertices for the edge (0 to %d): ", vertices - 1);
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                    addEdge(graph, src, dest);
                    printf("Edge added between vertex %d and %d.\n", src, dest);
                } else {
                    printf("Invalid vertices!\n");
                }
                break;
            case 2:
                resetVisited(graph);
                printf("Enter the starting vertex for BFS (0 to %d): ", vertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < vertices) {
                    bfs(graph, startVertex);
                } else {
                    printf("Invalid starting vertex!\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
