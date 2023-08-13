/*
Link:https://practice.geeksforgeeks.org/problems/find-the-highest-occurring-digit-in-prime-numbers-in-a-range3634/1?page=1&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions
Given a range L to R, the task is to find the highest occurring digit in prime numbers which lie between L and R (both inclusive). If multiple digits have same highest frequency return the largest of them.
If no prime number occurs between L and R, return -1.
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

    int frequencyOf(int digit)
    {
        int count = 0;
        for (int i = 0; i < stringValue.length(); i++)
            if (stringValue[i] == digit + '0')
                count++;
        return count;
    }
};
class PrimesUptoN
{

    // Generating Primes
private:
    const static int N = 1e5;
    static bool primeContainer[N + 1];
    bool alreadyPrimeGenerated = false;
    const bool cross = true, notCross = false;

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
    // constructor
    PrimesUptoN()
    {
        generatePrimesSieve();
    }

public:
    bool isPrime(int number)
    {
        // Time complexity: O(1)
        return primeContainer[number] == notCross;
    }

    void forEachPrime(std::function<void(int prime)> lambda, int l = 2, int r = N)
    {
        for (int number = l; number <= r; number++)
            if (isPrime(number))
                lambda(number);
    }
};
bool PrimesUptoN::primeContainer[];
class Solution
{
public:
    int maxDigit(int l, int r)
    {
        PrimesUptoN s = PrimesUptoN();
        int frequency[10] = {0};
        s.forEachPrime([&frequency](int prime)
                       {
            Integer in = Integer(prime);
            for(int i=0; i<10; i++)
            frequency[i]+=in.frequencyOf(i); },
                       l, r);

        int ans = 9;
        int f = 0;
        for (int i = 9; i >= 0; i--)
            if (frequency[i] > f)
                ans = i, f = frequency[i];
        return f == 0 ? -1 : ans;
    }
};

int main()
{
    int t = 1;
    while (t--)
    {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.maxDigit(L, R) << endl;
    }
    return 0;
}
