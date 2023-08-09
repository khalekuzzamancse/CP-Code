/*
Link:
https:https://practice.geeksforgeeks.org/problems/prime-palindrome-sum3700/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Uses:
Sieve class
Integer class

*/

#include <bits/stdc++.h>
using namespace std;

class Sieve
{
private:
    const static int mx = 1e5;

    static vector<int> primes;
    bool alreadyPrimeGenerated = false;
    const bool cross = true;
    const bool notCross = false;

private:
    static bool primeContainer[mx + 1];

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
    Sieve()
    {
        generatePrimesSieve();
    }

    bool isPrime(int number)
    {
        // Time complexity: O(1)

        return primeContainer[number] == notCross;
    }
    vector<int> getPrimes(int a, int b)
    {
        vector<int> primes;
        for (int i = a; i <= b; i++)
            if (isPrime(i))
                primes.push_back(i);

        return primes;
    }
};
bool Sieve::primeContainer[];

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
    bool isPalindrome()
    {
        std::string rstr = stringValue;
        std::reverse(rstr.begin(), rstr.end());
        return stringValue == rstr;
    }
};

class Solution
{
public:
    long long getPPS(int a, int b)
    {
        Sieve s = Sieve();
        vector<int> primes = s.getPrimes(a, b);
        long long sum = 0;
        for (int it : primes)
        {
            Integer i = Integer(it);
            if (i.isPalindrome())
                sum += it;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{

    int a, b;
    cin >> a >> b;
    Solution ob;
    cout << ob.getPPS(a, b) << endl;

    return 0;
}
// } Driver Code Ends
