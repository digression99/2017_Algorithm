#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        vector<int> v;
        
        for (auto op : ops)
        {
            int n = 0;
            if (op == "+") {
                n = v[v.size() - 1] + v[v.size() - 2];
                sum += n;
                v.push_back(n);
            } else if (op == "D") {
                n = v[v.size() - 1] * 2;
                sum += n;
                v.push_back(n);
            } else if (op == "C") {
                n = v[v.size() - 1];
                sum -= n;
                v.pop_back();
            } else {
                int n = stoi(op);
                v.push_back(n);
                sum += n;
            }
        }
        
        return sum;
    }
};


vector<vector<string> > stringVecs = {
    {"5","2","C","D","+"},
    {"5","-2","4","C","D","9","+","+"},
};

//vector<int> numVecs = {
//    1, 2, 3,
//};


vector<int> resVecs = {
    30, 27
};

void TEST()
{
    Solution obj = Solution();
    auto stringItr = stringVecs.begin();
    //auto numItr = numVecs.begin();
    auto resItr = resVecs.begin();
    
    while (stringItr != stringVecs.end())
    {
        auto test = obj.calPoints(*stringItr++);
        if (test != *resItr++)
        {
            cout << "TEST ERROR IN " << stringItr - stringVecs.begin() << " TH TESTCASE." << endl;
            return;
        }
    }
    
    cout << "TEST FINISHED" << endl;
}




int main()
{
    TEST();
    
    return 0;
}
