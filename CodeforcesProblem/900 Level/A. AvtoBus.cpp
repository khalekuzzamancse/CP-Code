/*
https://codeforces.com/problemset/problem/1679/A
*/
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        bool isPossible = (n % 2 == 0);
        if (isPossible)
        {
           long long divisibleBy6=n%4;
           
        }
        else
            cout << -1 << endl;
    }

    return 0;
}