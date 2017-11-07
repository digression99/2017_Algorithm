
//test case
//2
//6 10
//laptop 4 7
//camera 2 10
//xbox 6 6
//grinder 4 7
//dumbell 2 5
//encyclopedia 10 4
//6 17
//laptop 4 7
//camera 2 10
//xbox 6 6
//grinder 4 7
//dumbell 2 5
//encyclopedia 10 4
//
//results
//24 3
//laptop
//camera
//grinder
//30 4
//laptop
//camera
//xbox
//grinder

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int MAXW = 1000;

int weights[MAXN + 1], values[MAXN + 1];
string names[MAXN + 1];
bool checked[MAXN + 1];
int N, W;
int memo[MAXW + 1][MAXN + 1];
int idxMemo[MAXN + 1];

int exhaustive(int nowW) {
    if (nowW == W) return 0;
    int maxValue = 0;
    
    for (int i = 0; i < N; ++ i) {
        if (!checked[i] && nowW + weights[i] <= W) {
            checked[i] = true;
            maxValue = max(maxValue, values[i] + exhaustive(nowW + weights[i]));
            //swap(names[i], names[0]);
            checked[i] = false;
        }
    }
    return maxValue;
}

// my solution
int dp(int nowW, int start) {
    if (nowW >= W || start >= N) return 0;
    int & ret = memo[nowW][start + 1];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i = start + 1; i < N; ++i) {
        if (start == -1 || nowW + weights[i] <= W)
            ret = max(ret, max(dp(nowW + weights[i], i) + values[i], dp(nowW, i)));
    }
    return ret;
}

// jmb solution
int pack(int nowW, int start) {
    if (start == N) return 0;
    int & ret = memo[nowW][start];
    if (ret != -1) return ret;
    
    ret = pack(nowW, start + 1); // not taking this item.
    
    if (nowW >= weights[start])
        ret = max(ret, pack(nowW - weights[start], start + 1) + values[start]);
    
    return ret;
}

void reconstruct(int nowW, int start, vector<string> & picked) {
    // base case
    if (start == N) return;
    
    if (pack(nowW, start) == pack(nowW, start + 1)) {
        reconstruct(nowW, start + 1, picked);
    } else {
        picked.push_back(names[start]);
        reconstruct(nowW - weights[start], start + 1, picked);
    }
}

//int exhaustive(int nowW, int start) {
//    if (nowW == W) return 0;
//    int maxValue = 0;
//
//    for (int i = start; i < N; ++ i) {
//        if (start == -1 || nowW + weights[i] <= W) {
//            maxValue = max(maxValue, values[i] + exhaustive(nowW + weights[i], i));
//        }
//    }
//    return maxValue;
//}

int main() {
    int tc;
    vector<string> picked;
    cin >> tc;
    
    for (int i = 0 ; i < tc; ++i) {
        cin >> N >> W;
        for (int j = 0; j < N; ++j) {
            cin >> names[j] >> weights[j] >> values[j];
        }
        memset(checked, 0, sizeof(checked));
        memset(memo, -1, sizeof(memo));
        //cout << exhaustive(0) << endl;
        //cout << dp(0, -1) << endl;
        cout << pack(W, 0);
        reconstruct(W, 0, picked);
        cout << " " << picked.size() << endl;
        for (auto dat : picked) cout << dat << endl;
        
        picked.clear();
    }
    
    return 0;
}

