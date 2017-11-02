#include <iostream>
using namespace std;

int exhaustive(int remain, int nowNum) {
    if (remain == 0) return 1;
    
    int tot = 0;
    for (int i = 1; i <= remain; ++i) {
        tot += (nowNum + i - 1) * exhaustive(remain - i, i);
    }
    return tot;
}

const int MAXN = 100;
const int MOD = 10000000;
int memo[MAXN + 1][MAXN + 1];
int n = 0;


int dp(int remain, int nowNum) {
    if (remain == 0) return 1;
    
    int & ret = memo[remain][nowNum];
    if (ret != -1) return ret;
    
    ret = 0;
    
    if (remain == n) {
        for (int i = 1; i <= remain; ++i) {
            ret += dp(remain - i, i);
            ret %= MOD;
        }
    } else {
        for (int i = 1; i <= remain; ++i) {
            ret += (nowNum + i - 1) * dp(remain - i, i);
            ret %= MOD;
        }
    }
    return ret;
}

int cache[101][101];
int poly(int n, int first) {
    
    if (n == first) return 1;
    int & ret = cache[n][first];
    if (ret != -1) return ret;
    ret = 0;
    for (int second = 1; second <= n - first; ++second) {
        int add = second + first - 1;
        add *= poly(n - first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    
    return ret;
}

int main() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n;
        
        memset(memo, -1, sizeof(memo));
        //memset(cache, -1, sizeof(cache));
        
        //cout << poly(n + 1, 0) << endl;
        cout << dp(n, 1) << endl;
    }
    
    return 0;
}

