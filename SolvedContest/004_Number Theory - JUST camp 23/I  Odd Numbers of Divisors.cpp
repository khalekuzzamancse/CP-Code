
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;
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
    int distinctNumberOfPrimeFactors()
    {
        return _factors.size();
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
    static bool alreadyCalculated;
    const bool notCross = 0;
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
        //   cout<<"Generating"<<endl;
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

    PrimeFactor getPrimeFactorizationSieve()
    {
        generateSmallestFactors();

        PrimeFactor factor = PrimeFactor();

        while (n > 1)
        {
            int p = getSmallestPrimeFactor(n);
            int exponent = 0;
            while (n % p == 0)
                exponent++, n = n / p;
            factor.add(p, exponent);
        }
        return factor;
    }
};
int PrimeFactorizer::smallestPrimeFactors[];
bool PrimeFactorizer::alreadyCalculated = false;
int getNumberOfDivisorsOfSquareN(int n)
{
    auto factors = PrimeFactorizer(n).getPrimeFactorizationSieve();
    int cnt = 1;
    for (auto it : factors.factors)
    {
        int exponent = it.exponent;
        cnt *= (2 * exponent + 1);
    }
    return cnt;
}
int divisorOfAllPerfectSquare[mx + 1];
unordered_map<int, vector<long long>> kAndItsNumber;
void calculateDivisorOfAllPerfectSquare()
{
    for (long long number = 1; number * number < 10000000000ll; ++number)
    {

        int divisorsCount = getNumberOfDivisorsOfSquareN(number);
        kAndItsNumber[divisorsCount].push_back(number * number);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calculateDivisorOfAllPerfectSquare();

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        long long low, high;
        cin >> k >> low >> high;
        long long ans = upper_bound(kAndItsNumber[k].begin(), kAndItsNumber[k].end(), high) - lower_bound(kAndItsNumber[k].begin(), kAndItsNumber[k].end(), low);
        cout << ans << "\n";
    }
}