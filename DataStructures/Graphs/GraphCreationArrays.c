#include <stdio.h>
#include <stdlib.h>
#include "GraphCreation.h"

G* graph;

int main() {
    createGraph(5);
    printGraph();
    return 0;
}

void initGraphArray(int n){
    graph = (G*)malloc(sizeof(G*));
    graph->numVertices = n;
    graph->adjacencyMatrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void createGraphArray(int n) {
    initGraph(n);
    int src, dst, i, j;
    while(1){
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dst);
        if(src <= 0 && dst <= 0){
            break;
        }
        else if(src >n || dst > n || src ==0 || dst == 0){
            printf("Out of range\n");
            continue;
        }
        addEdge(src-1, dst-1);
    }
}

void addEdgeArray(int src, int dst){
    graph->adjacencyMatrix[src][dst] = 1;
    graph->adjacencyMatrix[dst][src] = 1;
}

void printGraphArray(){
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

