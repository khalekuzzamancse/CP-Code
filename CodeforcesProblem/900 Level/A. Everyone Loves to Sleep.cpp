/*
https://codeforces.com/problemset/problem/1720/A
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int h, m;
        cin >> h >> m;
        int sleepTime = 60 * h + m;

        int ans = 24 * 60;
        for (int i = 0; i < n; ++i)
        {
            cin >> h >> m;
            int tillNextAlarm = 60 * h + m - sleepTime;
            if (tillNextAlarm < 0)
                tillNextAlarm += 24 * 60;
            ans = min(ans, tillNextAlarm);
        }
        cout << ans / 60 << " " << ans % 60 << endl;
    }

    return 0;
}