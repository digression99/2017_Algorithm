#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

unordered_map<int, unordered_map<int, int>> edges; // hash instead of 2d array.
const int INF = 99999;

class Solution {
public:
    
    class Comp {
        //unordered_map<int, unordered_map<int, int>> edges;
    public:
        //Comp(unordered_map<int, unordered_map<int, int>> & e) : edges(e) {}
        //Comp(const unordered_map<int, unordered_map<int, int>> & e) : edges(e) {}
        //Comp(unordered_map<int, unordered_map<int, int>> && e) : edges(e) {}
        
        bool operator()(pair<int, int> & p1, pair<int, int> & p2) {
            return edges[p1.first][p1.second] < edges[p2.first][p2.second];
        }
    };
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i = 0; i < letters.size(); ++i) {
            if (target <= letters[i]) {
                continue;
            } if (target > letters[i]) {
                if (i == letters.size() - 1) return letters[0];
                return letters[i];
            }
        }
        return '#';
    }
    void makeEdges(vector<vector<int>> & times) {
        // make edges.
        for (int i = 0; i < times.size(); ++i) {
            int src = times[i][0], dest = times[i][1], weight = times[i][2];
            if (edges.find(src) == edges.end())
                edges[src] = unordered_map<int, int>();
            if (edges[src].find(dest) == edges[src].end())
                edges[src][dest] = weight;
        }
    }
    
    int networkDelayTime(vector<vector<int>> & times, int N, int K) {
        vector<int> dist(N, INF), prev(N, -1);
        int sum = 0;
        Comp comp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> nextq(comp);
        
        makeEdges(times);
        
        dist[K] = 0;
        prev[K] = K;
        for (auto dat : edges[K])
            nextq.push(make_pair(K, dat.first)); // insert only the vertices connected to K.
        
        while (!nextq.empty()) {
            swap(q, nextq);
            while (!nextq.empty()) nextq.pop();
            while (!q.empty()) {
                int u = q.top().first, v = q.top().second; q.pop();
                if (dist[v] == INF) {
                    for (auto dat : edges[v])
                        nextq.push(make_pair(v, dat.first)); // add edges and sort it.
                }
                int alt = dist[u] + edges[u][v];
                if (dist[v] > alt) {
                    if (dist[v] < INF)
                        sum -= dist[v];
                    sum += alt;
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
        for (auto dat : dist) cout << dat << endl;
        return sum;
    }
    
//    int networkDelayTime(vector<vector<int>> & times, int N, int K) {
//        const int INF = 99999;
//        vector<int> dist(N, INF);
//        vector<int> prev(N, -1);
//        int sum = 0;
//
//        // make edges.
//        for (int i = 0; i < times.size(); ++i) {
//            int src = times[i][0], dest = times[i][1], weight = times[i][2];
//            if (edges.find(src) == edges.end())
//                edges[src] = unordered_map<int, int>();
//            if (edges[src].find(dest) == edges[src].end())
//                edges[src][dest] = weight;
//        }
//        Comp comp;
//
//        dist[K] = 0;
//        prev[K] = K;
//
////        auto comp = [&](pair<int, int> & p1, pair<int, int> & p2) -> bool {
////            return edges[p1.first][p1.second] <= edges[p2.first][p2.second];
////        }; // lambda is an object.
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> nextq(comp);
//        for (auto dat : edges[K])
//            nextq.push(make_pair(K, dat.first)); // insert only the vertices connected to K.
//
//        while (!nextq.empty()) {
//            //if (q.empty())
//            swap(q, nextq);
//            while (!nextq.empty()) nextq.pop();
////            if (q.empty()) {
////                while (!nextq.empty()) {
////                    q.push(nextq.top());
////                    nextq.pop();
////                }
////            }
//            while (!q.empty()) {
//                pair<int, int> t = q.top(); q.pop();
//                int u = t.first, v = t.second;
//                if (dist[v] == INF) {
//                    for (auto dat : edges[v]) {
//                        nextq.push(make_pair(v, dat.first)); // add edges and sort it.
//                    }
//                }
//                int alt = dist[u] + edges[u][v];
//                if (dist[v] > alt) {
//                    if (dist[v] < INF) {
//                        sum -= dist[v];
//                    }
//                    sum += alt;
//                    dist[v] = alt;
//                    prev[v] = u;
//                }
//            }
//        }
//
//        for (auto dat : dist) cout << dat << endl;
//        return sum;
//
////        auto test = find_if(dist.begin(), dist.end(), [&](int d) {
////            return d == INF;
////        });
////        if (test == dist.end())
////            return sum;
////        else return -1;
//    }
    
    
    
//    int networkDelayTime(vector<vector<int>> & times, int N, int K) {
////        sort(times.begin(), times.end(), [&](vector<int> & v1, vector<int> & v2) -> bool {
////            return v1[2] < v2[2]; // sort by weights.
////        });
//        // MST algorithm
//        auto comp = [&](vector<int> & v1, vector<int> & v2) -> bool {
//            return v1[2] < v2[2];
//        };
//        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q(comp);
//        unordered_set<int> set;
//        vector<bool> visited(N, false);
//
//        for(auto dat : times) q.push(dat);
//        // check if both of the vertex are in the set.
//
//        while (!q.empty()) {
//            vector<int> e(q.top());
//            q.pop();
//
//            int src = e[0], dest = e[1], weight = e[2];
//            if (set.find(e[1]) != set.end()) continue; // it makes a cycle.
//            //if (visited[src] && visited[dest]) continue; // it makes a cycle.
//
//            set.insert(e[1]);
//
//
//
//
//            //if (visited[e])
//
//
//
//
//
//
//        }
//
//
//
//
//
//
//
//
//
//
//
//        return 0;
//    }
    

//    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//        // times[i][0] = src, times[i][1] = dest, times[i][2] = weight;
//        unordered_map<int, unordered_map<int, int>> connected;
//
////        auto comp = [&](pair<int, int> & p1, pair<int, int> & p2) {
////            return connected[p1.first][p1.second] < connected[p2.first][p2.second];
////        };
//
//        auto comp = [&](int a, int b) -> bool {
//            return false;
//            //return connected[a][2] < connected[b][2];
//        };
//        //priority_queue<int, vector<int>, decltype(comp)> q(comp);
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
//        //unordered_map<int, vector<int>> connected;
//        vector<bool> visited(N, false); // vector init.
//        int sum = 0;
//
//        // init.
//        // connection hash map.
//        for (int i = 0; i < times.size(); ++i) {
//            int src = times[i][0] - 1;
//            int dest = times[i][1] - 1;
//            int weight = times[i][2];
//            if (connected.find(src) == connected.end())
//                connected[src] = unordered_map<int, int>();
//                //connected[times[i][0]] = vector<int>();
////            if (src == K - 1) {
////                q.push(dest); // destination push.
////            }
//            connected[src][dest] = weight;
//            //connected[times[i][0]].push_back(times[i][1]); // push the destination.
//        }
//        q.push(K - 1);
//
//
//        while (!q.empty()) {
//            int src = q.top(); q.pop();
//            for (auto it : connected[src]) {
//                int dest = it.first;
//                if (!visited[dest]) {
//                    visited[dest] = true;
//                    sum += connected[src][dest];
//                    q.push(dest);
//                }
//            }
//        }
//        auto allVisited = find_if(visited.begin(), visited.end(), [](bool t) {
//            return t == false;
//        });
//        if (allVisited == visited.end()) return sum;
//        return -1;
//    }
};

int main() {
    Solution obj = Solution();
    vector<vector<int>> ndt1 {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    vector<vector<int>> ndt2 {
        {0, 1, 4},
        {0, 2, 3},
        {1, 3, 1},
        {1, 4, 3},
        {2, 4, 11},
        {2, 5, 8},
        {4, 5, 1},
        {4, 6, 9},
        {5, 6, 1},
    };
    
    int N = 4;
    int K = 2;
    //cout << obj.networkDelayTime(ndt1, N, K) << endl;
    
    cout << obj.networkDelayTime(ndt2, 7, 0) << endl;
    
//
//    queue<int> q1, q2;
//    q1.push(10);
//    q1.push(20);
//    q1.push(30);
//    q2.push(60);
//    q2.push(70);
//    q2.push(80);
//
//
//    swap(q1, q2);
//
//    cout << "q1" << endl;
//    while (!q1.empty()) {
//        cout << q1.front() << endl;
//        q1.pop();
//    }
//
//    cout << "q2" << endl;
//    while (!q2.empty()) {
//        cout << q2.front() << endl;
//        q2.pop();
//    }
    
    
    
    
    return 0;
}

