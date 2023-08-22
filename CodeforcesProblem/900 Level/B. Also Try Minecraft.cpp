#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> v, f, b;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    f.push_back(0);
    for (int i = 1; i < n; i++)
    {
        long long damage = v[i] < v[i - 1] ? v[i - 1] - v[i] : 0;
        f.push_back(f[i - 1] + damage);
    }
    b.resize(n);
    b[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        long long damage = v[i] < v[i + 1] ? v[i + 1] - v[i] : 0;
        b[i] = (b[i + 1] + damage);
    }

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > x)
            cout << f[y - 1] - f[x - 1] << endl;
        else
            cout << b[y - 1] - b[x - 1] << endl;
    }

    return 0;
}