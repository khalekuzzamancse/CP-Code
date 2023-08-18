#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

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

        string msg;
        msg.append("start: " + to_string(start));
        msg.append("end: " + to_string(end));

        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range\n" + msg);
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
    size_t getLastIndex()
    {
        return this->_elements.size() - 1;
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

    int countIf(std::function<bool(const T &)> predicate, int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        return ::count_if(range.first, range.second, predicate);
    }
};
bool isZero(int value)
{
    return value == 0;
}
bool isOne(int value)
{
    return value == 1;
}
bool isGreaterThan1(int value)
{
    return 1 < value;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Vector<int> v = Vector<int>(n);
        int zeros = v.countIf(isZero), ones = v.countIf(isOne), greaterThan1 = v.countIf(isGreaterThan1);
        int ans = (zeros <= ceil(n / 2.0) ? 0 : (ones == 0 || greaterThan1 > 0) ? 1
                                                                                : 2);
        cout << ans << endl;
    }
    return 0;
}