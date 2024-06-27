#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to represent a graph
struct Graph {
    int V;
    struct AdjList* array;
    int* visited;
};

// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    graph->visited = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// DFS algorithm
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    struct Node* pCrawl = graph->array[vertex].head;
    while (pCrawl) {
        int adjVertex = pCrawl->dest;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        pCrawl = pCrawl->next;
    }
}

// Main function to demonstrate the graph operations
int main() {
    // Create the graph given in the example
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the above graph
    printGraph(graph);

    // Perform DFS starting from vertex 0
    printf("\nDFS traversal starting from vertex 0:\n");
    DFS(graph, 0);

    // Print the visited array after DFS
    printf("\nVisited array after DFS:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", graph->visited[i]);
    }
    printf("\n");

    return 0;
}
