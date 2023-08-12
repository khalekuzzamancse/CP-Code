#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Vector<long long> v = Vector<long long>(n);
        long long sum = 0, _1 = 0;
        v.forEach([&sum, &_1](size_t i, long long value, bool stop) {
            sum+=value;
            if(value==1)
            _1++; 
        });
        cout << ((n > 1) && sum >= n+_1 ? "YES" : "NO") << endl;
    }

    return 0;
}