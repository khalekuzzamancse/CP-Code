
/*
Link:https://practice.geeksforgeeks.org/problems/corner-digits1317/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Statement:
Given a number N, find the sum of first and last digit of N.
Solution:
Used the some code from Integer class.


*/

#include <bits/stdc++.h>
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
    int getNumberOfDigits()
    {
        return stringValue.length();
    }

    Integer removeDigits(int l, int r)
    {
        std::string s = stringValue;

        s.erase(s.begin() + l, s.begin() + r + 1);
        long long numberAsLongLong = std::stoll(s);
        return Integer(numberAsLongLong);
    }
    int getSumOfDigit()
    {
        int sum = 0;
        for (int i = 0; i < stringValue.length(); i++)
            sum += stringValue[i] - '0';
        return sum;
    }
};
class Solution
{
public:
    int corner_digitSum(int n)
    {
        if (n < 10)
            return n;
        Integer integer = Integer(n);
        int r = integer.getNumberOfDigits();
        return integer.removeDigits(1, r - 2).getSumOfDigit();
    }
};

//{ Driver Code Starts.
int main()
{

    int n;
    cin >> n;
    Solution ob;
    int ans = ob.corner_digitSum(n);
    cout << ans << "\n";

    return 0;
}
// } Driver Code Ends