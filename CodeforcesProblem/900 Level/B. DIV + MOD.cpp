/*
https://codeforces.com/problemset/problem/1650/B
*/

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, a;
        cin >> l >> r >> a;
        if (l == r)
        {
            cout << l / a + l % a << endl;
        }
        else
        {
            long long x = r / a;
            long long y = x * a - 1;
            if (y < l)
                y = r;
            cout << y / a + y % a << endl;
        }
    }

    return 0;
}