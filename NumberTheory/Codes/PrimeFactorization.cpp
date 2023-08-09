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
    map<long long, pair<int, int>> getCommonFactors(vector<Factor> f1, vector<Factor> f2)
    {
        map<long long, pair<int, int>> result;
        for (int i = 0; i < f1.size(); i++)
        {
            for (int j = 0; j < f2.size(); j++)
            {
                if (f1[i].base == f2[j].base)
                    result[f1[i].base] = make_pair(f1[i].exponent, f2[j].exponent);
            }
        }
        return result;
    }
    vector<Factor> getCommonFactorsWithMinExponents(vector<Factor> f1, vector<Factor> f2)
    {
        vector<Factor> result;
        for (int i = 0; i < f1.size(); i++)
        {
            for (int j = 0; j < f2.size(); j++)
            {
                long long base = f1[i].base;

                if (base == f2[j].base)
                {
                    int minExponent = min(f1[i].base, f2[j].base);
                    result.push_back(Factor(base, minExponent));
                }
            }
        }
        return result;
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
    int getSmallestPrimeFactor()
    {
        generateSmallestFactors();
        return smallestPrimeFactors[n] == 0 ? n : smallestPrimeFactors[n];
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

int main()
{
    PrimeFactorizer pf = PrimeFactorizer(20);
    auto f = pf.getPrimeFactorizationNaive();
    f.toString();

    return 0;
}