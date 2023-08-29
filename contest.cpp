#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long ans = ceil((sqrt(8*n+1)-1)/2);
        cout << ans << endl;
    }
    return 0;
}
