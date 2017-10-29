#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
using namespace std;

//vector<int> A = {0,1,1,1,1};
//vector<int> B = {1,0,1,0,1};

class Solution {
public:
    static const int MAXLEN = 1000;
    //vector<vector<int> > memo;
    int memo[MAXLEN + 1][MAXLEN + 1];
    
    int dp(vector<int> & A, vector<int> & B, int idxA, int idxB) {
        
        if (idxA == A.size() || idxB == B.size()) return 0;
        
        int & ret = memo[idxA][idxB];
        if (ret != -1) return ret;
        
        if (A[idxA] == B[idxB]) {
            //return ret = max(ret + 1, dp(A, B, idxA + 1, idxB + 1));
            return ret = 1 + dp(A, B, idxA + 1, idxB + 1);
        } else {
            ret = dp(A, B, idxA, idxB + 1);
            return ret = max(ret, dp(A, B, idxA + 1, idxB));
        }
    }
    
    int findLength(vector<int>& A, vector<int>& B) {

        
        //        memo.resize(A.size());
//        for (auto dat : memo) {
//            dat.resize(B.size(), -1);
//        }
        
        memset(this->memo, -1, sizeof(this->memo));
        dp(A, B, 0, 0);
        
        int maxElement = -1;
        
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < B.size(); ++j)
                maxElement = max(maxElement, memo[i][j]);
        return maxElement;
        
        
        
        
        // how can I get the value of the max element from max_element func?
//        return *max_element(memo.begin(), memo.end(), [](vector<int> frontVec, vector<int> backVec) {
//            return *max_element(frontVec.begin(), frontVec.end(), [](int frontDat, int backDat) {
//                return frontDat < backDat;
//            }) < *max_element(backVec.begin(), backVec.end(), [](int frontDat, int backDat) {
//                return frontDat < backDat;
//            });
//        });
//
//        return *max_element(begin(memo), end(memo), [](int * frontArr, int * backArr) {
//            return *max_element(begin(frontArr), end(frontArr), [](int frontDat, int backDat) {
//                return frontDat < backDat;
//            }) < *max_element(begin(backArr), end(backArr), [](int frontDat, int backDat) {
//                return frontDat < backDat;
//            });
        //return dp(A, B, 0, 0);
    }
};

//class Solution {
//public:
//    int compress(vector<char>& chars) {
//
//        if (chars.size() == 1) return 1;
//        int cnt = 0;
//        int len = 0;
//
//        // you cannot insert or add more memory to array.
//        // you have to make the array just like the explanation.
//
//        for (int i = 0; i < chars.size(); ++i) {
//
//            if (i == 0 || cnt == 0 || chars[i] == chars[i - 1] || (i == chars.size() - 1 && chars[i] == chars[i - 1]))
//                ++cnt;
//
//            if ((i > 0 && chars[i] != chars[i - 1]) || i == chars.size() - 1) {
//                chars[len] = chars[i - 1];
//                if (cnt > 1) {
//                    int start = len + 1, end = len + 1;
//
//                    while (cnt > 0) {
//                        chars[++len] = cnt % 10 + '0';
//                        cnt /= 10;
//                    }
//
//                    end = len;
//
//                    while (start < end) {
//                        int t = chars[start];
//                        chars[start] = chars[end];
//                        chars[end] = t;
//                        ++start; --end;
//                    }
//                }
//                cnt = 1;
//                ++len;
//            }
//        }
//
//        return len;
//    }
//};


//class Solution {
//public:
//    bool solve(vector<int> & bits, int idx) {
//
//        if (idx == bits.size() - 1) return true;
//        else if (idx >= bits.size()) return false;
//
//        if (bits[idx] == 0)
//            return solve(bits, idx + 1);
//        else {
//            return solve(bits, idx + 2);
//        }
//    }
//
//    bool isOneBitCharacter(vector<int>& bits) {
//        return solve(bits, 0);
//
//        //for_each(
//
//    }
//};


//class Solution {
//public:
//    bool twoSum(vector<int> & v, int tgt) {
//        unordered_map<int, int> hash; // key : value in vec, value : idx or bool.
//        bool isThere = false;
//
//        for_each(v.begin(), v.end(), [&](int d) {
//            if (hash.find(tgt - d) != hash.end()) {
//                isThere = true;
//                return;
//                //break;
//            } else {
//                hash[d] = 1;
//            }
//        });
//        return isThere;
//    }
//
//};


int main() {
    
    Solution obj;
    
//    [0,0,0,0,0,0,1,0,0,0]
//    [0,0,0,0,0,0,0,1,0,0]
    
    //vector<int> A = {1, 2, 3, 2, 1};
    //vector<int> B = {3, 2, 1, 4, 7};
    
    vector<int> A = {0,1,1,1,1};
    vector<int> B = {1,0,1,0,1};
    
    cout << obj.findLength(A, B) << endl;

//    Solution obj;
//    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
//    vector<char> chars2 = {'a', 'b', 'b','b', 'b','b', 'b','b', 'b','b', 'b','b', 'b'};
//    vector<char> chars3 = {'a'};
//
    //cout << obj.compress(chars1) << endl;
    //cout << obj.compress(chars2) << endl;
    //cout << obj.compress(chars3) << endl;
    
    
//    Solution obj;
//    vector<int> bits1 = {1, 0, 0};
//    vector<int> bits2 = {1, 1, 1, 0};
//
//    cout << obj.isOneBitCharacter(bits1) << endl;
//    cout << obj.isOneBitCharacter(bits2) << endl;
    
    
    
    
    //    Solution obj;
//    vector<int> v = {1, 2, 3, 8, 9};
//    int target = 10;
//
//    cout << obj.twoSum(v, target) << endl;
    
    
    
    
    
    return 0;
}

