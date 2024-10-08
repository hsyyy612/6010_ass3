// graphs program: dynamic graph management
#include <stdio.h>
#include "graph.h"

int main(int argc, char *argv[]) 
{
	Graph* vertexList = initializeGraph();
	addNode(vertexList,1);
	addNode(vertexList,2);
	addNode(vertexList,3);
	addNode(vertexList,4);
	printf("Number of nodes: %d; number of edges: %d\n",calcNumNodes(vertexList),calcNumEdges(vertexList));
	printNodeList(vertexList);

	addEdge(vertexList,1,2,2.4);
	addEdge(vertexList,2,3,18.7);
	addEdge(vertexList,4,3,6.3);
	addEdge(vertexList,2,1,77.5);
	addEdge(vertexList,2,4,0.9);
	printf("Number of nodes: %d; number of edges: %d\n",calcNumNodes(vertexList),calcNumEdges(vertexList));
	printEdgeList(vertexList);
	
	deleteEdge(vertexList,2,1);
	printf("Number of nodes: %d; number of edges: %d\n",calcNumNodes(vertexList),calcNumEdges(vertexList));
	printEdgeList(vertexList);
	
	deleteNode(vertexList,3);
	printf("Number of nodes: %d; number of edges: %d\n",calcNumNodes(vertexList),calcNumEdges(vertexList));
	printNodeList(vertexList);
	printEdgeList(vertexList);
	
	deleteGraph(vertexList);
	
	return 0;
}
