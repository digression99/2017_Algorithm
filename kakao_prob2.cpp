#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
//
//캐시
//
//지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.
//이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데, 제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.
//어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.
//
//어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.
//
//입력 형식
//캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다.
//cacheSize는 정수이며, 범위는 0 ≦ cacheSize ≦ 30 이다.
//cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
//각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.
//출력 형식
//입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.
//조건
//캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
//cache hit일 경우 실행시간은 1이다.
//cache miss일 경우 실행시간은 5이다.
//입출력 예제
//캐시크기(cacheSize)	도시이름(cities)	실행시간
//3	["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	50
//3	["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]	21
//2	["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	60
//5	["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	52
//2	["Jeju", "Pangyo", "NewYork", "newyork"]	16
//0	["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	25


int solution(string dr) {
    vector<int> scores(3);
    int nowIdx = -1;
    unordered_map<char, int> hash;
    
    hash['S'] = 1;
    hash['D'] = 2;
    hash['T'] = 3;
    
    for (int i = 0; i < dr.length(); ++i)
    {
        if ('0' <= dr[i] && '9' >= dr[i])
        {
            if (dr[i] == '1' && dr[i + 1] == '0') scores[++nowIdx] = 10;
            else scores[++nowIdx] = dr[i] - '0';
        }
        else if (dr[i] == 'S' || dr[i] == 'D' || dr[i] == 'T')
        {
            scores[nowIdx] = pow(scores[nowIdx], hash[dr[i]]);
        }
        else
        {
            if (dr[i] == '*')
            {
                for (int j = 0; j < 2 && (nowIdx - j >= 0); ++j) scores[nowIdx - j] *= 2;
                //for (int j = nowIdx; j >= 0; --j) scores[j] *= 2;
            }
            else
            {
                scores[nowIdx] = -scores[nowIdx];
            }
        }
    }

    return scores[0] + scores[1] + scores[2];
}
//1   1S2D*3T	37	11 * 2 + 22 * 2 + 33
//2	1D2S#10S	9	12 + 21 * (-1) + 101
//3	1D2S0T	3	12 + 21 + 03
//4	1S*2T*3S	23	11 * 2 * 2 + 23 * 2 + 31
//5	1D#2S*3S	5	12 * (-1) * 2 + 21 * 2 + 31
//6	1T2D3D#	-4	13 + 22 + 32 * (-1)
//7	1D2S3T*

int main()
{
    string str1 = "1S2D*3T";
    string str2 = "1D2S#10S";
    string str3 = "1D2S0T";
    string str4 = "1S*2T*3S";
    string str5 = "1D#2S*3S";
    string str6 = "1T2D3D#";
    string str7 = "1D2S3T*";
    
    cout << solution(str1) << endl;
    cout << solution(str2) << endl;
    cout << solution(str3) << endl;
    cout << solution(str4) << endl;
    cout << solution(str5) << endl;
    cout << solution(str6) << endl;
    cout << solution(str7) << endl;
    
    
    
    return 0;
}










