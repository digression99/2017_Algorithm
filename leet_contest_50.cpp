#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Node {
public:
    char c;
    int val;
    //vector<Node *> childs;
    unordered_map<char, Node *> childs;
    
    Node(char c = ' ', int val = 0) : c(c), val(val) {}
    ~Node() {
        for (auto c : childs)
            delete c.second;
    }
};

class MapSum {
public:
    Node * root;
    /** Initialize your data structure here. */
    MapSum() {
        this->root = new Node('$', 0);
    }
    
    void insert(string key, int val) {
        Node * np = root;
        
        for (int i = 0; i < key.length(); ++i)
        {
            if (np->childs.find(key[i]) == np->childs.end()) // 차일드가 없다면 끝까지 만든다.
            {
                np->childs[key[i]] = new Node(key[i]);
            }
            np = np->childs[key[i]];
        }
        np->val = val;
    }
    
    int sumSearch(Node * start)
    {
        int ret = start->val;
        
        for (auto c : start->childs)
        {
            ret += sumSearch(c.second);
        }
        
        return ret;
    }
    
    
    int sum(string prefix) {
        Node * np = this->root;
        
        for (int i = 0; i < prefix.length(); ++i)
        {
            if (np->childs.find(prefix[i]) != np->childs.end())
                np = np->childs[prefix[i]];
            else return 0;
        }
        
        return sumSearch(np);
    }
};

//class Solution {
//public:
//    
//    bool validPalindrome(string s)
//    {
//        int l = (int)s.length();
//    
//        int i = 0, j = l - 1;
//        
//        int tc1i, tc1j, tc2i, tc2j;
//        
//        
//        while (i <= j)
//        {
//            if (i == j) return true;
//            if (s[i] == s[j])
//            {
//                if (i == j - 1) return true;
//                ++i; --j;
//            } else {
//                tc1i = i, tc1j = j - 1;
//                tc2i = i + 1, tc2j = j;
//                
//                while (tc1i <= tc1j)
//                {
//                    if (s[tc1i] != s[tc1j]) break;
//                    ++tc1i, --tc1j;
//                }
//                if (tc1i >= tc1j) return true;
//                while (tc2i <= tc2j)
//                {
//                    if (s[tc2i] != s[tc2j]) break;
//                    ++tc2i, --tc2j;
//                }
//                if (tc2i >= tc2j) return true;
//                break;
//                
//            }
//        }
//        
//        return false;
//    }
//};


int main()
{
    MapSum obj = MapSum();
    
//    obj.insert("apple", 3);
//    obj.insert("app", 3);
//    cout << obj.sum("app") << endl;
    obj.insert("aa", 3);
    cout << obj.sum("a");
    obj.insert("ab", 2);
    cout << obj.sum("a");
    
    
    
    
    
    
//    Solution obj = Solution();
//    string str1 = "aba";
//    string str2 = "abca";
//    string str3 = "a";
//    string str4 = "abcbde";
//    string str5 = "ebcbbececabbacecbbcbe";
//    string str6 = "abc";
//    string str7 = "bddb";
//    
////    cout << obj.validPalindrome(str1) << endl;
////    cout << obj.validPalindrome(str2) << endl;
////    cout << obj.validPalindrome(str3) << endl;
////    cout << obj.validPalindrome(str4) << endl;
////    cout << obj.validPalindrome(str5) << endl;
//    //cout << obj.validPalindrome(str6) << endl;
//    cout << obj.validPalindrome(str7) << endl;
    
    
    
    
    return 0;
}
