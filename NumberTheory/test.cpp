
#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, int>> primeFactors(long long n)
{

    int cnt = 0;
    bool isFactored = cnt > 0;

    while (n % 2 == 0)
    {
        cnt++;
        n = n / 2;
    }
    vector<pair<long long, int>> factors;
    if (cnt > 0)
        factors.push_back({2, cnt});

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n = n / i;
        }
        if (cnt > 0)
            factors.push_back({2, cnt});
    }

    if (n > 2)
        factors.push_back({n, 1});
    // for (auto it : factors)
    //     cout << it.first << "^" << it.second << endl;
    return factors;
}
int getNumberOfDivisors(long long n)
{
    auto factors = primeFactors(n);
    int cnt = 1;
    for (auto it : factors)
    {
        int exponent = it.second;
        cnt *= (exponent + 1);
    }
    return cnt;
}

int main()
{

    long long n;
    cin >> n;
    primeFactors(n);
    cout << getNumberOfDivisors(n);

    return 0;
}
