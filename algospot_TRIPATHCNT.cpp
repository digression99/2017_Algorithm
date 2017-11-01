//
// algospot_TRIPATHCNT
// down or down-right.

//test case
//4
//9
//5 7
//1 3 2
//3 5 5 6

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int getMaxMemo[MAXN + 1][MAXN + 1];
int getPathMemo[MAXN + 1][MAXN + 1];
int triangle[MAXN + 1][MAXN + 1];
int n;
int target;

int exhaustiveGetMax(int lev, int pos) {
    
    // base case
    if (lev >= n) return triangle[lev - 1][pos];
    return max(exhaustiveGetMax(lev + 1, pos), exhaustiveGetMax(lev + 1, pos + 1)) + triangle[lev - 1][pos];
}

int dpGetMax(int lev, int pos) {
    
    // base case
    if (lev >= n) return triangle[lev - 1][pos];
    
    // memo check
    int & ret = getMaxMemo[lev - 1][pos];
    if (ret != -1) return ret;
    
    return ret = max(dpGetMax(lev + 1, pos), dpGetMax(lev + 1, pos + 1)) + triangle[lev - 1][pos];
}

int exhaustiveGetPath(int lev, int pos) {
    
    // base case
    if (lev >= n - 1) return 1;
    
    if (getMaxMemo[lev + 1][pos] == getMaxMemo[lev + 1][pos + 1])
        return exhaustiveGetPath(lev + 1, pos) + exhaustiveGetPath(lev + 1, pos + 1);
    else if (getMaxMemo[lev + 1][pos] < getMaxMemo[lev + 1][pos + 1])
        return exhaustiveGetPath(lev + 1, pos + 1);
    else
        return exhaustiveGetPath(lev + 1, pos);
}

int dpGetPath(int lev, int pos) {
    
    // base case
    if (lev >= n - 1) return 1;
    
    // memo check
    int & ret = getPathMemo[lev - 1][pos];
    if (ret != -1) return ret;
    
    if (getMaxMemo[lev + 1][pos] == getMaxMemo[lev + 1][pos + 1])
        return ret = dpGetPath(lev + 1, pos) + dpGetPath(lev + 1, pos + 1);
    else if (getMaxMemo[lev + 1][pos] < getMaxMemo[lev + 1][pos + 1])
        return ret = dpGetPath(lev + 1, pos + 1);
    else
        return ret = dpGetPath(lev + 1, pos);
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }
    memset(getMaxMemo, -1, sizeof(getMaxMemo));
    memset(getPathMemo, -1, sizeof(getPathMemo));
    
    cout << dpGetMax(1, 0) << endl;
    //cout << exhaustiveGetPath(1, 0);
    cout << dpGetPath(1, 0) << endl;
    
    //int target = exhaustiveGetMax(1, 0);
    //cout << endl << target << endl;
    //cout << exhaustiveGetPath(1, 0) << endl;
    
    return 0;
}
