#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// code after explanation.
const int MAXLEN = 1000;
const int INF = 987654321;
int memo[MAXLEN + 1][MAXLEN + 1];


int getMinimum(vector<int> & seq, int start, int end) {
    int sum = 0, mean = 0;
    
    for (int i = start; i < end; ++i) sum += seq[i];
    
    mean = floor(sum / end - start); // or floor; test it.
    sum = 0;
    
    for (int i = start; i < end; ++i)
        sum += (seq[i] - mean) * (seq[i] - mean);
    
    return sum;
}

int dp3(vector<int> & seq, int start, int s) {
    if (start >= seq.size() || s == 0) return 0;
    
    int & ret = memo[start][s];
    if (ret != -1) return ret;
    
    int mn = INF;
    for (int i = start + 1; i <= seq.size(); ++i) {
        mn = min(mn, dp3(seq, i, s - 1) + getMinimum(seq, start, i));
    }

    return ret = mn;
}
//test case
//2
//10 3
//3 3 3 1 2 3 2 2 2 1
//9 3
//1 744 755 4 897 902 890 6 777
//
//result
//0
//651



vector<int> tcVec = {
    2,
};

vector<int> input1Vec = {
    10, 9,
};

vector<int> input2Vec = {
    3, 3,
};
vector<vector<int> > input3Vec = {
    {3, 3, 3, 1, 2, 3, 2, 2, 2, 1},
    {1, 744, 755, 4, 897, 902, 890, 6, 777},
};

vector<int> resVec = {
    0, 651,
};

//int getMinimum(vector<int> & nums, vector<int> & selection) {
//    // find minimum selection and add it.
//    int minSum = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//
//        int mn = 9999, mnIdx = -1;
//
//        for (int j = 0; j < selection.size(); ++j) {
//            int prod = (nums[i] - selection[j]) * (nums[i] - selection[j]);
//            if (mn > prod)
//                mn = prod;
//        }
//        minSum += mn;
//    }
//    return minSum;
//}
//
//int getMinimum2(vector<int> & nums, vector<int> & selection) {
//    int minSum = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//
//        int mn = 9999;
//        int j = 0;
//
//
//    }
//
//    return 0;
//}

//int memo[1001][1001][11];
//
//int dp1(vector<int> & nums, int l, int h, int s, vector<int> & selection) {
//    return 0;
//}
//
//int exhaustive(vector<int> & nums, int l, int h, int s, vector<int> & selection) {
//    if (s == 0) {
//        return getMinimum(nums, selection);
//    }
//
//    int mn = 987654321;
//
//    for (int i = l + 1; i <= h; ++i) {
//        selection.push_back(i);
//        mn = min(mn, exhaustive(nums, i, h, s - 1, selection));
//        selection.pop_back();
//    }
//    return mn;
//}
//
//int dp(vector<int> & v1, vector<int> & v2) {
//    return 0;
//}

void TEST() {
    
    cout << "TEST START" << endl;

    auto tcIt = tcVec.begin();
    auto input1It = input1Vec.begin(); // n
    auto input2It = input2Vec.begin(); // s
    auto input3It = input3Vec.begin(); // vector
    auto resIt = resVec.begin(); // result
    
    while (tcIt != tcVec.end()) {
        int tc = *tcIt++;
        
        cout << "TEST NUM : " << tcIt - tcVec.begin() << endl;
        
        for (int i = 0; i < tc; ++i) {
            while (input1It != input1Vec.end()) {
                int res = *resIt++;
                
                //if (res != dp(*input1It++, *input2It++)) {
                //if (res != exhaustive)
                //if (res != dp3(input3It++, input)
                
                    cout << "TEST ERROR IN " << resIt - resVec.begin() << " TH CASE. " << endl;
                //}
            }
        }
    }
    
    cout << "TEST FINISHED. " << endl;
}


int main() {
    
    //void TEST();
    int tc, n, s, t, l = 9999, h = -1;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        
        memset(memo, -1, sizeof(memo));
        vector<int> seq, selection;
        cin >> n >> s;
        
        for (int j = 0; j < n; ++j) {
            cin >> t;
            //l = l > t ? t : l;
            //h = h < t ? t : h;
            
            seq.push_back(t);
        }
        sort(seq.begin(), seq.end());
        cout << dp3(seq, 0, s) << endl;
        
        //cout << exhaustive(seq, l - 1, h, s, selection) << endl;
    }
    return 0;
}

