#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const bool cross = true, notCross = false;
int N = 1e7;
vector<bool> p1(N + 1, notCross);
void generateP1()
{
    int upto = std::sqrt(N);
    p1[0] = cross, p1[1] = cross;
    for (int i = 2; i <= upto; ++i)
    {
        if (p1[i] == notCross)
            for (int multiple = i * i; multiple <= N; multiple += i)
                p1[multiple] = cross;
    }
}

int main()
{
    generateP1();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (p1[i] == notCross)
            {
                // if (i != n && n % i != 0)
                //     cnt
                cout<<i<<" ";
            }
        }
        cout<<endl;
      //  cout << cnt << endl;
    }

    return 0;
}