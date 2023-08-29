#include <iostream>
using namespace std;
void ans()
{
    int n, s;
    cin >> n >> s;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (a[1] == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (a[s] == 0 && b[s] == 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (a[s] == 1)
    {
        cout << "YES" << endl;
        return;
    }
    bool ok = 0;
    for (int i = s + 1; i <= n; i++)
    {
        if (a[i] == 1 && b[i] == 1)
        {
            ok = 1;
            break;
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ans();

    return 0;
}