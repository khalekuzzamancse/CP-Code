#include <bits/stdc++.h>
using namespace std;
class StringHash
{
private:
    const pair<long long, long long> mod = {1000000007, 1000000009};
    const pair<long long, long long> base = {29, 31};
    pair<long long, long long> hashValue = {0, 0};

    string text;
    void calculate1stHash()
    {
        // Time complexity: O(n)
        long long int power1 = 1, power2 = 1;
        for (char ch : text)
        {

            hashValue.first = (hashValue.first + (ch - 'a' + 1) * power1) % mod.first;
            hashValue.second = (hashValue.second + (ch - 'a' + 1) * power2) % mod.second;
            cout << hashValue.first << " " << hashValue.second << endl;
            power1 = (power1 * base.first) % mod.first;
            power2 = (power2 * base.second) % mod.second;
        }
    }

public:
    StringHash(string &s)
    {
        this->text = s;
        calculate1stHash();
    }
    StringHash()
    {
        this->text = "";
    }
    // getter
    pair<long long, long long> get1stHashValue()
    {
        return hashValue;
    }
};

int main()
{

    string s = "abc";
    auto hashValue = StringHash(s).get1stHashValue();
    cout << hashValue.first << " " << hashValue.second << endl;
    return 0;
}