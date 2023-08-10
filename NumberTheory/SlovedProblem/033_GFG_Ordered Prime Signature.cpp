/*
 */

#include <bits/stdc++.h>
using namespace std;
class Factor
{
public:
    const long long base;
    const int exponent;

public:
    Factor(long long base, int exponent)
        : base(base), exponent(exponent) {}
    void toString(std::string separator = "^")
    {
        cout << "(" << base << "^" << exponent << ")";
    }
};

class PrimeFactor
{
public:
private:
    vector<Factor> _factors;

public:
    const vector<Factor> &factors = _factors;

public:
    PrimeFactor()
    {
    }

    PrimeFactor(vector<Factor> factors) : _factors(factors) {}

public:
    void add(long long base, int exponent)
    {
        _factors.push_back(Factor(base, exponent));
    }

public:
    void toString()
    {
        for (auto it : factors)
            it.toString();
        cout << endl;
    }
};

class PrimeFactorizer
{

private:
    long long n;

public:
    PrimeFactorizer(long long n)
    {
        this->n = n;
    }

public:
    // Naive
    PrimeFactor getPrimeFactorizationNaive()
    {

        int cnt = 0;
        bool isFactored = cnt > 0;

        while (n % 2 == 0)
        {
            cnt++;
            n = n / 2;
        }
        PrimeFactor factor = PrimeFactor();
        if (cnt > 0)
            factor.add(2, cnt);
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            if (cnt > 0)
                factor.add(i, cnt);
        }

        if (n > 2)
            factor.add(n, 1);
        return factor;
    }
};
class Solution
{
public:
    vector<int> orderedPrime(int n)
    {
        vector<int> result;
        PrimeFactorizer pf(n);
        PrimeFactor factor = pf.getPrimeFactorizationNaive();
        int cnt = 1;

        for (auto it : factor.factors)
        {
            result.push_back(it.exponent);
            cnt *= (it.exponent + 1);
        }
        sort(result.begin(), result.end());
        result.push_back(cnt);
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.orderedPrime(n);
        for (int i = 0; i < ans.size() - 1; i++)
            cout << ans[i] << " ";
        cout << endl;
        cout << ans[ans.size() - 1] << "\n";
    }
    return 0;
}
