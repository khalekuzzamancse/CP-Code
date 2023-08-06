#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Sieve
{
private:
    const static int mx = 1e2 + 5;
    static bool primeContainer[mx + 1];
    static vector<int> primes;
    bool alreadyPrimeGenerated = false;
    bool alreadyPrimeCollected = false;
    const bool cross = true;
    const bool notCross = false;

private:
    void collectPrimes()
    {
        if (alreadyPrimeCollected)
            return;
        primes.push_back(2);
        for (int i = 3; i <= mx; i += 2)
        {
            if (primeContainer[i] == notCross)
                primes.push_back(i);
        }
        alreadyPrimeCollected = true;
    }
    void crossMultipleOf(int i)
    {
        for (int multiple = i * i; multiple <= mx; multiple += i)
            primeContainer[multiple] = cross;
    }

    void generatePrimesSieve()
    {
        // Time complexity: O(nloglog(n)))
        if (alreadyPrimeGenerated)
            return;
        int upto = std::sqrt(mx);
        primeContainer[0] = cross, primeContainer[1] = cross;
        for (int i = 2; i <= upto; ++i)
        {
            if (primeContainer[i] == notCross)
                crossMultipleOf(i);
        }
        alreadyPrimeGenerated = true;
    }

    void generatePrimesSegmentedSieve()
    {
    }
    void factorizeFactorialOf()
    {
    }
    void powerOfXinFactorial()
    {
    }
    // trailing zero finding
    // leading digit of a factorial
    // digit in n factorial ->log10(n!)=log10(1)+log10(2)+.....log10(n)
    // printing divisor of 1 to N
    // big mod ,a^b%m using modular arithmetic

public:
    Sieve()
    {
    }

    vector<int> &getPrimes()
    {
        collectPrimes();
        return primes;
    }
    bool isPrime(int number)
    {
        // Time complexity: O(1)
        generatePrimesSieve();
        return primeContainer[number] == notCross;
    }
    void toString()
    {
        collectPrimes();
        for (int it : primes)
            cout << it << " ";
        cout << endl;
    }

public:
    vector<pair<long long, int>> getPrimeFactorizationNaive(long long n)
    {
        // O(log(n)< T < O(sqrt(n))
        collectPrimes();
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
    // long long gcdUsingPrimeFactorization(long long n)
    // {
    //     auto factors = getPrimeFactorizationNaive(n);
    // }
    // long long lcmUsingPrimeFactorization(long long n)
    // {
    //     auto factors = getPrimeFactorizationNaive(n);
    // }
};
// Define the static vectors
vector<int> Sieve::primes;
bool Sieve::primeContainer[];
class PrimalityTest
{

public:
    bool isPrimeNaive(long long integer)
    {
        // Time complexity: O( sqrt(n) )
        if (integer < 2)
            return false;
        int root = std::sqrt(integer);
        for (int i = 2; i <= root; i++)
        {
            bool isDivisor = integer % i == 0;
            if (isDivisor)
                return false;
        }
        return true;
    }
    bool isPrimeNaiveImproved(long long n)
    {
        if (n == 2 || n == 3)
            return true;
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

private:
    long long power(long long x, unsigned long long y, long long p)
    {
        long long res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    bool millerTest(long long d, long long n)
    {
        long long a = 2 + rand() % (n - 4);

        long long x = power(a, d, n);

        if (x == 1 || x == n - 1)
            return true;

        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }

        return false;
    }

public:
    bool isPrimeMillerRobin(long long n, long long k = 50)
    {
        if (n <= 1 || n == 4)
            return false;
        if (n <= 3)
            return true;

        long long d = n - 1;
        while (d % 2 == 0)
            d /= 2;

        for (long long i = 0; i < k; i++)
            if (!millerTest(d, n))
                return false;
        return true;
    }
};

int main()
{

    Sieve s = Sieve();
    cout << s.getNumberOfDivisors(10) << endl;
    cout << s.getSumOfDivisors(10) << endl;
    // cout << s.isPrime(4) << endl;

    // PrimalityTest t = PrimalityTest();
    // cout << t.isPrimeMillerRobin(11) << endl;

    return 0;
}