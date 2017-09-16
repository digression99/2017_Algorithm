//
//Problem Statement
//Suppose you had an n by n chess board and a super piece called a kingknight. Using only one move the kingknight denoted 'K' below can reach any of the spaces denoted 'X' or 'L' below:
//.......
//..L.L..
//.LXXXL.
//..XKX..
//.LXXXL.
//..L.L..
//.......
//In other words, the kingknight can move either one space in any direction (vertical, horizontal or diagonally) or can make an 'L' shaped move. An 'L' shaped move involves moving 2 spaces horizontally then 1 space vertically or 2 spaces vertically then 1 space horizontally. In the drawing above, the 'L' shaped moves are marked with 'L's whereas the one space moves are marked with 'X's. In addition, a kingknight may never jump off the board.
//
//Given the size of the board, the start position of the kingknight and the end position of the kingknight, your method will return how many possible ways there are of getting from start to end in exactly numMoves moves. start and finish are s each containing 2 elements. The first element will be the (0-based) row position and the second will be the (0-based) column position. Rows and columns will increment down and to the right respectively. The board itself will have rows and columns ranging from 0 to size-1 inclusive.
//
//Note, two ways of getting from start to end are distinct if their respective move sequences differ in any way. In addition, you are allowed to use spaces on the board (including start and finish) repeatedly during a particular path from start to finish. We will ensure that the total number of paths is less than or equal to 2^63-1 (the upper bound for a ).
//Definition
//Class: ChessMetric
//Method: howMany
//Parameters: int, vector <int>, vector <int>, int
//Returns: long long
//Method signature: long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
//(be sure your method is public)
//Limits
//Time limit (s): 840.000
//Memory limit (MB): 64
//Notes
//- For C++ users: long long is a 64 bit datatype and is specific to the GCC compiler.
//Constraints
//- size will be between 3 and 100 inclusive
//- start will contain exactly 2 elements
//- finish will contain exactly 2 elements
//- Each element of start and finish will be between 1 and size-1 inclusive
//- numMoves will be between 1 and 50 inclusive
//- The total number of paths will be at most 2^63-1.
//Examples

//0)
//3val
//{0,0}
//{1,0}
//1
//Returns: 1
//Only 1 way to get to an adjacent square in 1 move

//1)
//3
//{0,0}
//{1,2}
//1
//Returns: 1
//A single L-shaped move is the only way

//2)
//3
//{0,0}
//{2,2}
//1
//Returns: 0
//Too far for a single move

//3)
//3
//{0,0}
//{0,0}
//2
//Returns: 5
//Must count all the ways of leaving and then returning to the corner

//4)
//100
//{0,0}
//{0,99}
//50
//Returns: 243097320072600

//
// - 1씩 더하는 것을 떠나서, 한꺼번에 어떻게 더할 수 있을지 생각해라.
// 특별한 방법을 떠올리는 것 보다 이것을 떠올리는 게 더 좋다.
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
using namespace std;

class ChessMetric {
public:
    
    long long map[100][100];
    int offset[16][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1},
        
        {2, 1},
        {1, 2},
        {-2, -1},
        {-1, -2},
        {2, -1},
        {-2, 1},
        {1, -2},
        {-1, 2}
    };
    
    int nowSize = 0;
    
    bool checkBoundary(pair<int ,int> & nowPos)
    {
        if (nowPos.first < 0 || nowPos.first > nowSize - 1) return false; // x pos check
        if (nowPos.second < 0 || nowPos.second > nowSize - 1) return false;
        return true;
    }
    
    void exhaustive(pair<int, int> & nowPos, int cnt, int n)
    {
        if (cnt > n) return;
        if (!checkBoundary(nowPos)) return;
        
        if (cnt > 0)
            map[nowPos.second][nowPos.first] += 1;
        
        //if (cnt + 1 > n) return;

        for (int i = 0; i < 16 ; ++i)
        {
            nowPos.first += offset[i][0];
            nowPos.second += offset[i][1];
            
            exhaustive(nowPos, cnt + 1, n);
            
            nowPos.first -= offset[i][0];
            nowPos.second -= offset[i][1];
        }
    }
    
    long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
    {
        int x, y, i, j;
        int sx = start[0], sy = start[1], ex = end[0], ey = end[1];
        
        long long ways[100][100][55] = { 0, };
        
        ways[sy][sx][0] = 1;
        
        for (i = 1; i <= numMoves; ++i)
        {
            for (x = 0; x < size; ++x)
            {
                for (y = 0; y < size; ++y)
                {
                    for (j = 0; j < 16; ++j)
                    {
                        int nx = x + offset[j][0];
                        int ny = y + offset[j][1];
                        
                        if (nx < 0 || ny < 0 || nx >= size || ny >= size)
                            continue;
                        
                        ways[ny][nx][i] += ways[y][x][i - 1];
                    }
                }
            }
        }
        
        return ways[ey][ex][numMoves];
    }
    
// mine
//    long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
//    {
//        memset(map, 0, sizeof(map));
//        pair<int, int> startPos = make_pair(start[0], start[1]);
//        nowSize = size;
//        
//        exhaustive(startPos, 0, numMoves);
//        
//        return map[end[1]][end[0]];
//    }
};



int main()
{
    ChessMetric obj = ChessMetric();
    
//    // tc1
//    int size = 3;
//    vector<int> start = {0, 0};
//    vector<int> end = {1, 0};
//    int numMoves = 1;
//    // tc1
//    cout << obj.howMany(size, start, end, numMoves) << endl;
//    

    // tc 2
//    int size = 3;
//    vector<int> start = {0, 0};
//    vector<int> end = {1, 2};
//    int numMoves = 1;
//    cout << obj.howMany(size, start, end, numMoves) << endl;
    // tc 2
    
//    // tc 3
//    int size = 3;
//    vector<int> start = {0, 0};
//    vector<int> end = {2, 2};
//    int numMoves = 1;
//    cout << obj.howMany(size, start, end, numMoves) << endl;
//    // tc 3
    
    // tc4
//    int size = 3;
//    vector<int> start = {0, 0};
//    vector<int> end = {0, 0};
//    int numMoves = 2;
//    cout << obj.howMany(size, start, end, numMoves) << endl;
    // tc4
    
    // tc5
    int size = 100;
    vector<int> start = {0, 0};
    vector<int> end = {0, 99};
    int numMoves = 50;
    cout << obj.howMany(size, start, end, numMoves);
    //Returns: 243097320072600
    
    // tc5
    
    
    
    return 0;
}

