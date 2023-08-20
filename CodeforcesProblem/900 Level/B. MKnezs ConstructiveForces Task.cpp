#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 != 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
                cout << (i % 2 == 0 ? 10 : -10) << " ";
            cout << endl;
        }
    }

    return 0;
}