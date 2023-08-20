#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
    vector<int> p;
    int n, k;

    int getSortedSequenceLength(int i = 0, int current = 1, int cnt = 0)
    {
        if (i >= n)
            return cnt;
        if (p[i] == current)
            current++, cnt++;
        return getSortedSequenceLength(i + 1, current, cnt);
    }

public:
    Solution()
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            p.push_back(x);
        }
    }
    void solve()
    {

        int ans = ceil((n - getSortedSequenceLength()) / (k * 1.0));
        cout << ans << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution = Solution();
        solution.solve();
    }

    return 0;
}