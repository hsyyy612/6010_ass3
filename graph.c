#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int fromNodeID;
    int toNodeID;
    double weight;
    struct Edge *nextEdge;
} Edge;

typedef struct Node
{
    int nodeID;
    Edge *edgeList;
    struct Node *nextNode;
} Node;

typedef struct Graph
{
    Node *nodeList;
} Graph;

// Function to initialize a graph
Graph *initializeGraph()
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->nodeList = NULL;
    return newGraph;
}

// Function to create a new node
Node *createNode(int myNodeID)
{
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->nodeID = myNodeID;
    newNode->nextNode = NULL;
    newNode->edgeList = NULL;
    return newNode;
}

// Function to add a node in nodeList
void addNode(Graph *myGraph, int myNodeID)
{
    Node *newNode, *temp;
    newNode = createNode(myNodeID);

    if (myGraph->nodeList == NULL)
    {
        myGraph->nodeList = newNode;
        return;
    }
    temp = myGraph->nodeList;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
}

// Function to print nodeList
void printNodeList(Graph *myGraph)
{
    Node *temp = myGraph->nodeList;
    while (temp != NULL)
    {
        printf("%d ", temp->nodeID);
        temp = temp->nextNode;
    }
    printf("\n");
}

// Function to calculate the number of node
int calcNumNodes(Graph *myGraph)
{
    int count = 0;
    Node *curr = myGraph->nodeList;
    while (curr != NULL)
    {
        count++;
        curr = curr->nextNode;
    }
    return count;
}

// Function to create an edge
Edge *createEdge(int FromNodeID, int ToNodeID, double Edgeweight)
{
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->fromNodeID = FromNodeID;
    newEdge->toNodeID = ToNodeID;
    newEdge->weight = Edgeweight;
    newEdge->nextEdge = NULL;
    return newEdge;
}

// Function to find a node in nodeList
Node *findNode(Graph *myGraph, int NodeID)
{
    Node *tarNode = myGraph->nodeList;
    while (tarNode->nodeID != NodeID)
    {
        tarNode = tarNode->nextNode;
    }
    return tarNode;
}

// Function to add edge in edge linked list
void addEdge(Graph *myGraph, int myFromNodeID, int myToNodeID, double myEdgeweight)
{

    Node *fromNode = findNode(myGraph, myFromNodeID);
    Edge *newEdge = createEdge(myFromNodeID, myToNodeID, myEdgeweight);
    Edge *temp = fromNode->edgeList;

    if (temp == NULL)
    {
        fromNode->edgeList = newEdge;
    }
    else
    {
        while (temp->nextEdge != NULL)
        {
            temp = temp->nextEdge;
        }
        temp->nextEdge = newEdge;
    }
}

// Function to print all edges in the graph
void printEdgeList(Graph *myGraph)
{
    Node *currentNode = myGraph->nodeList;
    while (currentNode != NULL)
    {
        Edge *currentEdge = currentNode->edgeList;
        while (currentEdge != NULL)
        {
            printf("(%d, %d, %f)\n", currentNode->nodeID, currentEdge->toNodeID, currentEdge->weight);
            currentEdge = currentEdge->nextEdge;
        }
        currentNode = currentNode->nextNode;
    }
    // printf("\n");
}

// Function to calculate the number of edges in the graph
int calcNumEdges(Graph *myGraph)
{
    int count = 0;
    Node *currentNode = myGraph->nodeList;
    while (currentNode != NULL)
    {
        Edge *currentEdge = currentNode->edgeList;
        while (currentEdge != NULL)
        {
            count++;
            currentEdge = currentEdge->nextEdge;
        }
        currentNode = currentNode->nextNode;
    }
    return count;
}

// Function to delete a single edge
void deleteEdge(Graph *myGraph, int myFromNodeID, int myToNodeID)
{
    Node *fromNode = findNode(myGraph, myFromNodeID);
    Edge *temp = fromNode->edgeList;
    Edge *prev = NULL;

    // if fromNode is not in the NodeList
    if (!fromNode)
    {
        exit(1);
    }

    while (temp != NULL)
    {
        if (temp->toNodeID == myToNodeID)
        {
            // if target Edge is the first edge
            if (prev == NULL)
            {
                fromNode->edgeList = temp->nextEdge;
            }
            else
            {
                prev->nextEdge = temp->nextEdge;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->nextEdge;
    }

    exit(1);
}

// Function to delete Edge linked list
void deleteEdgeList(Edge *curr)
{

    Edge *temp;
    // If the list is empty, return
    if (curr == NULL)
    {
        return;
    }

    // Recursively delete the next node
    while (curr != NULL)
    {
        temp = curr->nextEdge;
        free(curr);
        curr = temp;
    }
}

// Function to delete a Node, its Edge List and other Edges point to the Node
void deleteNode(Graph *myGraph, int myNodeID)
{
    Node *currentNode = myGraph->nodeList;
    Node *prevNode = NULL;
    int nodeDeleted = 0;

    while (currentNode != NULL)
    {
        // If we find the target node to delete
        if (currentNode->nodeID == myNodeID)
        {
            // Delete the node's edge list
            deleteEdgeList(currentNode->edgeList);

            // Remove the node from the node list
            if (prevNode == NULL)
            {
                // If it's the first node in the list
                myGraph->nodeList = currentNode->nextNode;
            }
            else
            {
                prevNode->nextNode = currentNode->nextNode;
            }
            free(currentNode);
            nodeDeleted = 1;
            // return;

            // Don't return here; continue checking the rest of the nodes for edges pointing to this node
            currentNode = (prevNode == NULL) ? myGraph->nodeList : prevNode->nextNode;
            continue;
        }

        // Delete edges pointing to the node
        Edge *currentEdge = currentNode->edgeList;
        Edge *prevEdge = NULL;

        while (currentEdge != NULL)
        {
            if (currentEdge->toNodeID == myNodeID)
            {
                // Delete the edge pointing to the node
                if (prevEdge == NULL) // If the node is the first node in the node list
                {
                    currentNode->edgeList = currentEdge->nextEdge;
                }
                else
                {
                    prevEdge->nextEdge = currentEdge->nextEdge;
                }
                free(currentEdge);
                currentEdge = (prevEdge == NULL) ? currentNode->edgeList : prevEdge->nextEdge;
            }
            else
            {
                prevEdge = currentEdge;
                currentEdge = currentEdge->nextEdge;
            }
        }
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    // Check if the node was found and deleted, otherwise exit

    if (!nodeDeleted)
    {
        exit(1);
    }
}

// Function to delete the graph
void deleteGraph(Graph *myGraph)
{
    Node *currentNode = myGraph->nodeList;
    while (currentNode != NULL)
    {
        Node *nextNode = currentNode->nextNode;
        deleteNode(myGraph, currentNode->nodeID);
        currentNode = nextNode;
    }
    free(myGraph);
}
