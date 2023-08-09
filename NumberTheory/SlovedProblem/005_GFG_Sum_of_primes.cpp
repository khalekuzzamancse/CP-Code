/*
Link:https://practice.geeksforgeeks.org/problems/sum-of-primes0042/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Statement:calculate sum  of primes present as digits of given number N.
Solution:
Using Miller-Rabin algorithm for primality test.
the code used from Integer class and PrimalityTest class.

*/
#include <bits/stdc++.h>
using namespace std;
class PrimalityTest
{

private:
    long long power(long long x, unsigned long long y, long long p)
    {
        long long res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    bool millerTest(long long d, long long n)
    {
        long long a = 2 + rand() % (n - 4);

        long long x = power(a, d, n);

        if (x == 1 || x == n - 1)
            return true;

        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }

        return false;
    }

public:
    bool isPrimeMillerRobin(long long n, long long k = 50)
    {
        if (n <= 1 || n == 4)
            return false;
        if (n <= 3)
            return true;

        long long d = n - 1;
        while (d % 2 == 0)
            d /= 2;

        for (long long i = 0; i < k; i++)
            if (!millerTest(d, n))
                return false;
        return true;
    }
};

class Integer
{
private:
    long long _value;
    std::string stringValue;

public:
    Integer(long long number)
    {
        this->_value = number;
        stringValue = std::to_string(number);
    }

    void forEachDigit(std::function<void(int digit, int position)> lambda)
    {
        for (int i = 0; i < stringValue.length(); i++)
            lambda(stringValue[i] - '0', i);
    }

    long long get()
    {
        return _value;
    }
};

class Solution
{
public:
    static bool isPrime(int n)
    {
        return PrimalityTest().isPrimeMillerRobin(n);
    }
    int primeSum(int n)
    {
        Integer in = Integer(n);
        PrimalityTest tester = PrimalityTest();
        int ans = 0;
        in.forEachDigit([&ans](int digit, int pos)
                        {
            if(isPrime(digit))
            ans+=digit; });
        return ans;
    }
};