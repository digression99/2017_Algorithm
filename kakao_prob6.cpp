#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

void search(vector<string> & board, vector<pair<int, int> > & eIdxs, int m, int n)
{
    for (int i = 0; i < m - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            //cout << board[i][j] << " " << board[i + 1][j] << " " << board[i][j + 1] << " " << board[i + 1][j + 1] << endl;
            if (board[i][j] == board[i + 1][j] &&
                board[i + 1][j] == board[i][j + 1] &&
                board[i][j + 1] == board[i + 1][j + 1] &&
                board[i][j] != 'X')
            { // found a block.
                eIdxs.push_back(make_pair(i, j));
            }
        }
    }
}

void gapCheck(vector<string> & board, vector<pair<int, int> > & eIdxs, int m, int n)
{
    for (int i = 0; i < eIdxs.size(); ++i)
    {
        for (int j = eIdxs[i].second; j <= eIdxs[i].second + 1; ++j)
        {
            int startI = eIdxs[i].first + 1, endI = eIdxs[i].first;
            
            while (endI >= 0 && board[endI][j] == 'X') endI--;
            
            if (endI >= 0)
                for (int k = endI; startI > endI && k >= 0; --startI, --k)
                {
                    board[startI][j] = board[k][j];
                    board[k][j] = 'X';
                }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    vector<pair<int, int> > eIdxs; // elimination index
    int ans = 0;
    
    while (true)
    {
        search(board, eIdxs, m, n);
        if (eIdxs.size() == 0) break;
        
        for (int i = 0; i < eIdxs.size(); ++i)
        {
            pair<int, int> nowPos = eIdxs[i]; // change Idxs to queue or something.
            
            if (board[nowPos.first][nowPos.second] != 'X')
            {
                ans++;
                board[nowPos.first][nowPos.second] = 'X';
            }
            if (board[nowPos.first][nowPos.second + 1] != 'X')
            {
                ans++;
                board[nowPos.first][nowPos.second + 1] = 'X';
            }
            if (board[nowPos.first + 1][nowPos.second] != 'X')
            {
                ans++;
                board[nowPos.first + 1][nowPos.second] = 'X';
            }
            if (board[nowPos.first + 1][nowPos.second + 1] != 'X')
            {
                ans++;
                board[nowPos.first + 1][nowPos.second + 1] = 'X';
            }
        }
        
        gapCheck(board, eIdxs, m, n);
        eIdxs.clear();
    }
    
    return ans;
}

//
//m	n	board	answer
//4	5	["CCBDE", "AAADE", "AAABF", "CCBBF"]	14
//6	6	["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]	15

int main()
{
    // tc1
//    int m = 4, n = 5;
//    vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
//    cout << solution(m, n, board) << endl;
    
    // tc2
    int m = 6, n = 6;
    vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
    cout << solution(m, n, board);
    
    
    
    return 0;
}


