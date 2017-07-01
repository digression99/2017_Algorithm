//
// 20170701
// geeksforgeeks
// closest pairs of points O(nlogn) implementation
//
// 목적 - 평면상의 n개의 점이 주어졌을 떄(x, y) 가장 가까운 두 점을 찾는 것.
//
// 방법
//
// * x 좌표를 기점으로 소팅한다.
// * 모든 점을 반으로 나눈다. (divide and conquer 적용)
// * 두 subarray에서 재귀적으로 가장 가까운 거리를 구한다.
// * 둘 중 미니멈을 취한다. 미니멈을 d 라고 한다.
// * strip 배열을 만드는데, 이 배열은 맨 처음 배열을 둘로 나누는 가운데 선에서
// 최대 d 만큼 떨어진 점들을 넣는다.
// strip 배열에서 가장 가까운 거리를 찾는다.
//
// 이 방법은 만일 strip 배열의 점들이 y를 기준으로 소트되었다면 O(n)시간에
// 가장 가까운 거리를 찾을 수 있다는 점이다.
//
// -- 새로운 방법
// 점들을 y를 기준으로 먼저 소트한다. 그 배열을 Py라고 한다.
// 재귀 호출을 할 때, vertical line을 기점으로 점들을 나누어야 한다.
// 이때는 가운데 선의 x 좌표를 기준으로 모든 점의 x좌표를 비교한다.
//
//

// [알고리즘 정리]
// 점들이 주어지면, 그 점들을 두 가지 각기 다른 배열을 이용, x 정렬, y정렬로 따로 저장한다.
// y 가 정렬된 것들을, x가 정렬된 것들 중 가운데 점을 기준으로
// 그 가운데보다 x가 작다면 왼쪽, 크다면 오른쪽으로 분류한다.
// 그리고 계속 재귀 호출을 하며 분류 작업을 계속하고,
// 그렇게 되면 x, y가 가까운 것들끼리 분류되게 된다. 그 후에
// bruteForce 함수로 거리를 구한다. 그리고 그 거리를 기준으로
// 가운데 x와 d보다 가까운 점들을 strip에 넣는다. 그리고
// stripClosest에서 y가 d보다 작은 애들 중에 거리가 d보다 작은 점들을 찾는다.
// 그 거리는 가운데까지 고려했을 때 가장 가까운 두 점의 거리일 것이다.
// 이것을 리턴한다.


// A divide and conquer program in C++ to find the smallest distance from a
// given set of points.

#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

// A structure to represent a Point in 2D plane
struct Point
{
    int x, y;
};


/* Following two functions are needed for library function qsort().
 Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */

// Needed to sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// A utility function to find the distance between two points
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y) );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(Point P[], int n)
{
    // 이게 divide and conquer 에서 base case에서의 답을 구하는 방법이다.
    // 즉, 마지막까지 내려가면 bruteForce로 구하는 것이다.
    
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}


// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
    
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
                // 일단 y를 비교해서 y가 min보다 작으면 본격적으로
                // x 까지 껴서 거리를 구하고, min보다 작으면 그것이 min이 된다.
                // 안쪽 루프가 왜 최대 6번만 도는가?
                // brute force 때문인가?
    return min;
}

// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
float closestUtil(Point Px[], Point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);
    
    // Find the middle point
    int mid = n/2;
    Point midPoint = Px[mid]; // x로 정렬된 것중 가운데를 받는다. 당연히 y좌표도 복사됨.
    
    
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point Pyl[mid+1];   // y sorted points on left of vertical line
    Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x) // midPoint보다 x가 작다면 왼쪽, 크다면 오른쪽.
            Pyl[li++] = Py[i]; // y가 정렬된 것들을 x를 기준으로 분류한다.
        else
            Pyr[ri++] = Py[i];
    }
    
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(Px, Pyl, mid); // 나뉜걸로 divide and conquer 로 들어간다.
    float dr = closestUtil(Px + mid, Pyr, n-mid);
    
    // Find the smaller of two distances
    float d = min(dl, dr);
    
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n]; // 이렇게 선언하는 건 c++14 이상에서 가능??...
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d) // d는 divide and conquer 로 구한 최소 거리다.
            strip[j] = Py[i], j++; // x의 차가 d보다 작다면 strip에 들어간다.
    // strip에는 n개 까지 들어갈 수 있지만,
    // 결국 j개가 들어가게 된다.
    
    // closestUtil에서는 x가 d보다 작은 것을 찾는다.
    // stripClosest에서는 y가 d보다 작은 것을 찾고
    // 그것들과 min을 비교하여 가장 가까운 것을 구한다.
    //
    //
    
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
float closest(Point P[], int n)
{
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    
    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(Px, Py, n);
}

// Driver program to test above functions
int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}
