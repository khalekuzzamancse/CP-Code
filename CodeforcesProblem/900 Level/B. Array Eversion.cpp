/*
https://codeforces.com/problemset/problem/1585/B
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    int n;
    vector<int> v;
    int partition(int i, int x, int cnt = 0)
    {

        if (i < 0)
            return cnt;
        if (v[i] > x)
            x = v[i], cnt++;
        i--;
        return partition(i, x, cnt);
    }

public:
    Solution()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << partition(n - 2, v[n - 1]) << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution s = Solution();
    }

    return 0;
}
