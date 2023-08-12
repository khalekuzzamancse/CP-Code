
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;
template <typename T>
class Vector
{
public:
    const static int INVALID_INDEX = -1;

private:
    std::vector<T> _elements;
    bool isOutOfBound(int position)
    {
        return position < 0 || position > getLastIndex();
    }
    std::pair<typename std::vector<T>::iterator,
              typename std::vector<T>::iterator>
    getRange(int start, int end)
    {
        if (end == INVALID_INDEX)
            end = getLastIndex();
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = _elements.begin();
        auto it_end = _elements.begin();
        std::advance(it_start, start), std::advance(it_end, end + 1);
        return std::make_pair(it_start, it_end);
    }

public:
    Vector() = default;
    Vector(const std::vector<T> &v) : _elements(v) {}
    Vector(std::vector<T> &&v) : _elements(std::move(v)) {}
    Vector(int inputSize)
    {
        while (inputSize--)
        {
            T x;
            cin >> x;
            pushBack(x);
        }
    }
    // Operator overloaded
public:
    T &operator[](size_t index)
    {
        if (isOutOfBound(index))
            throw std::out_of_range("Index out of bounds");
        return _elements[index];
    }
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
            _elements = other._elements;
        return *this;
    }
    bool operator!=(const Vector &other) const
    {
        return _elements != other._elements;
    }
    bool operator==(const Vector &other) const
    {
        return _elements == other._elements;
    }
    // Compulsory
    size_t getLastIndex()
    {
        return this->_elements.size() - 1;
    }

    // Empty or Not
    bool isEmpty()
    {
        return this->_elements.empty();
    }
    bool isNotEmpty()
    {
        return !isEmpty();
    }
    int size()
    {
        return _elements.size();
    }

public:
    // Adding elements
public:
    void pushBack(const T &value)
    {
        _elements.push_back(value);
    }

    //

    vector<T> get()
    {
        return _elements;
    }

    T getLast()
    {
        if (isEmpty())
            throw std::out_of_range("Vector is empty");
        return _elements[size() - 1];
    }

    void toString(string separator = " ")
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size() - 1; i++)
            cout << _elements[i] << separator;
        cout << _elements[_elements.size() - 1];
        cout << endl;
        return;
    }
    void removeLast()
    {
        if (isNotEmpty())
            this->_elements.pop_back();
    }

    void sort(
        int start = 0, int end = INVALID_INDEX, std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
                                                { return a < b; })
    {
        auto range = getRange(start, end);
        std::sort(range.first, range.second, comparator);
    }
};

class Solution
{
    Vector<int> a, b;
    void makeB()
    {
        int last = a.getLast();
        while (a.isNotEmpty() && a.getLast() == last)
        {
            b.pushBack(last);
            a.removeLast();
        }
    }

public:
    Solution()
    {
        int n;
        cin >> n;
        a = Vector<int>(n);
        a.sort();
    }
    void solve()
    {

        makeB();
        if (a.isEmpty())
            cout << -1 << endl;
        else if (b.isEmpty())
            cout << -1 << endl;
        else
        {
            cout << a.size() << " " << b.size() << endl;
            a.toString();
            b.toString();
        }
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