#include <iostream>
using namespace std;
#include <vector>

int exhaustive(vector<int> & seq, int pos) {
    
    // base case
    if (pos == seq.size() - 1) {
        return 1;
    }
    
    int maxLen = 0;
    
    // recursive algorithm
    for (int i = pos + 1; i < seq.size(); ++i) {
        if (seq[pos] < seq[i]) {
            maxLen = max(maxLen, exhaustive(seq, i));
        }
    }
    
    // final return
    return maxLen + 1;
}

const int MAXLEN = 100;
int memo[MAXLEN + 1];

int dp(vector<int> & seq, int pos) {

    // memo check
    int ret = memo[pos];
    if (ret != -1) return ret;
    
    // base case
    if (pos == seq.size() - 1)
        return ret = 1;
    
    // recursive algorithm
    int maxLen = 0;
    for (int i = pos + 1; i < seq.size(); ++i) {
        if (seq[pos] < seq[i]) {
            maxLen = max(maxLen, dp(seq, i));
        }
    }
    
    // final return
    return ret = maxLen + 1;
}

int main()
{
    vector<int> v = {-1};
    
    int n, t, tc;
    
    cin >> tc;
    
    for (int i = 0; i < tc; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> t;
            v.push_back(t);
        }
        
        // driver
        memset(memo, -1, sizeof(memo));
        cout << dp(v, 0) - 1 << endl;
        
        v.clear();
        v.push_back(-1);
    }
    
    //cout << exhaustive(v, 0) << endl;
    //cout << exhaustive(v2, 0) << endl;
    //cout << exhaustive(v3, 0) - 1 << endl;
    
    return 0;
}

