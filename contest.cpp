#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            if (x == 1)
                x++;
            v.push_back(x);
        }
        for (int i = 0; i <= n - 2; i++)
        {
            if (v[i] == 1)
                v[i]++;
            if (v[i + 1] % v[i] == 0)
                v[i + 1]++;
        }
        for (int it : v)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}