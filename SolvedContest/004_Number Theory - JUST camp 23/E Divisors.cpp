#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int N = 1e6;
int cnt;
class Factor
{
public:
    const long long base;
    const int exponent;

public:
    Factor(long long base, int exponent)
        : base(base), exponent(exponent) {}
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
};

//
vector<bool> primeContainer;
int numberOfDivisor[N + 10];

void calculateDivisorUptoN()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
            numberOfDivisor[j]++;
    }
}

int getNumberOfDiv(int n)
{
    return numberOfDivisor[n];
}
PrimeFactor getPrimeFactorizationNaive(int n)
{

    int cnt = 0;

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calculateDivisorUptoN();

    for (int i = 2; i < N; i++)
    {
        int nod = getNumberOfDiv(i);
        auto factor = getPrimeFactorizationNaive(nod).factors;
        if (factor.size() == 2 &&
            factor[0].exponent == 1 && factor[1].exponent == 1 && factor[0].base * factor[1].base == nod)
        {
            cnt++;
            if (cnt % 9 == 0)
                printf("%d\n", i);
        }
    }
    return 0;
}