/*
https://practice.geeksforgeeks.org/problems/next-prime-palindrome4153/1?page=1&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
You will be given a positive integer N. Your task is to find the smallest number greater
than or equal to N that is a prime and a palindrome.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
using namespace std;
class Sieve
{

    // Generating Primes
private:
    const static int mx = 1e7;
    static bool primeContainer[mx + 1];
    bool alreadyPrimeGenerated = false;
    const bool cross = true, notCross = false;

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
    // constructor
    Sieve()
    {
        generatePrimesSieve();
    }

public:
    bool isPrime(int number)
    {
        // Time complexity: O(1)
        return primeContainer[number] == notCross;
    }
    int getNextPrime(int number)
    {
        for (int i = number; i <= mx; ++i)
        {
            if (isPrime(i))
                return i;
        }
        return 0;
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

    long long value()
    {
        return _value;
    }
};
class Solution
{
public:
    int PrimePalindrome(int n)
    {
        Sieve s = Sieve();

        while (true)
        {

            int nextP = s.getNextPrime(n);
            Integer i = Integer(nextP);
            if (i.isPalindrome())
                return i.value();
            else
                n = nextP + 1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int tc = 1;
    while (tc--)
    {
        int N;
        cin >> N;
        Solution obj;
        int ans = obj.PrimePalindrome(N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
