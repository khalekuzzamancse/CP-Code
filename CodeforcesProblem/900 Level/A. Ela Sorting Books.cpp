/*
https://codeforces.com/problemset/problem/1737/A
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
private:
    int n, k;
    string s;
    map<char, int> frequency;
    void calculateFrequency()
    {
        for (char it : s)
            frequency[it]++;
    }

    char getMEX()
    {
        int stackLength = n / k;
        for (int i = 0; i < stackLength; i++)
        {
            if (frequency[i + 'a'] == 0)
                return i + 'a';
            else
                frequency[i + 'a']--;
        }
        return stackLength + 'a';
    }

public:
    Solution()
    {
        cin >> n >> k;
        cin >> s;
        calculateFrequency();
    }
    void solve()
    {
        string ans = "";
        for (int i = 1; i <= k; i++)
            ans.push_back(getMEX());
        std::sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
};
char getMEX(string &s)
{
    char mex = 'a';
    for (char it : s)
        if (it == mex)
            mex++;
    return mex;
}

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