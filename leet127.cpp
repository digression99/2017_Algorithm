// 20170801

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log","cog"]

//"red"
//"tax"
//["ted","tex","red","tax","tad","den","rex","pee"]
//red tax
//8
//ted
//tex
//red
//tax
//tad
//den
//rex
//pee

// solution from ShadowGiraffe
//int ladderLength(string start, string end, unordered_set<string> &dict)
//{
//    if (dict.empty() || dict.find(start) == dict.end() || dict.find(end) == dict.end())
//        return 0;
//    
//    queue<string> q;
//    q.push(start);
//    unordered_map<string, int> visited;  // visited track the distance
//    visited[start] = 1;
//    unordered_set<string> unvisited = dict;  // unvisited prevent searching through the whole dict
//    unvisited.erase(start);
//    
//    while (!q.empty()) {
//        string word = q.front(); q.pop();
//        auto itr = unvisited.begin();
//        while (itr != unvisited.end()) {
//            string adjWord = *itr;
//            if (oneCharDiff(word, adjWord)) {
//                visited[adjWord] = visited[word] + 1;
//                if (adjWord == end)
//                    return visited[adjWord];
//                itr = unvisited.erase(itr);  // tricky here
//                q.push(adjWord);
//            }
//            else
//                ++itr;
//        }
//    }
//    return 0;
//}
//
//inline bool oneCharDiff(const string& str1, const string& str2)
//{
//    int diff = 0;
//    for (int i = 0; i < str1.size(); ++i)  {
//        if (str1[i] != str2[i])
//            ++diff;
//        if (diff > 1)
//            return false;  // perhaps quicker
//    }
//    return diff == 1;
//}

class Solution {
public:
    int nowMin;
    bool checkMatch(string & a, string & b)
    {
        bool check = false;
        // the length of both strings are same.
        for (int i = 0; i < a.length(); ++i)
        {
            if (a[i] - b[i])
            {
                if (check) return !check; // return false
                // 두번째 다르면 false.
                check = !check;
            }
        }
        return check; // return true
    }
    
    void makeHasht(vector<string> & wl, map<int, vector<int> > & hasht)
    {
        for (int i = 0; i < wl.size(); ++i)
        {
            for (int j = 0; j < wl.size(); ++j)
            {
                if (i == j) continue;
                if (checkMatch(wl[i], wl[j]))
                {
                    hasht[i].push_back(j);
                }
            }
        }
    }
    
    void sol(map<int, vector<int> > & hasht, vector<bool> & mark, int nowPos, int nowLength, vector<int> & res)
    {
        if (nowLength >= nowMin)
            return;
        
        if (nowPos == 0)
        {
            if (nowMin > nowLength)
                nowMin = nowLength;
            
            res.push_back(nowLength);
            return;
        }
        
        for (int i = 0; i < hasht[nowPos].size(); ++i)
        {
            if (!mark[hasht[nowPos][i]])
            {
                mark[hasht[nowPos][i]] = true;
                sol(hasht, mark, hasht[nowPos][i], nowLength + 1, res);
                mark[hasht[nowPos][i]] = false;
            }
        }
        return;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<int, vector<int> > hasht;
        vector<bool> mark;
        vector<int> res;
        
        nowMin = 9999;
        
        // set beginWord to the front of the wordList
        // and the endWord to the end of the wordList
        
        for (auto it = wordList.begin(); it != wordList.end(); ++it)
            if (*it == beginWord)
            {
                wordList.erase(it);
                break;
            }
        wordList.insert(wordList.begin(), beginWord);
        
        auto it = wordList.begin();
        for (; it != wordList.end(); ++it)
        {
            if (*it == endWord)
            {
                wordList.erase(it);
                wordList.push_back(endWord);
                break;
            }
        }
        if (it == wordList.end()) return 0;
        
        // set the mark array
        mark.resize(wordList.size());
        for (int i = 0; i < mark.size(); ++i) mark[i] = false;
        for (int i = 0; i < wordList.size(); ++i) {
            hasht[i] = *new vector<int>;
            hasht[i].clear();
        }
        
        makeHasht(wordList, hasht);
        
        sol(hasht, mark, (int)hasht.size() - 1, 0, res);
        
        if (res.size() == 0)
            return 0;
        else
            return *(min_element(res.begin(), res.end())) + 1;
    }
};



int main()
{
    Solution c;
    string t1, t2, t;
    vector<string> wl;
    int n = 0;
    
    cin >> t1 >> t2;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        wl.push_back(t);
    }
    cout << c.ladderLength(t1, t2, wl);
    return 0;
}
