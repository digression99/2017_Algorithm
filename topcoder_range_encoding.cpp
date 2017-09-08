#include <vector>
#include <iostream>
using namespace std;

class RangeEncoding {
public:
    int minRanges(vector<int> arr)
    {
        int cnt = 1;
        
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i + 1] - arr[i] > 1) {
                cnt++;
            }
        }
        
        return cnt;
    }
};

vector<vector<int> > numberVecs = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 6, 10, 20, 32, 49},
    {2,4,5,6,8,9,10,11,12,15},
    {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},
    {10,11,12,13,14,15,20,21,22,23,25,27,28,29,30,31,32,33},
    {33},
};

vector<int> resVecs = {
    1,
    6,
    4,
    14,
    4,
    1,
};

void TEST() {
    RangeEncoding obj = RangeEncoding();
    auto itNum = numberVecs.begin();
    auto itRes = resVecs.begin();
    
    cout << "TEST BEGIN." << endl;
    
    while (itNum != numberVecs.end())
    {
        int res = obj.minRanges(*itNum++);
        if (res != *itRes++)
        {
            cout << "TEST ERROR IN " << itNum - numberVecs.begin() << " TH TEST CASE." << endl;
            return;
        }
    }
    
    cout << "TEST FINISHED." << endl;
}


int main()
{
    TEST();
    
    return 0;
}
