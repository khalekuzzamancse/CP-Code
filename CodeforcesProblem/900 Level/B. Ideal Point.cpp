#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
    int n, k;

public:
    void solve()
    {
        cin >> n >> k;
        int atLeft = 0, atRight = 0, singleSet = 0;
        for (int i = 1; i <= n; i++)
        {
            int l, r;
            cin >> l >> r;
            if (l == k && r == k)
                singleSet++;
            else if (l == k)
                atLeft++;
            else if (r == k)
                atRight++;
        }
         string ans;
        cout << ( singleSet>0?"YES":(atLeft>0&&atRight>0)?"YES":"NO") << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution;
        solution.solve();
    }
    return 0;
}