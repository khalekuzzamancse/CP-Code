/*
Link:https://practice.geeksforgeeks.org/problems/prime-string3953/1?page=1&difficulty[]=0&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Provided a String of length N, your task is to find out whether or not the given string is a prime string. A prime string is a string in
which the sum of the ASCII value of all the characters is prime
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
    bool isPrimeString(int N, string str)
    {
        int sum = 0;
        for (int it : str)
        {
            sum += it;
        }

        return PrimalityTest().isPrimeMillerRobin(sum);
    }
};

//{ Driver Code Starts.

int main()
{
    int T = 1;
    while (T--)
    {
        string str;
        int n;
        cin >> n >> str;
        Solution ob;
        if (ob.isPrimeString(n, str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// } Driver Code Ends