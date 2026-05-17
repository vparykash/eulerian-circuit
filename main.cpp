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

Graph* create_graph(int n)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (!g) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    g->n = n; g->m = 0;
    g->v = (Vertex*)calloc(n, sizeof(Vertex));
    if (!g->v) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        g->v[i].id = i + 1;
        g->v[i].adj = NULL;
    }
    return g;
}

void add_edge(Graph* g, int u, int v)
{
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    if (!node) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    node->dest = v;
    node->used = 0;
    node->next = g->v[u].adj;
    g->v[u].adj = node;
    g->v[u].out_deg++;
    g->v[v].in_deg++;
    g->m++;
}

void free_graph(Graph* g)
{
    for (int i = 0; i < g->n; i++) {
        AdjNode* cur = g->v[i].adj;
        while (cur) {
            AdjNode* t = cur->next;
            free(cur);
            cur = t;
        }
    }
    free(g->v);
    free(g);
}