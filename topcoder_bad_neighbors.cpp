//Problem Statement
//The old song declares "Go ahead and hate your neighbor", and the residents of Onetinville have taken those words to heart. Every resident hates his next-door neighbors on both sides. Nobody is willing to live farther away from the town's well than his neighbors, so the town has been arranged in a big circle around the well. Unfortunately, the town's well is in disrepair and needs to be restored. You have been hired to collect donations for the Save Our Well fund.
//
//Each of the town's residents is willing to donate a certain amount, as specified in the donations, which is listed in clockwise order around the well. However, nobody is willing to contribute to a fund to which his neighbor has also contributed. Next-door neighbors are always listed consecutively in donations, except that the first and last entries in donations are also for next-door neighbors. You must calculate and return the maximum amount of donations that can be collected.
//

//Definition
//Class: BadNeighbors
//Method: maxDonations
//Parameters: vector <int>
//Returns: int
//Method signature: int maxDonations(vector <int> donations)
//(be sure your method is public)
//Limits
//Time limit (s): 840.000
//Memory limit (MB): 64
//Constraints
//- donations contains between 2 and 40 elements, inclusive.
//- Each element in donations is between 1 and 1000, inclusive.

//Examples

//0)
//{ 10, 3, 2, 5, 7, 8 }
//Returns: 19
//The maximum donation is 19, achieved by 10+2+7. It would be better to take 10+5+8 except that the 10 and 8 donations are from neighbors.

//1)
//{ 11, 15 }
//Returns: 15

//2)
//{ 7, 7, 7, 7, 7, 7, 7 }
//Returns: 21

//3)
//{ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }
//Returns: 16

//4)
//{ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }
//Returns: 2926
//
// - 0번부터 시작, 끝까지 가면서 돌되, 마지막까지 가면 %.
// if (pos == arr.size() - 1) break;
// else if (pos > arr.size() - 1) pos %= arr.size();
// 이게 아니라, pos += 2 > arr.size() - 1 이라면 그냥 모듈러스 하면 됨. 왜냐면, 0으로 시작했을 땐 마지막 방을 갈 수 없다. (방의 개수가 짝수라면?)
// 1부터 시작했을 때는 무조건 마지막 방을 갔다가 넘어가게 된다.
//
// - 바로 옆 빼고 몇 칸을 뛰어도 된다. 따라서 한 칸 건너뛴 뒤에 한칸씩 더하면서 들어가야 한다.
//
//
//
//
//
//



#include <iostream>
#include <vector>
using namespace std;

class BadNeighbors{
public:
    
    int m[41]; // memoization
    
    int dp(vector<int> & donations, int pos, int nowSum)
    {
        if (m[pos]) return m[pos];
        int mx = 0;
        
        if (pos + 2 > donations.size())
        {
            m[pos] = nowSum;
            return m[pos];
        }
        pos += 2;
        
        while (pos < donations.size())
        {
            mx = std::max(mx, dp(donations, pos, nowSum + donations[pos]));
            pos += 1;
        }
        
        return 0;
    }
    
    int maxDonations(vector <int> donations)
    {
        int res = 0;
        
        for (int i = 0; i < donations.size(); ++i)
        {
            res = std::max(res, dp(donations, i, 0));
        }
        return res;
    }
};


int main()
{
    return 0;
}
