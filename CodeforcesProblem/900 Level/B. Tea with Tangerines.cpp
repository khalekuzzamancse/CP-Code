/*
https://codeforces.com/problemset/problem/1735/B
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int n, minPiece;
    vector<int> v;

    int getSteps(int i)
    {
        int maxPossibleSize = 2 * v[0] - 1;
        if (v[i] % v[0] == 0)
            return (v[i] / maxPossibleSize) - 1;
        else
            return v[i] / maxPossibleSize;
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
        minPiece = v[0];
    }
    void solve()
    {
        int steps = 0;
        for (int i = 1; i < n; i++)
            steps += getSteps(i);
        cout << steps << endl;
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