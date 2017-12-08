/*
 문제
 test case를 입력받는다.
 target weight을 입력받고, 무게추의 개수를 입력받음.
 무게추의 무게와 그것의 개수를 입력받음.
 최소한의 무게추를 이용해서 target weight을 만들 때, 사용하는 무게추와 그것의 개수는?
 
 */

//
//test case
//1
//15
//3
//11 1
//5 3
//1 4

#include <iostream>
using namespace std;

/*
 * Description:
 * Time complexity :
 * Space complexity :
 */

const int MAXNUM = 255;
const int INF = 9999;
int N = 0;

int memo[MAXNUM + 1][MAXNUM + 1];
int data[MAXNUM][2];
int result[MAXNUM];

//int dp(int weight, int selNum){
//    if (weight == 0) return 0;
//
//    if ((weight > 0 || weight < 0) && data[selNum][0] == 0) return MAXNUM;
//
//    int & ret = memo[weight][selNum];
//    if (ret != -1) return ret;
//    ret = MAXNUM; // count.
//
//    for (int i = 0; i <= data[selNum][1]; ++i) {
//        ret = min(ret, i + dp(weight - data[selNum][0] * i, selNum + 1));
//    }
//    return ret;
//}

int exhaustive(int idx, int weight) {
    if (weight == 0) return 0;
    
    if (weight > 0 && idx == N) return INF;
    int ret = INF;
    
    for (int i = 0; i <= data[idx][1]; ++i) {
        if (weight >= data[idx][0] * i) {
            data[idx][1] -= i;
            ret = min(ret, i + exhaustive(idx + 1, weight - data[idx][0] * i));
            data[idx][1] += i;
        }
    }
    
    return ret;
}

int dp(int idx, int weight) {
    if (weight == 0) return 0;
    if (weight > 0 && idx == N) return INF;
    
    int & ret = memo[idx][weight];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 0; i <= data[idx][1]; ++i) {
        if (weight >= data[idx][0] * i) {
            int res = i + dp(idx + 1, weight - data[idx][0] * i);
            if (res < INF) {
                if (ret > res) {
                    ret = res;
                    if (i > 0)
                        result[idx] = min(result[idx], res);
//                    else if (i == 0)
//                        result[idx] = 0;
                }
                //ret = min(ret, i + res);
                //result[idx] = min(result[idx], i);
            }
            
            //result[idx] = min(result[idx], i);
            //ret = min(ret, i + dp(idx + 1, weight - data[idx][0] * i));
        }
    }
    return ret;
}

void reconstruct(int idx, int weight, int minSelect) {
    // base case
    if (idx == N) return;
    if (memo[idx][weight] == memo[idx + 1][weight]) {
        result[idx] = 0;
        reconstruct(idx + 1, weight, minSelect);
    } else {
        // 이부분을 dp() 로 개수를 구할 수 있지 않을까.
        // dp(idx, weight)으로.
        for (int i = 0; i < weight; ++i) {
            if (memo[idx + 1][i] == minSelect) {
                //result[idx] = weight -
                
            }
        }
        
        
        
    }
}

//void reconstruct(int selNum) {
//    int & ret = result[selNum];
//
//    if (dp(weight - data[selNum][0] * i, selNum + 1) == dp(weight, selNum + 1)) {
//        result[selNum] = 0;
//        reconstruct(selNum + 1);
//    }
//
//
//    for (int i = 0; i < data[selNum][1]; ++i) {
//        if (dp(weight - data[selNum][0] * i, selNum + 1) == dp(weight, selNum + 1)) {}
//
//
//            }
//
//
//    //if (data[selNum][0] * ) {}
//
//
//}

bool selectWeight(const int data[][2], int result[], int N, int W) {
    // TODO implement your codes to here.
    return false;
}

int main(int argc, const char *argv[]) {
    int TC, W;
    cin >> TC;
    
    for (int tc = 1; tc <= TC; ++tc) {
        cin >> W;
        cin >> N;
        
        for (int i = 0; i < N; ++i) {
            cin >> data[i][0] >> data[i][1];
            result[i] = INF;
        }
        memset(memo, -1, sizeof(memo));
        
        cout << "#" << tc << endl;
        
        //int res = exhaustive(0, W);
        int res = dp(0, W);
        
        if (res < INF) cout << res << endl;
        else cout << "FAIL" << endl;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= W; ++j)
                cout << memo[i][j] << " ";
            cout << endl;
        }
        
        for (int i = 0; i < N; ++i)
            cout << data[i][0] << " " << result[i] << endl;
        
        
        
        
        
//        if (selectWeight(data, result, N, W) >= MAXNUM) {
//            cout << "FAIL" << endl;
//        } else {
//            for (int i = 0; i < N; ++i) {
//                cout << data[i][0] << " " << result[i] << endl;
//            }
//        }
    }
    return 0;
}


