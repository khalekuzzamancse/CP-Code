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
        int b, c, h;
        cin >> b >> c >> h;
        int x = c + h;
        int ans = (x >= b - 1) ? (2 * b - 1) : (2 * x + 1);
        cout << ans << endl;
    }
    return 0;
}