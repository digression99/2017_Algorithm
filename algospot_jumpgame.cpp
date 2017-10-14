// algospot jumpgame

// tc
//7
//2 5 1 6 1 4 1
//6 1 1 2 2 9 3
//7 2 3 2 1 3 1
//1 1 3 1 7 1 2
//4 1 2 3 4 1 2
//3 3 1 2 3 4 1
//1 5 2 9 4 7 -1


#include <iostream>
using namespace std;

const int NMAX = 100;
int n;
int cache[NMAX][NMAX];
int map[NMAX][NMAX];

int dp(int x, int y) {
    if (cache[y][x] != -1) return cache[y][x]; // base case
    if (x >= n || y >= n) return 0; // base case
    if (x == n - 1 && y == n - 1) return 1;
    return cache[y][x] = dp(x + map[y][x], y) || dp(x, y + map[y][x]); // algorithm
}

int main() {
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    
    cout << dp(0, 0);
    
    return 0;
}


