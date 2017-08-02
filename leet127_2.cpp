#20170802

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// someone else...
//class Solution {
//public:
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//        unordered_set<string> dict(wordList.begin(), wordList.end() );
//        unordered_set<string> set1, set2, *sp, *bp;
//        
//        if (dict.find(endWord) == dict.end()) return 0;
//        
//        int len = 2, cnt = beginWord.size();
//        set1.insert(beginWord);
//        set2.insert(endWord);
//        
//        while (!set1.empty() && !set2.empty()) {
//            if (set1.size() < set2.size()) {
//                sp = &set1;
//                bp = &set2;
//            }
//            else {
//                sp = &set2;
//                bp = &set1;
//            }
//            
//            unordered_set<string> temp;
//            
//            for (auto itr = sp->begin(); itr != sp->end(); itr++) {
//                string word = *itr;
//                //cout << word << endl;
//                dict.erase(word);
//                for (int i = 0; i < cnt; i++) {
//                    char c = word[i];
//                    for (int j = 0; j < 26; j++) {
//                        if ('a' + j == c) continue;
//                        
//                        word[i] = 'a' + j;
//                        //cout << "    " << word << endl;
//                        if (bp->find(word) != bp->end()) return len;
//                        if (dict.find(word) != dict.end()) {
//                            dict.erase(word);
//                            temp.insert(word);
//                        }
//                    }
//                    
//                    word[i] = c;
//                }
//            }
//            swap(*sp, temp);
//            
//            len++;
//            
//        }
//        
//        return 0;
//    }
//};


// mine
class Solution {
public:
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
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // check if there is endWord in the list.
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        deque<string> q;
        q.push_back(beginWord);
        int len = 1;
        int orgSize = 0;
        
        while (!q.empty())
        {
            orgSize = (int)q.size();
            auto it = wordList.begin();
            while (it != wordList.end())
            {
                cout << *it << endl;
                bool check = false;
                for (int i = 0; i < orgSize; ++i)
                {
                    if (checkMatch(q[i], *it))
                    {
                        if (*it == endWord)
                            return ++len;
                        
                        //q.pop();
                        q.push_back(*it);
                        wordList.erase(it);
                        check = true;
                        break;
                    }
                }
//                auto it2 = q.begin();
//                while (it2 != q.end())
//                {
//                    if (checkMatch(*it2, *it))
//                    {
//                        if (*it == endWord)
//                            return ++len;
//                        
//                        //q.pop();
//                        q.push_back(*it);
//                        wordList.erase(it);
//                    }
//                    it2++;
//                }
                if (!check)//it != wordList.end())
                    it++;
            }
            for (int i = 0; i < orgSize; ++i)
                q.pop_front();
            
            len++;
        }
        return 0;
    }
};
//"ta"
//"if"
//["ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"]


int main()
{
    vector<string> wl;
    string bw = "ta";
    string ew = "if";
    wl.push_back("ts");
    wl.push_back("sc");
    wl.push_back("ph");
    wl.push_back("ca");
    wl.push_back("jr");
    wl.push_back("hf");
    wl.push_back("to");
    wl.push_back("if");
    wl.push_back("ha");
    wl.push_back("is");
    wl.push_back("io");
    wl.push_back("cf");
    wl.push_back("ta");
    
    
//    string bw = "hot";
//    string ew = "dog";
//    wl.push_back("hot");
//    wl.push_back("dog");
//    wl.push_back("dot");
    
//    string bw = "hit";
//    string ew = "cog";
//    wl.push_back("hot");
//    wl.push_back("dot");
//    wl.push_back("dog");
//    wl.push_back("lot");
//    wl.push_back("log");
//    wl.push_back("cog");
    
    Solution s;
    cout << s.ladderLength(bw, ew, wl);
    
    return 0;
}
