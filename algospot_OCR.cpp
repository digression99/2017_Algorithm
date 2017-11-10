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
Last login: Wed Nov  8 08:02:07 on ttys003
 ~  ls
2017_Algorithm      IdeaProjects        PycharmProjects     jellybeans.vim
Applications        Library             WebstormProjects    naver_cloud
Desktop             Movies              XamarinProjects     sleepy-algorithm
Documents           Music               bin                 xcode_projects
Downloads           Parallels           data
Dropbox             Pictures            drracket_study
Google Drive        Public              formal_verification
 ~  cd 2017_Algorithm
 ~/2017_Algorithm   master  ls
20170924.cpp                      leet119.cpp
ChineseRemainderTheorem.cpp       leet127.cpp
Kruskal_minimum_spanning_tree.cpp leet127_2.cpp
NQueens.cpp                       leet129.cpp
README.md                         leet131.cpp
algospot_ASYMTILING.cpp           leet133.cpp
algospot_ASYMTILING_v2.cpp        leet139.cpp
algospot_JLIS.cpp                 leet153.cpp
algospot_JLIS_v2.cpp              leet694.cpp
algospot_NUMB3RS.cpp              leet_20171029_contest.cpp
algospot_OCR.cpp                  leet_669.cpp
algospot_PACKING.cpp              leet_671.cpp
algospot_PI.cpp                   leet_674.cpp
algospot_POLY.cpp                 leet_676.cpp
algospot_POLY_v2.cpp              leet_681.cpp
algospot_QUANTIZATION.cpp         leet_682.cpp
algospot_TILING2.cpp              leet_695.cpp
algospot_TRIANGLEPATH.cpp         leet_696.cpp
  1 //
  2 //
  3 //
  4 //
  5 //
  6 //
  7 //
  8 //
  9 //
 10 //
 11
 12 #include <iostream>
 13 #include <vector>
 14 using namespace std;
 15
 16 const int MAXM = 500;
 17 const int MAXN = 100;
 18 int m, q, n; // m : word num, q : sentence num (tc), n : max word num.
 19 double classifyTable[MAXM + 1][MAXM + 1];
 20 double firstTable[MAXM + 1];
 21 double nextPossTable[MAXM + 1][MAXM + 1];
 22 string words[MAXM + 1];
 23 string sentence[MAXN + 1];
 24
"algospot_OCR.cpp" 94L, 2058C
  1 //
  2 //
  3 //
  4 //
  5 //
  6 //
  7 //
  8 //
  9 //
 10 //
 11
 12 #include <iostream>
 13 #include <vector>
 14 using namespace std;
 15
 16 const int MAXM = 500;
 17 const int MAXN = 100;
 18 int m, q, n; // m : word num, q : sentence num (tc), n : max word num.
 19 double classifyTable[MAXM + 1][MAXM + 1];
 20 double firstTable[MAXM + 1];
 21 double nextPossTable[MAXM + 1][MAXM + 1];
 22 string words[MAXM + 1];
 23 string sentence[MAXN + 1];
 24
 25 int getNwIdx(string & w) {
 24
 25 int getNwIdx(string & w) {
 26     for (int i = 0; i < m; ++i) {
 27         if (w == words[i]) return i;
 28     }
 29     cout << "No Words found" << endl;
 30     return -1;
 31 }
 32
 33 double exhaustive(int nowIdx, int fwIdx) {
 34     // nowIdx : idx in sentence, fwIdx : former word idx.
 35
 36     // base case.
 37     if (nowIdx == n) return 1;
 38
 39     double maxPossibility = 0;
 40
 41     int nwIdx = getNwIdx(sentence[nowIdx]); // now word index.
 42
 43     // algorithm
 44     for (int i = 0; i < n; ++i) {
 45         if (classifyTable[nwIdx][i] > 0) {
 46             if (nowIdx == 0) {
 47                 maxPossibility = max(maxPossibility, classifyTable[nwIdx][i] * firstTable[nwIdx] * exhaustive(nowIdx + 1, nwIdx));
 48             } else {
 49                 maxPossibility = max(maxPossibility, classifyTable[nwIdx][i] * nextPossTable[fwIdx][nwIdx] * exhaustive(nowIdx + 1, nwIdx));
 50             }
 51         }
 52     }
 53     return maxPossibility;
 54 }
 55
 56 int main() {
 57
 58     cin >> m >> q;
 59
 60     // input words.
 61     for (int i = 0; i < m; ++i)
 62         cin >> words[i];
 63
 64     // input first possibility table.
 65     for (int i = 0; i < m; ++i) {
 66         cin >> firstTable[i];
 67     }
 68
 69     // input next possibility table.
 70     for (int i = 0; i < m; ++i) {
 71         for (int j = 0; j < m; ++j) {
-- INSERT --        for (int j = 0; j < m; ++j) {
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

