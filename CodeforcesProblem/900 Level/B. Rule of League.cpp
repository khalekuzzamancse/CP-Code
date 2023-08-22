/*
https://codeforces.com/problemset/problem/1735/B
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, x, y, winPerPlayer;
    bool isPossible()
    {
        bool mayPossible = (x == 0 && y == 0) || (x != 0 && y != 0) ? false : true;
        if (mayPossible)
        {
            winPerPlayer = (x == 0 ? y : x);
            mayPossible = (n - 1) % winPerPlayer == 0;
        }
        return mayPossible;
    }
    void winGame(int i)
    {
        int times = winPerPlayer;
        while (times--)
            cout << i << " ";
    }

public:
    Solution()
    {
        cin >> n >> x >> y;
    }
    void solve()
    {
        if (isPossible())
        {
            for (int i = 1; i < n; i += winPerPlayer)
                winGame(i);
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
};

main()
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