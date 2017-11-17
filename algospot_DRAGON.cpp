#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
const int MAXN = 50;
long long memo[MAXN + 1];


//long long dp(int gen) {
//    if (gen == 0) return 2;
//    long long & ret = memo[gen];
//    if (ret != -1) return ret;
//    return ret = dp(gen - 1) * 2 + 1;
//}

void precalc() {
    memo[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        memo[i] = memo[i - 1] * 2 + 2;
    }
}

string convert(string & str) {
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '+') str[i] = '-';
        else if (str[i] == '-') str[i] = '+';
    }
    return str;
}

//string reconstruct(int p, int l) {
//    if (n == 0) return string("+FX").substr(p, l);
//    if (n == 1) return string("FX+YF").substr(p, l);
//    if (n == 2) return string("+FX+YF+FX-YF").substr(p, l);
//    string curOrg = "", curHalf = "", prevOrg = "+FX+YF", prevHalf = "+FX-YF";
//    int nowGen = 0;
//    while (dp(nowGen++) < p + l - 1) {
//        curOrg = prevOrg + prevHalf;
//        curHalf = prevOrg + convert(prevHalf);
//        prevOrg = curOrg;
//        prevHalf = curHalf;
//    }
//    //string ans = curOrg + curHalf;
//    return curOrg.substr(p, l);
//}

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

char expand(const string & dragonCurve, int generations, int skip) {
    if (generations == 0) {
        //assert(skip < dragonCurve.size();
        return dragonCurve[skip];
    }
    
    for (int i = 0; i < dragonCurve.size(); ++i) {
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
            if (skip >= memo[generations]) {
                skip -= memo[generations];
            } else if (dragonCurve[i] == 'X') {
                return expand(EXPAND_X, generations - 1, skip);
            } else {
                return expand(EXPAND_Y, generations - 1, skip);
            }
        } else if (skip > 0) {
            --skip;
        } else {
            return dragonCurve[i];
        }
    }
    return '#';
}

int main() {
//    string str = "abcdefghijklmn";
//    cout << str.substr(2, 3) << endl;
    
    int tc, p, l;
    cin >> tc;
    
//    memset(memo, -1, sizeof(memo));
    //memo[0] = 2;
    
    //dp(50);
    
    precalc();
    
    for (int i = 0; i < tc; ++i) {
        cin >> n >> p >> l;
        for (int j = p; j <= p + l; ++j)
            cout << expand("FX", n, j);
        //cout << expand("FX", n, p) << endl;
        
        //cout << reconstruct(p, l) << endl;
    }
    
    return 0;
    
}



