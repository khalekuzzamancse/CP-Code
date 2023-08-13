/*
Link:
https://practice.geeksforgeeks.org/problems/transform-to-prime4635/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Given an array of n integers. Find the minimum positive number to be inserted in array, so that sum of all elements of
 array becomes prime. If sum is already prime, then return 0.
Uses:
Sieve class

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PrimesUptoN
{
private:
    const static int N = 1e5;
    static bool primeContainer[N + 1];
    static vector<int> primes;
    bool alreadyPrimeGenerated = false;
    const bool cross = true;
    const bool notCross = false;

private:
    void crossMultipleOf(int i)
    {
        for (int multiple = i * i; multiple <= N; multiple += i)
            primeContainer[multiple] = cross;
    }

    void generatePrimesSieve()
    {
        // Time complexity: O(nloglog(n)))
        if (alreadyPrimeGenerated)
            return;
        int upto = std::sqrt(upto);
        primeContainer[0] = cross, primeContainer[1] = cross;
        for (int i = 2; i <= upto; ++i)
        {
            if (primeContainer[i] == notCross)
                crossMultipleOf(i);
        }
        alreadyPrimeGenerated = true;
    }

public:
    PrimesUptoN()
    {
        generatePrimesSieve();
    }

    bool isPrime(int number)
    {
        // Time complexity: O(1)

        return primeContainer[number] == notCross;
    }
    int getNextPrime(int number)
    {
        for (int i = number; i <= N; ++i)
        {
            if (isPrime(i))
                return i;
        }
        return 0;
    }
};
bool PrimesUptoN::primeContainer[];

long long minNumber(long long arr[], long long N)
{
    PrimesUptoN s = PrimesUptoN();
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    return s.getNextPrime(sum) - sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    cout << minNumber(arr, n) << endl;
    return 0;
}
