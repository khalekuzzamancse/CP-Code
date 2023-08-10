/*
Link:https://practice.geeksforgeeks.org/problems/damon-prime4930/1?page=1&difficulty[]=0&status[]=unsolved&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Damon is a mathematician, and he calls a integer N Damon Prime if N+1 and N-1 both are prime numbers. He will give you an integer N, you need to find whether the number is Damon Prime or not.  
For example:  4 is a damon prime, 5 is not a damon prime, 102 is a damon prime, 9 is not a damon prime, etc . 

*/
#include <bits/stdc++.h>
using namespace std;

class Sieve
{
private:
    const static int mx = 1e4;
    static bool primeContainer[mx + 1];
    static vector<int> primes;
    bool alreadyPrimeGenerated = false;

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
    Sieve()
    {
        generatePrimesSieve();
    }

    bool isPrime(int number)
    {
        // Time complexity: O(1)

        return primeContainer[number] == notCross;
    }
};

bool Sieve::primeContainer[];
class Solution {
  public:
    string damonPrime(int n){
        Sieve s=Sieve();
        return s.isPrime(n-1)&&s.isPrime(n+1)==true?"Yes":"No";
    }
};

//{ Driver Code Starts.
int main() {
    int t=1;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.damonPrime(N) << endl;
    }
    return 0;
}

// } Driver Code Ends