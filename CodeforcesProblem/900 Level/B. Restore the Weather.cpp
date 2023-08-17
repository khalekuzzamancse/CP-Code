/*
https://codeforces.com/problemset/problem/1833/B
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
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
    Vector(size_t inputSize, T initialValue)
    {
        while (inputSize--)
            pushBack(initialValue);
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

public:
    // Adding elements
public:
    void pushBack(const T &value)
    {
        _elements.push_back(value);
    }

    void forEach(std::function<void(size_t index)> callback, size_t step = 1, int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        size_t index = 0;
        for (auto it = range.first; it != range.second; ++it)
            callback(index), index++;
    }

    void toString(string separator = " ")
    {
        if (_elements.empty())
            return;
        for (int i = 0; i < _elements.size() - 1; i++)
            cout << _elements[i] << separator;
        cout << _elements[_elements.size() - 1];
        cout << endl;
        return;
    }

    void sort(
        int start = 0, int end = INVALID_INDEX, std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
                                                { return a < b; })
    {
        auto range = getRange(start, end);
        std::sort(range.first, range.second, comparator);
    }

    Vector<pair<T, int>> sortWithPreserveIndex()
    {
        vector<pair<T, int>> result(_elements.size());
        for (size_t i = 0; i < _elements.size(); ++i)
            result[i] = {_elements[i], i};

        std::sort(result.begin(), result.end());
        return move(Vector<pair<T, int>>(result));
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Vector<int> a(n), b(n), ans(n, 0);
        b.sort();
        auto sorted = a.sortWithPreserveIndex();

        sorted.forEach([&sorted, &ans, &b](size_t i){
             ans[sorted[i].second] = b[i]; }
             );

        ans.toString();
    }

    return 0;
}
