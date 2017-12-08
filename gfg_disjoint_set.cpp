///*
// gfg_disjoint set
// - detect cycle in an undirected graph
// - find : determine which subset a particular element is in.
// - union : join two subsets into a single subset.
// */
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int MAXV = 3;
//
//int graph[MAXV][MAXV] = {
//    {0, 1, 1},
//    {1, 0, 1},
//    {1, 1, 0}
//};
//
////int newSubsetNum = 0;
//int parent[MAXV] = {-1, -1, -1};
//// parent means you save next vertex idx.
//// so, it means you can only save one vertext at a time.
//// union(int idx, int subsetNum)
//
//// find()
//// find should return the subset number.
//
//// union()
//// connect the parent edge.
//// subset only needs two.
//// that means, if a vertex is in some subset,
//// then find() should return the representative.
//// and union() should union two subset and
//// put the representative.
//
//// you can suspect that
//// the graph has only one edge and
//// has cycle or not.
//
//
//// no, there could be several edges,
//// but save only one vertex in same subset.
//
//// need to check how to check representative.
//
//
//void unionSubset(int idx1, int idx2) {
//    parent[idx1] = idx2;
//}
//
//bool detectCycle(int idx) {
//    for (int i = 0; i < MAXV; ++i) {
//        if (graph[idx][i]) {
//            //if (find(i) == find(idx)) return true; // check if both subsets are same.
//
//            parent[idx] = i; // union.
//            return detectCycle(i);
//        }
//    }
//    return false;
//}
//
//int main() {
//    cout << detectCycle(0) << endl;
//
//    return 0;
//}

// A union-find algorithm to detect cycle in a graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure to represent an edge in graph
struct Edge
{
    int src, dest;
};

// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    
    // graph is represented as an array of edges
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =
    (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    
    graph->edge =
    (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    
    return graph;
}

// A utility function to find the subset of an element i
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
    // a representative of a subset is
    // the last element of the subset.
}

// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
    // union operation sets xset's representative as yset's representative.
    // It reduces time to check the representative of the other subset.
}

// The main function to check whether a given graph contains
// cycle or not
int isCycle( struct Graph* graph )
{
    // Allocate memory for creating V subsets
    
    int *parent = (int*) malloc( graph->V * sizeof(int) );
    
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);
    
    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then
    // there is cycle in graph.
    for(int i = 0; i < graph->E; ++i)
    {
        // you assume that every edge has it's src and dest.
        // so, the perspective of this algorithm is to see
        // graph as a collection of edges.
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
        
        if (x == y)
            return 1;
        
        Union(parent, x, y);
    }
    return 0;
}

// Driver program to test above functions
int main()
{
    /* Let us create following graph
     0
     |  \
     |    \
     1-----2 */
    int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);
    
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
    
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
    
    return 0;
}
















