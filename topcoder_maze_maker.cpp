//
// 20170908_topcoder_maze_maker
//
//
// - X 를 고려해야 한다.
// numMaze를 따로 만들지 말고 차라리 maze를 그냥 쓰면 어떨까
//
//
//
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class MazeMaker {
public:
    
    // maze version
    
    void bfs(vector<string> & maze, pair<int, int> startPos, vector<int> & moveRow, vector<int> & moveCol)
    {
        deque<pair<int, int> > q;
        int nowCount = 0;
        int l = (int)maze.size();
        int nowSize = 0;
        
        maze[startPos.second][startPos.first] = nowCount + '0';
        q.push_back(make_pair(startPos.first, startPos.second));
        
        nowSize = 1;
        nowCount = 1;
        
        while (!q.empty())
        {
            for (int s = 0; s < nowSize; ++s)
            {
                pair<int, int> nowPos = q.front();
                q.pop_front();
                
                for (int i = 0; i < moveRow.size(); ++i)
                {
                    int nextX = nowPos.first + moveRow[i];
                    int nextY = nowPos.second + moveCol[i];
                    
                    if ((nextX < l && nextX >= 0) &&
                        (nextY < l && nextY >= 0) &&
                        maze[nextY][nextX] == '.') // if X or other number, then I can't go there.
                    {
                        maze[nextY][nextX] = nowCount + '0';
                        q.push_back(make_pair(nextX, nextY));
                    }
                }
            }
            
            nowSize = (int)q.size();
            nowCount++;
        }
    }
    
    int findSol(vector<string> &maze) {
        int mx = -1;
        int l = (int)maze.size();
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                if (maze[i][j] == '.') return -1;
                if (maze[i][j] != 'X') {
                    mx = std::max(mx, maze[i][j] - '0');
                }
                //mx = std::max(mx, maze[i][j])
            }
        }
        return mx;
    }
    // maze version
    
    
    // numMaze version
//    void bfs(vector<vector<int> > & numMaze, pair<int, int> startPos, vector<int> & moveRow, vector<int> & moveCol)
//    {
//        deque<pair<int, int> > q;
//        int nowCount = 0;
//        int l = (int)numMaze.size();
//        int nowSize = 0;
//        
//        numMaze[startPos.second][startPos.first] = nowCount++;
//        q.push_back(make_pair(startPos.first, startPos.second));
//        
//        nowSize = (int)q.size();
//        
//        while (!q.empty())
//        {
//            for (int s = 0; s < nowSize; ++s)
//            {
//                pair<int, int> nowPos = q.front();
//                q.pop_front();
//    
//                for (int i = 0; i < moveRow.size(); ++i)
//                {
//                    int nextX = nowPos.first + moveRow[i];
//                    int nextY = nowPos.second + moveCol[i];
//                    
//                    if ((nextX < l && nextX >= 0) &&
//                        (nextY < l && nextY >= 0) &&
//                        numMaze[nextY][nextX] == -1)
//                    //if ((nextX < l && nextY < l) && numMaze[nextY][nextX] == -1)
//                    {
//                        numMaze[nextY][nextX] = nowCount;
//                        q.push_back(make_pair(nextX, nextY));
//                    }
//                }
//            }
//            nowCount++;
//            nowSize = (int)q.size();
//        }
//    }
//    
//    int findSol(vector<vector<int> > & numMaze)
//    {
//        int l = (int)numMaze.size();
//        int mx = -1;
//        
//        for (int i = 0; i < l; ++i)
//        {
//            for (int j = 0; j < l; ++j)
//            {
//                if (numMaze[i][j] == -1) return -1;
//                mx = std::max(mx, numMaze[i][j]);
//            }
//        }
//        return mx;
//    }
    
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol)
    {
        bfs(maze, make_pair(startRow, startCol), moveRow, moveCol);
        return findSol(maze);
        
//        vector<vector<int> > numMaze;
//        numMaze.resize(maze.size());
//        for (auto v : numMaze) v.resize(maze.size(), -1);
        
//        for (int i = 0; i < maze.size(); ++i)
//        {
//            for (int j = 0; j < maze.size(); ++j)
//            {
//                if (maze[i][j] == 'X')
//                {
//                    numMaze[i][j] =
//                }
//            }
//        }

        //bfs(numMaze, make_pair(startRow, startCol), moveRow, moveCol);
        //return findSol(numMaze);
    }
};

vector<vector<string> > mazeVecs = {
    {
        "...",
        "...",
        "..."
    },
};
vector<int> startRowVec = {
    0,
};
vector<int> startColVec = {
    1,
};

vector<vector<int> > moveRowVecs = {
    {1, 0, 1, 0},
};

vector<vector<int> >moveColVecs = {
    {0, 1, 0, -1},
};

vector<int> resVecs = {
    3,
};



void TEST()
{
    cout << "TEST START" << endl;
    MazeMaker obj = MazeMaker();
    auto itMaze = mazeVecs.begin();
    auto itStartRow = startRowVec.begin();
    auto itStartCol = startColVec.begin();
    auto itMoveRow = moveRowVecs.begin();
    auto itMoveCol = moveColVecs.begin();
    auto itRes = resVecs.begin();
    
    while (itMaze != mazeVecs.end())
    {
        int res = obj.longestPath(*itMaze++, *itStartRow++, *itStartCol++, *itMoveRow++, *itMoveCol++);
        if (res != *itRes++)
        {
            cout << "TEST FAIL IN " << itMaze - mazeVecs.begin() << " TH TEST CASE." << endl;
            return;
        }
    }
    cout << "TEST FINISHED." << endl;
}

int main()
{
    TEST();
    return 0;
}
