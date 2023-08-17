/*
Link: https://codeforces.com/problemset/problem/1828/B

*/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int kMax = 0;
        for (int i = 1; i <= n; i++)
        {
            int pi;
            cin >> pi;
            int positionDifference = abs(pi - i);
            kMax = __gcd(kMax, positionDifference);
        }
        cout << kMax << endl;
    }

    return 0;
}