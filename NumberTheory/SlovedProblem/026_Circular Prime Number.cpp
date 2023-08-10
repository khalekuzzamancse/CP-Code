/*
link:https://practice.geeksforgeeks.org/problems/circular-prime-number0230/1?page=1&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
A prime number is a Circular Prime Number if all of its possible rotations 
are itself prime numbers. Now given a number N check if it is Circular Prime or Not.
 
Solution:
Use the predefine function of Sieve and Integer class.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long _value;
    std::string stringValue;

public:
    long long value()
    {
        return _value;
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

private:
    const static int mx = 1e5;
    static bool primeContainer[mx + 1];
    bool alreadyPrimeGenerated = false;
    bool alreadyPrimeCollected = false;
    const bool cross = true;
    const bool notCross = false;

private:
    void crossMultipleOf(int i)
    {
        for (int multiple = i * i; multiple <= mx; multiple += i)
            primeContainer[multiple] = cross;
    }

    void generatePrimesSieve()
    {
        // Time complexity: O(nloglog(n)))
        if (alreadyPrimeGenerated)
            return;
        int upto = std::sqrt(mx);
        primeContainer[0] = cross, primeContainer[1] = cross;
        for (int i = 2; i <= upto; ++i)
        {
            if (primeContainer[i] == notCross)
                crossMultipleOf(i);
        }
        alreadyPrimeGenerated = true;
    }

public:
    bool isPrime(int number)
    {
        // Time complexity: O(1)
        return primeContainer[number] == notCross;
    }

public:
    int isCircularPrime(int n)
    {
        this->_value = n;
        stringValue = std::to_string(n);
        generatePrimesSieve();
        bool ans = true;
        for (auto it : rotate())
            ans = ans && isPrime(it);
        return ans;
    }
};
bool Solution::primeContainer[];

int main()
{
    int tc = 1;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.isCircularPrime(n);
        cout << ans << "\n";
    }
    return 0;
}
