
/*
https://codeforces.com/problemset/problem/1593/B
Last two digits:{00,50,25,75}

*/
#include <iostream>
#include <string>

using namespace std;
class Solution
{
    string s;
    int remove(char ch1, char ch2, int cnt = 0)
    {
        if (s.back() == ch1 || s.back() == ch2)
            return cnt;
        s.pop_back();
        cnt++;
        return remove(ch1, ch2, cnt);
    }

public:
    Solution()
    {

        cin >> s;
    }
    void solve()
    {
        int cnt = remove('0', '5');
        cout << s << endl;
        if (s.back() == '0')
        {
            cout << s << " ," << cnt << "->";
            s.pop_back(), cnt += remove('0', '5');
            cout << s << " ," << cnt << endl;
        }

        else if (s.back() == '5')
        {
            cout << s << " ," << cnt << "->";
            s.pop_back();
            remove('5', '5');
            cout << s << " ," << cnt << endl;
        }
        cout << s << endl;
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
