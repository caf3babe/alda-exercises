#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NODES   20
#define WHITE       0
#define GRAY        1
#define BLACK       2


// structure for a node
typedef struct _node {
    char *name;
    int color;
    int startTime;
    int endTime;
} node;


// structure for a grpah defined by an adjacency matrix
typedef struct _graph {
    int numNodes;
    node nodes[MAX_NODES];
    int adjMatrix[MAX_NODES][MAX_NODES];
} graph;


// function prototypes
void initGraph(graph *g);
int addNode(graph *g, char *name);
void topologySearch(graph *g);


// initialize graph
void initGraph(graph *g) {
    int i, j;
    g->numNodes = 0;
    for (i = 0; i < MAX_NODES; i++) {
        g->nodes[i].name = NULL;
        g->nodes[i].color = WHITE;
        g->nodes[i].startTime = 0;
        g->nodes[i].endTime = 0;

        for (j = 0; j < MAX_NODES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// reset the colors to white and clear all times
void resetGraph(graph *g) {
    int i;
    for (i = 0; i < g->numNodes; i++) {
        g->nodes[i].color = WHITE;
        g->nodes[i].startTime = 0;
        g->nodes[i].endTime = 0;
    }
}


// add a node to the graph if it does not exist yet and return the index of the node
int addNode(graph *g, char *name) {
    int i;

    for (i = 0; i < g->numNodes; i++) {
        // if we find a node with the name return the index
        if (strcmp(g->nodes[i].name, name) == 0) {
            return i;
        }
    }

    // reserve memory for the name of the node
    g->nodes[g->numNodes].name = (char *)malloc((strlen(name) + 1) *sizeof(char));
    strcpy(g->nodes[g->numNodes].name, name);

    // increase the number of nodes since we added a new node
    g->numNodes++;

    return g->numNodes - 1;
}


void topologySearch(graph *g) {
    // TODO: implement
}


int main() {
    FILE *fp;
    char line[1000];
    char *pos;

    // our graph g
    graph g;
    int source;
    int target;

    // initialize the new graph
    initGraph(&g);

    // open the file
    fp = fopen("Makefile", "r");
    if (fp == NULL) {
        printf("Cannot open Makefile!!!\n");
        return -1;
    }

    // loop through all lines of the file
    while (!feof(fp)) {
        fgets(line, 1000, fp);
        printf("%s", line);

        // extract the first node name
        pos = strtok(line, " \n\r");
        // ignore any empty line
        if (pos == NULL) continue;

        // add the node to the graph
        target = addNode(&g, pos);

        // ignore the colon
        pos = strtok(NULL, " \n\r");

        // read all dependencies of the target node stated on the same line
        while ((pos = strtok(NULL, " \n\r")) != NULL) {
            source = addNode(&g, pos);

            // add an edge to the adjacency matrix
            g.adjMatrix[target][source] = 1;
            printf("[%d, %s] <- [%d, %s]\n", target, g.nodes[target].name, source, g.nodes[source].name);
        }
    }

    fclose(fp);

    // DFS search
    topologySearch(&g);

    return 0;
}



