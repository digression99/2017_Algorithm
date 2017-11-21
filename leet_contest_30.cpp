//
// leet 560
//
//
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

static const int MAXN = 20000;
int sumMemo[MAXN + 1];
class Solution {
public:
    int dp(vector<int> & nums, int end) {
        if (end == -1) return 0;
        int & ret = sumMemo[end];
        if (ret != -1) return ret;
        return ret = nums[end] + dp(nums, end - 1);
    }
    
    int subarraySum(vector<int>& nums, int k) {
        memset(sumMemo, -1, sizeof(sumMemo));
        int res = 0;
        sumMemo[0] = nums[0];
        
        for (int i = -1; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (dp(nums, j) - dp(nums, i) == k)
                    ++res;
            }
        }
        return res;
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int> > res;
        int nowCol = (int)nums.size(), nowRow = (int)nums[0].size();
        if (nowCol * nowRow != r * c) return nums;
        int k = 0, l = 0;
        
        for (int i = 0; i < r; ++i)
            res.push_back(vector<int>(c));
        
        for (int i = 0; i < nowCol; ++i) {
            for (int j = 0; j < nowRow; ++j) {
                res[l][k] = nums[i][j];
                if (k < c - 1) {
                    ++k;
                } else {
                    ++l;
                    k = 0;
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution obj = Solution();
    
    vector<vector<int> > mat = {
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30},
    };
    obj.matrixReshape(mat, 2, 15);
//
//    vector<int> nums1 ={2, 4, 1, 3, -1, 7, 3, 2};
//    int k1 = 8;
//    vector<int> nums2 = {-77,74,-54,-24,-50,62,-18,89,75,54,-31};
//    int k2 = 100;
//    vector<int> nums3 = {1, 1, 1};
//    int k3 = 2;
    //cout << obj.subarraySum(nums2, k2) << endl;
    //cout << obj.subarraySum(nums3, k3) << endl;
    
    

    return 0;
}



