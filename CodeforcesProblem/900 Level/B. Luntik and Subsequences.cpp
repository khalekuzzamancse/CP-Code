/*
https://codeforces.com/problemset/problem/1582/B
*/

#include <iostream>
#include <cmath>
using namespace std;
class Solution
{

public:
    Solution()
    {
        long long n, one = 0, zero = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
                zero++;
            if (x == 1)
                one++;
        }
        long long p = pow(2, zero);
        cout << p * one << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution();
    }

    return 0;
}
