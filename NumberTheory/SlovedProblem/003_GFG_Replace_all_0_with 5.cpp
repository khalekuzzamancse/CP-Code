/*
Link=https://practice.geeksforgeeks.org/problems/replace-all-0-with-5-in-an-input-integer/1?page=1&difficulty[]=-2&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Statement:
Given a number N. The task is to complete the function convertFive() which replaces
all zeros in the number with 5 and returns the number.

Solution:
Used the some code from Integer class

*/

#include <bits/stdc++.h>
using namespace std;
class Integer
{
private:
    long long number;
    std::string numberAsString;

public:
    Integer(long long number)
    {
        this->number = number;
        numberAsString = std::to_string(number);
    }
    Integer replaceDigitIf(std::function<int(int digit, int position)> lambda)
    {
        std::string num = numberAsString;
        for (int i = 0; i < num.length(); i++)
        {
            int replaceBy = lambda(num[i] - '0', i);
            if (replaceBy != -1)
                num[i] = replaceBy + '0';
        }
        return Integer(std::stoll(num));
    }
    long long get()
    {
        return number;
    }
};
class Solution
{
    static int shouldReplace(int digit, int position)
    {
        return digit == 0 ? 5 : -1;
    }

public:
    int convertFive(int n)
    {
        Integer integer = Integer(n);
        return integer.replaceDigitIf(shouldReplace)
            .get();
    }
};

