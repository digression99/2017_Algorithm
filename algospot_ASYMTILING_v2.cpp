#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int MOD = 1000000007;
long long tilingMemo[MAXN + 1];
long long asymTilingMemo[MAXN + 1];

long long tilingExhaustive(int nowNum) {
    if (nowNum == 0 || nowNum == 1) return 1; // if the tiling is perfect
    else if (nowNum < 0) return 0;
    return (tilingExhaustive(nowNum - 1) + tilingExhaustive(nowNum - 2)) % MOD;
}

long long asymTilingExhaustive(int nowNum) {
    //if (nowNum == 2) return 2;
    if (nowNum == 0 || nowNum == 1) return 1; // if the asym tiling is perfect.
    else if (nowNum < 0) return 0;
    return (asymTilingExhaustive(nowNum - 2) + asymTilingExhaustive(nowNum - 4)) % MOD;
}


long long tilingDp(int nowNum) {
    if (nowNum == 0) return 1;
    else if (nowNum < 0) return 0;

    long long & ret = tilingMemo[nowNum];
    if (ret != -1) return ret;

    return ret = (tilingDp(nowNum - 1) + tilingDp(nowNum - 2) + MOD) % MOD;

    //ret = tilingDp(nowNum - 1) % MOD;
    //return ret += tilingDp(nowNum - 2) % MOD;
}

long long asymTilingDp(int nowNum) {
    if (nowNum == 2) return 2;
    if (nowNum < 0) return 0;
    if (nowNum == 0 || nowNum == 1) return 1;
    
    long long & ret = asymTilingMemo[nowNum];
    if (ret != -1) return ret;



    // ret = asymTilingDp(nowNum - 2) % MOD;
    // return ret += asymTilingDp(nowNum - 4) % MOD;

    return ret = (asymTilingDp(nowNum - 2) + asymTilingDp(nowNum - 4) + MOD) % MOD;
}

int main()
{
    int tc;
    cin >> tc;
    cout << "tc : " << tc << endl;

    for (int i = 0; i < tc; ++i) {
        int n;
        cin >> n;
        memset(tilingMemo, -1, sizeof(tilingMemo));
        memset(asymTilingMemo, -1, sizeof(asymTilingMemo));
        //cout << tilingExhaustive(n) - asymTilingExhaustive(n) << endl;
        cout << tilingDp(n) << endl;// - asymTilingDp(n) << endl;
        cout << asymTilingDp(n) << endl;
    }

    return 0;
}

