#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;
const int mx = 1e8 - 1;
vector<int> primes;
bool primeContainer[mx + 1];
class PrimesUptoN
{

    // Generating Primes
private:
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

    bool alreadyPrimeCollected = false;

public:
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
public:
    PrimesUptoN()
    {
        generatePrimesSieve();
    }

public:
    bool isPrime(int number)
    {

        return primeContainer[number] == notCross;
    }
};
// vector<int> PrimesUptoN::primes;
// bool PrimesUptoN::primeContainer[];

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    PrimesUptoN s = PrimesUptoN();
    s.collectPrimes();
    int cnt = 0;
    while (cnt <= primes.size() - 1)
    {
        cout << primes[cnt] << "\n";
        cnt = cnt + 100;
    }

    return 0;
}