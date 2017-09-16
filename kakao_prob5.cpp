#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;


int solution(string str1, string str2) {
    
    multiset<string> A, B, inter, uni;
    
    // generate sets.
    
    for_each(str1.begin(), str1.end(), [](char & c) {c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;});
    for_each(str2.begin(), str2.end(), [](char & c) {c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;});
    
    for (int i = 0; i < str1.length() - 1; ++i)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
        {
            A.insert(str1.substr(i, 2));
        }
    }
    
    for (int i = 0; i < str2.length() - 1; ++i)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
        {
            B.insert(str2.substr(i, 2));
        }
    }
    
    if (A.size() == 0 && B.size() == 0) return 65536;
    
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(inter, inter.begin()));
    set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(uni, uni.begin()));
    
//    double res = double(inter.size()) / uni.size();
//    int ans = res * 65536;
//    return int(ans);
//    
    
    return int((double(inter.size()) / uni.size()) * 65536);
}

int main()
{
    string str1 = "FRANCE";
    string str2 = "french";
    
    cout << solution(str1, str2);
    
    
//    multiset<string> set1;
//    multiset<string> set2;
//    vector<string> res;
//    
//    set1.insert("aa");
//    set1.insert("a1");
//    set1.insert("aa");
//    
//    set2.insert("aa");
//    set2.insert("a2");
//    set2.insert("aa");
//    
//    multiset<string> intersect;
//    
//    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersect, intersect.begin()));
//    
//    for (auto it = intersect.begin(); it != intersect.end(); ++it) cout << *it << endl;

//    multiset<int> A = {1, 1, 2, 2, 3};
//    multiset<int> B = {1, 2, 2, 4, 5};
//    
//    multiset<int> Intersect;
//    multiset<int> unionSet;
//    set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(Intersect, Intersect.begin()));
//    set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(unionSet, unionSet.begin()));
//    
//    for (auto it = Intersect.begin(); it != Intersect.end(); ++it) cout << *it << endl;
//    for (auto it = unionSet.begin(); it != unionSet.end(); ++it) cout << *it << endl;
    
                    
    
    
    
    
    
    
    //auto it = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), res.begin());
    
    //for (; it != res.end(); ++it) cout << *it << endl;
//    
//    for (; it != set3.end(); ++it)
//        cout << *it << endl;
    
    

    return 0;
}
