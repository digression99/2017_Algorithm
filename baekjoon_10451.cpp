//
// 2017.07.12
// 
//
//
//
//
//
//
// test cases
// 2
// 8
// 3 2 7 8 1 4 5 6
// 10
// 2 1 3 4 5 6 7 9 10 8

#include <iostream>
using namespace std;

int graph[1001][1001];
bool check[1001];

void init()
{
    for (int i = 0; i < 1001; ++i)
    {
        check[i] = false;
        for (int j = 0; j < 1001; ++j)
            graph[i][j] = 0;
    }
}

void dfs(int v, int N, int & count)
{
    for (int i = 1; i <= N; ++i)
    {
        if (graph[v][i])
        {
            if (check[i])
            {
                // cycle
                count++;
            }
            else
            {
                check[i] = true;
                dfs(i, N, count);
            }
        }
    }
}

int main()
{
    int tc = 0;
    int N = 0;
    int temp = 0;
    int count = 0;
    
    cin >> tc;
    
    for (int i = 0; i < tc; ++i)
    {
        count = 0;
        init();
        
        cin >> N;
        
        for (int j = 1; j <= N; ++j)
        {
            cin >> temp;
            graph[j][temp] = 1;
        }
        
        for (int j = 1; j <= N; ++j)
        {
            if (!check[j])
            {
                check[j] = true;
                dfs(j, N, count);
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
