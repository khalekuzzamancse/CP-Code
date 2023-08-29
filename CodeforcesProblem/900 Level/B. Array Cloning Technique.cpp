/*
https://codeforces.com/problemset/problem/1665/B
*/

#include <iostream>
#include <map>
using namespace std;

class Solution
{
    long long n, swapNeeded;
    map<long long, long long> frequency;
    int getMaxFrequency()
    {
        long long _max = 0;
        for (auto it : frequency)
            _max = max(_max, it.second);
        return _max;
    }
    int getNumberOfCopy()
    {
        int cnt = 0;
        long long ini = getMaxFrequency();
        while (ini <= swapNeeded)
        {

            ini *= 2;
            cnt++;
        }
        return cnt;
    }

public:
    Solution()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            frequency[x]++;
        }
    }
    void solve()
    {
        long long _max = getMaxFrequency();
        n -= _max;
        long long operations = n;
        while (n > 0)
        {
            operations++;
            n -= _max;
            _max *= 2;
        }
        cout << operations << endl;
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