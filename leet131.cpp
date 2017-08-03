/*
 20170803
 
 - 쓸데없이 substr을 낭비하지 말자.
 - 꼭 필요할 때만 라이브러리 함수를 쓰고,
 웬만하면 index를 기반으로 한 알고리즘으로 극복하려고 애써보자.
 - 따라서, 항상 코드를 최적화하려고 신경쓰자. 그 편이 나중에 성능을 따로 신경 쓸 필요가 없어서 좋다.
 
 
 
 */


#include <iostream>
#include <vector>
using namespace std;

// not mine
//class Solution {
//public:
//    vector<vector<string>> partition(string s) {
//        vector<vector<string> > ret;
//        if(s.empty()) return ret;
//        
//        vector<string> path;
//        dfs(0, s, path, ret);
//        
//        for (int i = 0; i < ret.size(); ++i)
//        {
//            for (int j = 0; j < ret[i].size(); ++j)
//            {
//                cout << ret[i][j] << " ";
//            }
//            
//            cout << endl;
//        }
//        
//        return ret;
//    }
//    
//    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
//        if(index == s.size()) {
//            ret.push_back(path);
//            return;
//        }
//        for(int i = index; i < s.size(); ++i) {
//            if(isPalindrome(s, index, i)) {
//                path.push_back(s.substr(index, i - index + 1));
//                dfs(i+1, s, path, ret);
//                path.pop_back();
//            }
//        }
//    }
//    
//    bool isPalindrome(const string& s, int start, int end) {
//        while(start <= end) {
//            if(s[start++] != s[end--])
//                return false;
//        }
//        return true;
//    }
//};

// 굳이 substr을 만들 필요가 없을 때는 만들지 말자.

// mine!!
class Solution
{
public:
    int len;
    
    bool palinCheck(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void findPalin(vector<vector<string> > & res, vector<string> & q, string s, int idx)
    {
        if (idx == len)
        {
            res.push_back(q);
            return;
        }
        
        for (int i = idx; i < len; ++i)
        {
            if (palinCheck(s, idx, i))
            {
                q.push_back(s.substr(idx, i - idx + 1)); // 'a' 하나이든 빈칸이든 중요하지 않다.
                findPalin(res, q, s, i + 1);
                q.pop_back();
            }
        }
    }
    
    vector<vector<string> > partition(string s)
    {
        vector<vector<string> > res;
        vector<string> q;
        
        len = (int)s.length();
        
        findPalin(res, q, s, 0);
        
        for (int i = 0; i < res.size(); ++i)
        {
            for (int j = 0; j < res[i].size(); ++j)
            {
                cout << res[i][j] << " ";
            }
            
            cout << endl;
        }
        
        return res;
    }
};

//class Solution {
//public:
//    
//    bool palinCheck(string & s)
//    {
//        //if (s.length() <= 0) return false;
//        for (int i = 0, j = (int)s.length() - 1; i < j; ++i, --j)
//        {
//            if (s[i] != s[j])
//                return false;
//        }
//        return true;
//    }
//    
//    void findPalin(vector<vector<string> > & res, vector<string> & q, string nows)
//    {
//        if (nows.length() <= 0)
//        {
//            res.push_back(q);
//            return;
//        }
//        
//        for (int i = 1; i <= nows.length(); ++i)
//        {
//            //nows.substr(1, 2); substr(pos, len);
//            string left = nows.substr(0, i);
//            //string right = nows.substr(i, nows.length() - i);
//            
//            // palinCheck에서 굳이 substr을 만들 필요가 없다.
//            if (palinCheck(left))// && palinCheck(right))
//            {
//                q.push_back(left);
//                findPalin(res, q, nows.substr(i, nows.length() - i));
//                q.pop_back();
//                
//                
//                //q.push_back(left);
//                //q.push_back(right);
//                
//                //res.push_back(q);
//                //q.pop_back();
//            }
//            
//            //if (right.length() > 1)
//            //    findPalin(res, q, right);
//        }
//        
//        return;
//    }
//
//    vector<vector<string>> partition(string s) {
//        vector<vector<string> > res;
//        vector<string> q;
//        
//        findPalin(res, q, s);
//        
//        for (int i = 0; i < res.size(); ++i)
//        {
//            for (int j = 0; j < res[i].size(); ++j)
//            {
//                cout << res[i][j] << " ";
//            }
//            
//            cout << endl;
//        }
//        
//        return res;
//    }
//};


int main()
{
    Solution s;
    s.partition("aabaa");
    
    return 0;
}
