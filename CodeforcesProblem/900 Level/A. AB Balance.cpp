/*
https://codeforces.com/problemset/problem/1606/A
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s[s.length() - 1] = s[0];
        cout << s << endl;
    }

    return 0;
}
