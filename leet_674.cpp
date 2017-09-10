// 20170910

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if (nums.size() < 1) return 0;
        
        int mx = 1;
        int l = 1;
        
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] < nums[i + 1])
            {
                l++;
                mx = std::max(mx, l);
            } else {
                l = 1;
            }
        }

        return mx;
    }
};




int main()
{
    vector<int> n1 = {1, 3, 5, 4, 7};
    vector<int> n2 = {2, 2, 2, 2, 2};
    Solution obj = Solution();
    
    cout << obj.findLengthOfLCIS(n1) << endl;
    cout << obj.findLengthOfLCIS(n2) << endl;
    
    
    
    
    
    return 0;
}
