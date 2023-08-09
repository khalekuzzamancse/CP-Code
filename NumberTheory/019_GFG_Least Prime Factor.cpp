/*
Link:https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1?page=1&difficulty[]=0&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given a number N, find the least prime factors for all numbers from 1 to N.
  The least prime factor of an integer X is the smallest prime number that divides it.

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PrimeFactorizer
{
private:
    bool alreadyCalculated = false;
    const bool notCross = 0;
    static const int mx = 1e5;
    static int smallestPrimeFactors[mx + 1];
    bool shouldInitializeSmallestPrimeFactor(int number)
    {
        return smallestPrimeFactors[number] == 0;
    }
    bool isPrime(int number)
    {
        return smallestPrimeFactors[number] == notCross;
    }

    void updateMultipleOf(int primeFactor)
    {
        for (int multiple = primeFactor * primeFactor; multiple <= mx; multiple += primeFactor)
        {
            if (shouldInitializeSmallestPrimeFactor(multiple))
                smallestPrimeFactors[multiple] = primeFactor;
        }
    }

    void generateSmallestFactors()
    {

        if (alreadyCalculated)
            return;
        int till = std::sqrt(mx);
        for (int i = 2; i <= till; ++i)
        {
            if (isPrime(i))
                updateMultipleOf(i);
        }
        alreadyCalculated = true;
    }

private:
    long long n;

public:
    PrimeFactorizer(long long n)
    {
        this->n = n;
    }

public:
    // Sieve
    int getSmallestPrimeFactor(int n)
    {
        generateSmallestFactors();
        return smallestPrimeFactors[n] == 0 ? n : smallestPrimeFactors[n];
    }
};
int PrimeFactorizer::smallestPrimeFactors[];

class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {
        vector<int> ans;
        PrimeFactorizer pf(n);
        ans.push_back(0);
        ans.push_back(1);
        for (int i = 2; i <= n; ++i)
        {
            ans.push_back(pf.getSmallestPrimeFactor(i));
        }
        return ans;
    }
};
