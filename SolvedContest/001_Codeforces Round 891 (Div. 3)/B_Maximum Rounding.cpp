/*
https://codeforces.com/contest/1857/problem/B

Proposed Resolution Approach:
Let's devise a solution strategy as follows:

Step 1: Locate the position, denoted as 'pos', traversing from the end to the beginning of the string 's',
 where the character 's[i]' is greater than '4'.

Step 2: Define 'k' as 'pos - 1'.

Case 1:
    If 'k' is greater than or equal to 0:
    This implies that 'pos' is at least 1, since 'pos' is positive. Therefore, there exists an 'i' such that 's[i]'
    is greater than '4'. To perform rounding, we need to address the following scenarios:

    Sub-case 1: Check if 's[k]' is equal to '9'.
        - If 's[k]' is '9', then search for a position, denoted as 'k'', within the string, such that 's[i]' is greater than '9'.
        This position should be searched from 'k-1' to 0. If 'k'' is greater than or equal to 0, it signifies
        the existence of an index within the string where 's[i]' is less than '9'. We update 'k'' as the new rounded position.
        - If no index with 's[i] < 9' is found, we can use the position before index 0 as 'k''.
        According to the problem statement, we can consider the index before 0 to have 's[i] = '0''.
        - In this case, insert the digit '1' before the identified position 'k'' and replace characters from
        index 1 to the end of the string with '0'.
Case 2:
    If 'k' is -1:
    In this situation, 'pos' is 0, indicating that we need to round the index before 0. To achieve this:
    - Insert the digit '1' before index 0.
    - Replace the remaining characters in the string with '0'.
Case 3:
    If 'k' is -2:
    This indicates that no such position exists where 's[i]' is greater than '4'. Consequently, further
    rounding of the string is not possible.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int lastRoundedPosition;

private:
    int findPos()
    {
        for (int i = lastRoundedPosition; i >= 0; i--)
            if (s[i] > '4')
                return i;
        return -1;
    }
    int updateK(int k)
    {
        // k==0 ,k-1=-1
        for (int i = k - 1; i >= 0; i--)
        {
            if (s[i] < '9')
            {
                k = i;
                return i;
            }
        }
        return -1;
    }
    int findK()
    {
        int k = findPos() - 1; //-2, -1,...to last index
        if (k < 0)
            return k;
        if (s[k] == '9')
            k = updateK(k);
        return k;
    }
    void replaceWithZero(int k)
    {
        for (int i = k + 1; i < s.length(); i++)
            s[i] = '0';
    }

public:
    string s;
    Solution()
    {
        cin >> s;
        lastRoundedPosition = s.length() - 1;
    }

    void solve()
    {
        int k = -1;
        while (k != -2)
        {
            int k = findK();
            if (k == -2)
                break;
            if (k == -1)
                s = '1' + s, k = 0, lastRoundedPosition = k;
            else
                s[k] = s[k] + 1, lastRoundedPosition = k;
        }
        replaceWithZero(lastRoundedPosition);
        cout << s << endl;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        Solution s;
        s.solve();
    }

    return 0;
}
