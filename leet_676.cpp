#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

class MagicDictionary {
public:
    unordered_map<int, unordered_map<char, vector<string>> > hash; // key : length, val : strings.
    // has a data num.
    /** Initialize your data structure here. */
    MagicDictionary() {
        this->hash.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        int l = (int)dict.size();
        
        for (int i = 0; i < l; ++i)
        {
            int sl = (int)dict[i].length();
            this->hash[sl][dict[i][0]].push_back(dict[i]); // save by the length, start char.
            
            //this->hash[sl].push_back(dict[i]);
        }
    }
    
    bool diffCheck(string & org, string & word)
    {
        bool diff = false;
        
        for (int i = 0; i < org.length(); ++i)
        {
            if ((org[i] != word[i]))
            {
                if (diff) return false;
                else diff = true;
            }
        }
        
        return diff;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int sl = (int)word.length();
        
        if (this->hash.find(sl) != this->hash.end())
        {
            if (sl == 1)
            {
                if (this->hash.find(sl) != this->hash.end())
                {
                    if (this->hash[sl].find(word[0]) == this->hash[sl].end()) return true;
                    else
                    {
                        if (this->hash[sl].size() == 1) return false;
                        else return true;
                    }
                }
            }
            else
            {
                // first search.
                if (this->hash[sl].find(word[0]) != this->hash[sl].end())
                {
                    int vecLen = (int)this->hash[sl][word[0]].size();
                    
                    for (int i = 0; i < vecLen; ++i)
                    {
                        if (diffCheck(this->hash[sl][word[0]][i], word)) return true;
                    }
                }
                
                //second search. // else로 되면, 첫 번째 단어가 걸리는데에서 끝나버림. 그러면 못찾음.
                unordered_map<char, vector<string> > & hs = this->hash[sl];
                
                for (auto dat : hs)
                {
                    for (auto vecDat : dat.second)
                    {
                        if (diffCheck(vecDat, word)) return true;
                    }
                }
            }
            
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */


//Input: buildDict(["hello", "leetcode"]), Output: Null
//Input: search("hello"), Output: False
//Input: search("hhllo"), Output: True
//Input: search("hell"), Output: False
//Input: search("leetcoded"), Output: False

// tc 2
//["MagicDictionary", "buildDict", "search", "search", "search", "search", "search", "search"]
//[[], [["a"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"]]


//["MagicDictionary", "buildDict", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search"]
//[[], [["a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj","abcdefghijawefe","aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi","babcda","bcd","awefj"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["ab"], ["ba"], ["abc"], ["cba"], ["abb"], ["bb"], ["aa"], ["bbc"], ["abcd"]]


int main()
{
    MagicDictionary obj = MagicDictionary();

    vector<string> sVec = {"a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj","abcdefghijawefe","aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi","babcda","bcd","awefj"};
    obj.buildDict(sVec);
    cout << obj.search("bbc") << endl;
    
    
//    vector<string> sVec = {"a", "b", "ab", "abc"};
//    obj.buildDict(sVec);
//    cout << obj.search("bbc") << endl;
//    cout << obj.search("bb") << endl;
    
    

    //tc 1
//    vector<string> sVec = {"a"};
//    obj.buildDict(sVec);
//    cout << obj.search("a") << endl;
//    cout << obj.search("f") << endl;
    
    //tc2
//    vector<string> sVec = {"hello", "leetcode"};
//    obj.buildDict(sVec);
//    cout << obj.search("hello") << endl;
//    cout << obj.search("hhllo") << endl;
//    cout << obj.search("hell") << endl;
//    cout << obj.search("leetcoded") << endl;
    
    
    
    
    
    
    
    return 0;
}
