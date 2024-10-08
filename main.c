// graphs program: dynamic graph management
#include <stdio.h>
#include "graph.h"

int main(int argc, char *argv[])
{
    Graph *vertexList = initializeGraph();

    // add nodes
    addNode(vertexList, 5);
    addNode(vertexList, 3);
    addNode(vertexList, 9);
    addNode(vertexList, 7);
    addNode(vertexList, 6);
    addNode(vertexList, 2);    
    printf("Number of nodes: %d; number of edges: %d\n", calcNumNodes(vertexList), calcNumEdges(vertexList));
    printNodeList(vertexList);

    // add edges
    addEdge(vertexList, 3, 7, 2.4);
    addEdge(vertexList, 3, 9, 8.1);
    addEdge(vertexList, 3, 5, 0.5);
    addEdge(vertexList, 9, 7, 0.5);
    addEdge(vertexList, 7, 5, 10.9);
    addEdge(vertexList, 6, 7, 0.3);
    addEdge(vertexList, 2, 7, 0.5);

    printf("Number of nodes: %d; number of edges: %d\n", calcNumNodes(vertexList), calcNumEdges(vertexList));
    printEdgeList(vertexList);

    deleteNode(vertexList, 7);

    printNodeList(vertexList);
    printEdgeList(vertexList);

    deleteGraph(vertexList);

    return 0;
}