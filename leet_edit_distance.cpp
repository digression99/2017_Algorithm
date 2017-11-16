
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;


class Solution {
public:
    static const int MAXLEN = 1000;
    int memo[MAXLEN + 1][MAXLEN + 1];
    int minDistExhaustive(string w1, string w2, int w1Idx, int w2Idx) {
        // base case
        if (w1Idx == w1.length()) return 0;
        if (w2Idx == w2.length()) {
            return int(w1.length() - w2.length());
        }
        int ret = 9999;
        
        if (w1[w1Idx] == w2[w2Idx]) {
            ret = min(ret, minDistExhaustive(w1, w2, w1Idx + 1, w2Idx + 1)); // no step.
        } else {
            // replace
            char temp = w2[w2Idx];
            w2[w2Idx] = w1[w1Idx];
            ret = min(ret, minDistExhaustive(w1, w2, w1Idx + 1, w2Idx + 1) + 1);
            w2[w2Idx] = temp;
            // insert
            ret = min(ret, minDistExhaustive(w1, w1[w1Idx] + w2, w1Idx + 1, w2Idx + 1) + 1);
        }
        return ret;
    }
    int minDistance(string word1, string word2) {
        memset(memo, -1, sizeof(memo));
        if (word1.length() < word2.length()) swap(word1, word2);
        
        //string minStr = word1.length() < word2.length() ? word1 : word2;
        //string maxStr = word1.length() < word2.length() ? word2 : word1;
        //return minDistExhaustive(maxStr, minStr, 0, 0);
        //return minDistExhaustive(word1, word2, 0, 0);
        return minDistDp(word1, word2, 0, 0);
    }
    
    int minDistDp(string w1, string w2, int w1Idx, int w2Idx) {
        
        if (w1Idx == w1.length()) return 0;
        
        int & ret = memo[w1Idx][w2Idx];
        if (ret != -1) return ret;
        
        if (w2Idx == w2.length()) {
            return ret = int(w1.length() - w2.length());
        }
        
        //int & ret = memo[w1Idx][w2Idx];
        //if (ret != -1) return ret;
        
        ret = 9999;
        
        if (w1[w1Idx] == w2[w2Idx]) {
            ret = min(ret, minDistDp(w1, w2, w1Idx + 1, w2Idx + 1)); // no step.
        } else {
            // replace
            char temp = w2[w2Idx];
            w2[w2Idx] = w1[w1Idx];
            ret = min(ret, minDistDp(w1, w2, w1Idx + 1, w2Idx + 1) + 1);
            w2[w2Idx] = temp;
            // insert
            ret = min(ret, minDistDp(w1, w1[w1Idx] + w2, w1Idx + 1, w2Idx + 1) + 1);
        }
        return ret;
    }
};

int main() {
    Solution obj;
    string str1 = "abcdefg";
    string str2 = "abcd";
    string str3 = "efg";
    cout << obj.minDistance(str1, str3) << endl;
    
    return 0;
}
