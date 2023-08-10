/*

Link:https://practice.geeksforgeeks.org/problems/kth-prime-factor-of-a-number0132/1?page=1&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given two numbers n and k, find the kth prime factor of n.

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

    int getExponentOf(long long base)
    {

        for (int i = 0; i < _factors.size(); i++)
            if (_factors[i].base == base)
                return _factors[i].exponent;
        return 0;
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
public:
private:
    bool alreadyCalculated = false;
    const bool notCross = 0;
    static const int mx = 1e4;
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
};
int PrimeFactorizer::smallestPrimeFactors[];
class Solution
{
public:
    int kthPrime(int n, int k)
    {

        vector<int> result;
        PrimeFactorizer pf(n);
        PrimeFactor factor = pf.getPrimeFactorizationSieve();
        for (auto it : factor.factors)
        {
            for (int i = 1; i <= it.exponent; i++)
                result.push_back(it.base);
        }
        for (int it : result)
            cout << it << " ";
        return k > result.size() ? -1 : result[k - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        Solution ob;
        cout << ob.kthPrime(n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends