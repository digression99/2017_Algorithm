#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <string>
using namespace std;

class Trie { // unordered_map version trie.
private:
    class TrieNode {
    public:
        unordered_map<char, TrieNode * > children;
        bool isEndOfWord = false;
    };
    // private member functions.
    bool insert_helper(TrieNode * n, string & s, int strIdx) {
        if (strIdx == s.length()) {
            if (n->isEndOfWord) return false;
            return n->isEndOfWord = true;
        }
        if (n->children.find(s[strIdx]) == n->children.end())
            n->children[s[strIdx]] = new TrieNode;
        return insert_helper(n->children[s[strIdx]], s, strIdx + 1);
    }
    bool search_helper(TrieNode * n, string & s, int strIdx) {
        if (strIdx == s.length() && n->isEndOfWord) return true;
        if (n->children.find(s[strIdx]) != n->children.end())
            return search_helper(n->children[s[strIdx]], s, strIdx + 1);
        return false;
    }
    bool delete_helper(TrieNode * n, string & s, int strIdx) {
        if (strIdx == s.length()) {
            if (!n->isEndOfWord) return false; // search fail.
            // if has children. it means that the key is the prefix of another key.
            if (n->children.size() > 0) {
                n->isEndOfWord = false;
                return false;
            }
            // no children. it means that this is the only node to be deleted.
            return true;
        }
        auto it = n->children.find(s[strIdx]);
        if (it != n->children.end()) // next key exists.
        {
             if (delete_helper(it->second, s, strIdx + 1)) {
                 n->children.erase(it);
                 if (n->children.size() > 0 || n->isEndOfWord) return false;
                 else return true;
             } // delete nodes till it returns false.
        } // next key doesn't exists and strIdx couldn't meet keylength.
        return false;
    }
    // private member variables.
    TrieNode root;
public:
    Trie() {}
    ~Trie() {}
    bool insert(string s) {
        if (this->root.children.find(s[0]) == this->root.children.end())
            this->root.children[s[0]] = new TrieNode;
        return insert_helper(this->root.children[s[0]], s, 1);
    }
    bool search(string s) {
        if (this->root.children.find(s[0]) == this->root.children.end()) return false;
        return search_helper(this->root.children[s[0]], s, 1);
    }
    bool deleteKey(string s) {
        if (!this->search(s)) return false;
        if (s.length() == 0) return false;
        return delete_helper(&this->root, s, 0);
    }
    bool lpm_helper(TrieNode * n, string & s, int strIdx, string & res) {
        // error : can't push the end char.
        if (n->isEndOfWord) {
            if (strIdx == s.length()) {
                
                
            }
            
        }
        
        if (strIdx == s.length()) { // end node.
            // you cannot add the word itself.
            if (n->isEndOfWord) {
                return true;
            }
            return false;
        }
        // what if there's another longest prefix?
        // add results till something returns true.
        auto it = n->children.find(s[strIdx]); // next child is the end node.
        if (it != n->children.end()) {
            if (lpm_helper(it->second, s, strIdx + 1, res)) {
                res = it->first + res;
                return true;
            }
        }
        return false;
    }
    
    string longestPrefixMatching(string s) {
        string ret = "";
        lpm_helper(&this->root, s, 0, ret);
        return ret;
    }
};

// longest prefix matching.
// test case format
// dictnum inputnum
// dict strings...
// input strings...

//{are, area, base, cat, cater, children, basement}
//Below are some input/output examples:
//--------------------------------------
//Input String            Output
//--------------------------------------
//caterer                 cater
//basemexy                base
//child                   < Empty >
//test case
//7 3
//are
//area
//base
//cat
//cater
//children
//basement
//caterer
//basemexy
//child
//




int main() {
    Trie trie;
    int n, k; // n : dictnum, k : inputnum
    string ts;
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> ts;
        trie.insert(ts);
    }
    
    for (int i = 0; i < k; ++i) {
        cin >> ts;
        cout << trie.longestPrefixMatching(ts) << endl;
    }
    //cout << "end" << endl;
    
    return 0;
}





















