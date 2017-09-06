//
// 20170906_topcoder_friend_score
//
//
//
//
//
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FriendScore{
public:
//    void checkConnection(vector<string> & friends, int src, int dest, vector<int> & twoFriends)
//    {
//        int l = (int)friends.size();
//        for (int i = src + 1; i < l; ++i)
//        {
//            //if (friends[dest][i] == 'C' || friends[dest][i] == 'Y')
//            if (friends[dest][i] == 'Y' || friends[dest][i] == 'C')
//            {
//                // 'Y' -> not yet checked, has a direct connection.
//                // 'C' -> checked, or has a indirect connection.
//                
//                if (friends[i][src] == 'N') // if they had a connection, it already changed to 'C'.
//                { // need to handle 'C' here.
//                    friends[i][src] = friends[src][i] = 'C';
//                    twoFriends[i]++;
//                    twoFriends[src]++;
//                }
//            }
//        }
//    }
    int highestScore(vector<string> friends)
    {
        int mx = 0;
        int l = (int)friends.size();
        
        for (int i = 0; i < l; ++i)
        {
            int cnt = 0;
            
            for (int j = 0; j < l; ++j)
            {
                if (i != j)
                {
                    if (friends[i][j] == 'Y') cnt++;
                    else {
                        for (int k = 0; k < l; ++k)
                        {
                            if (friends[j][k] == 'Y' && friends[k][i] == 'Y')
                            {
                                cnt++;
                                break;
                            }
                        }
                    }
                }
            }
            mx = std::max(mx, cnt);
        }
        return mx;
    }
    
//    int highestScore(vector<string> friends)
//    {
//        vector<int> twoFriends;
//        int l = (int)friends.size();
//        
//        twoFriends.resize(l);
//        
//        for (int i = 0; i < l; ++i)
//        {
//            for (int j = 0; j < l; ++j)
//            {
//                if (i == j) continue;
//                
//                if (friends[i][j] == 'Y' || friends[i][j] == 'C')
//                {
//                    if (friends[i][j] == 'Y')
//                    {
//                        twoFriends[i]++;
//                        twoFriends[j]++;
//                        friends[i][j] = friends[j][i] = 'C';
//                    }
//                    checkConnection(friends, i, j, twoFriends);
//                }
//            }
//        }
//        return *std::max_element(twoFriends.begin(), twoFriends.end());
//    }
};


vector<vector<string> > friendsVecs = {
    {"NNN", "NNN", "NNN"},
    {"NYY", "YNY", "YYN"},
    {"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"},
    {"NNNNYNNNNN",
        "NNNNYNYYNN",
        "NNNYYYNNNN",
        "NNYNNNNNNN",
        "YYYNNNNNNY",
        "NNYNNNNNYN",
        "NYNNNNNYNN",
        "NYNNNNYNNN",
        "NNNNNYNNNN",
        "NNNNYNNNNN"},
    {"NNNNNNNNNNNNNNY",
        "NNNNNNNNNNNNNNN",
        "NNNNNNNYNNNNNNN",
        "NNNNNNNYNNNNNNY",
        "NNNNNNNNNNNNNNY", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNN", "NNNNNYNNNNNYNNN", "NNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "YNNYYNNNNYNNNNN"},
};

vector<int> resVecs = {
    0, 2, 4, 8, 6,
};

void TEST()
{
    cout << "TEST START" << endl;
    
    FriendScore obj = FriendScore();
    
    auto itFriends = friendsVecs.begin();
    auto itRes = resVecs.begin();
    
    while (itFriends != friendsVecs.end())
    {
        int res = obj.highestScore(*itFriends++);
        
        if (res != *itRes++)
        {
            cout << "TEST ERROR IN " << itFriends - friendsVecs.begin() << " TH TESTCASE." << endl;
            cout << "RESULT : " << res << endl;
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
