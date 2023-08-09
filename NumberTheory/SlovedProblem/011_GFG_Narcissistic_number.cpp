/*

Link:
Statement:https://practice.geeksforgeeks.org/problems/narcissistic-number4852/1?page=1&difficulty[]=-1&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given N, check whether it is a Narcissistic number or not.
Note: Narcissistic Number is a number that is the sum of its own digits
each raised to the power of the number of digits

Example 1:
Input:
N = 407
Output:
1
Explanation:
4^3+0^3+7^3 = 64+0+343
= 407 equals to N.
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
    int getNumberOfDigits()
    {
        return stringValue.length();
    }

    void forEachDigit(std::function<void(int digit)> lambda)
    {
        for (int i = 0; i < stringValue.length(); i++)
            lambda(stringValue[i] - '0');
    }
};
class Solution
{

public:
    int isNarcissistic(int n)
    {
        Integer i = Integer(n);
        int e = i.getNumberOfDigits();
        int sum = 0;
        i.forEachDigit([&sum, &e](int d)
                       { sum += pow(d, e); });
        return sum == n;
    }
};

//{ Driver Code Starts.
int main()
{

    int N;
    cin >> N;
    Solution ob;
    cout << ob.isNarcissistic(N) << endl;

    return 0;
}
// } Driver Code Ends