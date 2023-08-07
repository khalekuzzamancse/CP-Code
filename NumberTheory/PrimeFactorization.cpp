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

int main()
{
    PrimeFactorizer pf = PrimeFactorizer();
    pf.getPrimeFactorization(13);

    return 0;
}