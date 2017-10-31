//
// algospot_TILING2
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100;
int memo[MAXN + 1];
int exhaustive(int n) {
    
    // base case
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int res = 0;
    res = exhaustive(n - 1) + exhaustive(n - 2);
    return res;
}

int dp(int n) {
    int & res = memo[n];
    if (res != -1) return res;
    
    // base case
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    return res = (dp(n - 1) + dp(n - 2)) % MOD;
}

int main() {
    
    //cout << exhaustive(10) << endl;
    memset(memo, -1, sizeof(memo));
    cout << dp(100) << endl;
    
    return 0;
}

