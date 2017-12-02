#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

/*

 test case
4
321 3
123 3
422 2
127381733912 7
 
 
 
 
 */




const int MAXLEN = 15;
int valTable[MAXLEN];
int maxDepth = 0;
int m = 0;

void makeTable(int e, unordered_map<int, int> & hash) {
    stack<int> st;
    
    while (e > 0) {
        st.push(e % 10);
        if (hash.find(e % 10) == hash.end()) hash[e % 10] = 1;
        else hash[e % 10]++;
        e /= 10;
    }
    
    int nowVal = st.top();
    st.pop();
    int cnt = 0;
    
    while (!st.empty()) {
        valTable[cnt++] = nowVal;
        nowVal = nowVal * 10 + st.top();
        st.pop();
    }
    valTable[cnt] = nowVal;
    maxDepth = cnt;
}

int exhaustive(int nowVal, unordered_map<int, int> & hash, int depth) {
    if (depth == maxDepth) {
        int v = nowVal * 10 + hash.begin()->first;
        if (v < valTable[depth] && !(v % m)) return 1;
        else return 0;
    }
    int ret = 0;
    
    for (auto it = hash.begin(); it != hash.end(); ++it) {
        if (it->second > 0) {
            int temp = nowVal * 10 + it->first;
            int savedNum = 0;
            if (temp < valTable[depth]) {
                // delete.
                savedNum = it->first;
                if (--it->second == 0) hash.erase(it);
                // go deeper.
                ret += exhaustive(temp, hash, depth + 1);
                auto savedIt = hash.find(savedNum);
                // regain.
                if (savedIt != hash.end()) ++savedIt->second;
                else hash[savedNum] = 1;
                // 지금 에러는 hash가 원래 자리를 찾아가지 못하기 때문에 발생.
            }
        }
    }
    return ret;
}

int main() {
    int tc;
    unordered_map<int, int> hash;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        int e;
        cin >> e >> m;
        makeTable(e, hash);
        cout << exhaustive(0, hash, 0) << endl;
        hash.clear();
    }
    
    return 0;
}




