/*
Link:
https://practice.geeksforgeeks.org/problems/prime-palindrome-sum3700/1?page=1&difficulty[]=-1&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given is a range of integers [a , b]  . You have to find the sum of all the 
numbers in the range  [a , b] that are prime as well as palindrome.
Uses:
Sieve class
Integer class

*/

#include <bits/stdc++.h>
using namespace std;

class PrimesUptoN
{
private:
    const static int N = 1e5;

    static vector<int> primes;
    bool alreadyPrimeGenerated = false;
    const bool cross = true;
    const bool notCross = false;

private:
    static bool primeContainer[N + 1];

private:
    void crossMultipleOf(int i)
    {
        for (int multiple = i * i; multiple <= N; multiple += i)
            primeContainer[multiple] = cross;
    }

    void generatePrimesSieve()
    {
        // Time complexity: O(nloglog(n)))
        if (alreadyPrimeGenerated)
            return;
        int upto = std::sqrt(upto);
        primeContainer[0] = cross, primeContainer[1] = cross;
        for (int i = 2; i <= upto; ++i)
        {
            if (primeContainer[i] == notCross)
                crossMultipleOf(i);
        }
        alreadyPrimeGenerated = true;
    }

public:
    PrimesUptoN()
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
bool PrimesUptoN::primeContainer[];

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
        PrimesUptoN s = PrimesUptoN();
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
