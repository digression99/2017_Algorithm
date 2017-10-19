//
// gfg
// how to check if a given point lies inside or outside a polygon?
// how to check if two line segments intersect?
//
//
//
//

#include <iostream>
#include <vector>
using namespace std;

int ori(pair<int, int> & p1, pair<int, int> & p2, pair<int, int> & p3)
{ // calculate orientation.
    int val = (p2.second - p1.second) * (p3.first - p2.first) - (p3.second - p2.second) * (p2.first - p1.first);
    if (val == 0) return 0; // colinear
    else if (val < 0) return -1; // counter-clockwise
    else return 1; // clockwise
}

bool onSegment(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        p.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;
    return false;
}

bool checkIntersect(pair<int, int> & p1, pair<int, int> & q1, pair<int, int> & p2, pair<int, int> & q2)
{
    int p1q1p2Ori = ori(p1, q1, p2),
    p1q1q2Ori = ori(p1, q1, q2),
    p2q2p1Ori = ori(p2, q2, p1),
    p2q2q1Ori = ori(p2, q2, q1);
    
    if (p1q1p2Ori != p1q1q2Ori && p2q2p1Ori != p2q2q1Ori) {
        return true;
    } else if (p1q1p2Ori == p1q1q2Ori && p2q2p1Ori == p2q2q1Ori) {
        // if all colinear
        
        // Special Cases
        // p1, q1 and p2 are colinear and p2 lies on segment p1q1
        if (p1q1p2Ori == 0 && onSegment(p1, p2, q1)) return true;
        
        // p1, q1 and p2 are colinear and q2 lies on segment p1q1
        if (p1q1q2Ori == 0 && onSegment(p1, q2, q1)) return true;
        
        // p2, q2 and p1 are colinear and p1 lies on segment p2q2
        if (p2q2p1Ori == 0 && onSegment(p2, p1, q2)) return true;
        
        // p2, q2 and q1 are colinear and q1 lies on segment p2q2
        if (p2q2q1Ori == 0 && onSegment(p2, q1, q2)) return true;
    }
    return false;
}

bool isInside(vector<pair<int, int> > & polygon, pair<int, int> p)
{
    pair<int, int> rightExtreme = {99999, p.second};
    int cnt = 0, i = 0;
    do
    {
        int next = (i + 1) % polygon.size();
        
        if (checkIntersect(polygon[i], polygon[i + 1], p, rightExtreme)) {
            if (ori(polygon[i], polygon[i + 1], p) == 0) {
                return onSegment(polygon[i], polygon[i + 1], p);
            }
            cnt++;
        }
        i = next;
    } while (i != 0);
    
    return cnt & 1; // odd : true, even : false.
}

int testmain1() {
    // test main for isInside
    
    vector<pair<int, int> > polygon1 = {
        {0, 0},
        {10, 0},
        {10, 10},
        {0, 10},
    };
    pair<int, int> p1 = {20, 20};
    pair<int, int> p2 = {5, 5};
    
    cout << isInside(polygon1, p1) << endl;
    cout << isInside(polygon1, p2) << endl;
    
    
    
    
    return 0;
}

int main()
{
    testmain1();
    
    return 0;
}

/*
 http://marcodiiga.github.io/point-in-polygon-problem
 #include <iostream>
 #include <string>
 #include <vector>
 #include <iterator>
 #include <algorithm>
 #include <unordered_set>
 using namespace std;
 
 // NB: max_int would cause overflow in the orientation test
 const int INF = 100'000;
 
 struct Point {
 int x, y;
 bool operator==(const Point& other) const {
 return (x == other.x && y == other.y);
 }
 };
 
 namespace std {
 template <> struct hash<Point> {
 size_t operator()(const Point& p) const {
 return (p.x * 41) ^ p.y;
 }
 };
 }
 
 ostream& operator<<(ostream& os, const Point& p) {
 os << "{" << p.x << ";" << p.y << "}";
 return os;
 }
 ostream& operator<<(ostream& os, const vector<Point>& p) {
 os << "{";
 copy(p.begin(), p.end(), ostream_iterator<Point>(os));
 os << "}";
 return os;
 }
 
 int orientation(const Point& p1, const Point& p2, const Point& q1) {
 int val = (p2.y - p1.y) * (q1.x - p2.x) - (q1.y - p2.y) * (p2.x - p1.x);
 if (val == 0)
 return 0;
 else
 return (val < 0) ? -1 : 1;
 }
 
 // Returns true if q lies on p1-p2
 bool onSegment(const Point& p1, const Point& p2, const Point& q) {
 if (min(p1.x, p2.x) <= q.x && q.x <= max(p1.x, p2.x)
 && min(p1.y, p2.y) <= q.y && q.y <= max(p1.y, p2.y))
 return true;
 else
 return false;
 }
 
 bool intersectionTest(const Point& p1, const Point& p2,
 const Point& p3, const Point& p4) {
 int o1 = orientation(p1, p2, p3);
 int o2 = orientation(p1, p2, p4);
 int o3 = orientation(p3, p4, p1);
 int o4 = orientation(p3, p4, p2);
 
 // General case
 if (o1 != o2 && o3 != o4)
 return true;
 
 // Special cases
 if (o1 == 0 && onSegment(p1, p2, p3))
 return true;
 if (o2 == 0 && onSegment(p1, p2, p4))
 return true;
 if (o3 == 0 && onSegment(p3, p4, p1))
 return true;
 if (o4 == 0 && onSegment(p3, p4, p2))
 return true;
 
 return false;
 }
 
 bool pointInPolygon(const Point& p, const vector<Point>& polygon) {
 
 if (polygon.size() < 3)
 return false; // Flawed polygon
 
 Point PtoInfinity = { INF , p.y };
 
 int intersectionsCount = 0;
 int i = 0, j = i + 1;
 // Same Y coordinate points have to be counted once
 std::unordered_set<Point> sameYcoordPoints;
 do {
 
 if (intersectionTest(p, PtoInfinity, polygon[i], polygon[j]) == true) {
 
 bool invalidIntersection = false;
 if (p.y == polygon[i].y || p.y == polygon[j].y) {
 
 auto res = sameYcoordPoints.find(polygon[i]);
 // Possible collision
 if (res != sameYcoordPoints.end() && *res == polygon[i])
 invalidIntersection = true;
 
 res = sameYcoordPoints.find(polygon[j]);
 // Possible collision
 if (res != sameYcoordPoints.end() && *res == polygon[i])
 invalidIntersection = true;
 
 if (p.y == polygon[i].y)
 sameYcoordPoints.emplace(polygon[i]);
 else if (p.y == polygon[j].y)
 sameYcoordPoints.emplace(polygon[j]);
 }
 
 if (!invalidIntersection) {
 
 ++intersectionsCount;
 
 if (orientation(polygon[i], polygon[j], p) == 0) { // Collinear
 if (onSegment(polygon[i], polygon[j], p) == true)
 return true;
 else {
 // Exception case when point is collinear but not on segment
 // e.g.
 //           *  ************
 //             /            \
 //            k              w
 // The collinear segment is worth 0 if k and w have the same
 // vertical direction
 
 int k = (((i - 1) >= 0) ? // Negative wraparound
 (i - 1) % static_cast<int>(polygon.size()) :
 static_cast<int>(polygon.size()) + (i - 1));
 int w = ((j + 1) % polygon.size());
 
 if ((polygon[k].y <= polygon[i].y && polygon[w].y <= polygon[j].y)
 || (polygon[k].y >= polygon[i].y && polygon[w].y >= polygon[j].y))
 --intersectionsCount;
 }
 }
 }
 }
 
 i = ((i + 1) % polygon.size());
 j = ((j + 1) % polygon.size());
 
 } while (i != 0);
 
 return (intersectionsCount % 2 != 0);
 }
 
 int main() {
 
 auto printPointInPolygon = [](auto p, auto& polygon) {
 cout << boolalpha << "Point " << p << " lies in polygon " << polygon <<
 " - " << pointInPolygon(p, polygon) << endl;
 };
 
 vector<Point> polygon = { { 2,1 },{ 3,2 },{ 2,3 } };
 Point p = { 1,2 };
 printPointInPolygon(p, polygon);
 
 
 polygon = { { 0, 0 },{ 5, 0 },{ 10, 10 },{ 5, 10 } };
 p = { 3, 3 };
 printPointInPolygon(p, polygon);
 
 p = { 4, 10 };
 printPointInPolygon(p, polygon);
 
 polygon = { { 0, 0 },{ -5, 0 },{ -10, -10 } };
 p = { 0, -2 };
 printPointInPolygon(p, polygon);
 
 return 0;
 }
 */
