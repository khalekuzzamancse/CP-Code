/*
Link:https://practice.geeksforgeeks.org/problems/primes-sum5827/1?page=1&difficulty[]=0&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions


        // n=x+y
        // x is prime that means ,y=n-x should be prime

        Given a number N. Find if it can be expressed as sum of two prime numbers.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

class PrimesUptoN
{

    // Generating Primes
private:
    const static int N = 1e5;
    static bool primeContainer[N + 1];
    bool alreadyPrimeGenerated = false;
    const bool cross = true, notCross = false;

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

    vector<int> getPrimes(int a, int b)
    {
        vector<int> primes;
        for (int i = a; i <= b; i++)
            if (isPrime(i))
                primes.push_back(i);

        return primes;
    }
};
bool PrimesUptoN::primeContainer[];
class Solution
{

public:
    string isSumOfTwo(int n)
    {
        if (n < 4)
            return "No";
        PrimesUptoN s = PrimesUptoN();
        int half = n / 2;
        for (int it : s.getPrimes(2, half))
        {
            int y = n - it;
            if (s.isPrime(y))
                return "Yes";
        }
        return "No";
    }
};

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends