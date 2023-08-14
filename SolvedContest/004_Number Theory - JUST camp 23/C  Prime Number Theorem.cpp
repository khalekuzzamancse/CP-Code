#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e8 + 5;
bool sievePrimes[N];
vector<int> primes;
const bool cross = false, notCross = true;
void sieve()
{
    fill(sievePrimes, sievePrimes + N, notCross);
    sievePrimes[0] = sievePrimes[1] = cross;
    for (int i = 2; i * i <= N; i++)
    {
        if (sievePrimes[i] == notCross)
        {
            for (int j = i * i; j <= N; j += i)
            {
                sievePrimes[j] = cross;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (sievePrimes[i])
            primes.push_back(i);
    }
}

int pi(int x)
{
    return upper_bound(primes.begin(), primes.end(), x) - primes.begin();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int x;
    while (cin >> x && x != 0)
    {
        double pi_x = pi(x);
        double error = abs(pi_x - x / log(x)) / pi_x * 100;
        printf("%.1f\n", error);
    }
    return 0;
}
