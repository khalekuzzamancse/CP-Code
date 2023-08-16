/*

https://codeforces.com/problemset/problem/1855/B

Given a positive integer n find the maximum size of an interval [l,r]
 of positive integers such that, for every i in the interval (i.e., l≤i≤r
), n is a multiple of i
.

Given two integers l≤r
, the size of the interval [l,r]
 is r−l+1
 (i.e., it coincides with the number of integers belonging to the interval
*/

#include <iostream>
#include <math.h>
using namespace std;
long long ans(long long n, long long i)
{
    if (n % i != 0)
        return i - 1;
    return ans(n, i + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i = 1;
        cout << ans(n, 1) << endl;
    }

    return 0;
}
