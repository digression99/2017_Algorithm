#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 50;
const int LIMIT = 1000000000 + 1;
int memo[MAXN];

int dp(int generation) {
    int & ret = memo[generation];
    if (ret != -1) return ret;
    
    if (generation == 0) return ret = 1;
    return ret = dp(generation - 1) * 2 + 2;
}
//char dragonCurve(const string & str, int skip, int generation) {
//    if (generation == 0) return str[skip];
//
//    for (int i = 0; i < str.length(); ++i) {
//        if (str[i] == 'X' || str[i] == 'Y') {
//            if (skip >= dp(generation)) {
//                skip -= dp(generation);
//            } else if (str[i] == 'X') {
//                return dragonCurve("X+XF", skip, generation - 1);
//            } else {
//                return dragonCurve("FX-Y", skip, generation - 1);
//            }
//        } else if (skip > 0) {
//            --skip;
//        } else {
//            return str[i];
//        }
//    }
//    return '*';
//}
//
char dragonCurve(const string & str, int skip, int generation) {
    if (generation == 0) return str[skip];

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'F' || str[i] == '+') {
            skip -= 1;
        } else if (str[i] == 'X' || str[i] == 'Y') {
            if (skip < dp(generation)) {
                if (str[i] == 'X')
                    return dragonCurve("X+YF", skip, generation - 1);
                else if (str[i] == 'Y') {
                    return dragonCurve("FX-Y", skip, generation - 1);
                }
            } else if (skip >= dp(generation)) {
                skip -= dp(generation);
            } else if (skip == dp(generation)) {
                return str[i];
            }
        }
        if (skip == 0) return str[i];
    }
    return '*';
}

int main() {
    int tc, n, p, l;
    cin >> tc;
    
    memset(memo, -1, sizeof(memo));
    
    for (int i = 0; i < tc; ++i) {
        cin >> n >> p >> l;
        
        dp(n);
        
        for (int j = 0; j < l; ++j) {
            cout << dragonCurve("FX", p + j - 1, n);
        }
        cout << endl;
    }
    
    return 0;
}

