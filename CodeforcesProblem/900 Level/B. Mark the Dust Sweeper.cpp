/*
https://codeforces.com/problemset/problem/1705/B
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int n;
    vector<long long> v;
    int getNumberOfLeadingZeros(int i = 0)
    {
        if (i > n - 2 || v[i] != 0)
            return i;
        i++;
        return getNumberOfLeadingZeros(i);
    }
    long long getOperations(int i = 0, long long cnt = 0)
    {
        if (i == n - 1)
            return cnt;
        cnt += (v[i] == 0 ? 1 : v[i]);
        i++;
        return getOperations(i, cnt);
    }

public:
    Solution()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }
    }
    void solve()
    {
        cout << getOperations() - getNumberOfLeadingZeros() << endl;
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