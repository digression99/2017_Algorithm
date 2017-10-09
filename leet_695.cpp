#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    
    int offset[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };
    
    int getArea(vector<vector<int> > &grid, int starti, int startj)
    {
        int area = 1;
        queue<pair<int, int> > q;
        q.push(make_pair(starti, startj));
        
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int nowx = t.second, nowy = t.first;
            for (int i = 0; i < 4; ++i) {
                int checkPosX = nowx + offset[i][0], checkPosY = nowy + offset[i][1];
                if ((checkPosX >= 0 && checkPosX < grid[i].size()) && (checkPosY >= 0 && checkPosY < grid.size()) &&
                    grid[checkPosY][checkPosX]) {
                    area++;
                    grid[checkPosY][checkPosX] = 0;
                    q.push(make_pair(checkPosY, checkPosX));
                }
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    maxArea = max(maxArea, getArea(grid, i, j));
                }
            }
                
        }
        return maxArea;
    }
};
//
//{{0,0,1,0,0,0,0,1,0,0,0,0,0},
// {0,0,0,0,0,0,0,1,1,1,0,0,0},
// {0,1,1,0,1,0,0,0,0,0,0,0,0},
// {0,1,0,0,1,1,0,0,1,0,1,0,0},
// {0,1,0,0,1,1,0,0,1,1,1,0,0},
// {0,0,0,0,0,0,0,0,0,0,1,0,0},
// {0,0,0,0,0,0,0,1,1,1,0,0,0},
// {0,0,0,0,0,0,0,1,1,0,0,0,0}}


int main()
{
    Solution obj = Solution();
    vector<vector<int> > grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    vector<vector<int> > grid2 = {
        {0, 1}
    };

    //cout << obj.maxAreaOfIsland(grid) << endl;
    cout << obj.maxAreaOfIsland(grid2) << endl;
    
    
    
    return 0;
}

