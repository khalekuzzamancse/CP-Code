#include <bits/stdc++.h>
using namespace std;

class StringHash
{

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
    }
    int moduloMultiplication(int a, int b)
    {
        int result = (a * 1LL * b) % mod;
        bool isResultNegative = result < 0;
        if (isResultNegative)
            result += mod;
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
    StringHash(string text, int base = 32, int mod = 1e9 + 7)
    {
        this->text = text;
        this->length = text.length();
        this->base = base;
        this->mod = mod;
        //
        calculateHash();
        calculatePower();
        calculateHash();
    }
    int getHash(int l, int r)
    {
        // O(n)
        int result = moduloAddition(prefixHash[r], (l == 0) ? 0 : -prefixHash[l - 1]);
        result = moduloMultiplication(result, powerInverseUnderModulo[l]);
        return result;
    }
};

int main()
{

    return 0;
}