/*
https://practice.geeksforgeeks.org/problems/gambling-stark3304/1?page=2&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given a number N, you have to say if it is adjacent to two prime numbers. Two numbers are adjacent if
the absolute difference between them is 1


*/

#include <bits/stdc++.h>
using namespace std;

class Sieve
{
private:
    const static int mx = 1e4;
    static bool primeContainer[mx + 1];
    static vector<int> primes;
    bool alreadyPrimeGenerated = false;

    const bool cross = true;
    const bool notCross = false;

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
};

bool Sieve::primeContainer[];
class Solution
{
public:
    int primeAdjacent(int n)
    {
        Sieve s = Sieve();
        return s.isPrime(n - 1) && s.isPrime(n + 1) == true ? 1 : 0;
    }
};
