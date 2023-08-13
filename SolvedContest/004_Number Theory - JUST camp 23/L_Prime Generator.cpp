#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class PrimesUptoN
{
private:
    int N;
    const bool cross = true, notCross = false;
    vector<bool> primeContainer;

public:
    PrimesUptoN(int N) : N(N) {}

private:
    void crossMultipleOf(int i)
    {
        for (int multiple = i * i; multiple <= N; multiple += i)
            primeContainer[multiple] = cross;
    }

    void generatePrimes()
    {
        primeContainer.resize(N + 1);
        int upto = std::sqrt(N);
        primeContainer[0] = cross, primeContainer[1] = cross;
        for (int i = 2; i <= upto; ++i)
        {
            if (primeContainer[i] == notCross)
                crossMultipleOf(i);
        }
    }

public:
    vector<int> get()
    {
        generatePrimes();
        vector<int> primes;
        if (N > 1)
            primes.push_back(2);
        for (int i = 3; i <= N; i += 2)
            if (primeContainer[i] == notCross)
                primes.push_back(i);

        return primes;
    }

public:
    void toString()
    {

        for (int it : get())
            cout << it << " ";
        cout << endl;
    }
};

class SegmentedSieve
{
private:
    long long L, R;
    int rangeLength;
    int sqrtOfR;

public:
    SegmentedSieve(long long L, long long R)
    {
        this->L = L, this->R = R, this->rangeLength = R - L + 1;
        sqrtOfR = std::sqrt(R);
    }

private:
    const bool cross = true, notCross = false;

private:
    vector<bool> segmentPrimes;
    int getEncodedIndex(long long number)
    {
        return number - L;
    }
    long long getDecodedNumber(long long index)
    {
        return L + index;
    }
    void markMultipleAsNonPrime(int prime)
    {
        long long _1stMultiple = (L / prime) * prime;
        if (_1stMultiple < L)
            _1stMultiple += prime;
        for (long long multiple = max(_1stMultiple, prime * prime * 1LL); multiple <= R; multiple += prime)
        {
            segmentPrimes[getEncodedIndex(multiple)] = cross;
        }
    }

private:
    void generateSegmentPrimes()
    {
        vector<int> primesTillRootR = PrimesUptoN(sqrtOfR).get();
        segmentPrimes.resize(rangeLength, notCross);
        for (int prime : primesTillRootR)
            markMultipleAsNonPrime(prime);
    }
    bool isPrime(long long number)
    {
        return segmentPrimes[getEncodedIndex(number)] == notCross;
    }

public:
    void toString()
    {
        generateSegmentPrimes();

        for (int i = 0; i < rangeLength; i++)
        {
            long long number = getDecodedNumber(i);
            if (number > 1 && isPrime(number))
                cout << number << endl;
        }
        cout << endl;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long L, R;
        cin >> L >> R;
        SegmentedSieve(L, R).toString();
    }

    return 0;
}
