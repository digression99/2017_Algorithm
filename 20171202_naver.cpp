//
// 20171202_naver service
//
//3. 아래를 구현하시오.
//- 소스 코드와 수행결과를 Paste해 주세요. (작성한 코드를 인터넷 등 외부에 공개하지 마시오.)
//- Java, C, C++ 중 택1.
//
//- 파일명은 "PreTest.확장자"로 고정하며, 하나의 파일로만 구현하세요.
//
//* 읽기 좋은 코드가 좋은 코드 입니다. 읽기 좋은 코드로 작성해 주세요.
//** 시간 복잡도와 메모리 이슈, 최적의 성능에 중점을 두세요.
//*** 요구 사항이 모호하다면, 그 부분을 재정의하여 서술하고 구현하시오.
//
//문제) 입력받은 숫자를 한글 구음으로 변환하여 Standard out으로 출력하는 프로그램을 만들고자 합니다.
//PreTest.java라면, 아래와 같이 동작하도록 구현하시오. (입력값은 1 ~ 99999 의 정수에 한함.)
//
//~>java PreTest 37
//삼십칠
//
//~>java PreTest 2011
//이천십일
//
//~>java PreTest 90000
//구만
//

// ---------------------------
/*
 자세한 조건 정의
 - 숫자는 1 <= n <= 99999 (이미 정의에 있음)
 - 앞 숫자가 1이라면 일십, 일백, 일천, 일만이 아니라 그냥 십, 백, 천, 만으로 나오게 한다.
 
 */

#include <iostream>
#include <string>
using namespace std;

string numToKor[] = {"", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구", "십"};
string tenSquareKor[] = {"", "십", "백", "천", "만"};

string solve(int num, int cnt) {
    // 기저 사례.
    if (num == 0) return "";
    // 현재 자릿수를 만든다.
    int nowNum = num % 10;
    string pow = nowNum > 0 ? tenSquareKor[cnt] : "";
    string val = (nowNum > 1 && cnt > 0) || cnt == 0 ? numToKor[nowNum] : "";
    val += pow;
    // 결과를 반환한다.
    return solve(num / 10, cnt + 1) += val;
}

// test case
/*
 12
 37
 2011
 90000
 1
 10
 100
 1000
 10000
 11000
 10001
 10300
 48362
 
 */

int main() {
    int tc, n;
    cin >> tc;
    
    for (int i = 0; i < tc; ++i) {
        cin >> n;
        cout << solve(n, 0) << endl;
    }
    
    return 0;
}















