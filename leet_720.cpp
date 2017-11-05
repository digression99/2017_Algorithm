#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

// string match algorithm
// using dfs, find the longest string with minimum lexical order.
// use trie.
// check at the moment when the length diminishes.


class Solution {
public:
    string longestWord(vector<string>& words) {
        if (words.size() == 1) return words[0];
        
        // sort by character algorithm
        sort(words.begin(), words.end());
        for (auto dat : words) cout << dat << endl;
        int nowIdx = 0;
        //char start = words[0];
        string ans = words[0], realAns = words[0];
        
        while (nowIdx < words.size()) {
            int l = words[nowIdx + 1].length();
            while (ans.length() < l && ans + words[nowIdx + 1][l - 1] == words[nowIdx + 1]) {
                ans = words[nowIdx + 1];
                nowIdx++;
            }
            if (realAns < ans) realAns = ans;
        }
        return realAns;
        
        
        
        
        
        
        // sort by length algorithm
//        sort(words.begin(), words.end(), [](string front, string end) {
//            return front.length() < end.length() || (front.length() == end.length() && front < end);
//        });
//        map<char, vector<int> > nowHash, nextHash;
//        int nowIdx = 0, l = (int)words[0].length();
//        string ans = words[0];
//
//        nextHash[words[0][l - 1]].push_back(0);
//
//        while (nowIdx < words.size() - 1) {
//            l = (int)words[nowIdx + 1].length();
//
//            if (words[nowIdx].length() < l) {
//                // size gets bigger. copy nextHash to nowHash.
//                if (l - ans.length() > 1) return ans;
//                nowHash.clear();
//                copy(nextHash.begin(), nextHash.end(), inserter(nowHash, nowHash.begin()));
//                nextHash.clear();
//            }
//
//            if (nowHash.size() == 0)
//                nextHash[words[nowIdx + 1][l - 1]].push_back(nowIdx + 1);
//            else {
//                auto it = nowHash.find(words[nowIdx + 1][l - 2]);
//                if (it != nowHash.end()) {
//                    for (auto dat : it->second) {
//                        if (words[dat] + words[nowIdx + 1][l - 1] == words[nowIdx + 1]) {
//                            nextHash[words[nowIdx + 1][l - 1]].push_back(nowIdx + 1);
//                            break;
//                        }
//                    }
//                }
//            }
//            if (nextHash.size() > 0 && ans.length() < words[nextHash.begin()->second[0]].length())
//                ans = words[nextHash.begin()->second[0]]; // get the answer.
//
//            nowIdx++;
//        }
        
        return ans;
        
        
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //vector<vector<int> > g(numCourses);
        vector<unordered_map<int, int> > g(numCourses);
//        for_each(g.begin(), g.end(), [](unordered_map<int, int> dat) {
//            //dat.
//
//
//        });
        
        for_each(prerequisites.begin(), prerequisites.end(), [&](pair<int, int> pre) {
            //if (
            
            
        });
        
        
        
        
        
        
        return false;
    }
};

int main() {
    Solution obj;
    // string sorting test.
    vector<string> stringVec = {
        "apps",
        "appsk",
        "apple",
        "appskg",
        "a",
        "ap",
        "app",
        "appl",
    };
    vector<string > stringVec2 = {
      "a","banana","app","appl","ap","apply","apple"
    };
    
    vector<string> stringVec3 = {
        "d","do","dog","p","pe","pen","peng","pengu","pengui","penguin","e","el","ele","elep","eleph","elepha","elephan","elephant"
    };
    vector<string> stringVec4 = {
        "m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"
    };
    vector<string> stringVec5 = {
        "ogz","eyj","e","ey","hmn","v","hm","ogznkb","ogzn","hmnm","eyjuo","vuq","ogznk","og","eyjuoi","d"
    };
    vector<string> stringVec6 = {
        "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"
    };
    vector<string> stringVec7 = {
        "gbra","jy","pl","zn","gb","j","jyh","jyhm","plr","znicn","p","gbr","zni","znic","aq"
    };
    vector<string> stringVec8 = {
        "t","ti","tig","tige","tiger","e","en","eng","engl","engli","englis","english","h","hi","his","hist","histo","histor","history"
    };
    vector<string> stringVec9 = {
        "sg","qgca","s","qzu","qzub","qzubvs","hlyc","hl","qg","qzubv","qgc","qgcab","qz","sgs","sgsnyn","hly","hlycf","sgsn"
    };
    
    cout << "answer : " << obj.longestWord(stringVec) << endl;
    cout << "answer : " << obj.longestWord(stringVec2) << endl;
    cout << "answer : " << obj.longestWord(stringVec3) << endl;
    cout << "answer : " << obj.longestWord(stringVec4) << endl;
    cout << obj.longestWord(stringVec5) << endl;
    cout << obj.longestWord(stringVec6) << endl;
    cout << obj.longestWord(stringVec7) << endl;
    cout << obj.longestWord(stringVec8) << endl;
    cout << obj.longestWord(stringVec9) << endl; // sgsn
    
    //sort(stringVec.begin(), stringVec.end());
    
    //for(int i = 0; i < stringVec.size(); ++i)
    //    cout << stringVec[i] << endl;

    // for each copy test.
//    vector<vector<int> > test;
//    for_each(test.begin(), test.end(), [](vector<int> & v) {
//        v.push_back(10);
//    });
//
//    for_each(test.begin(), test.end(), [](vector<int> & v) {
//        for_each(v.begin(), v.end(), [](int dat) {
//            cout << dat << endl;
//        });
//        //cout << v[0] << endl;
//        //v.push_back(10);
//    });
//
//    cout << " hi " << endl;
    
    
    
    return 0;
}

