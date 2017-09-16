#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

//캐시크기(cacheSize)	도시이름(cities)	실행시간
//3	["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	50
//3	["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]	21
//2	["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	60
//5	["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	52
//2	["Jeju", "Pangyo", "NewYork", "newyork"]	16
//0	["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	25


bool compareFunc(pair<string, int> front, pair<string, int> end)
{
    return front.second < end.second;
}


int solution(int cSize, vector<string> cities) {
    
    unordered_map<string, int> hash;
    int time = 0;
    //hash.find(cities[0]) != hash.end() // exist condition
    std::for_each(cities.begin(), cities.end(), [](string & s) {
        std::for_each(s.begin(), s.end(), [](char & c) {
            if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
        });
    });
    
    for (int i = 0; i < cities.size(); ++i) cout << cities[i] << endl;
    
    for (int i = 0; i < cities.size(); ++i)
    {
        auto it = hash.find(cities[i]); // pos
        
        if (it == hash.end())
        { // cache miss
            time += 5;
            
            if (cSize == 0) continue;
            
            if (hash.size() == cSize)
            {
                auto maxEl = std::max_element(hash.begin(), hash.end(), [](pair<string, int> front, pair<string, int> end) {
                    return front.second < end.second;
                });
                cout << maxEl->first << endl;
                hash.erase(maxEl);
            }
            
            hash[cities[i]] = 0;
        }
        else
        { // cache hit
            it->second = 0;
            time++;
        }
        
        for (auto dat : hash)
        {
            hash[dat.first] += 1;
        }
        
        //for (auto dat : hash) dat.second = dat.second + 1;
        
        //for (int i = 0; i < datNum; ++i) freq[i]++;
        for (auto dat : hash) cout << dat.first << " " << dat.second << endl;
        cout << endl;
    }
    
    return time;
}

void test()
{
    unordered_map<string, int> hash;
    hash["hi"] = 1;
    hash["come"] = 5;
    hash["bye"] = 10;
    hash["jesus"] = 3;
    
    auto it = max_element(hash.begin(), hash.end(), compareFunc);
    
    cout << it->first << " " << it->second << endl;
}

int main()
{
    // tc1
//    vector<string> strs = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
//    int n = 3;
    
    // tc2
//    vector<string> strs = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
//    int n = 3;
    
    // tc3
    vector<string> strs = {"Jeju", "Pangyo", "NewYork", "newyork"};
    int n = 2;
    
    cout << solution(n, strs) << endl;
    
    
    
    
    //test();
//    map<char, int> hash;
//    
//    hash['c'] = 3;
//    hash['d'] = 4;
//    
//    hash['e'] = 100;
//    
//    hash['a'] = 2;
    
    //for (auto dat : hash) cout << dat.first << endl;
    
    
    
    return 0;
}
