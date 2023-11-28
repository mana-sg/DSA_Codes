#ifndef GRAPH_CREATION_H
#define GRAPH_CREATION_H
#define MAX_VERTICES 1000

typedef struct Graph {
    int numVertices;
    int** adjacencyMatrix;
}G;

typedef struct Node {
    int vertex;
    struct Node* next;
}N;

typedef struct g {
    N* head;
}GA;


N* createNode(int vertex);
void initGraphArray(int n);
void initGraphList(GA** graph, int n);
void createGraphArray(int n);
void addEdgeArray(int src, int dest);
void addEdgeList(GA** graph, int src, int dst);
void printGraphArray();
void printGraphList(GA** graph, int n);

#endif
