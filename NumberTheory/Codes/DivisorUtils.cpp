#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
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

public:
    PrimeFactorizer()
    {
        generateSmallestFactors();
    }
    int getSmallestPrimeFactor(int n)
    {
        return smallestPrimeFactors[n] == 0 ? n : smallestPrimeFactors[n];
    }

    vector<pair<int, int>> getPrimeFactorization(int n)
    {

        vector<pair<int, int>> factorization;
        while (n > 1)
        {
            int p = getSmallestPrimeFactor(n);
            int exponent = 0;
            while (n % p == 0)
                exponent++, n = n / p;
            factorization.push_back({p, exponent});
        }
        return factorization;
    }
};
int PrimeFactorizer::smallestPrimeFactors[];
class DivisorUtils
{
private:
    PrimeFactorizer pf;

public:
    DivisorUtils() : pf(PrimeFactorizer()){

                     };

public:
    int getNumberOfDivisors(int n)
    {
        vector<pair<int, int>> factors = pf.getPrimeFactorization(n);
        int cnt = 1;
        for (auto it : factors)
        {
            int exponent = it.second;
            cnt *= (exponent + 1);
        }
        return cnt;
    }
    long long getSumOfDivisors(int n)
    {

        auto factors = pf.getPrimeFactorization(n);
        long long sum = 1;
        for (auto it : factors)
        {
            long long exponent = it.second;
            long long base = it.first;
            long long p = (pow(base, (exponent + 1)) - 1) / (base - 1);
            sum *= p;
        }
        return sum;
    }
    
};
int main()
{
    DivisorUtils util = DivisorUtils();
    cout << util.getSumOfDivisors(8) << endl;
    return 0;
}