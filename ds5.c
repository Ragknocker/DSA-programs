#include <stdio.h>
#define MAX_VERTICES 100

void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
   printf("Adjacency Matrix:\n");
   for (int i = 0; i < vertices; i++) {
       for (int j = 0; j < vertices; j++) {
           printf("%d ", graph[i][j]);
       }
       printf("\n");
   }
}

void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end) {
   graph[start][end] = 1;
   graph[end][start] = 1; 
}
int main() {
   int vertices, edges;
   
   printf("Enter the number of vertices: ");
   scanf("%d", &vertices);
   if (vertices <= 0 || vertices > MAX_VERTICES) {
       printf("Invalid number of vertices. Exiting...\n");
       return 1;
   }
   int graph[MAX_VERTICES][MAX_VERTICES] = {0}; 
   
   printf("Enter the number of edges: ");
   scanf("%d", &edges);
   if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
       printf("Invalid number of edges. Exiting...\n");
       return 1;
   }

   for (int i = 0; i < edges; i++) {
       int start, end;
       printf("Enter edge %d (start end): ", i + 1);
       scanf("%d %d", &start, &end);
       
       if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
           printf("Invalid vertices. Try again.\n");
           i--;
           continue;
       }
       addEdge(graph, start, end);
   }
   
   displayGraph(graph, vertices);
   return 0;
}