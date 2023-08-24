/*
https://codeforces.com/problemset/problem/1697/B
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int q, n;
    cin >> n >> q;
    vector<long long> p(n), prefixSum(n + 1);
    for (auto &x : p)
        cin >> x;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; ++i)
        prefixSum[i + 1] = prefixSum[i] + p[i];

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << prefixSum[n - x + y] - prefixSum[n - x] << endl;
    }

    return 0;
}