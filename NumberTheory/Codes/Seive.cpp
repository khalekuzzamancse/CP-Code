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

public:
    Sieve()
    {
        generatePrimesSieve();
    }

    vector<int> &getPrimes()
    {
        collectPrimes();
        return primes;
    }
    bool isPrime(int number)
    {
        // Time complexity: O(1)

        return primeContainer[number] == notCross;
    }
    int getNextPrime(int number)
    {
        for (int i = number; i <= mx; ++i)
        {
            if (isPrime(i))
                return i;
        }
        return 0;
    }
    int getPrevPrime(int number)
    {
        for (int i = number; i >= 2; --i)
        {
            if (isPrime(i))
                return i;
        }
        return 0;
    }
    vector<int> getPrimes(int a, int b)
    {
        vector<int> primes;
        for (int i = a; i <= b; i++)
            if (isPrime(i))
                primes.push_back(i);

        return primes;
    }
    void toString()
    {
        collectPrimes();
        for (int it : primes)
            cout << it << " ";
        cout << endl;
    }
};
// Define the static vectors
vector<int> Sieve::primes;
bool Sieve::primeContainer[];

int main()
{

    Sieve s = Sieve();

    // cout << s.isPrime(4) << endl;

    // PrimalityTest t = PrimalityTest();
    // cout << t.isPrimeMillerRobin(11) << endl;

    return 0;
}