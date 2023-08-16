
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
using namespace std;
class String
{
public:
    static const int INDEX_BEYOND_END = -1;

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
        if (end ==INDEX_BEYOND_END)
            end = getLastIndex();
        if (end == INDEX_BEYOND_END)
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
    vector<int> computeLPS(string pattern)
    {
        int m = pattern.length(), i = 1, j = 0;
        vector<int> lps(m);
        lps[0] = 0;
        while (i < m)
        {
            if (pattern[i] == pattern[j])
                j++, lps[i] = j, i++;
            else
            {
                if (j > 0)
                    j = lps[j - 1];
                else
                    lps[i] = 0, i++;
            }
        }
        return move(lps);
    }
    bool kmp(string pattern)
    {
        int m = pattern.length(), n = this->data.length();
        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;
        while (i < n)
        {
            if (pattern[j] == this->data[i])
                i++, j++;
            if (j == m)
                return true;
            else if (i < n && pattern[j] != this->data[i])
            {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
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

public: // operator overloading
    // adding elements
    void pushBack(const char &value)
    {
        data.push_back(value);
    }
    void pushFront(const char &value)
    {
        this->data.insert(this->data.begin(), value);
    }
    void insertAt(char value, size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = this->data.begin();
        advance(it, position);
        this->data.insert(it, value);
    }

    // Removing elements
    //  removing elements
    void removeFirst()
    {
        if (isNotEmpty())
            this->data.erase(this->data.begin());
    }
    void removeLast()
    {
        if (isNotEmpty())
            this->data.pop_back();
    }
    void removeAt(size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = this->data.begin();
        advance(it, position);
        this->data.erase(it);
    }
    void remove(const char &value, int start = 0, int end = INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        this->data.erase(std::remove(range.first, range.second, value), range.second);
    }
    void remove(int start = 0, int end = INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        this->data.erase(range.first, range.second);
    }
    void removeUntil(int start = 0, int end = INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        this->data.erase(range.first, range.second);
    }
    void removeIf(std::function<bool(const char &)> predicate, int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        this->data.erase(std::remove_if(range.first, range.second, predicate), range.second);
    }
    String &removeDuplicate(int start = 0, int end =INDEX_BEYOND_END)
    {
        // Complexity: O(N)
        auto range = getRange(start, end);
        std::unordered_set<char> s;
        auto is_duplicate = [&s](char x)
        {
            return !s.insert(x).second;
        };
        this->data.erase(std::remove_if(range.first, range.second, is_duplicate), range.second);
        return *this;
    }

    String &removeConsecutiveDuplicate(int start = 0, int end =INDEX_BEYOND_END)
    {
        // Complexity: O(N)
        auto range = getRange(start, end);
        String result;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (result.isEmpty() || result.data.back() != *it)
            {
                result.pushBack(*it);
            }
        }
        this->data = std::move(result.data);
        return *this;
    }

    // Diffiererent finding methods

    int find(std::function<bool(const char &)> predicate, int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        auto it = std::find_if(range.first, range.second, predicate);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }
    int findReseverse(std::function<bool(const char &)> predicate, int start = 0, int end =INDEX_BEYOND_END)
    {
        std::pair<typename std::string::iterator,
                  typename std::string::iterator>
            range = getRange(start, end);
        auto it = std::find_if(std::make_reverse_iterator(range.second), std::make_reverse_iterator(range.first), predicate);
        int pos = -1;
        bool isFound = it != std::make_reverse_iterator(range.first);
        if (isFound)
            pos = std::distance(range.first, it.base()) - 1 + start;
        return pos;
    }

    bool doesExits(const char &value)
    {
        bool isFound = find([&value](char ch)
                            { return ch == value; }) != -1;
        return isFound;
    }
    bool doesNotExits(const char &value)
    {

        return !doesExits(value);
    }

    int count(const char &value, int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        return ::count(range.first, range.second, value);
    }
    int countIf(std::function<bool(const char &)> predicate, int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        return ::count_if(range.first, range.second, predicate);
    }

    // Minimum and maximum values
    // These methods have default paramter implementations

    pair<char, int> max(
        int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        auto it = std::max_element(range.first, range.second);
        char value = *it;
        int pos = std::distance(this->data.begin(), it);
        return std::make_pair(value, pos);
    }
    pair<char, int> min(
        int start = 0,
        int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::min_element(range.first, range.second);
        char value = *it;
        int pos = std::distance(this->data.begin(), it);
        return std::make_pair(value, pos);
    }
    //
    void forEach(std::function<void(size_t, const char &)> func, int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        size_t i = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            func(i, *it);
            i++;
        }
    }
    void forEachReverse(std::function<void(size_t, const char &)> func, int start = 0, int end =INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        size_t i = 0;
        // use reverse_iterator to wrap the normal iterators
        for (auto it = std::reverse_iterator(range.second); it != std::reverse_iterator(range.first); ++it)
        {
            func(i, *it);
            i++;
        }
    }
    // Modifityng elemnts
    // String map(std::function<char(char)> transformFunction) const
    // {
    //     string result;
    //     for (const char &element : data)
    //         result.insert(result.end(), transformFunction(element));
    //     return String(result);
    // }

    String &map(std::function<char(char)> transformFunction, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        std::transform(range.first, range.second, range.first, transformFunction);
        return *this;
    }

    // Filter methods
    String filter(std::function<bool(size_t, const char &)> predicate, int start = 0, int end = INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        string result;

        size_t i = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (predicate(i, *it))
                result.insert(result.end(), *it);
            i++;
        }
        return String(result);
    }
    //

    // Sorting
    void sort(
        int start = 0,
        int end = -1,
        function<bool(char a,
                      char b)>
            comparator = [](char a, char b)
        { return a < b; })
    {
        auto range = getRange(start, end);
        std::sort(range.first, range.second, comparator);
    }

    // Reversing
    void reverse(int start = 0,
                 int end = INDEX_BEYOND_END)
    {
        auto range = getRange(start, end);
        std::reverse(range.first, range.second);
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
    size_t length()
    {
        return size();
    }
    int getLastIndex()
    {
        return size() - 1;
    }
    //
    bool isEqual(string &value)
    {
        return this->data == value;
    }
    char getAt(int position)
    {
        if (isOutOfBound(position))
            throw std::out_of_range("Invalid index");
        return this->data.at(position);
    }
    string get()
    {

        return this->data;
    }
    char getFirst()
    {
        if (data.empty())
            throw std::out_of_range("Empty string");
        return this->data.front();
    }
    char getLast()
    {
        if (data.empty())
            throw std::out_of_range("Empty string");
        return this->data.back();
    }
    // query
    bool isSubstring(string pattern)
    {
        return this->kmp(pattern);
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

int main()
{
    string str = "abaaacde";
    String s = String(str);
    s.toString();
    // s.pushBack('1');
    // s.pushFront('0');
    // s.insertAt('c',2);
    // s.toString();
    // s.removeFirst();
    // s.removeLast();
    // s.toString();
    // s.removeIf([](char c)
    //            { return c != 'a'; });
    // s.toString();
    //     .removeDuplicate()
    //     .toString();
    s.removeConsecutiveDuplicate().toString();

    // cout << s.findIf([](char c)
    //                  { return c == 'c'; });
    // cout << s.findIfReseverse([](char c)
    //                           { return c == 'a'; });
    // cout << s.findIf([](char c)
    //                  { return c == 'c'; },
    //                  0,3);
    // cout << s.findIfReseverse([](char c)
    //                           { return c == 'a'; },
    //                           0, 1);

    // cout << s.count('a') << endl;
    //  cout << s.countIf([](char c)
    //                   { return c == 'c'; });
    //  cout << s.countIf([](char c)
    //                   { return c == 'c'; },
    //                   0,2);
    // cout << s.max(0, 2).first << s.max(0, 2).second << endl;
    // cout << s.max().first << s.max().second << endl;
    // s.forEach([](size_t i, char c)
    //           { cout << i << c << endl; });
    // s.forEachReverse([](size_t i, char c)
    //           { cout << i << c << endl; });

    // s.map([](const char ch)
    //       { return ch - 32; })
    //     .toString();
    // string x = "abacd";
    //  cout << s.isEqual(x);

    // s.map([](char c)
    //       { return std::toupper(c); })

    // cout << s.min(0, 2).first << s.min(0, 2).second << endl;
    // s.filter([](size_t index, const char &ch)
    //          { return (ch == 'a' && index % 2 == 0); })
    //     .toString(",");
    // s.filter([](size_t index, const char &ch)
    //          { return (index % 2 == 0); })
    //     .toString("");
    // s.sort();
    // s.toString();
    // s.reverse();
    // s.toString();

    return 0;
}