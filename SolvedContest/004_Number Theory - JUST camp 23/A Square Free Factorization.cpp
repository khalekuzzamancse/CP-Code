#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
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

class PrimeFactorizer
{

private:
    long long n;

public:
    PrimeFactorizer(long long n)
    {
        this->n = n;
    }

public:
    // Naive
    PrimeFactor getPrimeFactorizationNaive()
    {

        int cnt = 0;
        bool isFactored = cnt > 0;

        while (n % 2 == 0)
        {
            cnt++;
            n = n / 2;
        }
        PrimeFactor factor = PrimeFactor();
        if (cnt > 0)
            factor.add(2, cnt);
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            if (cnt > 0)
                factor.add(i, cnt);
        }

        if (n > 2)
            factor.add(n, 1);
        return factor;
    }
};
int ans(int n)
{
    auto a = PrimeFactorizer(n).getPrimeFactorizationNaive();

    if (a.factors.size() == 1)
    {
        int cnt = 0;
        if (a.factors.at(0).exponent == 1)
            cnt = 1;
        else if (a.factors.at(0).exponent % 2 == 0)
            cnt = 2;
        else
            cnt = 3;
        return cnt;
    }
    int cnt = 0;
    for (auto it : a.factors)
    {
        if (it.exponent % 2 == 0)
            cnt = cnt + 2;
        else
            cnt = cnt + 1;
    }
    return cnt;
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
        int n;
        cin >> n;
        cout << ans(n) << endl;
    }

    return 0;
}