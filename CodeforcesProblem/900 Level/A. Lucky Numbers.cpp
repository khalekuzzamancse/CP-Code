#include <iostream>

#include <algorithm>
using namespace std;
class Solution
{
    const int MAX_POSSIBLE = 9;
    int getMaxDiff(int n)
    {
        string s = to_string(n);
        std::sort(s.begin(), s.end());
        return s[s.length() - 1] - s[0];
    }

public:
    void solve()
    {
        int l, r;
        cin >> l >> r;
        int diff = -1;
        int num;
        for (int i = l; i <= r; i++)
        {

            int d = getMaxDiff(i);
            if (d > diff)
                diff = d, num = i;
            if (diff == MAX_POSSIBLE)
                break;
        }
        cout << num << endl;
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