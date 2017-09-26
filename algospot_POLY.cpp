//
// stoi -> string to integer?
//
//
//
//
//
//
//
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

const int MAX_SIZE = 101;
int n;
int memo[MAX_SIZE][MAX_SIZE];

int dp(int end, int lastAmount)
{
    if (end == n)
        return 1;
    if (memo[end][lastAmount] > -1)
        return memo[end][lastAmount];
    
    int res = 0;
    for (int i = 1; i + end <= n; ++i) {
        res += (lastAmount + i - 1) * dp(end + i, i); // (a + b - 1) * poly(nextEnd, nextAmount)
    }
    
    memo[end][lastAmount] = res;
    return res;
}

int poly(int n, int lastAmount) {
    if (n == 1) return 1;
    
    if (memo[n][lastAmount] > -1) return memo[n][lastAmount];
    
    int res = 0;
    for (int i = 1; n - i > 0; ++i)
    {
        res += (lastAmount + i - 1) * poly(n - i, i);
    }
    return memo[n][lastAmount] = res;
}

int main()
{
    int tc;
    
    cin >> tc;
    
    for (int i = 0; i < tc; ++i)
    {
        cin >> n;
        memset(memo, -1, sizeof(memo));
        cout << poly(n + 1, 1) << endl;
        //n += 1;
        //dp(1, 1);
        //cout << memo[1][1] << endl;
        //cout << dp(1, 1) - 1 << endl;
    }
    
    return 0;
}


