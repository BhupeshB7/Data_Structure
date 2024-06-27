#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
    int V;
    int **adjMatrix;
  int *visited;
};

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
       struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->adjMatrix=(int**)malloc(V* sizeof(int*));
    for(int i=0;i<V;i++){
        graph->adjMatrix[i]=(int*) malloc(V* sizeof(int));
        for (int j=0;j<V;j++){
            graph->adjMatrix[i][j]=0;
        }
    }
 graph->visited = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
     graph->adjMatrix[src][dest]=1;
    graph->adjMatrix[dest][src]=1;
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph* graph) {
    for(int i=0;i<graph->V;i++){
        for(int j=0;j<graph->V;j++){
            printf("%d ",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
// DFS algorithm
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !graph->visited[i]) {
            DFS(graph, i);
        }
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

    // Print the adjacency matrix representation of the above graph
    printGraph(graph);
 // Perform DFS starting from vertex 0
    printf("\nDFS traversal starting from vertex 0:\n");
    DFS(graph, 0);
    return 0; 
}
