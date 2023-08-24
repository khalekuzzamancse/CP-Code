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

    pair<T, int> max(int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        auto it_max = std::max_element(range.first, range.second);
        int pos = std::distance(_elements.begin(), it_max);
        return make_pair(*it_max, pos);
    }

    void forEach(std::function<void(size_t index, const T &value, bool &stop)> callback, size_t step = 1, int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        size_t index = 0;
        bool stop = false;
        for (auto it = range.first; it != range.second; ++it)
        {
            callback(index, *it, stop);
            if (stop)
                break;
            index++;
        }
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
};
class Solution
{
    Vector<int> old;
    int n, k;
    int findMaxPos()
    {
        int pos = -1, mx = -1;
        for (int i = 0; i <= n - 2; i++)
        {
            if (old[i] <= old[i + 1] && old[i] > mx)
                mx = old[i], pos = i;
        }
        return pos;
    }
    int difference(int i)
    {
        return old[i + 1] - old[i];
    }
    int incPossible(int diff, int k)
    {
        return min(diff, k);
    }
    int updatedK(int k, int inc)
    {
        return k - inc;
    }

public:
    Solution()
    {

        cin >> n >> k;
        old = Vector<int>(n);
    }
    void solve()
    {

        while (k > 0)
        {
            old.toString();
            int pos = findMaxPos();
            if (pos != -1)
            {
                int d = difference(pos);
                int inc = incPossible(d, k);

                cout << "d: " << d << " inc :" << inc << " k " << k << endl;
                cout << old[pos] << " " << pos + 1 << endl;
                old[pos] += inc;
                k = updatedK(k, inc);
            }
        }
        old.toString();
        cout << old.max().first << endl;
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