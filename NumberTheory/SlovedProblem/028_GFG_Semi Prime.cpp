/*

https://practice.geeksforgeeks.org/problems/semi-prime4736/1?page=1&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given a positive integer n. Find whether a number is a semiprime or not.
 Note: A semiprime is a natural number that is a product of two prime numbers .



*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
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
    int getTotalExponent(long long n)
    {
        auto factors = pf.getPrimeFactorizationNaive(n);
        int cnt = 0;
        for (auto it : factors)
        {
            // int exponent = it.second;
            // cnt *= (exponent + 1);
            cnt += it.second;
        }
        return cnt;
    }
};
class Solution
{
public:
    int checkSemiprime(int n)
    {
        int div = DivisorUtils().getTotalExponent(n);
        return div == 2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkSemiprime(N) << "\n";
    }
}
