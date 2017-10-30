
//test case
//5
//12341234
//11111222
//12122222
//22222222
//12673939

//result
//4
//2
//5
//2
//14

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXLEN = 10000;
int memo[MAXLEN + 1];
const int INF = 987654321;

int level(string & str, int start, int end) {
    
    int next = start + 1, nnext = start + 2;
    //int front = str[nnext] - str[next];
    //int back = str[next] - str[start];
    
    if (str[nnext] - str[next] == str[next] - str[start]) {
        while (nnext < end && (str[nnext] - str[next] == str[next] - str[start])) {
            //if (str[nnext] - str[next] != str[next] - str[start]) break;
            ++start; ++next; ++nnext;
        }
        if (nnext == end) {
            // check all the sequence.
            int check = str[next] - str[start];
            if (check == 0) return 1;
            else if (check == 1 || check == -1) return 2;
            else if (check > 1 || check < -1) return 5;
        }
    } else if (str[nnext] - str[next] == str[start] - str[next]) { // numbers are zigzag.
        while (nnext < end && (str[nnext] - str[next] == str[start] - str[next])) {
            ++start; ++next; ++nnext;
        }
        if (nnext == end) {
            return 4;
        }
    }
    return 10;
}

int dp(string & str, int start) {
    
    if (start > str.length() - 3) {
        if (start == str.length()) {
            return 0;
        }
        else  {
            return INF;
        }
    }
    
    int & ret = memo[start];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 3; i <= 5; ++i) {
        //ret = level(str, start, start + i) + dp(str, start + i) >= INF ? ret : INF;
        ret = min(ret, level(str, start, start + i) + dp(str, start + i));
    }
    return ret;
}

int exhaustive(string & str, int start) {
    
    if (start > str.length() - 3) {
        if (start == str.length()) {
            return 0;
        }
        else  {
            return INF;
        }
    }
    //if (start >= str.length()) return INF;
    //else if (start == str.length() - 1) return 0;
    
    //if (start > str.length() - 3) return INF;
    // start is always smaller or equal to str.length() - 4.
    //if (start >= str.length()) return INF;
    
    int minLev = INF;
    
    for (int i = 3; i <= 5; ++i) {
        //if (str.length() - (start + i) >= 3) {
            minLev = min(minLev, level(str, start, start + i) + exhaustive(str, start + i));
        //}
    }
    
    return minLev;
}

int main() {
    
    int tc;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i){
        string t;
        cin >> t;
        
        memset(memo, -1, sizeof(memo));
        
        cout << dp(t, 0) << endl;
        //cout << exhaustive(t, 0) << endl;
    }
    
    return 0;
}

