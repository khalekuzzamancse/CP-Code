/*

Given a string S that represents column title of an Excel sheet, find the number that represents that column.
In excel A=1, AA = 27 and so on.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getEncoded(char ch)
    {
        return ch - 'A'+1;
    }

public:
    int ExcelColumnNumber(string s)
    {
        int ans = 0, base = 26;
        for (int i = 0; i < s.length(); i++)
        {
            ans += getEncoded(s[i]) * pow(base, s.size() - i - 1);
        }
        return ans;
    }
};
