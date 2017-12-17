#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <iterator>
#include <utility>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> orgHash;
        //licensePlate.
        for (char c : licensePlate) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                char t = c >= 'a' ? c : c += 'a' - 'A';
                if (orgHash.find(t) == orgHash.end()) orgHash[t] = 0;
                ++orgHash[t];
            }
        }
        // sort should be changed to hash table by length.
        sort(words.begin(), words.end(), [](string first, string second) -> bool {
            return first.length() < second.length();
            //if (first.length() != second.length()) return first.length() < second.length();
            //return first < second;
        }); // sort by length and dic order.
        
        for (auto w : words) cout << w << endl;
        
        for(auto w : words) {
            unordered_map<char, int> tHash;
            //copy(tHash.begin(), tHash.end(), orgHash.begin());
            for_each(orgHash.begin(), orgHash.end(), [&](pair<char, int> p) {
                tHash[p.first] = p.second;
            });
            
            for (char c : w) {
                if (tHash.find(c) != tHash.end())
                    --tHash[c];
            }
            if (none_of(tHash.begin(), tHash.end(), [&](pair<char, int> p) -> bool {
                if (p.second > 0) return true;
                return false;
            })) {
                return w;
            }
        }
        
        return "";
    }
};

int main() {
    Solution obj = Solution();
    vector<string> v{
        "looks",
        "pest",
        "stew",
        "show"
    };
    string lp1 = "1s3 456";
    cout << obj.shortestCompletingWord(lp1, v) << endl;
    
    return 0;
}























