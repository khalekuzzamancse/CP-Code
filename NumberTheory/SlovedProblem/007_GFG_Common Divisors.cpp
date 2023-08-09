/*
Link:https://practice.geeksforgeeks.org/problems/common-divisors4712/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Statement:
Given two integer numbers a and b, the task is to find count of all common
divisors of given numbers.

Solution:
N<=10^3,so can be solved using both naive and sieve.
I used sieve here.
You can also solve it by counting the divisor of GCD(a,b).
Used some code from(pasted):
    Factor
    PrimeFactor
    PrimeFactorizer class.
    Divisor Utils class.


*/
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
    PrimeFactor getCommonFactorsWithMinExponents(PrimeFactor a)
    {
        vector<Factor> f = a.factors;
        vector<Factor> result;
        for (int i = 0; i < factors.size(); i++)
        {
            for (int j = 0; j < f.size(); j++)
            {
                long long base = factors[i].base;

                if (base == f[j].base)
                {
                    int minExponent = min(factors[i].exponent, f[j].exponent);
                    result.push_back(Factor(base, minExponent));
                }
            }
        }
        return PrimeFactor(result);
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

class DivisorUtils
{
private:
    PrimeFactorizer pf;
    long long n;

public:
    DivisorUtils(long long n) : pf(PrimeFactorizer(n))
    {
        this->n = n;
    }

public:
    static int getNumberOfCommonDivisor(long long a, long long b)
    {
        auto x = PrimeFactorizer(a).getPrimeFactorizationNaive();
        auto y = PrimeFactorizer(b).getPrimeFactorizationNaive();
        auto res = x.getCommonFactorsWithMinExponents(y);
        int cnt = 1;
        for (auto it : res.factors)
            cnt *= (it.exponent + 1);
        return cnt;
    }
};
class Solution
{
public:
    long long int commDiv(long long int a, long long int b)
    {
        return DivisorUtils::getNumberOfCommonDivisor(a, b);
    }
};

int main()
{

    long long int a, b;
    cin >> a >> b;
    Solution ob;
    cout << ob.commDiv(a, b) << endl;

    return 0;
}
