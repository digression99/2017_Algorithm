
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        
        unordered_map<string, vector<string>> hash;
        
        for (int i = 0; i < pairs.size(); ++i) { // to for_each, lambda로.
            string front = pairs[i].first, back = pairs[i].second;
            
            if (hash.find(front) != hash.end()) {
                hash[front].push_back(back);
            } else {
                hash[front] = vector<string>();
                hash[front].push_back(back);
            }
            
            if (hash.find(back) != hash.end()) {
                hash[back].push_back(front);
            } else {
                hash[back] = vector<string>();
                hash[back].push_back(front);
            }
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] != words2[i]) {
                if (hash.find(words1[i]) == hash.end()) {
                    return false;
                } else if (find(hash[words1[i]].begin(), hash[words1[i]].end(), words2[i]) == hash[words1[i]].end()) {
                        return false;
                }
            }
        }
        return true;
    }
};
