//
// assumes that graph doesn't contain any self-loops.
//
//
//
//
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> edges = {
    {0, 1},
    {1, 2},
    {2, 0}
};

const int MAXV = 3;
int parent[MAXV] = {-1, -1, -1};
int nodeRank[MAXV] = {0, 0, 0};

int find(int idx) {
    if (parent[idx] == -1) return idx;
    parent[idx] = find(parent[idx]); // flatten the tree.
    return parent[idx];
}

void Union(int idx1, int idx2) {
    int xset = find(idx1);
    int yset = find(idx2);
    
    // use rank, diminishing time complexity.
    if (nodeRank[xset] > nodeRank[yset]) {
        parent[yset] = xset;
    } else if (nodeRank[xset] < nodeRank[yset]) {
        parent[xset] = yset;
    } else {
        parent[xset] = yset;
        nodeRank[xset]++;
    }
}

bool isCycle() {
    for (auto e : edges) {
        int front = find(e.first);
        int back = find(e.second);
        
        if (front == back) return true;
        Union(front, back);
    }
    return false;
}

int main() {
    cout << isCycle() << endl;
    
    return 0;
}

