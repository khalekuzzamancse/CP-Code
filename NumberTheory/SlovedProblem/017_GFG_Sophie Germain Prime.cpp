/*
Link:
https://practice.geeksforgeeks.org/problems/sophie-germain-prime2014/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given N find all Sophie Germain Prime numbers less than N . A prime number p is
called a sophie prime number if 2p+1 is also a prime number.
 The number 2p+1 is called a safe prime.
Uses:
Sieve class


*/

#include <bits/stdc++.h>
using namespace std;

class Sieve
{
private:
    const static int mx = 20000 + 10;

    static vector<int> primes;
    bool alreadyPrimeGenerated = false;
    const bool cross = true;
    const bool notCross = false;

private:
    static bool primeContainer[mx + 1];

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

public:
    Sieve()
    {
        generatePrimesSieve();
    }

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
bool Sieve::primeContainer[];
class Solution
{
public:
    vector<int> sophie_Primes(int n)
    {
        vector<int> ans;
        Sieve s = Sieve();
        for (int it : s.getPrimes(2, n - 1))
        {
            int p = 2 * it + 1;
            if (s.isPrime(p))
                ans.push_back(it);
        }
        return ans;
    }
};

int main()
{
    int tc = 1;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.sophie_Primes(n);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
