// leet_697

class Solution {
public:
    
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() < 2) return 1;
        unordered_map<int, int> hash;
        int maxFreq = 0;
        for_each(nums.begin(), nums.end(), [&](int dat) {
            if (hash.find(dat) != hash.end()) {
                hash[dat]++;
            }
            else {
                hash[dat] = 1;
            }
            maxFreq = max(maxFreq, hash[dat]);
        });
        vector<int> maxFreqVec;
        int minLen = 99999;
        
        for_each(hash.begin(), hash.end(), [&](const pair<int, int> & dat)  {
            if (dat.second == maxFreq) {
                minLen = min(minLen, [&](int tgt) -> int {
                    int firstNum = -1, lastNum = -1;
                    for (int i = 0; i < nums.size(); ++i) {
                        if (nums[i] == tgt) {
                            if (firstNum == -1) {
                                firstNum = lastNum = i;
                            } else {
                                lastNum = i;
                            }
                        }
                    }
                    return lastNum - firstNum + 1;
                }(dat.first));
            }
        });
        return minLen;
    }
};
