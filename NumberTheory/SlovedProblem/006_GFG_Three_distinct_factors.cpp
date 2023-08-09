/*
Link=https://practice.geeksforgeeks.org/problems/three-distinct-factors5613/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Statement:
Given a positive integer N. The task is to check whether a number has exactly
three distinct factors or not.
Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 10^12

Solution:
Since beyond integer that is why used naive approach to find prime factorization.
Code used from:
    DivisorUntil
    PrimeFactorizationUtil

*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class PrimeFactorizer
{

public:
    PrimeFactorizer()
    {
    }
    vector<pair<long long, int>> getPrimeFactorizationNaive(long long n)
    {

        int cnt = 0;
        bool isFactored = cnt > 0;

        while (n % 2 == 0)
        {
            cnt++;
            n = n / 2;
        }
        vector<pair<long long, int>> factors;
        if (cnt > 0)
            factors.push_back({2, cnt});

        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            if (cnt > 0)
                factors.push_back({2, cnt});
        }

        if (n > 2)
            factors.push_back({n, 1});
        return factors;
    }
};
class DivisorUtils
{
private:
    PrimeFactorizer pf;

public:
    DivisorUtils() : pf(PrimeFactorizer()){

                     };

public:
    int getNumberOfDivisors(long long n)
    {
        auto factors = pf.getPrimeFactorizationNaive(n);
        int cnt = 1;
        for (auto it : factors)
        {
            int exponent = it.second;
            cnt *= (exponent + 1);
        }
        return cnt;
    }
};
class Solution
{

public:
    int hasThreePrimeFac(long long n)
    {
        return DivisorUtils().getNumberOfDivisors(n) == 3;
    }
};