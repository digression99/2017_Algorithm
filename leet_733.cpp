#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int offset[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int startColor = image[sr][sc], maxY = (int)image.size(), maxX = (int)image[0].size();
        image[sr][sc] = newColor;
        q.push(make_pair(sr, sc));
        
        while (!q.empty()) {
            pair<int, int> pos = q.front(); q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int y = pos.first + offset[i][0], x = pos.second + offset[i][1];
                if (y >= 0 && y < maxY && x >= 0 && x < maxX && image[y][x] != newColor && image[y][x] == startColor) {
                    image[y][x] = newColor;
                    q.push(make_pair(y, x));
                }
            }
        }
        return image;
    }
};


int main() {
    Solution obj = Solution();
    vector<vector<int>> image1 = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr1 = 1, sc1 = 1, nc1 = 2;
    image1 = obj.floodFill(image1, sr1, sc1, nc1);
    
    for (int i = 0; i < image1.size(); ++i) {
        for (int j = 0; j < image1[0].size(); ++j)
            cout << image1[i][j];
        cout << endl;
    }
    
    return 0;
}

