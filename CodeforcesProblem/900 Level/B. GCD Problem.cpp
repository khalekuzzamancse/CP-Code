/*
https://codeforces.com/problemset/problem/1617/B
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n--;
        int x = n / 2, y = n / 2;
        if (n % 2 == 0)
        {
            if (x % 2 == 0)
                x--, y++;
            else
                x -= 2, y += 2;
        }
        else
            x++;
        cout << x << " " << y << " " << 1 << endl;
    }

    return 0;
}