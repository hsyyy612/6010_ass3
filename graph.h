// header file: structs and function declarations for graphs

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
    // fill in
    Node *nodeList;
} Graph;

// add any additional struct definitions

Graph *initializeGraph();
void deleteGraph(Graph *myGraph);
void addNode(Graph *myGraph, int myNodeID);
void addEdge(Graph *myGraph, int myFromNodeID, int myToNodeID, double myEdgeweight);
void deleteNode(Graph *myGraph, int myNodeID);
void deleteEdge(Graph *myGraph, int myFromNodeID, int myToNodeID);
int calcNumNodes(Graph *myGraph);
int calcNumEdges(Graph *myGraph);
void printNodeList(Graph *myGraph);
void printEdgeList(Graph *myGraph);

// add any additional function declarations
Node *createNode(int myNodeID);
Edge *createEdge(int FromNodeID, int ToNodeID, double Edgeweight);
Node *findNode(Graph *myGraph, int NodeID);
void deleteEdgeList(Edge *curr);