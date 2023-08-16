#include <iostream>
using namespace std;
const int N = 1e6;
int cnt;
int numberOfDivisor[N + 10];
void calculateDivisorUptoN()
{
    for (int divisor = 1; divisor <= N; divisor++)
    {
        for (int multipleOf_i = divisor; multipleOf_i <= N; multipleOf_i += divisor)
        {
            numberOfDivisor[multipleOf_i]++;
        }
    }
}
int getNumberOfDiv(int n)
{
    return numberOfDivisor[n];
}
bool does_dM_Divides_dN[N];
const bool dMDoesNotDividedN = true;
const bool dMDividedN = false;
void calculate_dM_Divide_dN()
{
    for (int divisor = 1; divisor <= N; divisor++)
    {
        for (int multipleOf_i = divisor; multipleOf_i <= N; multipleOf_i += divisor)
        {
            int N = multipleOf_i;
            int dN = getNumberOfDiv(N);
            int m = divisor;
            int dM = getNumberOfDiv(m);
            bool dM_doesNotDivide_dN = dN % dM != 0;
            if (dN <= 3 || dM_doesNotDivide_dN)
                does_dM_Divides_dN[N] = dMDoesNotDividedN;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calculateDivisorUptoN();
    calculate_dM_Divide_dN();
    for (int n = 2; n < N; n++)
    {
        if (does_dM_Divides_dN[n] == dMDividedN)
        {
            cnt++;
            if (cnt % 108 == 0)
                cout << n << "\n";
        }
    }
    return 0;
}