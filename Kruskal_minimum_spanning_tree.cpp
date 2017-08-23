//
// 20170823 Kruskal's minimum spanning tree 구현.
// 아마 C형태의 코드를 C++로 구현한다.
//
// [자료구조 설계]
//
// 노드의 연결관계를 나타내는 것은 map이나 배열로 구현하는데,
// 이거는 undirected graph임에도 불구하고 하나의 엣지를 두 번 이상 고려하면 안되므로,
// 그냥 그래프가 undirected이지만 한 방향의 엣지만 주어졌다고 가정하면 된다.
// 만일 search알고리즘에서 두 방향이 다 주어져야 한다면 그때는 비슷하지만 다른 자료구조를 이용하면 된다.
// 따라서, hash로 연결관계를 만든다. 그리고 c++의 알고리즘에 따라 value를 기준으로 정렬한다.
//
// [알고리즘 설계]
//
// 이것은 greedy의 개념이므로, 가장 작은 weight의 엣지를 고르고, 그것이 Cycle을 만드는지 아닌지를 판단하여야 한다.
// 이게 구현의 핵심인 듯 하다.
// 그리고 minimum spanning tree를 만드는 것 역시 map으로 한다.
// 왜냐면 이 mst를 이용하여 minimum path 알고리즘을 구현할때 사용할 것이기 때문이다.
// 또한 이때 map은 두 방향을 다 포함하고 있어야 한다.
//
// cycle check -> 어떤 엣지를 추가했더니 그 엣지의 왼쪽과 오른쪽이 이미 있는 원소를 가리키고 있을 때는 싸이클.
// 이거는 set로직으로 구현하여야 한다?...
//
// [깨달음]
// -map<int, pair<int, int> > hash = makeHash(hash);
// 이 구문은 성립하지만, 심각한 메모리 에러를 일으킨다.
// 왜냐면, hash가 메모리에 올라와 있기도 전에 그냥 이름만 함수로 보냈기 때문이다. 계속 bad excess가 떴다. 주의하자.
//
// -map의 이터레이션은 단지 first, second만 하면 되는 게 아니다.
// -> first는 key가 담겨 있다. 따라서 만일 페어가 first에 있다면, (*i).first.first, (*i).first.second로 접근하면 된다.
// 그러나, second는 value가 담겨 있는데, 이거는 주소값이다. 따라서 i->second.first, i->second.second로 접근해야 한다.
// 즉 map의 value 부분은 포인터로 동적할당되는 것이다.
//
// - unordered_map 타입을 정렬하는 것은 일단 논리적으로도 말이 안되고, 정렬하는 방법도 굉장히 복잡하다.
// map은 요소들을 정렬해 주므로, 어차피 n log n이 걸려서 한꺼번에 정렬하나, log n * n번을 insert하면서 정렬 상태를 유지하나
// 같다. 따라서 map 을 쓰자.
// 참고로, map의 order은 std::less<keyType> 이므로 std::greater<keyType>을 쓰면 반대 상태로 정렬 가능하다.
//
// - multimap -> #include <map>만 해주면 된다.
// 이것도 원소들을 정렬하여 놓는다.
// 그러나 m[2] = ? 와 같은 subscription이 안되고, 반드시 insert함수를 써서 원소를 넣어야 한다.
// -> multimap iteration이 정말 너무 어렵다.
// 솔직히 자료구조는 파이썬이 가장 간단한 것 같다. 이건 뭐 추상화하지 않고 최대한 구현하려 하니까
// 문법도 기상천외하고 pair를 활용하니까 second.first.second... 여기에 template 문법까지 가세해서 < < >> > 뭐 이러면
// 이건 거의 brainfuck 수준이다.
//
// - MST 뒤에는 Union-Find라는 Cycle check 알고리즘이 숨어 있었는데, 이게 상당히 까다롭다.
// -> 결국 dfs로 체크하는거다. 원래 아이디어가 맞았다. 그냥 구현하면 되는데 왜 뭔가 있는 줄 알고 고민한거지?
// 이건 추상화에 너무 적응되었기 때문에 그런 듯.
//
// - weight 8에서 (1, 2)를 넣으나 (0, 7)을 넣으나 결과는 같다.
//

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <functional>

const int MAX_EDGE = 14;

//Weight   Src    Dest
//1         7      6
//2         8      2
//2         6      5
//4         0      1
//4         2      5
//6         8      6
//7         2      3
//7         7      8
//8         0      7
//8         1      2
//9         3      4
//10        5      4
//11        1      7
//14        3      5

void makeHash(multimap<int, pair<int, int> > & hash) {
    int edges[MAX_EDGE][2] = { {7, 6}, {8, 2}, {6, 5}, {0, 1}, {2, 5}, {8, 6}, {2, 3}, {7, 8}, {0, 7}, {1, 2},
        {3, 4}, {5, 4}, {1, 7}, {3, 5}};
    int weights[MAX_EDGE] = {1, 2, 2, 4, 4, 6, 7, 7, 8, 8, 9, 10, 11, 14};
    
    for (int i = MAX_EDGE - 1; i >= 0; --i)
    { // push it in reverse order so I can test the sorting algorithm.
        pair<int, int> tp = make_pair(edges[i][0], edges[i][1]);
        hash.insert(pair<int, pair<int, int>>(weights[i], tp));
    }
}

int find(vector<int> & parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(vector<int> & parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void getMST(multimap<int, pair<int, int> > & mst, multimap<int, pair<int, int> > & hash)
{
    vector<int> parent(hash.size(), -1);
    
    for (auto it = hash.begin(); it != hash.end();)
    {
        auto p = hash.equal_range((*it).first);
        
        for (it = p.first; it != p.second; ++it)
        {
            pair<int, int> tp = make_pair(it->second.first, it->second.second);
            
            int x = find(parent, tp.first);
            int y = find(parent, tp.second);
            
            if (x != y) // no cycle.
            {
                mst.insert(make_pair(it->first, tp));
                Union(parent, x, y);
            }
        }
    }
    
    return;
}

int main()
{
    multimap<int, pair<int, int> > hash;
    multimap<int, pair<int, int> > mst;
    
    makeHash(hash);

    for (auto it = hash.begin(); it != hash.end();)
    {
        cout << (*it).first << endl;
        auto p = hash.equal_range((*it).first);
        
        for (it = p.first; it != p.second; it++)
        {
            cout << it->second.first << " " << it->second.second << endl;
        }
    }
    
    getMST(mst, hash);
    cout << endl << "After get mst" << endl;
    
    for (auto it = mst.begin(); it != mst.end();)
    {
        cout << (*it).first << endl;
        auto p = mst.equal_range((*it).first);
        
        for (it = p.first; it != p.second; ++it)
        {
            cout << it->second.first << " " << it->second.second << endl;
        }
    }
    
    return 0;
}


/*
not mine.
C 언어로 구현한 geeksforgeeks 의 코드.

알고리즘을 구현하는 건 좋으나, 그 스패닝 트리를 가지고 사용할 수는 없다.
왜냐면 구한 배열 자체가 비효율적이기 때문에 다시 압축하는 과정을 거쳐야 한다.

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
 
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    // Allocate memory for creating V ssubsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    return;
}

*/

