
/*
test case
3
8 6
5 1 6 4 3 2 8 7
8 4
2 1 4 3 6 5 8 7
8 2
5 6 7 8 1 2 3 4

result
3
1 4 8
4
1 3 6 8
4
5 6 7 8
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2000000000 + 1;
const int MAXN = 500;
int S[MAXN + 1], cacheCnt[MAXN + 1], cacheLen[MAXN + 1];
int n, k;

int lis(int start) {
    int & ret = cacheLen[start + 1];
    if (ret != -1) return ret;
    ret = 1;
    
    for (int i = start + 1; i < n; ++i) {
        if (start == -1 || S[start] < S[i]) {
            ret = max(ret, lis(i) + 1);
        }
    }
    return ret;
}

int count(int start) {
    if (lis(start) == 1) return 1;
    
    int & ret = cacheCnt[start + 1];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = start + 1; i < n; ++i) {
        if ((start == -1 || S[start] < S[i]) && lis(start) == lis(i) + 1) {
            ret = min<long long>(MAX, (long long)ret + count(i));
        }
    }
    return ret;
}

void reconstruct(int start, int skip, vector<int> & klis) {
    if (start != -1) klis.push_back(S[start]);
    
    vector<pair<int, int> > followers;
    
    for (int i = start + 1; i < n; ++i) {
        if ((start == -1 || S[start] < S[i]) && lis(start) == lis(i) + 1) {
            followers.push_back(make_pair(S[i], i));
        }
    }
    sort(followers.begin(), followers.end());
    
    for (int i = 0; i < followers.size(); ++i) {
        int idx = followers[i].second;
        int cnt = count(idx);
        if (cnt <= skip) skip -= cnt;
        else {
            reconstruct(idx, skip, klis);
            break;
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        cin >> n >> k;
        
        memset(S, -1, sizeof(S));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        memset(cacheLen, -1, sizeof(cacheLen));
        
        for (int j = 0; j < n; ++j) {
            cin >> S[j];
        }
//        cout << "max lis len" << endl;
//        cout << lis(-1) - 1 << endl;
//        cout << "count" << endl;
//        for (int j = -1; j < n - 1; ++j) {
//            cout << count(j) << endl;
//        }
        vector<int> klis;
        reconstruct(-1, k - 1, klis);
        cout << cacheLen[0] - 1 << endl;
        for (int i = 0; i < klis.size(); ++i) {
            if (i == klis.size() - 1) cout << klis[i] << endl;
            else cout << klis[i] << " ";
        }
    }
    
    return 0;
}

