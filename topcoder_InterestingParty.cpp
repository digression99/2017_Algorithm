//
// 20170831 topcoder_InterestingParty
//
// ** Important things
// - I figured out the solution right after I read the problem,
// but that was the problem. I couldn't think any other solutions after that.
// It's true that I couldn't focus on this problem as I proposed, so
// I think I need to think in more various way and think as many solutions as I can.
// + I need to think more about the code. I didn't write my code in my head
// to the most detailed one. I need to focus on those things and make myself to compile my code
// in my head and see the results.
//
// - It's good to make the automated test code so that I can easily test my code with it.
// But, I think I should use vim ide because in the xcode project, it's very complicated to
// compile just one cpp file. But I need that because I could make several cpp files for each problems
// not making the whole project for just one problem. And that's also good in that I can learn how to use
// vim ide.
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class InterestingParty {
public:
    int bestInvitation(vector <string> first, vector <string> second)
    {
        unordered_map<string, int> hash;
        int l = (int)first.size();
        int mx = 0;
        
        for (int i = 0; i < l; ++i)
        {
            if (hash.find(first[i]) != hash.end()) hash[first[i]]++;
            else hash[first[i]] = 1;
            mx = std::max(hash[first[i]], mx);
            
            if (hash.find(second[i]) != hash.end()) hash[second[i]]++;
            else hash[second[i]] = 1;
            mx = std::max(hash[second[i]], mx);
        }
        
        return mx;
    }
};

vector<vector<string> > testFirstArr = {
    {"fishing", "gardening", "swimming", "fishing"},
    {"variety", "diversity", "loquacity", "courtesy"},
    {"snakes", "programming", "cobra", "monty"},
    {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"},

};

vector<vector<string> >testSecondArr = {
    {"hunting", "fishing", "fishing", "biting"},
    {"talking", "speaking", "discussion", "meeting"},
    {"python", "python", "anaconda", "python"},
    {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"},
};

vector<int> testResultArr = {
    4, 1, 3, 6,
};

void TEST()
{
    InterestingParty ip = InterestingParty();
    auto itFirst = testFirstArr.begin(), itSecond = testSecondArr.begin();
    auto itResult = testResultArr.begin();
    
    cout << "TEST START" << endl;
    
    while (itFirst != testFirstArr.end())
    {
        if (ip.bestInvitation(*itFirst++, *itSecond++) != *itResult++)
        {
            cout << "TEST ERROR IN " << itFirst - testFirstArr.begin() << " TEST CASE." << endl;
            return;
        }
    }
    cout << "TEST DONE" << endl;
}

int main()
{
    TEST();
    
    return 0;
}
