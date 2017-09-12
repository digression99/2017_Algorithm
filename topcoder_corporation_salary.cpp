//
// 20170911 - topcoder_corporation_salary
//
// - 부하 없으면 셀러리 1, 부하 있으면 급여의 합.
//
//
//
//
//
//


#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


class CorporationSalary {
public:
    
    long long m[51]; // max n : 50
    int l = 0;
    
    long long dp(vector<string> & g, int v)
    {
        if (m[v] > -1) return m[v];
        long long ret = 0;
        bool check = false;
        for (int i = 0; i < l; ++i)
        {
            if (g[v][i] == 'Y') {
                check = true;
                ret += dp(g, i);
            }
        }
        if (check) return m[v] = ret;
        else return m[v] = 1;
        //return m[v] = ret;
    }
    
    
    long long totalSalary(vector<string> relations)
    {
        this->l = (int)relations.size();
        long long res = 0;
        
        memset(m, -1, sizeof(m));
        //for_each(begin(m), end(m), [](int d){d = -1;});
        
        for (int i = 0; i < l; ++i)
        {
            if (m[i] > -1) res += m[i];
            else
                res += dp(relations, i);
            
            //res += dp(relations, i);
        }
        return res;
    }
};

vector<vector<string> > relVecs = {
    {"N"},
    {"NNYN", "NNYN", "NNNN", "NYYN"},
    {"NNNNNN", "YNYNNY", "YNNNNY", "NNNNNN", "YNYNNN", "YNNYNN"},
};

vector<long long> resVecs = {
    1, 5, 17
};

void TEST()
{
    cout << "TEST START" << endl;
    CorporationSalary obj = CorporationSalary();
    
    auto itRel = relVecs.begin();
    auto itRes = resVecs.begin();
    
    while (itRel != relVecs.end())
    {
        long long res = obj.totalSalary(*itRel++);
        if (res != *itRes++)
        {
            cout << "TEST FAIL IN " << itRel - relVecs.begin() << " TH TESTCASE." << endl;
            return;
        }
    }
    
    cout << "TEST FINISHED." << endl;
}

int main()
{
    TEST();
    
    return 0;
}
