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
    bool delete_helper(TrieNode * n, string s, int strIdx) {
        if (strIdx == s.length()) {
            if (n->children.size() > 0 || !n->isEndOfWord) return false;
            // key is prefix of other keys, or key doesn't exists.
            return true;
        }
        auto it = n->children.find(s[strIdx]);
        if (it != n->children.end()) // next key exists.
        {
             if (delete_helper(it->second, s, strIdx + 1)) {
                 n->children.erase(it);
                 //delete it->second;
                 if (n->children.size() > 0) return false;
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
        if (delete_helper(&this->root, s, 0)) {
            auto it = this->root.children.find(s[0]);
            if (it->second->children.size() > 0) return false;
            this->root.children.erase(it);
            return true;
        }
        return false;
    }
};

//class Trie { // array version trie.
//private:
//    const static int ALPHABET_SIZE = 26;
//    class TrieNode {
//    public:
//        TrieNode * children[ALPHABET_SIZE];
//        bool isEndOfWord;
//        TrieNode() :isEndOfWord(false) {
//            for (int i = 0; i < ALPHABET_SIZE; ++i) this->children[i] = nullptr;
//
//            // there's no concrete object, so I can't do this.
////            for_each(begin(children), end(children), [](TrieNode & n) {
////                n = nullptr;
////            });
//        }
//        ~TrieNode() {
//            for (int i = 0; i < ALPHABET_SIZE; ++i) delete this->children[i];
//        }
//    };
//    TrieNode * root;
//public:
//    Trie() :root(new TrieNode) {}
//    ~Trie() {
//        delete root;
//    }
//    bool insert(string str) { // false : already exists. true : newly added.
//        int idx = str[0] - 'a';
//        // TrieNode * charNode = this->root->children[idx]; // this is value copy.
//        if (!this->root->children[idx]) this->root->children[idx] = new TrieNode;
//        return insert_helper(this->root->children[idx], str, 1);
//    }
//    bool insert_helper(TrieNode * n, string & str, int strIdx) {
//        if (strIdx == str.length()) {
//            if (n->isEndOfWord) return false;
//            return n->isEndOfWord = true;
//        }
//        int idx = str[strIdx] - 'a';
//        if (!n->children[idx]) n->children[idx] = new TrieNode;
//        return insert_helper(n->children[idx], str, strIdx + 1);
//    }
//    bool search(string str) {
//        TrieNode * next = this->root->children[str[0] - 'a'];
//        if (next) return search_helper(next, str, 1);
//        return false;
//    }
//    bool search_helper(TrieNode * n, string & str, int strIdx) {
//        // search completed.
//        if (strIdx == str.length() && n->isEndOfWord) return true;
//        TrieNode * next = n->children[str[strIdx] - 'a'];
//        if (next) return search_helper(next, str, strIdx + 1);
//        return false;
//    }
//};

int main() {
    Trie trie;

    cout << trie.insert("there") << endl;
    cout << trie.insert("their") << endl;
    cout << trie.insert("answer") << endl;
    cout << trie.insert("any") << endl;
    cout << trie.insert("bye") << endl;
    cout << trie.insert("by") << endl;

    cout << trie.search("there") << endl;
    cout << trie.search("their") << endl;
    cout << trie.search("answer") << endl;
    cout << trie.search("any") << endl;
    cout << trie.search("bye") << endl;
    cout << trie.search("by") << endl;
    // failure case.
    cout << trie.search("ans") << endl;
    
    trie.deleteKey("there");
    trie.deleteKey("their");
    // failure case.
    cout << trie.search("there") << endl;
    cout << trie.search("their") << endl;
    cout << trie.search("t") << endl;
    
    return 0;
}


