#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void push(vector<int> &p, vector<bool> &isPushed, int i, int n)
{
    if (isPushed[i])
        return;
    while (i <= n)
    {
        p.push_back(i);
        isPushed[i] = true;
        i = 2 * i;
        if (i > n)
            return;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<bool> isPushed(n + 1, false);
        vector<int> p;
        p.push_back(1);
        for (int i = 2; i <= n; i++)
            push(p, isPushed, i, n);
        for (auto it : p)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}