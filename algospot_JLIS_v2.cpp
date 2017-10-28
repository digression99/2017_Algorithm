/*
 algospot_JLIS
 
 vector reserve : you reserve memory areas and not actually add data.
 vector resize : you actually add data and initialize it.
 vector size :  number of actually added data.
 vector capacity : the maximum capacity that can add data without extra memory reallocation.
 
 so, if you want to add data with push_back(), then use reserve.
 it will prevent any extra memory realloc.
 if you want to set data with vector[], then use resize.

 */

//testcase
//3
//3 3
//1 2 4
//3 4 7
//3 3
//1 2 3
//4 5 6
//5 3
//10 20 30 1 2
//10 20 30

#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;
int memo[MAX_SIZE + 1][MAX_SIZE + 1];

int dp(vector<int> & A, vector<int> & B, int idxA, int idxB) {
    
    int & ret = memo[idxA][idxB];
    if (ret != -1) return ret;
    
    int mxNum = max(A[idxA], B[idxB]);
    
    ret = 2;
    
    // how can you figure out in for_each what index you are working in?
    for (int i = idxA + 1; i < A.size(); ++i) {
        if (mxNum < A[i]) ret = max(ret, dp(A, B, i, idxB) + 1);
    }
    for (int i = idxB + 1; i < B.size(); ++i) {
        if (mxNum < B[i]) ret = max(ret, dp(A, B, idxA, i) + 1);
    }
    
    return ret;
}

int main() {
    
    int tc, n, m, t;
    vector<int> A, B;
    
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n >> m;
        A.reserve(n + 1);
        B.reserve(m + 1);
        
        // dummy data.
        A.push_back(-1);
        B.push_back(-1);
        
        for (int j = 0; j < n; ++j) {
            cin >> t;
            A.push_back(t);
        }
        for (int j = 0; j < m; ++j) {
            cin >> t;
            B.push_back(t);
        }
        memset(memo, -1, sizeof(memo));
        
        cout << dp(A, B, 0, 0) - 2<< endl;
        
        A.clear();
        B.clear();
    }
    
    
    
    return 0;
}

