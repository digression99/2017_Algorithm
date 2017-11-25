//
//test case
//9
//aaa aaa
//a?a aaa
//ab aa
//*ab aaaab
//a*b*c abc
//a*b*c a
//b*ccd bd
//*? abcdefg
//a*?b alineb
//
//result
//O
//O
//X
//O
//O
//O
//X
//O
//O


#include <iostream>
#include <cstring>

using namespace std;

const int MAXLEN = 1000;

int memo[MAXLEN + 1][MAXLEN + 1];
string pattern, target_string;
int patLen, sLen;

/*
 * Description :
 * Time complexity :
 * Space complexity :
 */
bool match(int patIdx, int sIdx) {
    if (patIdx == patLen && sIdx == sLen)
        return true;
    int & ret = memo[patIdx][sIdx];
    if (ret != -1) return ret;
    
    if (pattern[patIdx] == '*') {
        if (patIdx + 1 <= patLen && pattern[patIdx + 1] == '?') {
            for (int i = sIdx; i <= sLen; ++i) {
                if (match(patIdx + 2, i)) return ret = true;
            }
        } else if (patIdx + 1 <= patLen && (pattern[patIdx + 1] >= 'a' && pattern[patIdx + 1] <= 'z')) {
//            int start = sIdx;
//            while (start <= sLen) {
//                if (pattern[patIdx + 1] == target_string[start]) {
//                    if (match(patIdx + 2, start)) return ret = true;
//                }
//                else break;
//                ++start;
//            }
            
            
            for (int i = sIdx; i <= sLen; ++i) {
                if (pattern[patIdx + 1] == target_string[i]) {
                    if (match(patIdx + 2, i)) return ret = true;
                } else return ret = match(patIdx + 2, i);
            }
        }
    } else if (pattern[patIdx] == '?') {
        return ret = match(patIdx + 1, sIdx + 1);
    } else if (pattern[patIdx] >= 'a' && pattern[patIdx] <= 'z') {
        if (pattern[patIdx] == target_string[sIdx])
            return ret = match(patIdx + 1, sIdx + 1);
    }
    // TODO implement your codes to here.
    return false;
}

int main(int argc, const char *argv[]) {
    int TC;
    
    cin >> TC;
    for (int t = 0; t < TC; t++) {
        memset(memo, -1, sizeof(memo));
        cin >> pattern >> target_string;
        patLen = (int)pattern.length(), sLen = (int)target_string.length();
        cout << (match(0, 0) ? 'O' : 'X') << endl;
    }
    return 0;
}


