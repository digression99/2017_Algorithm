#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
 * Description :
 N : 정류장의 수.
 * Time complexity:
 O(N^2). 각 정류장을 시작으로 모든 정류장을 돌 수 있는지를 검사해야 한다.
 for 문이 최대 N번, 그 안의 while 문이 최대 N번이다.
 * Space complexity:
 O(1). 상수 메모리 공간만 있으면 된다.
 */
int N = 0;
int next(int pos) {
    return (pos + 1) % N;
}

int isEnableDrive(const vector<int> &E, const vector<int> &C) {
    for (int i = 0; i < N; ++i) {
        int start = i;
        int eng = E[i] - C[i];
        int pos = next(start);
        
        while (pos != start && eng >= 0) {
            eng += E[pos] - C[pos];
            pos = next(pos);
        }
        if (pos == start) return i;
    }
    return -1;
}

int main(int argc, const char *argv[]) {
    int T = 0;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<int> E, C;
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            int energy = 0;
            cin >> energy;
            E.push_back(energy);
        }
        
        for (int i = 0; i < N; i++) {
            int cost = 0;
            cin >> cost;
            C.push_back(cost);
        }
        
        cout << isEnableDrive(E, C) << endl;
    }
}

