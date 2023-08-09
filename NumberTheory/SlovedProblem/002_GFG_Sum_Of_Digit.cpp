/*
Link:https://practice.geeksforgeeks.org/problems/sum-of-digits1742/1?page=1&difficulty[]=-2&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Problem Statements:
Given a number, N. Find the sum of all the digits of N

Solution:
Using some code from the Integer class.

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

    int long getSumOfDigit()
    {
        int long sum = 0;
        for (int i = 0; i < numberAsString.length(); i++)
            sum += numberAsString[i] - '0';
        return sum;
    }
};
class Solution
{
public:
    int sumOfDigits(int N)
    {
        return Integer(N).getSumOfDigit();
    }
};
