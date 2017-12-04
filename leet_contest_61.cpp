

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

class Solution {
public:
    static const int MAXN = 30000 + 1;
    int memo[MAXN]; // 메모가 너무 크다.
    vector<int> res;
    
    int findNext(vector<int> & temp, int idx, int target) {
        int & ret = memo[idx];
        // base case
        if (idx + 1 == temp.size()) return ret = 0;
        if (temp[idx + 1] > target) return ret = 1;
        
        if (ret == -1)
            ret = findNext(temp, idx + 1, temp[idx + 1]);
        if (ret == 0) return 0;
        int next = findNext(temp, idx + ret, target);
        if (next == 0) return 0;
        else return ret + next;
    }
    
    int findNext2(vector<int> & temp, int idx, int target) {
        int & ret = memo[idx];
        // base case
        if (idx == temp.size() || temp[idx] > target) return ret = 0;
        ret = findNext(temp, idx + 1, temp[idx + 1]);
        if (ret > 0)
        
        if (ret == -1)
            ret = findNext(temp, idx + 1, temp[idx + 1]);
        if (ret == 0) return 0;
        int next = findNext(temp, idx + ret, target);
        if (next == 0) return 0;
        else return ret + next;
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), -1);
        memset(memo, -1, sizeof(memo));
        
        for (int i = 0; i < temperatures.size(); ++i) {
            res[i] = findNext(temperatures, i, temperatures[i]);
        }
        
        return res;
    }
};

int main() {
    Solution obj = Solution();
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res;
    // result1 : 1, 1, 4, 2, 1, 1, 0, 0
    //res = obj.dailyTemperatures(temperatures1);
//    for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
    
    vector<int> temp2 = {55,38,53,81,61,93,97,32,43,78};
    res = obj.dailyTemperatures(temp2);
    for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
    // res : [3,1,1,2,1,1,0,1,1,0]
    
    
    return 0;
}
