class ModularArithmetic
{
private:
public:
    long long getModularExponent(long long base, unsigned long long exponent, long long mod)
    {
        long long res = 1;
        base = base % mod;
        while (exponent > 0)
        {
            if (exponent & 1)
                res = (res * base) % mod;

            exponent = exponent >> 1;
            base = (base * base) % mod;
        }
        return res;
    }
};

