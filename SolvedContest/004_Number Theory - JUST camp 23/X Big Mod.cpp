
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
    long long a, b, m;
    while (cin >> a >> b >> m)
        cout << getModularExponent(a, b, m) << "\n";

    return 0;
}