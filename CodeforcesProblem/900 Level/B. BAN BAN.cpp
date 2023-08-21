/*
https://codeforces.com/problemset/problem/1747/B
*/
#include <iostream>
#include <math.h>
using namespace std;
void solve(int n, int i, int j)
{
    if (i >= j)
    {
        cout << endl;
        return;
    }
    cout << i << " " << j << " ";
    j -= 3, i += 3;
    solve(n, i, j);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ceil(n / 2.0) << endl;
        int i = 2, j = 3 * n;
        solve(n, i, j);
    }

    return 0;
}