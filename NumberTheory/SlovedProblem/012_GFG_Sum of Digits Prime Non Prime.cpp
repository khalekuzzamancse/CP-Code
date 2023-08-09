
/*
Link:https://practice.geeksforgeeks.org/problems/sum-of-digits-prime-non-prime1935/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Statement:
Given a number N, you need to write a program that finds the sum of digits
 of the number till the number becomes a single digit and then check
whether the number is Prime/Non-Prime.

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
    long long _value;
    std::string stringValue;

public:
    Integer(long long number)
    {
        this->_value = number;
        stringValue = std::to_string(number);
    }
    int getSumOfDigit()
    {
        int sum = 0;
        for (int i = 0; i < stringValue.length(); i++)
            sum += stringValue[i] - '0';
        return sum;
    }
    bool ifAllDigit(std::function<bool(int digit)> predicate)
    {
        for (int i = 0; i < stringValue.length(); i++)
            if (!predicate(stringValue[i] - '0'))
                return false;
        return true;
    }
    long long value()
    {
        return _value;
    }
};
class Solution
{
public:
    int digitPrime(int n)
    {
        Integer i = Integer(n);
        while (i.value() > 9)
        {
            i = Integer(i.getSumOfDigit());
        }
        return i.ifAllDigit([](int d)
                            { return d == 2 || d == 3 || d == 5 || d == 7; });
    }
};
