#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AdjNode {
    int dest;
    int used;
    struct AdjNode* next;
} AdjNode;

typedef struct Vertex {
    int id;
    int out_deg;
    int in_deg;
    AdjNode* adj;
} Vertex;

typedef struct Graph {
    int n;
    int m;
    Vertex* v;
} Graph;