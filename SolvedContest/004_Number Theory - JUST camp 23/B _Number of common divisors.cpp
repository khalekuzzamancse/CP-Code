#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int getCommonDiv(int gcd)
{

    int count = 0;

    for (int i = 1; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            count += 2;
            if (i * i == gcd)
            {
                count--;
            }
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        cout << getCommonDiv(g) << "\n";
    }
    return 0;
}
