
//
// algospot_ NUMB3RS
//

//test case

//2
//5 2 0
//0 1 1 1 0
//1 0 0 0 1
//1 0 0 0 0
//1 0 0 0 0
//0 1 0 0 0
//3
//0 2 4
//8 2 3
//0 1 1 1 0 0 0 0
//1 0 0 1 0 0 0 0
//1 0 0 1 0 0 0 0
//1 1 1 0 1 1 0 0
//0 0 0 1 0 0 1 1
//0 0 0 1 0 0 0 1
//0 0 0 0 1 0 0 0
//0 0 0 0 1 1 0 0
//4
//3 1 2 6

#include <cstring>
#include <iostream>
#include <iterator>
using namespace std;

const int MAXN = 50;
const int MAXD = 100;

int g[MAXD + 1][MAXN + 1];
double memo[MAXD + 1][MAXN + 1];
int sumNodes[MAXN + 1];
int P;
int N;

int exhaustive(int d, int n) {
    
    // base case
    if (d == 0) {
        if (n == P) return 1;
        else return 0;
    }
    // algorithm
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (g[n][i])
            sum += exhaustive(d - 1, i);
    }
    return sum;
}

double possibility(int d, int n) {
    
    // base case
    if (d == 0) {
        if (n == P) return 1;
        else return 0;
    }
    // memo check
    double & ret = memo[d][n];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i = 0; i < N; ++i) {
        if (g[n][i]) {
            ret += (double(1) / sumNodes[i]) * possibility(d - 1, i);
        }
    }
    return ret;
}


int main() {
    int tc, day;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> N >> day >> P;
        
        memset(g, 0, sizeof(g));
        memset(sumNodes, 0, sizeof(sumNodes));
        
        
        
        //fill_n(memo[0], sizeof(memo) * sizeof(memo[0]), -1.0);
        //fill(begin(memo), end(memo), -1);
        //fill_n(memo, -1);
        
//        for (int i = 0; i < N; ++i)
//            for (int j = 0; j < N; ++j)
//                memo[i][j] = -1;
        //memset(memo, -1, sizeof(memo));
        
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k) {
                cin >> g[j][k];
                sumNodes[j] += g[j][k];
            }
//        int total = 0;
//        for (int i = 0; i < N; ++i) {
//            // to get all the cases.
//            total += exhaustive(day, i);
//        }
        
        //cout << "total : " << total << endl;
        int t, q;
        cin >> t;
        for (int j = 0; j < t; ++j) {
            cin >> q;
            
            // just get the case.
            //cout << exhaustive(day, q) << endl;
            
            // get the possibility
            cout << possibility(day, q) << " ";
            //cout << "possibility : " << possibility(day, q) << endl;
        }
        cout << endl;
    }

    return 0;
}

