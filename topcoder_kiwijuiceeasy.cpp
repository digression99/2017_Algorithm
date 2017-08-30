//
// 20170830 topcoder - kiwijuiceeasy
//
// 적용한 것들
// - 몰입, sleepy algorithm.
// - TEST 의 자동화 코드 제작.
// -> vector 연산에서 ==, != 등이 지원된다.
// -> array 에서 vector로 iterator, 초기화 등을 이용하여 초기화할 수 있는데,
// 그냥 처음부터 벡터를 쓰는 게 여러모로 편하다.
// array to vector
//
//
//
//
//
//
//
//
//
//

#include <iostream>
using namespace std;
#include <vector>
#include <iterator>
#include <algorithm>

class KiwiJuiceEasy
{
public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
        vector<int> res(bottles);
        int M = (int)fromId.size();
        
        for (int i = 0; i < M; ++i)
        {
            if (!bottles[fromId[i]] || !(capacities[toId[i]] - bottles[toId[i]])) continue;
            
            int remain = capacities[toId[i]] - bottles[toId[i]];
            
            if (remain > bottles[fromId[i]])
            {
                bottles[toId[i]] += bottles[fromId[i]];
                bottles[fromId[i]] = 0;
            }
            else
            {
                bottles[fromId[i]] -= remain;
                bottles[toId[i]] = capacities[toId[i]];
            }
            
            res[toId[i]] = bottles[toId[i]];
            res[fromId[i]] = bottles[fromId[i]];
        }
        
        return res;
    };
};

// making testcase.
// 각 인풋마다 배열을 만들고, 테스트 함수를 이용하여 한꺼번에 결과를 출력하게 한다.
// 테스트 케이스가 추가될 때 마다, 배열에 요소를 하나 더 추가하면 된다.
// 각 배열의 길이가 다른 것은 어떻게 만드는가?

//const int TESTNUM = 3;
//const int MAXN = 50;
//const int MAXM = 50;

vector<vector<int> > capVecs = {
    {10, 10,},
    {30, 20, 10},
    {14, 35, 86, 58, 25, 62},
};

vector<vector<int> > botVecs = {
    {5, 8},
    {10, 5, 5},
    {6, 34, 27, 38, 9, 60},
};

vector<vector<int> > fromIdVecs = {
    {0},
    {0, 1, 2},
    {1, 2, 4, 5, 3, 3, 1, 0},
};

vector<vector<int> > toIdVecs = {
    {1},
    {1, 2, 0},
    {0, 1, 2, 4, 2, 5, 3, 1},
};

vector<vector<int> > resVecs = {
    {3, 10 },
    {10, 10, 0 },
    {0, 14, 65, 35, 25, 35 },
};

void TEST()
{
    KiwiJuiceEasy kje = KiwiJuiceEasy();
    cout << "TEST START" << endl;
    
    auto itCap = capVecs.begin(),
    itBot = botVecs.begin(),
    itFromId = fromIdVecs.begin(),
    itToId = toIdVecs.begin(),
    itRes = resVecs.begin();
    
    while (itCap != capVecs.end())
    {
        vector<int> res = kje.thePouring(*itCap++, *itBot++, *itFromId++, *itToId++);
        if (res != *itRes++)
        {
            cout << "TEST ERROR IN " << itCap - capVecs.begin() - 1 << endl;
            return;
        }
    }
    
    cout << "TEST DONE" << endl;
}


//void TEST()
//{
//    KiwiJuiceEasy kje = KiwiJuiceEasy();
//    cout << "TEST START" << endl;
//
//    for (int i = 0; i < TESTNUM; ++i)
//    {
//        cout << "TEST " << i << endl;
//        vector<int> cap = vector<int>(begin(capArr[i]), end(capArr[i]));
//        vector<int> bot = vector<int>(begin(botArr[i]), end(botArr[i]));
//        vector<int> fromId = vector<int>(begin(fromIdArr[i]), end(fromIdArr[i]));
//        vector<int> toId = vector<int>(begin(toIdArr[i]), end(toIdArr[i]));
//
////        vector<int> cap = vector<int>(capArr[i], capArr[i] + nArr[i]);
////        vector<int> bot = vector<int>(botArr[i], botArr[i] + nArr[i]);
////        vector<int> fromId = vector<int>(fromIdArr[i], fromIdArr[i] + mArr[i]);
////        vector<int> toId = vector<int>(toIdArr[i], toIdArr[i] + mArr[i]);
//
//        vector<int> res = kje.thePouring(cap, bot, fromId, toId);
//
//        //for (auto dat : res) cout << dat << endl;
//        auto it1 = res.begin();
//        auto it2 = begin(results[i]);
//
//        for (; it1 != res.end() || it2 != end(results[i]); it1++, it2++)
//        {
//            if (*it1 == 0) break;
//            if (*it1 != *it2)
//            {
//                cout << "TEST ERROR :" << *it1 << " != " << *it2 << endl;
//                cout << "in " << it1 - res.begin() <<" th data." << endl;
//                return;
//            }
//        }
//
////        for (int j = 0; j < nArr[i]; ++j)
////        {
////            if (res[j] != results[i][j])
////            {
////                cout << "TEST ERROR :" << res[j] << " != " << results[i][j] << endl;
////                cout << "in " << j <<" th data." << endl;
////                return;
////            }
////        }
//    }
//
//    cout << "TEST DONE" << endl;
//}



//
//
//int capArr[TESTNUM][MAXN] = {
//    {10, 10, },
//    {30, 20, 10, },
//    {14, 35, 86, 58, 25, 62},
//};
//
//int botArr[TESTNUM][MAXN] = {
//    {5, 8},
//    {10, 5, 5},
//    {6, 34, 27, 38, 9, 60},
//};
//
//int nArr[TESTNUM] = {
//    2, 3, 6,
//};
//
//int mArr[TESTNUM] = {
//    1, 3, 8,
//};
//
//int fromIdArr[TESTNUM][MAXM] = {
//    {0},
//    {0, 1, 2},
//    {1, 2, 4, 5, 3, 3, 1, 0},
//    
//};
//
//int toIdArr[TESTNUM][MAXM] = {
//    {1},
//    {1, 2, 0},
//    {0, 1, 2, 4, 2, 5, 3, 1},
//};
//
//int results[TESTNUM][MAXN] = {
//    {3, 10 },
//    {10, 10, 0 },
//    {0, 14, 65, 35, 25, 35 },
//};




//int capArr[TESTNUM][] = {
//    {10, 10},
//    {30, 20, 10},
//};


int main()
{
    TEST();
    //KiwiJuiceEasy kje = KiwiJuiceEasy();
    // tc1
//    vector<int> cap = {10, 10};
//    vector<int> bot = {5, 8};
//    vector<int> fromId = {0};
//    vector<int> toId = {1};
    
    // tc2
//    vector<int> cap = {30, 20, 10};
//    vector<int> bot = {10, 5, 5};
//    vector<int> fromId = {0, 1, 2};
//    vector<int> toId = {1, 2, 0};
    
    // tc3
//    vector<int> cap = {700000, 800000, 900000, 1000000};
//    vector<int> bot = {478478, 478478, 478478, 478478};
//    vector<int> fromId = {2, 3, 2, 0, 1};
//    vector<int> toId = {0, 1, 1, 3, 2};
    
    //vector<int> res = kje.thePouring(cap, bot, fromId, toId);
    
    //for (auto dat : res) cout << dat << endl;
    
    return 0;
}
