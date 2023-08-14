#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int mx = 1e6;
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
vector<int> distinctPrimeFactorsUpto10e6[mx + 1];

void calculate()
{
    vector<int> v(11, 0);
    v[0] = 1;
    distinctPrimeFactorsUpto10e6[0] = v;
    distinctPrimeFactorsUpto10e6[1] = v;

    for (int i = 2; i <= mx; i++)
    {
        auto a = PrimeFactorizer(i).getPrimeFactorizationSieve();
        int dis = a.distinctNumberOfPrimeFactors();
        vector<int> tmp = distinctPrimeFactorsUpto10e6[i - 1];
        tmp[dis]++;
        distinctPrimeFactorsUpto10e6[i] = tmp;
    }
}
int getNFactful(int a, int b, int n)
{
    if (a < 2 && n == 0)
        return 1;
    return distinctPrimeFactorsUpto10e6[b][n] - distinctPrimeFactorsUpto10e6[a][n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calculate();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << getNFactful(a, b, n) << "\n";
    }

    return 0;
}