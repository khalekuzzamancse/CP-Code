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

    Factor getLargestFactor()
    {
        return _factors[_factors.size() - 1];
    }
    Factor getSmallestFactor()
    {
        return _factors[0];
    }
    bool isFactorOf(long long prime)
    {
        for (int i = 0; i < _factors.size(); i++)
        {
            if (_factors[i].base == prime)
            {
                return true;
            }
        }
        return false;
    }
    bool isNotFactorOf(long long prime)
    {
        return !isFactorOf(prime);
    }
    int getExponentOf(long long base)
    {

        for (int i = 0; i < _factors.size(); i++)
            if (_factors[i].base == base)
                return _factors[i].exponent;
        return 0;
    }
    map<long long, pair<int, int>> getCommonFactorsWith(PrimeFactor a)
    {
        vector<Factor> f2 = a.factors;
        map<long long, pair<int, int>> result;
        for (int i = 0; i < factors.size(); i++)
        {
            for (int j = 0; j < f2.size(); j++)
            {
                if (factors[i].base == f2[j].base)
                    result[factors[i].base] = make_pair(factors[i].exponent, f2[j].exponent);
            }
        }
        return result;
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
    PrimeFactor getCommonFactorsWithMaxExponents(PrimeFactor a)
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
                    int maxExponent = max(factors[i].exponent, f[j].exponent);
                    result.push_back(Factor(base, maxExponent));
                }
            }
        }
        return PrimeFactor(result);
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
    bool alreadyCalculated = false;
    const bool notCross = 0;
    static const int mx = 1e2;
    static int smallestPrimeFactors[mx + 1];
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

        if (alreadyCalculated)
            return;
        int till = std::sqrt(mx);
        for (int i = 2; i <= till; ++i)
        {
            if (isPrime(i))
                updateMultipleOf(i);
        }
        alreadyCalculated = true;
    }

private:
    long long n;

public:
    PrimeFactorizer(long long n)
    {
        this->n = n;
    }

public:
    // Sieve
    int getSmallestPrimeFactor(int n)
    {
        generateSmallestFactors();
        return smallestPrimeFactors[n] == 0 ? n : smallestPrimeFactors[n];
    }

    PrimeFactor getPrimeFactorizationSieve()
    {
        generateSmallestFactors();
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
int PrimeFactorizer::smallestPrimeFactors[];

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
    int getNumberOfDivisors()
    {
        auto factors = PrimeFactorizer(n).getPrimeFactorizationSieve();
        int cnt = 1;
        for (auto it : factors.factors)
        {
            int exponent = it.exponent;
            cnt *= (exponent + 1);
        }
        return cnt;
    }
    static int getNumberOfCommonDivisor(long long a, long long b)
    {
        auto x = PrimeFactorizer(a).getPrimeFactorizationSieve();
        auto y = PrimeFactorizer(b).getPrimeFactorizationSieve();
        auto res = x.getCommonFactorsWithMinExponents(y);
        int cnt = 1;
        for (auto it : res.factors)
            cnt *= (it.exponent + 1);
        return cnt;
    }
    long long getSumOfDivisors()
    {
        auto factors = PrimeFactorizer(n).getPrimeFactorizationNaive();
        long long sum = 1;
        for (auto it : factors.factors)
        {
            long long p = (pow(it.base, (it.exponent + 1)) - 1) / (it.base - 1);
            sum *= p;
        }
        return sum;
    }
    // get all the divisor
    // getTotal Exponent
};
int main()
{
    // DivisorUtils util = DivisorUtils::getNumberOfCommonDivisor(10, 20);
    // cout << DivisorUtils::getNumberOfCommonDivisor(10, 10) << endl;
    cout << DivisorUtils(2018).getNumberOfDivisors() << endl;

    return 0;
}