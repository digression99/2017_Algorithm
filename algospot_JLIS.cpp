// tc
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

// res
//5
//6
//5

#include <vector>
#include <iostream>
#include <limits>
using namespace std;

const int MAXN = 100;
const long long NEGINF = numeric_limits<long long>::min();

int memo[MAXN + 1][MAXN + 1];

int dp(vector<int> & A, vector<int> & B, int k, int l) {
    int & ret = memo[k + 1][l + 1];
    if (ret != -1) return ret;
    
    ret = 2; // basic length starts from 2
    
    // key idea : you choose the next big number than both of A[k], B[l].
    long long a = (k == -1 ? NEGINF : A[k]);
    long long b = (l == -1 ? NEGINF : B[l]);
    long long mx = max(a, b);
    
    for (int i = k + 1; i < A.size(); ++i) {
        if (mx < A[i]) ret = max(ret, dp(A, B, i, l) + 1);
    }
    for (int i = l + 1; i < B.size(); ++i) {
        if (mx < B[i]) ret = max(ret, dp(A, B, k, i) + 1);
    }
    return ret;
}

int exhaustive(vector<int> & A, vector<int> & B, int k, int l) {
    // A.size() == n, B.size() == m,
    // k : pos of A, l : pos of B
    
    // base case. you reached the end of both seq.
    if (k >= A.size() - 1 || l >= B.size() - 1) return 0;
    
    int maxLen = 2;
    
    if (A[k] == B[l]) {
        for (int i = k + 1; i < A.size(); ++i) {
            if (B[l] < A[i]) {
                maxLen = max(maxLen, exhaustive(A, B, i, l));
            }
        }
        
        for (int i = l + 1; i < B.size(); ++i) {
            if (A[k] < B[i]) {
                maxLen = max(maxLen, exhaustive(A, B, k, i));
            }
        }
    }
    
    
    return maxLen;
}

int main() {
    
    int tc, n, m, t;
    vector<int> A, B;//A = {-1}, B = {-1};
    
    cin >> tc;
    
    for (int i = 0; i < tc; ++i){
        
        cin >> n >> m;
        for (int j = 0; j < n; ++j) {
            cin >> t;
            A.push_back(t);
        }
        for (int j = 0; j < m; ++j) {
            cin >> t;
            B.push_back(t);
        }
        
        memset(memo, -1, sizeof(memo));
        cout << dp(A, B, -1, -1) - 2 << endl;
        
        //cout << exhaustive(A, B, 0, 0) << endl;
        A.clear();
        B.clear();
        //A.push_back(-1);
        //B.push_back(-1);
    }
    
    return 0;
}

