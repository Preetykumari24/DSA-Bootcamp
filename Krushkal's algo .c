#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in a graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Structure for union-find operations
struct Subset {
    int parent, rank;
};

// Function to create a new graph with error handling
struct Graph* createGraph(int V, int E) {
    if (V <= 0 || E <= 0) {
        fprintf(stderr, "Error: Invalid number of vertices or edges\n");
        return NULL;
    }

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for graph\n");
        return NULL;
    }

    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    if (graph->edges == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for edges\n");
        free(graph);
        return NULL;
    }

    graph->V = V;
    graph->E = E;
    return graph;
}

// Find with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union by rank
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Validate edge inputs
int validateEdge(struct Graph* graph, int src, int dest, int weight) {
    if (src < 0 || src >= graph->V || dest < 0 || dest >= graph->V) {
        fprintf(stderr, "Error: Invalid vertex indices\n");
        return 0;
    }
    if (weight < 0 || weight > INT_MAX) {
        fprintf(stderr, "Error: Invalid edge weight\n");
        return 0;
    }
    return 1;
}

// Function to implement Kruskal's algorithm with error handling
int KruskalMST(struct Graph* graph) {
    if (graph == NULL) {
        fprintf(stderr, "Error: Invalid graph\n");
        return -1;
    }

    int V = graph->V;
    struct Edge* result = (struct Edge*)malloc((V-1) * sizeof(struct Edge));
    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for MST result\n");
        return -1;
    }

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    if (subsets == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for subsets\n");
        free(result);
        return -1;
    }

    // Sort edges
    qsort(graph->edges, graph->E, sizeof(struct Edge), compareEdges);

    // Initialize subsets
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;  // Index for result array
    int i = 0;  // Index for sorted edges

    // Build MST
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Check if MST is complete
    if (e != V - 1) {
        fprintf(stderr, "Error: Graph is not connected, no spanning tree possible\n");
        free(result);
        free(subsets);
        return -1;
    }

    // Print MST
    printf("\nMinimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("Edge %d-%d: Weight %d\n", 
               result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total MST Weight: %d\n", totalWeight);

    free(result);
    free(subsets);
    return totalWeight;
}

int main() {
    int V, E;
    
    printf("Enter number of vertices (>0): ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        fprintf(stderr, "Error: Invalid number of vertices\n");
        return 1;
    }

    printf("Enter number of edges (>0): ");
    if (scanf("%d", &E) != 1 || E <= 0) {
        fprintf(stderr, "Error: Invalid number of edges\n");
        return 1;
    }

    // Validate edge count
    if (E < V - 1) {
        fprintf(stderr, "Error: Too few edges for a spanning tree\n");
        return 1;
    }

    struct Graph* graph = createGraph(V, E);
    if (graph == NULL) {
        return 1;
    }

    printf("\nEnter edges as 'source destination weight':\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        if (scanf("%d %d %d", &src, &dest, &weight) != 3 ||
            !validateEdge(graph, src, dest, weight)) {
            fprintf(stderr, "Error: Invalid edge input\n");
            free(graph->edges);
            free(graph);
            return 1;
        }
        graph->edges[i].src = src;
        graph->edges[i].dest = dest;
        graph->edges[i].weight = weight;
    }

    int mstWeight = KruskalMST(graph);
    
    free(graph->edges);
    free(graph);
    
    return mstWeight >= 0 ? 0 : 1;
}
