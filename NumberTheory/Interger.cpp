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

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
using namespace std;
class Integer
{
private:
    long long number;
    string numberAsString;

public:
    Integer(long long number)
    {
        this->number = number;
        numberAsString = to_string(number);
    }
    bool isOdd()
    {
        return number % 2 != 0;
    }
    bool isEven()
    {
        return number % 2 == 0;
    }
    bool isDivisibleBy(long long divisor)
    {
        return number % divisor == 0;
    }
    bool isMultipleOf(long long n)
    {
        return number % n == 0;
    }
    bool isCoPrimeWith(long long n)
    {
        long long gcd = __gcd(number, n);
        return gcd == 1;
    }
    bool isPalindrome()
    {
        std::string rstr = numberAsString;
        std::reverse(rstr.begin(), rstr.end());
        return numberAsString == rstr;
    }
    bool isPerfectSquare()
    {
        if (number < 0)
            return false;
        long long root = std::sqrt(number);
        return root * root == number;
    }
    bool doesExits(int digit)
    {
        for (int i = 0; i < numberAsString.length(); i++)
            if (numberAsString[i] == digit + '0')
                return true;
        return false;
    }
    bool doesNotExits(int digit)
    {
        return !doesExits(digit);
    }
    bool isAllUniqueDigit()
    {
        return numberAsString.length() == getUniqueNumberOfDigits();
    }

    // getters
    long long getGCDWith(long long n)
    {
        return __gcd(number, n);
    }
    long long getLCMWith(long long n)
    {
        return (number / __gcd(number, n)) * n;
    }
    long long getSumOfDigit()
    {
        long long sum = 0;
        for (int i = 0; i < numberAsString.length(); i++)
            sum += numberAsString[i] - '0';
        return sum;
    }
    long long getLargestDigits()
    {
        long long largest = 0;
        for (int i = 0; i < numberAsString.length(); i++)
            if (numberAsString[i] - '0' > largest)
                largest = numberAsString[i] - '0';

        return largest;
    }

    long long getSmallestDigits()
    {
        long long smallest = 9;
        for (int i = 0; i < numberAsString.length(); i++)
            if (numberAsString[i] - '0' < smallest)
                smallest = numberAsString[i] - '0';
        return smallest;
    }

    long long getNumberOfDigits()
    {
        return numberAsString.length();
    }
    long long getUniqueNumberOfDigits()
    {
        return getUniqueDigits().size();
    }
    set<int> getUniqueDigits()
    {
        set<int> s;
        for (int i = 0; i < numberAsString.length(); i++)
            s.insert(numberAsString[i] - '0');
        return s;
    }

    Integer removeDigits(int l, int r)
    {
        string s = numberAsString;
        s.erase(s.begin() + l, s.begin() + r + 1);
        long long numberAsLongLong = std::stoll(s);
        return Integer(numberAsLongLong);
    }

    Integer getSmallestPossibleNumber()
    {
        string s = numberAsString;
        std::sort(s.begin(), s.end());
        return Integer(std::stoll(s));
    }
    Integer getLargestPossibleNumber()
    {
        std::string s = numberAsString;
        std::sort(s.begin(), s.end(), std::greater<char>());
        return Integer(std::stoll(s));
    }

    long long get()
    {
        return number;
    }
};

int main()
{
    Integer integer(123004);
    // cout << integer.isOdd() << endl;
    // cout << integer.isEven() << endl;
    // cout << integer.isDivisibleBy(3) << endl;
    // cout << integer.isMultipleOf(3) << endl;
    // cout << integer.isCoPrimeWith(3) << endl;
    // cout << integer.isPalindrome() << endl;
    // cout << integer.isPerfectSquare() << endl;
    // cout << integer.doesExits(3) << endl;
    // cout << integer.doesNotExits(5) << endl;
    // cout << integer.isAllUniqueDigit() << endl;

    // cout << integer.getGCDWith(3) << endl;
    // cout << integer.getLCMWith(3) << endl;
    // cout << integer.getSumOfDigit() << endl;
    // cout << integer.getLargestDigits() << endl;
    //  cout << integer.getSmallestDigits() << endl;
    //  cout << integer.getNumberOfDigits() << endl;
    // cout << integer.getUniqueNumberOfDigits() << endl;
    // cout << integer.getUniqueDigits().size() << endl;
    // cout << integer.getLargestPossibleNumber().get() << endl;
    // cout << integer.getSmallestPossibleNumber().get() << endl;
    // cout << integer.removeDigits(2, 3).get() << endl;

    return 0;
}
