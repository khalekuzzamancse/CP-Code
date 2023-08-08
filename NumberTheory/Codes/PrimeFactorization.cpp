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

    vector<pair<long long, int>> getPrimeFactorizationNaive(long long n)
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
};
int PrimeFactorizer::smallestPrimeFactors[];

int main()
{
    PrimeFactorizer pf = PrimeFactorizer();
    auto f = pf.getPrimeFactorizationNaive(21);
    for (auto it : f)
        cout << it.first << "^" << it.second << endl;

    return 0;
}