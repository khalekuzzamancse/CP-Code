/*
Link:https://practice.geeksforgeeks.org/problems/twisted-prime-number0500/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Statement:
Given a number N. Check whether N is a Twisted Prime number or not.
Note: A number is called Twisted Prime if it is a prime and its reverse is also a prime.

Solution:
used Miller-Rabin algorithm and the Integer class

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
using namespace std;

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

    long long getReserve()
    {
        std::string rstr = stringValue;
        std::reverse(rstr.begin(), rstr.end());
        return std::stoll(rstr);
    }

    long long value()
    {
        return _value;
    }
};
class PrimalityTest
{

public:
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

class Solution
{
public:
    int isTwistedPrime(int n)
    {
        return PrimalityTest().isPrimeMillerRobin(n) &&
               PrimalityTest().isPrimeMillerRobin((Integer(n).getReserve()));
    }
};

//{ Driver Code Starts.
int main()
{

    int N;
    cin >> N;
    Solution ob;
    cout << ob.isTwistedPrime(N) << "\n";
}
// } Driver Code Ends
