//
// leet 694. num of distinct islands
//
//
//
//
//
//
//
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    int offset[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };
    
    int getArea(vector<vector<int> > &grid, int starti, int startj, vector<pair<int, int> > & onePos)
    {
        int area = 1;
        queue<pair<int, int> > q;
        q.push(make_pair(starti, startj));
        onePos.push_back(make_pair(starti, startj));
        grid[starti][startj] = 0;
        
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int nowx = t.second, nowy = t.first;
            for (int i = 0; i < 4; ++i) {
                int checkPosX = nowx + offset[i][0], checkPosY = nowy + offset[i][1];
                if ((checkPosX >= 0 && checkPosX < grid[i].size()) && (checkPosY >= 0 && checkPosY < grid.size()) &&
                    grid[checkPosY][checkPosX]) {
                    
                    area++; // to get the area.
                    grid[checkPosY][checkPosX] = 0; // check the grid.
                    onePos.push_back(make_pair(checkPosY, checkPosX)); // for one check.
                    q.push(make_pair(checkPosY, checkPosX));
                }
            }
        }
        return area;
    }
    
    bool checkAreas(vector<vector<pair<int, int> > > & islands, vector<pair<int, int> > & oneVec)
    {
        bool isMatched = true;
        
        for (int i = 0; i < islands.size(); ++i) {
            isMatched = true;
            int offsetX = islands[i][0].second - oneVec[0].second,
            offsetY = islands[i][0].first - oneVec[0].first;
            
            // every element is oneVecs.
            for (int j = 1; j < islands[i].size(); ++j) {
                if (offsetX != islands[i][j].second - oneVec[j].second ||
                    offsetY != islands[i][j].first - oneVec[j].first) isMatched = false;
            }
            
            if (isMatched) return true;
        }
        
        return true; // true if everything is same.
    }
    
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_map<int, vector<vector<pair<int, int> > > > hasht;
        int cnt = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    vector<pair<int, int> > oneVec;
                    int area = getArea(grid, i, j, oneVec);
                    if (hasht.find(area) != hasht.end()) {
                        // there's some islands exist with the same area.
                        if (!checkAreas(hasht[area], oneVec)) {
                            // there's no same island exists.
                            cnt++;
                            hasht[area].push_back(oneVec);
                        }
                    } else {
                        cnt++;
                        hasht[area] = vector<vector<pair<int, int> > >();
                        hasht[area].push_back(oneVec);
                        // no island exists.
                    }
                }
            }
        }
        return cnt;
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
    vector<vector<int> > grid = {
        {11000},
        {11000},
        {00011},
        {00011},
    };
    
    cout << obj.numDistinctIslands(grid) << endl;
    
//    vector<vector<int> > grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
//        {0,0,0,0,0,0,0,1,1,1,0,0,0},
//        {0,1,1,0,1,0,0,0,0,0,0,0,0},
//        {0,1,0,0,1,1,0,0,1,0,1,0,0},
//        {0,1,0,0,1,1,0,0,1,1,1,0,0},
//        {0,0,0,0,0,0,0,0,0,0,1,0,0},
//        {0,0,0,0,0,0,0,1,1,1,0,0,0},
//        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
//
//    vector<vector<int> > grid2 = {
//        {0, 1}
//    };

    //cout << obj.maxAreaOfIsland(grid) << endl;
    //cout << obj.maxAreaOfIsland(grid2) << endl;
    
    
    
    return 0;
}

