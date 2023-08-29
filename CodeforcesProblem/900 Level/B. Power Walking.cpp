/*
https://codeforces.com/problemset/problem/1642/B
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> frequency;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            frequency[x]++;
        }
        for (int k = 1; k <= n; k++)
        {
            int ans = k - 1;
            if (k <= frequency.size())
                ans += frequency.size() - (k - 1);
            else
                ans++;
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}