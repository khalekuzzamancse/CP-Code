/*
Link:https://practice.geeksforgeeks.org/problems/the-amazing-number0459/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

You are given a number N. Your task is to determine if N is an amazing number or not.
 A number is called amazing if it has exactly three distinct divisors.
Solution:
I number has odd divisors it it is a perfect square.
if a number square root is prime then it has 3 divisors.
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

    bool isPerfectSquare()
    {
        long long x = _value;
        long long root = std::sqrt(x);
        return root * root == _value;
    }

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
    bool isPrimeMillerRobin(long long k = 50)
    {
        if (_value <= 1 || _value == 4)
            return false;
        if (_value <= 3)
            return true;

        long long d = _value - 1;
        while (d % 2 == 0)
            d /= 2;

        for (long long i = 0; i < k; i++)
            if (!millerTest(d, _value))
                return false;
        return true;
    }
};
class Solution
{
public:
    long long isAmazing(long long n)
    {
        Integer i = Integer(n);
        bool isPrime = Integer(sqrt(n)).isPrimeMillerRobin();
        return i.isPerfectSquare() && isPrime;
    }
};

int main()
{

    long long n;
    cin >> n;
    Solution ob;
    cout << ob.isAmazing(n) << endl;

    return 0;
}
