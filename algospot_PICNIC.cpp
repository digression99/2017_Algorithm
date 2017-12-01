/*

test case
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

result
1
3
4
 */

#include <iostream>
#include <cstring>
using namespace std;

int n;
const int MAXN = 10;
bool isFriend[MAXN][MAXN];
bool isVisited[MAXN];

int nextPick(int start) {
    for (int i = start + 1; i < n; ++i)
        if (!isVisited[i]) return i;
    return -1;
}

int exhaustive(int start, int cnt) {
    // base case
    if (start == -1) {
        if (cnt == n) return 1;
        else if (cnt > 0) return 0;
    }
    
    int res = 0;
    
    for (int i = start + 1; i < n; ++i) {
        if (start == -1) {
            res += exhaustive(i, 0);
        } else if (isFriend[start][i] && !isVisited[i]) {
            isVisited[start] = isVisited[i] = true;
            res += exhaustive(nextPick(start), cnt + 2);
            isVisited[start] = isVisited[i] = false;
        }
    }
    return res;
}


int main() {
    int tc, m;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        memset(isFriend, false, sizeof(isFriend));
        memset(isVisited, false, sizeof(isVisited));
        
        cin >> n >> m;
        for (int j = 0; j < m; ++j) {
            int f, b;
            cin >> f >> b;
            isFriend[b][f] = isFriend[f][b] = true;
        }
        // -1 : start num.
        cout << exhaustive(-1, 0) << endl;
    }
    
    return 0;
}

