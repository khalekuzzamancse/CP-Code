
#include <iostream>
using namespace std;

long long getModularExponent(long long base, unsigned long long exponent, long long mod)
{
    long long res = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent & 1)
            res = (res * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return res;
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
        long long a, b;
        cin >> a >> b;
        cout << getModularExponent(a, b, 10) << "\n";
    }

    return 0;
}