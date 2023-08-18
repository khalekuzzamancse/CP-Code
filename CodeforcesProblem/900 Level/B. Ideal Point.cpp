#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
    int n, k;
    vector<vector<int>> segmentsOfK;
    bool isKInSegment(int l, int r)
    {
        return l <= k && r >= k;
    }
    void addSegment(int l, int r)
    {
        vector<int> segment;
        for (int i = l; i <= r; i++)
            segment.push_back(i);
        segmentsOfK.push_back(segment);
    }
    void printToSegments()
    {
        for (int i = 0; i < segmentsOfK.size(); i++)
        {
            for (int j = 0; j < segmentsOfK[i].size(); j++)
                cout << segmentsOfK[i][j] << " ";
            cout << endl;
        }
    }

    bool isKHasMaxFrequency(map<int, int> frequency)
    {
        for (auto it : frequency)
        {
            if (it.first != k && !(it.second < frequency[k]))
                return false;
        }
        return true;
    }

public:
    void solve()
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            int l, r;
            cin >> l >> r;
            if (isKInSegment(l, r))
                addSegment(l, r);
        }

        bool isPossible = false;
        map<int, int> frequency;
        for (int i = 0; i < segmentsOfK.size(); i++)
        {
            for (int j = 0; j < segmentsOfK[i].size(); j++)
            {
                int number = segmentsOfK[i][j];
                frequency[number]++;
            }
            if (isKHasMaxFrequency(frequency))
            {
                isPossible = true;
                break;
            }
        }
        cout << (isPossible ? "YES" : "NO") << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution;
        solution.solve();
    }
    return 0;
}