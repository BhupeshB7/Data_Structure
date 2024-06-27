#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Graph{
    int V;
    int **adjMatrix;
    int *visited;
};

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->adjMatrix= (int**)malloc(V*sizeof(int*));
    for(int i=0;i<V;i++){
        graph->adjMatrix[i]=(int*)malloc(V*sizeof(int));
        for(int j=0;j<V;j++){
            graph->adjMatrix[i][j]=0;
        }
    }
    graph->visited= (int*)malloc(V*sizeof(int));
    for(int i=0;i<V;i++){
        graph->visited[i]=0;
    }
    return graph;
}
void addEdge(struct Graph* graph,int src,int dest){
    graph->adjMatrix[src][dest]=1;
    // graph->adjMatrix[dest][src]=1;
}

void printGraph(struct Graph* graph){
    for(int i=0;i<graph->V;i++){
        for(int j=0;j<graph->V;j++){
            printf("%d ",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
void DFS(struct Graph* graph,int vertex){
    graph->visited[vertex]=1;
    printf("Visited vertex %d\n",vertex);
    for(int i=0;i<graph->V;i++){
        if(graph->adjMatrix[vertex][i]==1 && !graph->visited[i]){
            DFS(graph,i);
        }
    }
}
void BFS(struct Graph* graph, int startVertex, int endVertex) {
    int queue[graph->V];
    int front = 0, rear = 0;
    int dist[graph->V];
    for (int i = 0; i < graph->V; ++i) {
        dist[i] = INT_MAX;
    }
    dist[startVertex] = 0;
    queue[rear++] = startVertex;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < graph->V; ++v) {
            if (graph->adjMatrix[u][v] && dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    printf("Shortest distance from vertex %d to vertex %d is: %d\n", startVertex, endVertex, dist[endVertex]);
}

int main(){
    int V=5;
    struct Graph* graph=createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printGraph(graph);
    DFS(graph,0);
    BFS(graph,0,0);
    return 0;

    for (int i = 0; i < V; ++i) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph->visited);
    free(graph);

}
