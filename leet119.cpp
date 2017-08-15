//
// 20170815
// leet 119 - Pascal's triangle 2
//
// my sol -> dp
// other sol -> mathematical sol.
//
//
//
//

#include <iostream>
#include <vector>
using namespace std;

// not mine.
//class Solution {
//public:
//    vector<int> getRow(int rowIndex) {
//        vector<int> list(rowIndex+1);
//        int value = rowIndex, size = list.size() >> 1;
//        list[0] = 1;
//        if (rowIndex == 0)
//            return list;
//        list[list.size() - 1] = 1;
//        if (rowIndex == 1)
//            return list;
//        
//        for (int i = 1; i <= size; i++){
//            list[i] = value;
//            list[list.size() - 1 - i] = list[i];
//            int c = rowIndex - i, d = i + 1, a = value / d, b = value%d;
//            value = a*c+b*c/d;		
//        }
//        return list;
//    }
//};

// mine.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        if (rowIndex == 0) return v;
        v.push_back(1);
        int prev = 0;
        int now = 0;
        if (rowIndex == 1) return v;
        
        for (int i = 1; i < rowIndex; ++i)
        {
            v.push_back(1);
            prev = v[0];
            for (int j = 1; j < v.size(); ++j)
            {
                if (j == v.size() - 1) continue;
                now = v[j];
                v[j] = prev + v[j];
                prev = now;
            }
        }
        return v;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> v = s.getRow(4);
    
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    
    return 0;
}
