//
// stoi -> string to integer?
//
//
//
//
//
//
//
//


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
    void makeTime(vector<int> & res, vector<int> & dat, int pos) {
        if (pos < 0) {
            makeTime(res, dat, 3);
            return;
        }
        
        // dat배열을 해쉬로 해도 될 듯 하다...
        // 바로 다음 숫자를 선택하는 로직이 필요. (원처럼 생겨서 9 다음에 0 혹은 1 이런 식으로..)
        
        auto it = find_if(dat.begin(), dat.end(), [&](int target) -> bool {
            return res[pos] < target;
        });
        
        if (it != dat.end()) {
            res[pos] = *it;
        } else {
            auto it2 = find_if(dat.begin(), dat.end(), [](int n) {return 0 <= n;});

            res[pos] = *it2;
            if (pos - 1 >= 0)
            {
                res[pos - 1] += 1;
                pos -= 1;
            }
        }
        if (find(dat.begin(), dat.end(), res[pos]) == dat.end()) makeTime(res, dat, pos);
        else if (res[pos] > 9 || (res[pos] > 5 && pos == 2) || (res[pos] > 3 && pos == 1 && res[pos - 1] > 1))
            makeTime(res, dat, pos);
        else if (res[pos] > 2 && pos == 0)
        {
            for (int i = 0; i < 4; ++i) res[i] = 0;
            //for (auto d : res) d = 0;
            makeTime(res, dat, 3);
        } else {
            // 밑에 숫자가 올바른지 체크.
            if (pos > 0) {
                auto it2 = find(dat.begin(), dat.end(), res[pos - 1]);
                if (it2 == dat.end())
                    makeTime(res, dat, pos - 1);
            }
        }
    }
    
    string nextClosestTime(string time) {
        vector<int> dat;
        vector<int> res;
        
        for_each(time.begin(), time.end(), [&](char & c){
            if (c != ':') {
                if (find(dat.begin(), dat.end(), c - '0') == dat.end())
                    dat.push_back(c - '0');
                res.push_back(c - '0');
            }
        });
        
        if (dat.size() == 1) return time;
        
        sort(dat.begin(), dat.end(), less<int>());
        makeTime(res, dat, 3);
        
        return to_string(res[0]) + to_string(res[1]) + ":" + to_string(res[2]) + to_string(res[3]);
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
        //auto test = obj.calPoints(*stringItr++);
//        if (test != *resItr++)
//        {
//            cout << "TEST ERROR IN " << stringItr - stringVecs.begin() << " TH TESTCASE." << endl;
//            return;
//        }
    }
    
    cout << "TEST FINISHED" << endl;
}




int main()
{
    Solution obj = Solution();
    
    cout << obj.nextClosestTime("19:34") << endl;
    
    cout << obj.nextClosestTime("23:59") << endl;
    cout << obj.nextClosestTime("19:19") << endl;
    
    cout << obj.nextClosestTime("22:23") << endl;
    cout << obj.nextClosestTime("13:55") << endl;
    
    cout << obj.nextClosestTime("20:48") << endl;
    
    return 0;
}
