#include <iostream>
#include <string>
using namespace std;

int memo[101][101];

bool exhaustive(string & str, int start, string & pat) {
    
//    if (start >= pat.length()) {
//        if (start >= str.length()) return true;
//        else return false;
//    }
    while (start < str.length() && start < pat.length() &&
           pat[start] == str[start]) start++;

//    if (pat[start] >= 'a' && pat[start] <= 'z') {
//        if (pat[start] != str[start]) return false;
//        while (start < str.length() && start < pat.length() &&
//               pat[start] == str[start]) start++; // jump every char.
//       // return exhaustive(str, start, pat);
//    }
    
    if (start >= pat.length()) return start == str.length();
    // if it reaches the end of the pattern, then return.
    // this means that the end of the pattern isn't *.
    
    if (pat[start] == '?') {
        if (start >= str.length()) return false;
        else return exhaustive(str, start + 1, pat);
    } else if (pat[start] == '*') { // pat[start] == '*'
        for (int i = start + 1; i < str.length(); ++i) {
            if (exhaustive(str, i, pat)) return true;
        }
//        bool isMatched = false;
//        for (int i = start; i < str.length(); ++i) {
//            isMatched = exhaustive(str, start + i, pat);
//            if (isMatched) return true;
//        }
    }
    return false;
}

int dp(string & str, string & pat, int strStart, int patStart) {
    
    int & ret = memo[strStart][patStart];
    if (ret != -1) return ret;
    
    while (strStart < str.length() && patStart < pat.length() &&
           str[strStart] == pat[patStart]) {
        strStart++; patStart++;
    }
    
    if (patStart >= pat.length()) return strStart == str.length();
    
    if (pat[patStart] == '?') {
        return ret = dp(str, pat, strStart + 1, patStart + 1);
    } else if (pat[patStart] == '*') {
        for (int i = 0; i + strStart < str.length(); ++i) {
            if (dp(str, pat, strStart + i, patStart + 1))
                return ret = 1;
        }
    }
    return ret = false;
}

int dp2(string & str, string & pat,int strStart, int patStart) {
    int & ret = memo[patStart][strStart]; // does it matter if patStart is exchanged with strStart?
    if (ret != -1) return ret;
    
    if (strStart < str.length() && patStart < pat.length() &&
        (pat[patStart] == '?' || str[strStart] == pat[patStart]))
        return ret = dp(str, pat, strStart + 1, patStart + 1);
    
    if (patStart >= pat.length()) return ret = (strStart == str.length());
    
    if (pat[patStart] == '*') {
        if (dp2(str, pat, strStart + 1, patStart) ||
            (strStart < str.length() && dp2(str, pat, strStart, patStart + 1)))
            return ret = true;
    }
    return ret = false;
}

int main()
{
    int tc = 0;

    cin >> tc;

    for (int i = 0; i < tc; ++i)
    {
        string pat;
        cin >> pat;
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            string temp;
            cin >> temp;

            memset(memo, -1, sizeof(memo));

            if (dp2(temp, pat, 0, 0)) cout << temp << endl;
            else cout << "not matched : " << temp << endl;
            
            
            //if (exhaustive(temp, 0, pat)) cout << temp << endl;
            //else cout << "not matched : " << temp << endl;
        }
    }

    return 0;
}

