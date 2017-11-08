//
//
//
//
//
//
//
//
//
//

#include <iostream>
#include <vector>
using namespace std;

const int MAXM = 500;
const int MAXN = 100;
int m, q, n; // m : word num, q : sentence num (tc), n : max word num.
double classifyTable[MAXM + 1][MAXM + 1];
double firstTable[MAXM + 1];
double nextPossTable[MAXM + 1][MAXM + 1];
string words[MAXM + 1];
string sentence[MAXN + 1];

int getNwIdx(string & w) {
    for (int i = 0; i < m; ++i) {
        if (w == words[i]) return i;
    }
    cout << "No Words found" << endl;
    return -1;
}

double exhaustive(int nowIdx, int fwIdx) {
    // nowIdx : idx in sentence, fwIdx : former word idx.
    
    // base case.
    if (nowIdx == n) return 1;
    
    double maxPossibility = 0;
    
    int nwIdx = getNwIdx(sentence[nowIdx]); // now word index.
    
    // algorithm
    for (int i = 0; i < n; ++i) {
        if (classifyTable[nwIdx][i] > 0) {
            if (nowIdx == 0) {
                maxPossibility = max(maxPossibility, classifyTable[nwIdx][i] * firstTable[nwIdx] * exhaustive(nowIdx + 1, nwIdx));
            } else {
                maxPossibility = max(maxPossibility, classifyTable[nwIdx][i] * nextPossTable[fwIdx][nwIdx] * exhaustive(nowIdx + 1, nwIdx));
            }
        }
    }
    return maxPossibility;
}

int main() {
    
    cin >> m >> q;
    
    // input words.
    for (int i = 0; i < m; ++i)
        cin >> words[i];
    
    // input first possibility table.
    for (int i = 0; i < m; ++i) {
        cin >> firstTable[i];
    }
    
    // input next possibility table.
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> nextPossTable[i][j];
        }
    }
    
    // input classify table.
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> classifyTable[i][j];
        }
    }
    
    // test.
    for (int i = 0; i < q; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> sentence[j];
        }
        cout << exhaustive(0, -1) << endl;
    }
    
    return 0;
}

