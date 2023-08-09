/*
Link:https://practice.geeksforgeeks.org/problems/repeated-sum-of-digits3955/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Statement:
Given an integer N, recursively sum digits of N until we get a single digit.
Solution:
Used code from Integer class

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
    long long value()
    {
        return _value;
    }
};
class Solution
{
public:
    int repeatedSumOfDigits(int n)
    {
        Integer i = Integer(n);
        while (i.value() > 9)
        {
            i = Integer(i.getSumOfDigit());
        }
        return i.value();
    }
};
int main()
{
    long long n;
    cin >> n;
    Integer i = Integer(n);
    while (i.value() > 9)
    {
        i = Integer(i.getSumOfDigit());
    }
    cout << i.value() << endl;

    return 0;
}
