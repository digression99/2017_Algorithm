#include <iostream>
using namespace std;
#include <map>
#include <cmath>

int main()
{
    int A, p, sum, k, i = 0;
    map<int, int> dic;
    
    cin >> A >> p;
    
    k = sum = A;
    
    while (!dic.count(sum))
    {
        dic[sum] = i++;
        k = sum;
        sum = 0;
        while (k > 0)
        {
            sum += pow(k % 10, p);
            k /= 10;
        }
    }
    
    cout << dic[sum] << endl;
    
    return 0;
}
