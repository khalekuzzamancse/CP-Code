/*
https://codeforces.com/problemset/problem/1675/B
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{

    int n;
    vector<int> v;

    bool checkDivisibility(int n, int i)
    {
        while (n > i)
        {
            n /= 2;
        }
        return n == i;
    }

public:
    Solution()
    {
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }
    void solve()
    {
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (!checkDivisibility(v[i], i))
            {
                possible = false;
                break;
            }
        }
        cout << (possible == true ? "YES" : "NO") << endl;
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