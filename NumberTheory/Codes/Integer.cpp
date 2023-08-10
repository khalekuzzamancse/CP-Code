/*
isPrime()
isPerfect()
isDeficient();

getDivisors()
getSumOfDivisors()
getLargestProperDivisors()
getSmallestProperDivisors()

getEulerTotient();
getPrimeFactorization()
getTralingZeroOnFactorial()
getTotalDigitOnFactorial();
getSmallestPrimDivisisor()
getLargeestPrimDivisor()
convertBaseTo(int base)
Interget(number,base n){

}
replaceDigitIf()
increseDigitIf()
decreaseDigitIF()
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>

class Integer
{
private:
    long long _value;
    std::string stringValue;

public:
    Integer(long long number)
    {
        this->_value = number;
        stringValue = std::to_string(number);
    }
    bool isOdd()
    {
        return _value % 2 != 0;
    }
    bool isEven()
    {
        return _value % 2 == 0;
    }
    bool isDivisibleBy(long long divisor)
    {
        return _value % divisor == 0;
    }
    bool isMultipleOf(long long n)
    {
        return _value % n == 0;
    }
    bool isCoPrimeWith(long long n)
    {
        long long gcd = std::__gcd(_value, n);
        return gcd == 1;
    }
    bool isPalindrome()
    {
        std::string rstr = stringValue;
        std::reverse(rstr.begin(), rstr.end());
        return stringValue == rstr;
    }
    bool isPerfectSquare()
    {
        if (_value < 0)
            return false;
        long long root = std::sqrt(_value);
        return root * root == _value;
    }
    bool doesExits(int digit)
    {
        for (int i = 0; i < stringValue.length(); i++)
            if (stringValue[i] == digit + '0')
                return true;
        return false;
    }
    bool doesNotExits(int digit)
    {
        return !doesExits(digit);
    }
    bool isAllUniqueDigit()
    {
        return stringValue.length() == getUniqueNumberOfDigits();
    }

    // getters
    long long getGCDWith(long long n)
    {

        return std::__gcd(_value, n);
    }
    long long getLCMWith(long long n)
    {
        return (_value / std::__gcd(_value, n)) * n;
    }
    int getSumOfDigit()
    {
        int sum = 0;
        for (int i = 0; i < stringValue.length(); i++)
            sum += stringValue[i] - '0';
        return sum;
    }
    int getLargestDigits()
    {
        int largest = 0;
        for (int i = 0; i < stringValue.length(); i++)
            if (stringValue[i] - '0' > largest)
                largest = stringValue[i] - '0';

        return largest;
    }

    int getSmallestDigits()
    {
        long long smallest = 9;
        for (int i = 0; i < stringValue.length(); i++)
            if (stringValue[i] - '0' < smallest)
                smallest = stringValue[i] - '0';
        return smallest;
    }

    int getNumberOfDigits()
    {
        return stringValue.length();
    }
    int getUniqueNumberOfDigits()
    {
        return getUniqueDigits().size();
    }
    std::set<int> getUniqueDigits()
    {
        std::set<int> s;
        for (int i = 0; i < stringValue.length(); i++)
            s.insert(stringValue[i] - '0');
        return s;
    }

    Integer removeDigits(int l, int r)
    {
        std::string s = stringValue;
        s.erase(s.begin() + l, s.begin() + r + 1);
        long long numberAsLongLong = std::stoll(s);
        return Integer(numberAsLongLong);
    }

    //
    bool ifAllDigit(std::function<bool(const int digit)> predicate)
    {
        for (int i = 0; i < stringValue.length(); i++)
            if (!predicate(stringValue[i] - '0'))
                return false;
        return true;
    }
    Integer replaceDigitIf(std::function<int(int digit, int position)> lambda)
    {
        std::string num = stringValue;
        for (int i = 0; i < num.length(); i++)
        {
            int replaceBy = lambda(num[i] - '0', i);
            if (replaceBy != -1)
                num[i] = replaceBy + '0';
        }
        return Integer(std::stoll(num));
    }

    void forEachDigit(std::function<void(int digit)> lambda)
    {
        for (int i = 0; i < stringValue.length(); i++)
            lambda(stringValue[i] - '0');
    }

    Integer getSmallestPermutation()
    {
        std::string s = stringValue;
        std::sort(s.begin(), s.end());
        return Integer(std::stoll(s));
    }
    Integer getLargestPermutation()
    {
        std::string s = stringValue;
        std::sort(s.begin(), s.end(), std::greater<char>());
        return Integer(std::stoll(s));
    }
    int getFirstDigit()
    {
        return stringValue[0] - '0';
    }
    int getLastDigit()
    {
        return stringValue[stringValue.length() - 1] - '0';
    }
    long long getReserve()
    {
        std::string rstr = stringValue;
        std::reverse(rstr.begin(), rstr.end());
        return std::stoll(rstr);
    }

    long long value()
    {
        return _value;
    }

private:
    long long power(long long x, unsigned long long y, long long p)
    {
        long long res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    bool millerTest(long long d, long long n)
    {
        long long a = 2 + rand() % (n - 4);

        long long x = power(a, d, n);

        if (x == 1 || x == n - 1)
            return true;

        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }

        return false;
    }

public:
    bool isPrimeMillerRobin(long long k = 50)
    {
        if (_value <= 1 || _value == 4)
            return false;
        if (_value <= 3)
            return true;

        long long d = _value - 1;
        while (d % 2 == 0)
            d /= 2;

        for (long long i = 0; i < k; i++)
            if (!millerTest(d, _value))
                return false;
        return true;
    }
    bool isPrimeNaive()
    {
        if (_value == 2 || _value == 3)
            return true;
        if (_value <= 1 || _value % 2 == 0 || _value % 3 == 0)
            return false;
        for (int i = 5; i * i <= _value; i += 6)
            if (_value % i == 0 || _value % (i + 2) == 0)
                return false;

        return true;
    }
    std::vector<long long> rotate()
    {
        std::vector<long long> res;
        std::string s = stringValue;
        for (int i = 0; i < s.size(); i++)
        {
            std::string t = s.substr(i) + s.substr(0, i);
            res.push_back(stoll(t));
        }
        return res;
    }
    int frequencyOf(int digit){
        int count = 0;
        for (int i = 0; i < stringValue.length(); i++)
            if (stringValue[i] == digit + '0')
                count++;
        return count;
    }
};

/*
Tested:
int main()
{
    Integer integer(123004);
    cout << integer.isOdd() << endl;
    cout << integer.isEven() << endl;
    cout << integer.isDivisibleBy(3) << endl;
    cout << integer.isMultipleOf(3) << endl;
    cout << integer.isCoPrimeWith(3) << endl;
    cout << integer.isPalindrome() << endl;
    cout << integer.isPerfectSquare() << endl;
    cout << integer.doesExits(3) << endl;
    cout << integer.doesNotExits(5) << endl;
    cout << integer.isAllUniqueDigit() << endl;

    cout << integer.getGCDWith(3) << endl;
    cout << integer.getLCMWith(3) << endl;
    cout << integer.getSumOfDigit() << endl;
    cout << integer.getLargestDigits() << endl;
    cout << integer.getSmallestDigits() << endl;
    cout << integer.getNumberOfDigits() << endl;
    cout << integer.getUniqueNumberOfDigits() << endl;
    cout << integer.getUniqueDigits().size() << endl;
    cout << integer.getLargestPermutation().get() << endl;
    cout << integer.getSmallestPermutation().get() << endl;
    cout << integer.removeDigits(2, 3).get() << endl;

    return 0;
}

Sloved Problems:
https://practice.geeksforgeeks.org/problems/sum-of-primes0042/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions


/*
