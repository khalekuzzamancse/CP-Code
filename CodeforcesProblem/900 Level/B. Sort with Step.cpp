/*
Link:
https://codeforces.com/problemset/problem/1823/B

*/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int pi;
            cin >> pi;
            if (pi % k != i % k)
                cnt++;
        }
        if (cnt == 0)
            cout << 0 << endl;
        else if (cnt == 2)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}