/*
https://codeforces.com/problemset/problem/1525/B
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    int n;
    vector<int> v;
    bool isSorted(int i = 0)
    {
        if (i == n)
            return true;
        if (v[i] != i + 1)
            return false;
        i++;
        return isSorted(i);
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
        int ans = isSorted() ? 0 : (v[0] == 1 || v[n - 1] == n ? 1 : (v[0] == n && v[n - 1] == 1) ? 3
                                                                                                  : 2);
        cout << ans << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution();
    }

    return 0;
}
