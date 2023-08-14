#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PrimalityTest
{
private:
    long long power(long long x, unsigned long long y, long long p)
    {
        long long res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    bool millerTest(long long d, long long n)
    {
        long long a = 2 + rand() % (n - 4);

        long long x = power(a, d, n);

        if (x == 1 || x == n - 1)
            return true;

        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }

        return false;
    }

public:
    bool isPrimeMillerRobin(long long n, long long k = 5)
    {
        if (n <= 1 || n == 4)
            return false;
        if (n <= 3)
            return true;

        long long d = n - 1;
        while (d % 2 == 0)
            d /= 2;

        for (long long i = 0; i < k; i++)
            if (!millerTest(d, n))
                return false;
        return true;
    }
};
bool isPrimeNaiveImproved(long long n)
{
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
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
        long long n;
        cin >> n;
        PrimalityTest p;
        for (long long i = n - 1; i >= 2; i--)
        {
            bool isPrime = p.isPrimeMillerRobin(i);
            if (isPrime)
            {
                cout << i << "\n";
                break;
            }
        }
    }
}