#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool notCross = 0;
const int mx = 1e6 + 5;
int smallestPrimeFactors[mx + 1];

class Factor
{
public:
    const long long base;
    const int exponent;

public:
    Factor(long long base, int exponent)
        : base(base), exponent(exponent) {}
    void toString(std::string separator = "^")
    {
        cout << "(" << base << "^" << exponent << ")";
    }
};

class PrimeFactor
{
public:
private:
    vector<Factor> _factors;

public:
    const vector<Factor> &factors = _factors;

public:
    PrimeFactor()
    {
    }

    PrimeFactor(vector<Factor> factors) : _factors(factors) {}

public:
    void add(long long base, int exponent)
    {
        _factors.push_back(Factor(base, exponent));
    }

public:
    void toString()
    {
        for (auto it : factors)
            it.toString();
        cout << endl;
    }
};
bool shouldInitializeSmallestPrimeFactor(int number)
{
    return smallestPrimeFactors[number] == 0;
}
bool isPrime(int number)
{
    return smallestPrimeFactors[number] == notCross;
}

void updateMultipleOf(int primeFactor)
{
    for (int multiple = primeFactor * primeFactor; multiple <= mx; multiple += primeFactor)
    {
        if (shouldInitializeSmallestPrimeFactor(multiple))
            smallestPrimeFactors[multiple] = primeFactor;
    }
}

void generateSmallestFactors()
{

    int till = std::sqrt(mx);
    for (int i = 2; i <= till; ++i)
    {
        if (isPrime(i))
            updateMultipleOf(i);
    }
}
int getSmallestPrimeFactor(int n)
{
    return smallestPrimeFactors[n] == 0 ? n : smallestPrimeFactors[n];
}

PrimeFactor getPrimeFactorizationSieve(int n)
{
    PrimeFactor factor = PrimeFactor();

    while (n > 1)
    {
        int p = getSmallestPrimeFactor(n);
        int exponent = 0;
        while (n % p == 0)
            exponent++, n = n / p;
        factor.add(p, exponent);
    }
    return factor;
}
int getNumberOfDivisors(int n)
{
    auto factors = getPrimeFactorizationSieve(n).factors;
    int cnt = 1;
    for (auto it : factors)
    {
        int exponent = it.exponent;
        cnt *= (exponent + 1);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    generateSmallestFactors();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int gcd = __gcd(a, b);
        cout << getNumberOfDivisors(gcd) << endl;
    }

    return 0;
}