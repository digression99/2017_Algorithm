#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//// 타일로 덮는 경우 구하기.
//const int MOD = 1000000007;
//int m[101];
//
//int tiling(int width) {
//    
//    if (width <= 1) return 1;
//    
//    int & ret = m[width];
//    if (ret != -1) return ret;
//    
//    return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
//}


//// 삼각형 최대 경로의 개수 세기.
//int countCache[100][100];
//int n = 0;
//
//int path2(int y, int x);
//
//int count(int y, int x) {
//    if (y == n - 1) return 1;
//    
//    int & ret = countCache[y][x];
//    if (ret != -1) return ret;
//    
//    ret = 0;
//    
//    if (path2(y + 1, x + 1) >= path2(y + 1, x)) ret += count(y + 1, x + 1);
//    if (path2(y + 1, x + 1) <= path2(y + 1, x)) ret += count(y + 1, x);
//    
//    return ret;
//}

// 달팽이 n미터 이상 올라갈 경우의 수 세기.
const int MAX_N = 10;
int n, m;
int cache[MAX_N][2 * MAX_N + 1];

int climb(int days, int climbed) {
    if (days == m) return climbed >= n ? 1 : 0;
    
    int & ret = cache[days][climbed];
    
    if (ret != -1) return ret;
    
    return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

// 비올 확률이 75%로 올라갔을 경우.
double doubleCache[MAX_N][2 * MAX_N + 1];

int climb2(int days, int climbed)
{
    if (days == m) return climbed >= n ? 1 : 0;
    double & ret = doubleCache[days][climbed];
    if (ret != -1) return ret;
    
    return ret = climb2(days + 1, climbed + 2) * 0.25 + climb2(days + 1, climbed + 1) * 0.75;
}

double calcDistance(pair<int, int> & p, pair<int, int> & A, pair<int, int> & B)
{
    double a = (B.second - A.second) / (B.first - A.first);
    double b = -1;
    double c = A.second - a;
    double dividend = abs(a * A.first + b * A.second + c);
    double divisor = sqrt(pow(a, 2) + pow(b, 2));
    
    return dividend / divisor;
}

double getArea(pair<int, int> & point, pair<int, int> & A, pair<int, int> & B)
{
    double d = 0;
    double area = 0;
    
    if (A.first - B.first == 0) d = abs(A.first - point.first);
    else if (A.second - B.second == 0) d = abs(A.second - point.second);
    else
    {
        d = calcDistance(point, A, B);
    }
    return sqrt(pow(B.first - A.first, 2) + pow(B.second - A.second, 2)) * d;
}

bool isInsideTriangle(pair<int, int> & point, vector<pair<int, int> > & triangle)
{
    // 두 점을 잡아 y의 차이가 없다면 => 수평
    // 두 점을 잡아 x의 차이가 없다면 => 수직
    
    std::sort(triangle.begin(), triangle.end(), [](pair<int, int> & front, pair<int, int> & back) {
        return front.first < back.first;
    });
    
    double d = 0;
    double area1 = 0, area2 = 0, area3 = 0, triangleArea = 0;
    
    triangleArea = getArea(triangle[0], triangle[1], triangle[2]);
    area1 = getArea(point, triangle[0], triangle[1]);
    area2 = getArea(point, triangle[1], triangle[2]);
    area3 = getArea(point, triangle[0], triangle[2]);
    
    return area1 + area2 + area3 == triangleArea;
    
    // triangle[0], triangle[1] // area1
    
    if (triangle[0].first - triangle[1].first == 0)
    { // 수직
        d = abs(triangle[0].first - point.first);
    }
    else if (triangle[0].second - triangle[1].second == 0)
    { // 수평
        d = abs(triangle[0].second - point.second);
    } else {
        d = calcDistance(point, triangle[0], triangle[1]);
    }
    area1 = sqrt(pow(triangle[1].first - triangle[0].first, 2) + pow(triangle[1].second - triangle[0].second, 2)) * d;
    
    return triangleArea == area1 + area2 + area3;
}
