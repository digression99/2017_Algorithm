
//vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
//{
//    vector<string> ans;
//    vector<bitset<16> > bitMap;
//    
//    for (int i = 0; i < n; ++i)
//    {
//        bitMap.push_back(bitset<16>(arr1[i]) | bitset<16>(arr2[i]));
//        string str = "                ";
//        
//        
//        for (int j = 0; j < n; ++j)
//        {
//            if (bitMap[i][j]) str[n - j - 1] = '#';
//        }
//        ans.push_back(str.substr(0, n));
//    }
//    
//    for (int i = 0; i < n; ++i)
//    {
//        cout << ans[i] << endl;
//    }
//    return ans;
//}




//int main()
//{
//    int n = 5;
//    vector<int> arr1 = {9, 20, 28, 18, 11};
//    vector<int> arr2 = {30, 1, 21, 17, 28};
//    
//    solution(n, arr1, arr2);
//    
//    
//    
//    
//    
//    return 0;
//}
