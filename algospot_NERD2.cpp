/*
 
 algospot_NERD2
 
 -- map 을 이용하여 이진 검색 트리를 표현하고,lower_bound 등의 함수를 사용하여 문제를 푼다.
 
 -- 나는 두개의 트리를 생각했는데 하나만으로도 할 수 있다.
 
 */

// test case
//2
//4
//72 50
//57 67
//74 55
//64 60
//5
//1 5
//2 4
//3 3
//4 2
//5 1


// result
//8
//15


#include <map>
#include <iostream>
using namespace std;

map<int, int> coords;

bool isDominated(int x, int y) {
    auto it = coords.lower_bound(x);
    
    // x 보다 큰 key 중에서 가장 작은 수를 찾는다.
    if (it == coords.end()) return false;
    return y < it->second;
}

void removeDominated(int x, int y) {
    auto it = coords.lower_bound(x);
    if (it == coords.begin()) return;
    
    --it;
    
    while (true) {
        if (it->second > y) break;
        if (it == coords.begin()) {
            coords.erase(it);
            break;
        } else {
            auto jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if (isDominated(x, y)) return coords.size();
    removeDominated(x, y);
    coords[x] = y;
    return coords.size();
}

void playground() {
    map<int, int> m;
    
    m[72] = 50;
    m[57] = 67;
    m[74] = 55;
    m[64] = 60;
    
    auto it = m.lower_bound(70);
    auto it2 = m.upper_bound(70);
    
    cout << it->first << endl;
    cout << it2->first << endl;
}

void solve() {
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        int n, s = 0;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int x, y;
            cin >> x >> y;
            s += registered(x, y);
        }
        cout << s << endl;
        coords.clear();
    }
}

int main() {
    //playground();
    //test();
    solve();
    
    return 0;
}









