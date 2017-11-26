#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <deque>
#include <cmath>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> astList;
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            astList.push_back(asteroids[i]);
        }
        bool isCollided = true;
        while (isCollided) {
            isCollided = false;
            list<int>::iterator it = astList.begin(), leftIt = astList.end(), rightIt = astList.end();
            
            while ((leftIt == astList.end() || rightIt == astList.end()) && it != astList.end()) {
                // find last leftval and first rightval.
                if (*it < 0 && leftIt == astList.end()) {
                    it++;
                    continue; // if neg val shows up first, then continue.
                }
                
                if (*it > 0) leftIt = it;
                else if (*it < 0) rightIt = it;
                
                if (leftIt != astList.end() && rightIt != astList.end()) {
                    isCollided = true;
                    int leftVal = *leftIt, rightVal = abs(*rightIt);
                    if (leftVal == rightVal) {
                        astList.erase(leftIt);
                        astList.erase(rightIt);
                    } else if (leftVal > rightVal) astList.erase(rightIt);
                    else if (leftVal < rightVal) astList.erase(leftIt);
                    
                    break;
                }
                it++;
            }
        }
        for (auto it = astList.begin(); it != astList.end(); ++it)
            res.push_back(*it);
        return res;
    }
};


int main() {
    Solution obj = Solution();
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> res1 = obj.asteroidCollision(asteroids1);

    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i] << " ";
    }
    cout << endl;
    vector<int> asteroids2 = {8, -8};
    vector<int> res2 = obj.asteroidCollision(asteroids2);

    for (int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " ";
    }
    cout << endl;
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> res3 = obj.asteroidCollision(asteroids3);

    for (int i = 0; i < res3.size(); ++i) {
        cout << res3[i] << " ";
    }
    cout << endl;
    vector<int> asteroids4 = {-2, -2, -2, -2};
    vector<int> res4 = obj.asteroidCollision(asteroids4);
    
    for (int i = 0; i < res4.size(); ++i) {
        cout << res4[i] << " ";
    }
    cout << endl;
    vector<int> asteroids5 = {-2, -2, -2, 1};
    vector<int> res5 = obj.asteroidCollision(asteroids5);
    
    for (int i = 0; i < res5.size(); ++i) {
        cout << res5[i] << " ";
    }
    cout << endl;
    vector<int> asteroids6 = {-2, -2, 1 ,-2};
    vector<int> res6 = obj.asteroidCollision(asteroids6);
    
    for (int i = 0; i < res6.size(); ++i) {
        cout << res6[i] << " ";
    }
    cout << endl;
    
    return 0;
}

