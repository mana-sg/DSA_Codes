#include <stdio.h>
#include <stdlib.h>
#include "GraphCreation.h"


int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    GA* graph[n];
    initGraphList(graph, n);
    int src, dst;
    while(1){
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dst);
        if(src < 0 && dst < 0){
            break;
        }
        else if(src > n || dst > n || src ==0 || dst == 0){
            printf("Out of range\n");
            continue;
        }
        addEdgeList(graph, src, dst);
    }
    printGraphList(graph, n);

    return 0;
}

N* createNode(int vertex){
    N* newNode = (N*)malloc(sizeof(N*));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(GA** graph, int src, int dst){
    N* newNode = createNode(dst);
    if(graph[src-1]->head == NULL)
        graph[src-1]->head = newNode;
    else{
        N* temp = graph[src-1]->head;
        while(temp->next){
            if(temp->vertex == dst)
                return;
            temp = temp->next;
        }
        temp->next = newNode;
    }

    newNode = createNode(src);
    if(graph[dst-1]->head == NULL)
        graph[dst-1]->head = newNode;
    else{
        N* temp = graph[dst-1]->head;
        while(temp->next){
            if(temp->vertex == src)
                return;
            temp = temp->next;
        }
        temp->next = newNode;
    
    }
}

void initGraphList(GA** graph, int n){
    for(int i = 0; i < n; i++){
        graph[i] = (GA*)malloc(sizeof(GA*));
        graph[i]->head = NULL;
    }
}

void printGraphList(GA** graph, int n){
    for(int i = 0; i < n; i++){
        N* temp = graph[i]->head;
        printf("Adjacency list of vertex %d\n", i+1);
        while(temp->next){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("%d", temp->vertex);
        printf("\n");
    }
}