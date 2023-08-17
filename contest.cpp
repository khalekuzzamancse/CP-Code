#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;

        int n = x.size();
        string s1(n, '(');
        string s2(n, ')');
        string s = s1 + s2;
        if (n % 2 != 0)
        {
            cout << "YES" << endl;
            cout << s << endl;
        }
        else
        {
            ;
        }
    }
    return 0;
}