/*
Problem Link:
https://practice.geeksforgeeks.org/problems/full-prime2659/1?page=1&difficulty[]=-2&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

class PrimalityTest
{

public:
    bool isPrimeNaive(long long integer)
    {
        // Time complexity: O( sqrt(n) )
        if (integer < 2)
            return false;
        int root = std::sqrt(integer);
        for (int i = 2; i <= root; i++)
        {
            bool isDivisor = integer % i == 0;
            if (isDivisor)
                return false;
        }
        return true;
    }
    bool isPrimeNaiveImproved(long long n)
    {
        if (n == 2 || n == 3)
            return true;
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
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
    long long number;
    std::string numberAsString;

public:
    Integer(long long number)
    {
        this->number = number;
        numberAsString = std::to_string(number);
    }
    bool isOdd()
    {
        return number % 2 != 0;
    }
    bool isEven()
    {
        return number % 2 == 0;
    }
    bool isDivisibleBy(long long divisor)
    {
        return number % divisor == 0;
    }
    bool isMultipleOf(long long n)
    {
        return number % n == 0;
    }
    bool isCoPrimeWith(long long n)
    {
        long long gcd = std::__gcd(number, n);
        return gcd == 1;
    }
    bool isPalindrome()
    {
        std::string rstr = numberAsString;
        std::reverse(rstr.begin(), rstr.end());
        return numberAsString == rstr;
    }
    bool isPerfectSquare()
    {
        if (number < 0)
            return false;
        long long root = std::sqrt(number);
        return root * root == number;
    }
    bool doesExits(int digit)
    {
        for (int i = 0; i < numberAsString.length(); i++)
            if (numberAsString[i] == digit + '0')
                return true;
        return false;
    }
    //
    bool ifAllDigit(std::function<bool(const int &)> predicate)
    {
        for (int i = 0; i < numberAsString.length(); i++)
            if (!predicate(numberAsString[i] - '0'))
                return false;
        return true;
    }
    //
    bool doesNotExits(int digit)
    {
        return !doesExits(digit);
    }
    bool isAllUniqueDigit()
    {
        return numberAsString.length() == getUniqueNumberOfDigits();
    }

    // getters
    long long getGCDWith(long long n)
    {

        return std::__gcd(number, n);
    }
    long long getLCMWith(long long n)
    {
        return (number / std::__gcd(number, n)) * n;
    }
    long long getSumOfDigit()
    {
        long long sum = 0;
        for (int i = 0; i < numberAsString.length(); i++)
            sum += numberAsString[i] - '0';
        return sum;
    }
    long long getLargestDigits()
    {
        long long largest = 0;
        for (int i = 0; i < numberAsString.length(); i++)
            if (numberAsString[i] - '0' > largest)
                largest = numberAsString[i] - '0';

        return largest;
    }

    long long getSmallestDigits()
    {
        long long smallest = 9;
        for (int i = 0; i < numberAsString.length(); i++)
            if (numberAsString[i] - '0' < smallest)
                smallest = numberAsString[i] - '0';
        return smallest;
    }

    long long getNumberOfDigits()
    {
        return numberAsString.length();
    }
    long long getUniqueNumberOfDigits()
    {
        return getUniqueDigits().size();
    }
    std::set<int> getUniqueDigits()
    {
        std::set<int> s;
        for (int i = 0; i < numberAsString.length(); i++)
            s.insert(numberAsString[i] - '0');
        return s;
    }

    Integer removeDigits(int l, int r)
    {
        std::string s = numberAsString;
        s.erase(s.begin() + l, s.begin() + r + 1);
        long long numberAsLongLong = std::stoll(s);
        return Integer(numberAsLongLong);
    }

    Integer getSmallestPermutation()
    {
        std::string s = numberAsString;
        std::sort(s.begin(), s.end());
        return Integer(std::stoll(s));
    }
    Integer getLargestPermutation()
    {
        std::string s = numberAsString;
        std::sort(s.begin(), s.end(), std::greater<char>());
        return Integer(std::stoll(s));
    }

    long long get()
    {
        return number;
    }
};

class Solution
{
public:
    static bool isPrime(int n)
    {
        return PrimalityTest().isPrimeMillerRobin(n);
    }
    int fullPrime(int n)
    {
        Integer in = Integer(n);
        PrimalityTest tester = PrimalityTest();
        bool ans = tester.isPrimeMillerRobin(n);
        bool isFullPrime = in.ifAllDigit(isPrime);
        ans = ans && isFullPrime;
        return ans;
    }
};
