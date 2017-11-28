//
// gfg_topological sort
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 6;
int graph[MAXN][MAXN] = {
    {0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 0, 0, 0, 0}, // 1
    {0, 0, 0, 1, 0, 0}, // 2
    {0, 1, 0, 0, 0, 0}, // 3
    {1, 1, 0, 0, 0, 0}, // 4
    {1, 0, 1, 0, 0, 0}, // 5
};
int visited[MAXN] = {0, 0, 0, 0, 0, 0};

bool isEmptyNode(int i) {
    for (int j = 0; j < MAXN; ++j) {
        if (graph[j][i]) return false;
    }
    return true;
}

//vector<int> topologicalSort(int graph[MAXN][MAXN]) {
//vector<int> topologicalSort(int graph[][MAXN]) {
vector<int> topologicalSort(int(*graph)[MAXN]) {
    vector<int> res;
    queue<int> q;
    
    for (int i = 0; i < MAXN; ++i) {
        if (isEmptyNode(i)) {
            visited[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        res.push_back(n);
        for (int i = 0; i < MAXN; ++i) {
            if (visited[i]) continue;
            if (graph[n][i]) {
                graph[n][i] = 0;
            }
            if (isEmptyNode(i)) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    // if graph has edges, then return error.
    return res;
}

int main() {
    vector<int> ans = topologicalSort(graph);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}

