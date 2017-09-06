//
// 20170905_topcoder_thefriends
//
// Problem Statements
//You want to determine the most popular person in a social network. To do this, you will count the number of "2-friends" that each person has. Person A is called a 2-friend of another person B if they are friends with each other or if there exists some person C who is a friend of both A and B. The most popular person is the person with the highest number of 2-friends. (There might be more than one if multiple people all have the maximal number of 2-friends.)
//You are given a friends, where the j-th character of the i-th element is 'Y' if person i and person j are friends, and 'N' otherwise. Return the number of 2-friends of the most popular person in this social network.
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
#include <unordered_map>
using namespace std;

//0)
//{"NNN", "NNN", "NNN"}
//Returns: 0
//Here, there are 3 people and none of them are friends, so everybody has zero 2-friends.
//1)
//{"NYY", "YNY", "YYN"}
//Returns: 2
//Each person has two 2-friends.
//2)
//{"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"}
//Returns: 4
//Persons 0 and 4 have two 2-friends, persons 1 and 3 have three 2-friends. Person 2 is the most popular one - four 2-friends.
//3)
//{"NNNNYNNNNN", "NNNNYNYYNN", "NNNYYYNNNN", "NNYNNNNNNN", "YYYNNNNNNY", "NNYNNNNNYN", "NYNNNNNYNN", "NYNNNNYNNN", "NNNNNYNNNN", "NNNNYNNNNN"}
//Returns: 8
//4)
//{"NNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNN", "NNNNNNNYNNNNNNY", "NNNNNNNNNNNNNNY", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNN", "NNNNNYNNNNNYNNN", "NNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "YNNYYNNNNYNNNNN"}
//Returns: 6

class FriendScore {
public:
    
    void checkConnection(vector<string> & friends, int start, int dest, vector<int> & twoFriends)
    {
        for (int i = 0; i < friends.size(); ++i)
        {
            if (friends[dest][i] == 'Y') // 어차피 N 되므로 검사할 필요 없다.
            {
                if (friends[i][start] == 'N')
                {
                    friends[i][start] = friends[start][i] = 'C'; // edge를 만든다.
                    twoFriends[i]++;
                    twoFriends[start]++; // 둘이 친구가 된다.
                }
            }
        }
    }
    
    int highestScore(vector<string> friends)
    {
        vector<int> twoFriends;
        int l = (int)friends.size();
        twoFriends.resize(l, 0);
        
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                if (friends[i][j] == 'Y')
                {
                    friends[i][j] = friends[j][i] = 'C';
                    twoFriends[i]++;
                    twoFriends[j]++;
                    checkConnection(friends, i, j, twoFriends);
                }
            }
        }
        
        return *std::max_element(twoFriends.begin(), twoFriends.end());
    }
    
    
//    int highestScore(vector<string> friends)
//    {
//        int l = (int)friends.size();
//        unordered_map<int, vector<int> > hash = unordered_map<int, vector<int> >(l);
//        int mx = 0;
//        
//        for (int i = 0; i < l; ++i)
//        {
//            for (int j = 0; j < l; ++j)
//            {
//                if (friends[i][j] == 'Y')
//                {
//                    hash[i].push_back(j);
//                    hash[j].push_back(i);
//                    mx = std::max((int)hash[i].size(), std::max(mx, (int)hash[j].size()));
//                }
//            }
//        }
//        
//        return mx / 2;
//    };
    
    
};

vector<vector<string> > friendsVecs = {
    {"NNN", "NNN", "NNN"},
    {"NYY", "YNY", "YYN"},
    {"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"},
    {"NNNNYNNNNN", "NNNNYNYYNN", "NNNYYYNNNN", "NNYNNNNNNN", "YYYNNNNNNY", "NNYNNNNNYN", "NYNNNNNYNN", "NYNNNNYNNN", "NNNNNYNNNN", "NNNNYNNNNN"},
    {"NNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNN", "NNNNNNNYNNNNNNY", "NNNNNNNNNNNNNNY", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNN", "NNNNNYNNNNNYNNN", "NNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "YNNYYNNNNYNNNNN"},
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
        if (obj.highestScore(*itFriends++) != *itRes++)
        {
            cout << "TEST ERROR IN " << itFriends - friendsVecs.begin() << " TH TESTCASE." << endl;
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
