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
    int time;
    int numNodes;
    node nodes[MAX_NODES];
    int adjMatrix[MAX_NODES][MAX_NODES];
} graph;


// function prototypes
void initGraph(graph *g);
int addNode(graph *g, char *name);
void topologySearch(graph *g);
int getWhiteNode(graph *g);
void goDeep(int n, graph *g);


// initialize graph
void initGraph(graph *g) {
    int i, j;
    g->numNodes = 0;
    for (i = 0; i < MAX_NODES; i++) {
        g->time = 0;
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
        g->time = 0;
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
    int whiteNode = getWhiteNode(g);

    while(whiteNode!=-1) {
        goDeep(whiteNode, g);
        whiteNode = getWhiteNode(g);
    }
    printf("Total time: %d\n", g->time);
}

int getWhiteNode(graph *g){
    for(int i = 0;i < g->numNodes; i++){
        if(g->nodes[i].color==WHITE){
            g->nodes[i].color==GRAY;
            return i;
        }
    }
    return -1;
}

void goDeep(int n, graph *g) {
    g->nodes[n].startTime = ++g->time;
    // loop over adjacency matrix and see if there is a edge to another node
    // if so we call recursively goDeep function
    for(int i = 0; i < g->numNodes; i++){
        if(g->adjMatrix[n][i]==1){
            if(g->nodes[i].color == WHITE) {
                g->nodes[i].color = GRAY;
                goDeep(i, g);
            }
        }
    }
    // if loop is over no edge to another node
    // that is why we set color black and return from this function call
    g->nodes[n].color = BLACK;
    g->nodes[n].endTime = ++g->time;
    return;
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
    fp = fopen("../Makefile", "r");
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

    printf("\n");
    // DFS search
    topologySearch(&g);

    for(int i = 0; i < g.numNodes; i++){
        printf("%s has start %d end %d\n",g.nodes[i].name,g.nodes[i].startTime,g.nodes[i].endTime);
    }

    // output for drawing graph https://csacademy.com/app/graph_editor/
    /*printf("\n");
    for(int i = 0; i < g.numNodes; i++){
        for(int j = 0; j < g.numNodes; j++){
            if(g.adjMatrix[i][j]==1){
                printf("%s %s \n",g.nodes[i].name,g.nodes[j].name);
            }
        }
    }*/

    return 0;
}



