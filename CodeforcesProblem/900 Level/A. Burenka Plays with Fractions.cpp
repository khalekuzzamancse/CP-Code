/*
https://codeforces.com/problemset/problem/1720/A
*/
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long x = a * d, y = b * c;
        if (x == y)
            cout << 0 << endl;
        else if (x == 0 || y == 0)
            cout << 1 << endl;
        else if (x % y == 0 || y % x == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}