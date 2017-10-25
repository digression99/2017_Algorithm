/*
algospot_TRIANGLEPATH
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int triangle[101][101];
int memo[101][101];

int exhaustive(int row, int col, int n) {
    // base case
    if (row >= n || col >= n) return 0;
    
    int mx = 0;
    for (int i = col; i < n; ++i) {
        mx = max(exhaustive(row + 1, col, n), exhaustive(row + 1, col + 1, n));
    }
    return mx + triangle[row][col];
}

int dp(int row, int col, int n) {
    int & ret = memo[row][col];
    
    if (ret != -1) return ret;
    if (row >= n || col >= n) return ret = 0;
    
    return ret = (max(dp(row + 1, col, n), dp(row + 1, col + 1, n)) + triangle[row][col]);
}

void getPath(vector<pair<int, int> > & v, int n) {
    v.push_back(make_pair(0, 0));
    
    int i = 2, x = max(memo[1][0], memo[1][1]) == memo[1][0] ? 0 : 1;
    while (i <= n - 1) {
        x = max(memo[i][x], memo[i][x + 1]) == memo[i][x] ? x : x + 1;
        v.push_back(make_pair(i, x));
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    
    cout << dp(0, 0, n) << endl;
    
    vector<pair<int, int> > pathVec;
    getPath(pathVec, n);
    
    for (auto dat : pathVec)
        cout << dat.first << " " << dat.second << endl;
    
    //cout << exhaustive(0, 0, n) << endl;

    return 0;
    
}

