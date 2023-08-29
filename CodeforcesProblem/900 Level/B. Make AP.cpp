/*
https://codeforces.com/problemset/problem/1624/B
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        bool case_01 = (a + c) % (2 * b) == 0, case_02 = (2 * b - c) % a == 0 && (2 * b - c) > 0, case_03 = (2 * b - a) % c == 0 && (2 * b - a) > 0;
        if (case_01 || case_02 || case_03)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}