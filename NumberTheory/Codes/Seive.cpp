#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

class PrimesUptoN
{

    // Generating Primes
private:
    const static int mx = 1e5;
    static bool primeContainer[mx + 1];
    bool alreadyPrimeGenerated = false;
    const bool cross = true, notCross = false;

private:
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

private:
    // collecting primes
    static vector<int> primes;
    bool alreadyPrimeCollected = false;
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

public:
    vector<int> getPrimes(int a, int b)
    {
        vector<int> primes;
        for (int i = a; i <= b; i++)
            if (isPrime(i))
                primes.push_back(i);

        return primes;
    }
    vector<int> &getPrimes()
    {
        collectPrimes();
        return primes;
    }
    void toString()
    {
        collectPrimes();
        for (int it : primes)
            cout << it << " ";
        cout << endl;
    }

public:
    // constructor
    PrimesUptoN()
    {
        generatePrimesSieve();
    }

public:
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

    void forEachPrime(std::function<void(int prime)> lambda, int l = 2, int r = mx)
    {
        for (int number = l; number <= r; number++)
            if (isPrime(number))
                lambda(number);
    }
};
vector<int> PrimesUptoN::primes;
bool PrimesUptoN::primeContainer[];

int main()
{

    PrimesUptoN s = PrimesUptoN();

    // cout << s.isPrime(4) << endl;

    // PrimalityTest t = PrimalityTest();
    // cout << t.isPrimeMillerRobin(11) << endl;
    s.forEachPrime([](int prime)
                   { cout << prime << endl; },
                   2, 40);

    return 0;
}