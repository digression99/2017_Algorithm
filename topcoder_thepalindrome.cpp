//
// 20170904_topcoder_thepalindrome
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
#include <string>
using namespace std;

class Palindrome {
public:
    int find(string s) {
        int startNum = -1;
        int j = 0, k = 0, l = (int)s.length();
        int offset = -1;
        
        for (int i = -1; i < l; ++i) {
            j = 0;
            k = 0;
            
            while (j < l) {
                // i == -1 -> init cond.
                if (i == -1 || (k >= startNum && offset == 1)) {
                    k = l - 1; // if less than 0, start checking from the eng of the string.
                    offset = -1;
                }
                else if (k >= 0) {
                    offset = 1;
                }
                
                if (s[j] != s[k]) break; // check if it's palindrome.
                
                if (j == (l + startNum) / 2) {
                    if ((l + startNum) % 2)
                        return l + startNum; // if j gets to the half of the string, return.
                    else return l + startNum + 1;
                }
                
                j++;
                k += offset;
            }
        
            startNum++;
        }
        
        return l + startNum;
    }

};

vector<string> strVec = {
    "abab",
    "abc", // error
};

vector<int> resVec = {
    5, 5,
};


void TEST()
{
    cout << "TEST START" << endl;
    
    Palindrome obj = Palindrome();
    auto itStr = strVec.begin();
    auto itRes = resVec.begin();
    
    while (itStr != strVec.end() && itRes != resVec.end())
    {
        if (obj.find(*itStr++) != *itRes++)
        {
            cout << "TEST ERROR IN " << itStr - strVec.begin() << " TH TESTCASE." << endl;
            return;
        }
    }
    cout << "TEST FINISH" << endl;
}


int main()
{
    TEST();
    
    return 0;
}
