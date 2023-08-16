/*
https://codeforces.com/problemset/problem/1837/B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class String
{
private:
    std::string data;
    bool isOutOfBound(int position)
    {
        return position < 0 || position > getLastIndex();
    }
    std::pair<typename std::string::iterator,
              typename std::string::iterator>
    getRange(int start, int end)
    {
        if (end == -1)
            end = getLastIndex();
        if (isOutOfBound(start))
            throw std::out_of_range("Invalid start position");
        if (isOutOfBound(end))
            throw std::out_of_range("Invalid end position");
        if (isOutOfBound(start > end))
            throw std::out_of_range("Invalid start>end");

        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        return std::make_pair(it_start, it_end);
    }

public:
    // Constructors
    String() = default;
    String(string &s)
    {
        this->data = s;
    }
    String(int inputSize)
    {
        while (inputSize--)
        {
            char x;
            cin >> x;
            pushBack(x);
        }
    }

    // adding elements
    void pushBack(const char &value)
    {
        data.push_back(value);
    }

    int find(std::function<bool(const char &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find_if(range.first, range.second, predicate);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }

    // Utility methods
    bool isEmpty()
    {
        return this->data.empty();
    }
    bool isNotEmpty()
    {
        return !isEmpty();
    }
    size_t size()
    {
        return this->data.size();
    }

    int getLastIndex()
    {
        return size() - 1;
    }

    char getAt(int position)
    {
        if (isOutOfBound(position))
        {
            string s=to_string(position);
            throw std::out_of_range("Invalid index:getAt(),index: "+s);
        }

        return this->data.at(position);
    }
    string get()
    {

        return this->data;
    }

    void toString(string separator = "")
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size() - 1; i++)
            cout << data[i] << separator;
        cout << data[data.size() - 1];
        cout << endl;
        return;
    }
};

class Solution
{

    int n;
    String s;
    int longestContiguousSegment;

public:
    Solution()
    {
        cin >> n;
        string x;
        cin >> x;
        s = String(x);
        longestContiguousSegment = 1;
    }
    void solve()
    {
      
        int pos = 0;
        while (pos != -1)
        {
            char c = s.getAt(pos);
            int nextPos = s.find([&c](char ch)
                                 { return ch != c; },
                                 pos);
           
            int len=(nextPos==-1?s.size():nextPos)-pos;
             pos = nextPos;
          longestContiguousSegment =max(longestContiguousSegment,len);
        }

         cout << longestContiguousSegment +1 << endl;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution solution = Solution();
        solution.solve();
    }

    return 0;
}
