//
// 20170818_geeksforgeeks Dynamic programming
//
// exponential 한 솔루션을 찾은 후에 그것에 메모이제이션을 넣어 dp를 완성하는 방법.
// 그런데 이 방법 말고 다른 방법은 없을까.
//
// dp문제를 푼다면, top down과 bottom up 방식 모두를 이용해서 풀고 완전하게 이해하자.
// state transition, base case, optimal substructure을 잘 정의하고 넘어가야 한다.
//
//

#include <iostream>
using namespace std;

/*
 fibonacci
 
 const int NIL = -1;
 const int MAX = 101;
 
 long int lookup[MAX];
 
 void init() {
 for (int i = 0; i <= MAX; ++i)
 {
 lookup[i] = NIL;
 }
 }
 
 // memoization
 long int fib(int n)
 {
 // Check if lookup[n] is not nil.
 if (lookup[n] != NIL) return lookup[n];
 
 if (n <= 1) // base case. if n == 1, lookup[1] starts in 1.
 lookup[n] = n;
 else
 lookup[n] = fib(n - 1) + fib(n - 2); // if n == 2 -> fib(1) + fib(0) -> lookup[1] + lookup[0] = 1
 
 return lookup[n];
 }
 
 // tabulation
 long int fib2(int n)
 {
 long int f[MAX + 1];
 f[0] = 0;
 f[1] = 1;
 
 for (int i = 2; i <= n; ++i)
 {
 f[i] = f[i - 1] + f[i - 2];
 }
 
 return f[n];
 }
 */

/*
 prob. you can only use 1, 3, 5 to make the specific number n.
 ex) to form 6,
 
 1+1+1+1+1+1
 1+1+1+3
 1+1+3+1
 1+3+1+1
 3+1+1+1
 3+3
 1+5
 5+1
 
 -> 8 ways to make it.
 
 make the algorithm that can compute how many ways to form n.
 */

const int MAX = 100;

int m[MAX + 1];


// top down method.
int dp(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (m[n] > 0) return m[n];
    
    m[n] = dp(n - 1) + dp(n - 3) + dp(n - 5);
    
    return m[n];
}

// bottom up method.
int dp2(int n)
{
    int m[MAX] = { 0, };
    m[0] = 1;
    m[1] = 1;
    m[2] = 1;
    //m[3] = 2;
    
    for (int i = 3; i <= n; ++i)
    {
        if (i - 1 >= 0) m[i] += m[i - 1];
        if (i - 3 >= 0) m[i] += m[i - 3];
        if (i - 5 >= 0) m[i] += m[i - 5];
    }
    
    return m[n];
}




int main()
{
    /*
     fibonacci runner
     
     init();
     //cout << fib(50) << endl;
     
     cout << fib2(50) << endl;
     */
    
    cout << dp(10) << endl;
    cout << dp2(10) << endl;
    
    
    return 0;
}
