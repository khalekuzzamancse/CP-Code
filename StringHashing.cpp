#include <bits/stdc++.h>
using namespace std;

class StringHash
{
private:
    int max_length = 1e6;
    bool wasPowerCalculated = false;

private:
    int mod = 1e9 + 7, base = 29, length;
    string text;
    vector<int> powerUnderModulo, powerInverseUnderModulo, prefixHash;

    int moduloAddition(int a, int b)
    {

        int result = (a + b) % mod;
        bool isResultNegative = result < 0;
        if (isResultNegative)
            result += mod;
        return result;
    }
    int moduloMultiplication(int a, int b)
    {
        int result = (a * 1LL * b) % mod;
        bool isResultNegative = result < 0;
        if (isResultNegative)
            result += mod;
        return result;
    }
    int moduloExponent(int exponent)
    {
        // calculating (a^b)%m
        //  Complexity: O(log2exponent))
        int result = 1;
        while (exponent)
        {
            bool isExponentOdd = exponent % 2 == 1;
            if (isExponentOdd)
                result = moduloMultiplication(result, base);
            base = moduloMultiplication(base, base);
            exponent /= 2;
        }
        return result;
    }

    void calculatePower()
    {
        // Complexity: O(n)
        powerUnderModulo.resize(length);
        powerUnderModulo[0] = 1;
        for (int i = 1; i < length; i++)
            powerUnderModulo[i] = moduloMultiplication(powerUnderModulo[i - 1], base);
        powerInverseUnderModulo.resize(length);
        int powerInverse = moduloExponent(mod - 2);
        powerInverseUnderModulo[0] = 1;
        for (int i = 1; i < length; i++)
            powerInverseUnderModulo[i] = moduloMultiplication(powerInverseUnderModulo[i - 1], powerInverse);
    }
    int getCharacterHash(char ch)
    {
        return ch - 'a' + 1;
    }
    void calculateHash()
    {
        prefixHash.resize(length);
        for (int i = 0; i < length; i++)
            prefixHash[i] = moduloAddition(
                i == 0 ? 0 : prefixHash[i - 1],
                moduloMultiplication(powerUnderModulo[i], getCharacterHash(text[i])));
    }

public:
    StringHash(string text, int base = 29, int mod = 1e9 + 7)
    {
        this->text = text;
        this->length = text.length();
        this->base = base;
        this->mod = mod;
        //
        if (length > max_length)
            max_length = length;
        if (!wasPowerCalculated)
        {
            calculatePower();
            wasPowerCalculated = true;
        }

        calculateHash();
    }
    StringHash()
    {
    }

    //

    int getHash(int l, int r)
    {
        // O(n)
        int result = moduloAddition(prefixHash[r], (l == 0) ? 0 : -prefixHash[l - 1]);
        result = moduloMultiplication(result, powerInverseUnderModulo[l]);
        return result;
    }
    int getHash()
    {
        int result = prefixHash[length - 1];
        result = moduloMultiplication(result, powerInverseUnderModulo[0]);
        return result;
    }
};
class DoubleHash
{
private:
    string text;
    StringHash _1st, _2nd;

public:
    DoubleHash(string text, int base = 31, int mod = 1e9 + 9)
    {
        _1st = StringHash(text);
        _2nd = StringHash(text, base, mod);
    }
    pair<int, int> getHash(int l, int r)
    {

        return {_1st.getHash(l, r), _2nd.getHash(l, r)};
    }
    pair<int, int> getHash()
    {

        return {_1st.getHash(), _2nd.getHash()};
    }
    bool isEqual(string pattern, int l = 0, int r = 0)
    {

        pair<int, int> textHash = getHash();
        pair<int, int> patternHash;
        if (l == 0 && r == 0)
            patternHash = DoubleHash(pattern).getHash();
        else
            patternHash = DoubleHash(pattern).getHash(l, r);
        // cout << textHash.first << " " << textHash.second << endl;
        // cout << patternHash.first << " " << patternHash.second << endl;
        return textHash.first == patternHash.first && textHash.second == patternHash.second;
    }
};

int main()
{
    // string s = "abcdef";

    // StringHash sh = StringHash(s);
    // cout << sh.getHash(3, 5) << endl;
    // s = "def";
    // sh = StringHash(s);
    // cout << sh.getHash() << endl;
    // string s1 = "abc";
    // DoubleHash dh = DoubleHash(s1);
    // string s2 = "abcdef";
    // cout << dh.isEqual(s2) << endl;

    return 0;
}