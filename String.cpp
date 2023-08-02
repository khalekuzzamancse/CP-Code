#include <iostream>
#include <string>
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
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        return std::make_pair(it_start, it_end);
    }

public:
    // Constructors
    String()
    {
    }
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
    void remove(const char &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->data.erase(std::remove(range.first, range.second, value), range.second);
    }
    void removeIf(std::function<bool(const char &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->data.erase(std::remove_if(range.first, range.second, predicate), range.second);
    }

    // Diffiererent finding methods
    int find(const char &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find(range.first, range.second, value);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }

    int findIf(std::function<bool(const char &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find_if(range.first, range.second, predicate);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }

    bool doesExits(const char &value)
    {
        bool isFound = find(value) != -1;
        return isFound;
    }
    bool doesNotExits(const char &value)
    {

        return !doesExits(value);
    }

    int count(const char &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        return ::count(range.first, range.second, value);
    }
    int countIf(std::function<bool(const char &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        return ::count_if(range.first, range.second, predicate);
    }

    // Minimum and maximum values
    // These methods have default paramter implementations

    pair<char, int> max(
        int start = 0, int end = -1)
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
                 int end = -1)
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

    char get(int position)
    {
        if (isOutOfBound(position))
            throw std::out_of_range("Invalid index");
        return this->data.at(position);
    }
    char getFirst()
    {
        if (isEmpty())
            throw std::out_of_range("Empty string");
        return this->data.front();
    }
    char getLast()
    {
        if (isEmpty())
            throw std::out_of_range("Empty string");
        return this->data.back();
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
    string str = "abacde";
    String s = String(str);
    s.toString();
    // s.pushBack('1');
    // s.pushFront('0');
    // s.insertAt('c',2);
    // s.toString();
    // s.removeFirst();
    // s.removeLast();
    // s.toString();
    // cout << s.find('c') << endl;
    // cout << s.find('c', 2, 3) << endl;
    // cout << s.findIf([](char c)
    //                  { return c == 'c'; });
    // cout << s.findIf([](char c)
    //                  { return c == 'c'; },
    //                  0,3);

    // cout << s.count('a') << endl;
    //  cout << s.countIf([](char c)
    //                   { return c == 'c'; });
    //  cout << s.countIf([](char c)
    //                   { return c == 'c'; },
    //                   0,2);
    // cout << s.max(0, 2).first << s.max(0, 2).second << endl;
    // cout << s.max().first << s.max().second << endl;

    // str.filter([](const char &ch)
    //            { return (ch == 'a') || (ch == 'e'); })
    //     .toString(",");

    // str.filterIndexed([](const char &ch, size_t index)
    //                   { return (ch == 'a' && index % 2 == 0); })
    //     .toString(",");
    // str.filterIndexed([](const char &ch, size_t index)
    //                   { return (index % 2 == 0); })
    //     .toString("");
    // cout << str.getFirst() << str.getLast() << endl;

    return 0;
}