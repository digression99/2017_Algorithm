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

const int MOD = 1000000007;

int cache[101];

int tiling(int width) {
    if (width <= 1) return 1;
    if (cache[width] != -1) return cache[width];
    
    return cache[width] = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int asymmetric(int width)
{
    if (width % 2) return (tiling(width) - tiling(width / 2) + MOD) % MOD;
    int ret = tiling(width);
    ret = (ret - tiling(width / 2) + MOD) % MOD;
    ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
    return ret;
}

int asymmetric2(int width)
{
    if (width <= 2) return 0;
    
    if (cache[width] != -1) return cache[width];
    
    int ret = asymmetric2(width - 2) % MOD;
    ret = (ret + asymmetric2(width - 4)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    ret = (ret + tiling(width - 3)) % MOD;
    return ret;
}

int main()
{
    int tc = 0;
    
    cin >> tc;
    
    for (int i = 0; i < tc; ++i)
    {
        memset(cache, -1, sizeof(cache));
        int t;
        cin >> t;
        
        tiling(t);
        cout << asymmetric(t) << endl;
    }
    
    return 0;
}
