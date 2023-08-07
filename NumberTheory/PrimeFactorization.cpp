#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class PrimeFactorizer
{
private:
    bool alreadyCalculated = false;
    const bool notCross = 0;
    const bool notGetSmallestPrimeFactorYet = 0;
    static const int mx = 50;
    static int smallestPrimeFactors[mx + 1];
    void updateSmallestPrimeFactors(int primeFactor)
    {
        for (int multiple = primeFactor * primeFactor; multiple <= mx; multiple += primeFactor)
        {

            if (!notGetSmallestPrimeFactorYet)
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
            bool isItPrime = smallestPrimeFactors[i] == notCross;
            if (isItPrime)
            {
                int prime = i;
                smallestPrimeFactors[i] = prime;
                updateSmallestPrimeFactors(prime);
            }
        }

        alreadyCalculated = true;
    }

public:
    PrimeFactorizer()
    {
        generateSmallestFactors();
    }
    void toString()
    {
        for (int i = 2; i <= mx; i++)
        {
            cout << i << ":" << smallestPrimeFactors[i] << endl;
        }
    }
};
int PrimeFactorizer::smallestPrimeFactors[];

int main()
{
    PrimeFactorizer pf = PrimeFactorizer();
    pf.toString();

    return 0;
}