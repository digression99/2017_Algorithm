#include <iostream>
#include <vector>
using namespace std;

int m[100][100];

string pat, str;

bool dp(int patPos, int strPos)
{
    int & ret = m[patPos][strPos];
    if (ret != -1) return ret;
    
    //if (patPos == pat.length() && strPos == str.length()) return ret = 1;
    
    // patPos == pat.length()일 경우 s도 끝이 아니라면 리턴 false.
    if (patPos == pat.length()) return ret = (strPos == str.length());
    // strPos == str.length()라면 와일드카드일 경우만 참.
    
//    if ((patPos == pat.length() && strPos < str.length()) ||
//        (patPos < pat.length() && strPos == str.length()))
//        return ret = 0;
    
    if (pat[patPos] == '*') { // patPos + 1, strPos : * is none.
        //if (strPos == str.length() - 1) return ret = 1;
        if (dp(patPos + 1, strPos) || // * is none case.
            dp(patPos, strPos + 1)) // * matched to one char.
            return ret = 1;
        else ret = 0;
    } else if (pat[patPos] == '?' || (pat[patPos] == str[strPos]))
            return dp(patPos + 1, strPos + 1);

    return ret = 0;
}

// original idea.
//bool mydp(int patPos, int strPos)
//{
//    for (int i = 0; i < str.length(); ++i)
//    {
//        if ((patPos > 0 && m[patPos - 1][i]) && pat[patPos] == '?' || pat[patPos] == str[strPos])  // 그 전이 참.
//        
//        
//        
//        
//        
//    }
//    
//    
//    return false;
//}


bool dp(string & pat, string & str) // patlen : pat.length(), strl : str.length()
{
    int wl = (int)pat.length();
    int sl = (int)str.length();
    
    
    
    for (int i = 0; i < wl; ++i)
    {
        if (pat[i] == '*' || pat[i] == '?')
        {
            m[i][0] = true;
            for (int j = 1; j < sl; ++j)
            {
                
            }
            
            
            
        }
        
        

    }
    
    
    
    
    return false;
    
    
    
}

//1
//*p*p
//1
//helpelp

//1
//*p*
//1
//helpp


int main()
{
    int c, n;
    vector<string> strs;
    //string pat;
    //string end;
    
    cin >> c;
    cin >> pat;
    
    for (int i = 0; i < c; ++i)
    {
        cin >> n;
        
        for (int j = 0; j < n; ++j)
        {
            cin >> str;
            
            memset(m, -1, sizeof(m));
            
            if (dp(0, 0)) cout << str << endl;
            //if (dp(pat, str) == 1) cout << str << endl;
        }
    }
    
    //cin >> end;
    
    return 0;
}
