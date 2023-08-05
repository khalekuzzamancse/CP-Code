#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class PrimeUtils
{
private:
    const int mx = 1e2 + 5;
    static vector<bool> primeContainer;
    static vector<int> primes;
    bool alreadyPrimeGenerated = false;

private:
    void collectPrimes()
    {
        primes.push_back(2);
        for (int i = 3; i < mx; i += 2)
        {
            bool wasMarkedAsPrimed = primeContainer[i] == true;
            if (wasMarkedAsPrimed)
                primes.push_back(i);
        }
    }

    void generatePrimes(void)
    {
        primeContainer.resize(mx + 1);
        for (int i = 2; i <= mx; ++i)
            primeContainer[i] = true;
        for (int i = 2; i * i <= mx; ++i)
        {
            if (primeContainer[i] == true)
            {
                for (int j = i * i; j <= mx; j += i)
                    primeContainer[j] = false;
            }
        }
    }

public:
    PrimeUtils()
    {
        if (!alreadyPrimeGenerated)
        {
            generatePrimes();
            collectPrimes();
            alreadyPrimeGenerated = true;
        }
    }
    vector<int> &getPrimes()
    {
        return primes;
    }
    bool isPrime(int number)
    {
        return primeContainer[number];
    }
    void toString()
    {

        for (int it : primes)
            cout << it << " ";
        cout << endl;
    }

public:
    vector<pair<long long, int>> getPrimeFactorizationNaive(long long n)
    {
        // O(log(n)< T < O(sqrt(n))
        vector<pair<long long, int>> ans;
        int root = std::sqrt(n);
        for (int i = 0; i < primes.size() && primes[i] <= root; i++)
        {

            int currentPrime = primes[i];
            bool isDivisibleByCurrentPrime = n % currentPrime == 0;
            if (isDivisibleByCurrentPrime)
            {
                int exponent = 0;
                while (n % currentPrime == 0)
                {
                    exponent++;
                    n /= currentPrime;
                }

                ans.push_back({currentPrime, exponent});
                root = std::sqrt(n);
            }
        }
        bool hasOneMorePrimeDivisor = n > 1;
        if (hasOneMorePrimeDivisor)
            ans.push_back({n, 1});

        return ans;
    }
    int getNumberOfDivisors(long long n)
    {
        auto factors = getPrimeFactorizationNaive(n);
        int cnt = 1;
        for (auto it : factors)
        {
            int exponent = it.second;
            cnt *= (exponent + 1);
        }
        return cnt;
    }
    long long getSumOfDivisors(long long n)
    {
        auto factors = getPrimeFactorizationNaive(n);
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
// Define the static vectors
vector<bool> PrimeUtils::primeContainer;
vector<int> PrimeUtils::primes;

int main()
{

    PrimeUtils s = PrimeUtils();
    // cout << s.getNumberOfDivisors(10) << endl;
    cout << s.getSumOfDivisors(8) << endl;

    return 0;
}