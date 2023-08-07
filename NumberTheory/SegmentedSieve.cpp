#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class SegmentedSieve
{
private:
    long long L, R;
    int rangeLength;
    int mx;

public:
    SegmentedSieve(long long L, long long R)
    {
        this->L = L;
        this->R = R;
        this->rangeLength = R - L + 1;
        mx = std::sqrt(R);
        collectPrimes();
    }

private:
private:
    static vector<int> primes;
    bool alreadyPrimeCollected = false;
    const bool cross = true;
    const bool notCross = false;
    // void crossMultipleOf(int prime)
    // {
    //     long long startFrom = static_cast<long long>(std::ceil(static_cast<double>(L) / prime) * prime);
    //     for (long long multiple = prime * prime; multiple <= mx; multiple += prime)
    //         primeContainer[getEncodedIndex(multiple)] = cross;
    // }

    void crossMultipleOf(int i, bool primeContainer[])
    {
        for (int multiple = i * i; multiple <= mx; multiple += i)
            primeContainer[multiple] = cross;
    }

    void collectPrimes()
    {
        // collecting primes upto sqrt R
        //  Time complexity:
        //  O(n log log(n)))+O(n)=O(n log log(n)))
        if (alreadyPrimeCollected)
            return;

        bool primeContainer[mx + 1];
        int till = std::sqrt(mx);
        primeContainer[0] = cross, primeContainer[1] = cross;
        for (int i = 2; i <= till; ++i)
        {
            if (primeContainer[i] == notCross)
                crossMultipleOf(i, primeContainer);
        }
        // collecting primes
        primes.push_back(2);
        for (int i = 3; i <= mx; i += 2)
        {
            if (primeContainer[i] == notCross)
                primes.push_back(i);
        }
        alreadyPrimeCollected = true;
    }

public:
    vector<int> &getPrimes()
    {

        return primes;
    }

    void toString()
    {

        for (int it : primes)
            cout << it << " ";
        cout << endl;
    }

private:
    int getEncodedIndex(long long number)
    {

        return number - L;
    }
    long long getDecodedNumber(int index)
    {
        return L + index;
    }
};
// Define the static vectors
vector<int> SegmentedSieve::primes;
int main()
{
    SegmentedSieve s = SegmentedSieve(200, 300);
    s.toString();
    return 0;
}