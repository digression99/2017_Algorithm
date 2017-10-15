
class Solution {
public:
    int memoLength[50000];
    int memoCheck[50000];
    
    int dp(string & s, int start) {
        
        // basecase
        if (start > (int)s.length() - 1) return 0;
        
        if (s[start] == s[start + 1]) {
            memoLength[start] = dp(s, start + 1);
            //if (!memoCheck[start + 1]) memoLength[start] -= 2;
        } else {
            memoLength[start] = 2;
            memoCheck[start] = true;
            return memoLength[start];
        }
        
        if (start + memoLength[start + 1] + 1 > s.length() - 1) { // if the end reaches the end of the string.
            memoCheck[start] = false;
            memoLength[start] = memoLength[start + 1];
            return memoLength[start];
        }
        
        if (memoCheck[start + 1] == true && (s[start] != s[start + memoLength[start + 1] + 1])) {
            memoCheck[start] = true;
            //memoLength[start] += 2;
        } else {
            //memoLength[start] = memoLength[start + 1] + 2;
            memoCheck[start] = false;
        }
        memoLength[start] += 2;
        
        return memoLength[start];
    }
    
    int countBinarySubstrings(string s) {
        memset(memoLength, -1, sizeof(memoLength));
        memset(memoCheck, -1, sizeof(memoCheck));
        
        for (int i = 0; i < s.length() - 1; ++i) {
            if (memoCheck[i] == -1)
                dp(s, i);
                //dp(s, i, (int)s.length() - 1);
        }
        
        int cnt = 0;
        for (int i = 0; i < s.length() - 1; ++i)
            if (memoCheck[i] == true) cnt++;
        return cnt;
    }
};
