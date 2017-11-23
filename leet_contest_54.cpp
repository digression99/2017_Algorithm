#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int ret = 0, pos = 0, count = 1;
        
        while (pos < s.length() - 1) {
            if (s[pos + 1] == s[pos]) {
                ++count;
            }
            if (s[pos + 1] != s[pos]) {
                
                
            
                
                
                
                
                
            }
            
            
            ++pos;
        }
        
        
        
        
        
        
        
        
        while (pos < s.length() - 1) {
            int start = pos + 1;
            
            while (start < s.length()) {
                if (s[start] == s[pos]) {
                    ++count;
                } else {
                    int t = count;
                    while (start < s.length() && t > 0 && s[start++] != s[pos]) {
                        ++ret;
                        --t;
                    }
                    if (t == 0) {
                        pos += count;
                        count = 1;
                    } else {
                        pos += (count + (count - t) - 1);
                        count = (count - t);
                    }
                    break;
                }
                ++start;
            }
            //if (start == s.length()) break;
        }
        return ret;
    }
//    int countBinarySubstrings(string s) {
//        if (s.length() == 1) return 0;
//
//        int pos = 0, ret = 0;
//        while (pos < s.length()) {
//            char nowC = s[pos];
//            // start algorithm.
//            int start = pos + 1;
//            int count = 1;
//            while (start < s.length()) {
//                if (s[start] == nowC) {
//                    ++count;
//                    ++start;
//                } else {
//                    int t = count;
//                    while (t--) {
//                        if (s[start] != nowC) {
//                            ++ret;
//                            ++start;
//                        } else break;
//                    }
//                    pos += count;
//                }
//                break;
//            }
//        }
//        return ret;
//    }
    
    int findShortestSubArray(vector<int> & nums) {
        if (nums.size() == 1) return 1;

        unordered_map<int, int> freq; // key : number, value : freq.
        int maxFreq = 1, ret = 1;
        unordered_map<int, int> firstAppear;
        unordered_map<int, int> lastAppear;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 1; // freq.
                firstAppear[nums[i]] = i;
                lastAppear[nums[i]] = i;
            } else {
                ++freq[nums[i]];
                lastAppear[nums[i]] = i;
                
                if (maxFreq < freq[nums[i]]) {
                    maxFreq = freq[nums[i]];
                    ret = lastAppear[nums[i]] - firstAppear[nums[i]] + 1;
                } else if (maxFreq == freq[nums[i]]) {
                    ret = min(ret, lastAppear[nums[i]] - firstAppear[nums[i]] + 1);
                }
            }
        }
        return ret;
    }
    
    
//    int findShortestSubArray(vector<int>& nums) {
//        if (nums.size() < 2) return 1;
//        unordered_map<int, int> hash;
//        int maxFreq = 0;
//        for_each(nums.begin(), nums.end(), [&](int dat) {
//            if (hash.find(dat) != hash.end()) {
//                hash[dat]++;
//            }
//            else {
//                hash[dat] = 1;
//            }
//            maxFreq = max(maxFreq, hash[dat]);
//        });
//        vector<int> maxFreqVec;
//        int minLen = 99999;
//
//        for_each(hash.begin(), hash.end(), [&](const pair<int, int> & dat)  {
//            if (dat.second == maxFreq) {
//                minLen = min(minLen, [&](int tgt) -> int {
//                    int firstNum = -1, lastNum = -1;
//                    for (int i = 0; i < nums.size(); ++i) {
//                        if (nums[i] == tgt) {
//                            if (firstNum == -1) {
//                                firstNum = lastNum = i;
//                            } else {
//                                lastNum = i;
//                            }
//                        }
//                    }
//                    return lastNum - firstNum + 1;
//                }(dat.first));
//            }
//        });
//        return minLen;
//    }
};

int main () {
    Solution obj = Solution();
    string str1 = "000011110000";
    string str2 = "010101";
    string str3 = "00000001110000";
    string str4 = "00";
    string str5 = "100111001";
    
//    cout << obj.countBinarySubstrings(str1) << endl;
//    cout << obj.countBinarySubstrings(str2) << endl;
//    cout << obj.countBinarySubstrings(str3) << endl;
    cout << obj.countBinarySubstrings(str4) << endl;
//    cout << obj.countBinarySubstrings(str5) << endl;
    
    
//    vector<int> nums1 = {1, 2, 2, 3, 1};
//
//    cout << obj.findShortestSubArray(nums1) << endl;
    
    
    return 0;
}

