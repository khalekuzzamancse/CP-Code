#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << (i % 2 == 0 ? i - 1 : i + 1) << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}