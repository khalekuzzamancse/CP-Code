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
};
// Define the static vectors
vector<int> Sieve::primes;
bool Sieve::primeContainer[];


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