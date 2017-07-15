//
// chinese remainder theorem
//
// -> num[0 .. k - 1], rem[0 .. k - 1] 이 있다.
// 여기서 num배열 안의 수들은 모두 서로소이다. (coprime)
// 우리의 목적은 어떤 수 x가 있어서
// 그 x가
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ...
// x % [k - 1] = rem[k - 1]
// 를 만족하는 최소의 x를 찾는 것이다.
// 예시
//Input:  num[] = {5, 7}, rem[] = {1, 3}
//Output: 31
//Explanation:
//31 is the smallest number such that:
//(1) When we divide it by 5, we get remainder 1.
//(2) When we divide it by 7, we get remainder 3.
//
//Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
//Output: 11
//Explanation:
//11 is the smallest number such that:
//(1) When we divide it by 3, we get remainder 2.
//(2) When we divide it by 4, we get remainder 3.
//(3) When we divide it by 5, we get remainder 1.
//

//x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
//Where 0 <= i <= n-1
//
//rem[i] is given array of remainders
//
//prod is product of all given numbers
//prod = num[0] * num[1] * ... * num[k-1]
//
//pp[i] is product of all but num[i]
//pp[i] = prod / num[i]
//
//inv[i] = Modular Multiplicative Inverse of
//pp[i] with respect to num[i]

//Let us take below example to understand the solution
//num[] = {3, 4, 5}, rem[] = {2, 3, 1}
//prod  = 60
//pp[]  = {20, 15, 12}
//inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
//// (12*3)%5 = 1
//
//x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] +
//     rem[2]*pp[2]*inv[2]) % prod
//= (2*20*2 + 3*15*3 + 1*12*3) % 60
//= (40 + 135 + 36) % 60
//= 11

// A C++ program to demonstrate working of Chinise remainder
// Theorem
#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
// http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1)
        return 0;
    
    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;
        
        t = m;
        
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
        
        t = x0;
        
        x0 = x1 - q * x0;
        
        x1 = t;
    }
    
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}

// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k)
{
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    
    // Initialize result
    int result = 0;
    
    // Apply above formula
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    
    return result % prod;
}

// Driver method
int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}
