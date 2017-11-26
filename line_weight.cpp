#include <iostream>

using namespace std;

/*
 * Description:
 * Time complexity :
 * Space complexity :
 */

const int MAXNUM = 255;

int memo[MAXNUM + 1][MAXNUM + 1];
int data[MAXNUM][2];
int result[MAXNUM];

int dp(int weight, int selNum){
    if (weight == 0) return 0;
    
    if (weight == 0) return 0;
    if (weight > 0 && data[selNum][0] == 0) return MAXNUM;
    
    int & ret = memo[weight][selNum];
    if (ret != -1) return ret;
    ret = MAXNUM; // count.
    
    for (int i = 0; i <= data[selNum][1]; ++i) {
        ret = min(ret, i + dp(weight - data[selNum][0] * i, selNum + 1));
    }
    return ret;
}

void reconstruct(int selNum) {
    int & ret = result[selNum];
    
    if (dp(weight - data[selNum][0] * i, selNum + 1) == dp(weight, selNum + 1)) {
        result[selNum] = 0;
        reconstruct(selNum + 1);
    }
    
    
    for (int i = 0; i < data[selNum][1]; ++i) {
        if (dp(weight - data[selNum][0] * i, selNum + 1) == dp(weight, selNum + 1))
        
        
    }
    
    
    if (data[selNum][0] * )
    
    
}

bool selectWeight(const int data[][2], int result[], int N, int W) {
    // TODO implement your codes to here.
    return false;
}

int main(int argc, const char *argv[]) {
    int TC, W, N;
    cin >> TC;
    
    for (int tc = 1; tc <= TC; ++tc) {
        cin >> W;
        cin >> N;
        
        int data[N][2];
        int result[N];
        
        for (int i = 0; i < N; ++i) {
            cin >> data[i][0] >> data[i][1];
            result[i] = 0;
        }
        
        cout << "#" << tc << endl;
        if (selectWeight(data, result, N, W) >= MAXNUM) {
            cout << "FAIL" << endl;
        } else {
            for (int i = 0; i < N; ++i) {
                cout << data[i][0] << " " << result[i] << endl;
            }
        }
    }
    return 0;
}

