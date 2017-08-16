//
// 20170816
//
// Dictionary words can be used several times. So, you can't delete the words in the dictionary.
// Then how you prevent the time limit??
// -> You should find the longest matched word that is in the dict.
//
// --> I knew this problem related to dp, but I couldn't find out how to
// make the idea, what to save, what to check out, like that.
// I should focus more on dp technique and practice harder.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    
    bool checkLen(string & hash, string & org)
    {
        for (int i = 0; i < hash.length(); ++i)
        {
            if (hash[i] != org[i]) return false;
        }
        
        return true;
    }
    
    bool rec(unordered_map<char, vector<string> *> & hasht, string s)
    {
        if (s.size() == 0) return true;
        
        //int veclen = (int)hasht[s[0]]->size();
        
        for (auto it = hasht[s[0]]->begin(); it != hasht[s[0]]->end();)
        {
            // Be careful not to pass the end().
            string nowStr = *it;
            int stringLen = (int)nowStr.size();
            
            if (checkLen(nowStr, s))
            {
                string nowSubstr = s.substr(stringLen, s.size() - stringLen);
                hasht[s[0]]->erase(it);
                if (rec(hasht, nowSubstr)) return true;
                hasht[s[0]]->push_back(nowStr);
                if ((it + 1) == hasht[s[0]]->end()) it++;
            }
            else it++;
        }
//        
//        for (int i = 0; i < veclen; ++i)
//        {
//            string nowstr = hasht[s[0]]->at(i);
//            int stringLen = (int)nowstr.size();
//            
//            if (checkLen(nowstr, s))
//            {
//                string nowSubstr = s.substr(stringLen, s.size() - stringLen);
//
//                
//                //hasht[s[0]]->erase(i);
//                if (rec(hasht, nowSubstr)) {
//                    return true;
//                }
//                //return rec(hasht, s.substr(stringLen, s.size() - stringLen));
//                //return rec(hasht, s.substr(hasht[s[0]][i].size(), s.size() - hasht[s[0]][i].size()));
//            }
//        }
        
        return false;
    }
    // not mine.
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
    // mine.
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string> *> hasht;
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (hasht.find(s[i]) == hasht.end())
            {
                hasht[s[i]] = new vector<string>;
            }
        }
        
        for (int i = 0; i < wordDict.size(); ++i)
        {
            if (hasht.find(wordDict[i][0]) != hasht.end())
                hasht[wordDict[i][0]]->push_back(wordDict[i]);
        }
        
        return rec(hasht, s);
    }
};

int main()
{
    Solution sol = Solution();
    vector<string> dict;
    
    string s = "leetcode";
    
//    dict.push_back(string("leet"));
//    dict.push_back(string("code"));
    
    dict.push_back(string("leet"));
    dict.push_back(string("cod"));
    dict.push_back(string("le"));
    dict.push_back(string("etco"));
    dict.push_back(string("de"));
    
    cout << sol.wordBreak(s, dict);
    
    return 0;
}
