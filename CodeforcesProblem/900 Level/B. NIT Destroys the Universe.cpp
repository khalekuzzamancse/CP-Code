/*
https://codeforces.com/problemset/problem/1696/B
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    int n;
    vector<int> v;

public:
    Solution()
    {

        cin >> n;
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
    }
    int solve()
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (v[i - 1] == 0 && v[i] != 0)
                ans++;
        ans = min(ans, 2);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution = Solution();
        cout << solution.solve() << endl;
    }

    return 0;
}