//
// 20170901 - topcoder_cryptography
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
#include <deque>
using namespace std;

class InterestingDigits {
public:
    
    int toBaseN(int base, int digit)
    { // modified.
        vector<int> st;
        //int remain = 0;
        int res = 0;
        
        while (digit > 0)
        {
            res += digit % base;
            //remain = digit % base;
            //st.push_back(remain);
            digit /= base;
        }
        //if (remain) st.push_back(remain);
        //reverse(st.begin(), st.end());
        
        
        return res;
    }
    
    bool checkCorrectNum(int n, int base)
    {
        for (int i = 2; i < 1000; ++i)
        {
            if (toBaseN(base, i * n) % n) return false;
        }
        
        return true;
    }
    
    vector<int> digits(int base)
    {
        vector<int> resVec;
        
        for (int i = 2; i < base; ++i)
        {
            if (checkCorrectNum(i, base))
            {
                resVec.push_back(i);
            }
        }
        
        return resVec;
    }
};




void TEST()
{
    cout << "TEST START" << endl;
//    Cryptography obj = Cryptography();
//        auto itNumbers = numbersVecs.begin();
//    auto itRes = resVecs.begin();
//    
//    while (itNumbers != numbersVecs.end())
//    {
//        if (obj.encrypt(*itNumbers++) != *itRes++)
//        {
//            cout << "TEST ERRORS IN " << itNumbers - numbersVecs.begin() << " TH TEST CASE." << endl;
//            return;
//        }
//    }

    cout << "TEST DONE" << endl;
}


int main()
{
    InterestingDigits obj = InterestingDigits();
    
    vector<int> resv = obj.digits(10);
    vector<int> resv2 = obj.digits(30);
    
    for (auto dat : resv) cout << dat << endl;
    for (auto dat : resv2) cout << dat << endl;
    
    
    
    
    
    //TEST();
    
    return 0;
}
