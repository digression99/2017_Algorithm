//
// algospot_tsp
//
//
//
//
/*
test case
1
5
0 7 6 9 2
7 0 4 11 12
6 4 0 23 1
9 11 23 0 5
2 12 1 5 0


*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//int n;
const int MAXN = 10;
int graph[MAXN][MAXN];
bool visited[MAXN];

//int TSP(int start, vector<int> & path, int nowLength) {
//    int ret = 9999;
//    bool isExist = false;
//    for (int i = 1; i < n; ++i) {
//        if (start != i && !visited[i]) {
//            isExist = true;
//            visited[i] = true;
//            path.push_back(i);
//            ret = min(ret, graph[start][i] + TSP(i, path, nowLength + graph[start][i]));
//            visited[i] = false;
//            path.pop_back();
//        }
//    }
//    if (isExist) return ret;
//    else return graph[start][0];
//}

const int INF = 1000000000 + 1;
int n, dist[MAXN][MAXN];
double cache[MAXN][1<<MAXN]; // visited 을 활용하면 빠른 대신에 cache의 크기가 지수적으로 증가.

double dp(int here, int visited) {
    if (visited == (1<<n) - 1) return dist[here][0];
    
    double & ret = cache[here][visited];
    if (ret >= 0) return ret;
    
    ret = INF;
    
    for (int next = 0; next < n; ++next) {
        if (visited & (1 << next)) continue;
        
        double cand = dist[here][next] + dp(next, visited + (1<<next));
        ret = min(ret, cand);
    }
    return ret;
}

int main() {
    int tc;
    vector<int> path;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                cin >> graph[j][k];
        memset(visited, false, sizeof(visited));
        path.clear();
        path.push_back(0);
        // 0 : start node
        visited[0] = true;
        cout << TSP(0, path, 0) << endl;
        cout << endl;
    }
    
    return 0;
}


