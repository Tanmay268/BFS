/*
Implement the BFS algorithm and display the output tree for a given graph and a start 
vertex s of V. The user can enter the details for a graph and the source vertex s. 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int start, int end) {
    graph->adjacencyMatrix[start][end] = 1;
    graph->adjacencyMatrix[end][start] = 1;
}

void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");

    while (front < rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    free(graph);

    return 0;
}
