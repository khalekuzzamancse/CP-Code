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

    // Adding elements
public:
    void pushBack(const T &value)
    {
        _elements.push_back(value);
    }
    size_t getLastIndex()
    {
        return this->_elements.size() - 1;
    }

    // Minimum and maximum values
    // These methods have default paramter implementations

    pair<T, int> max(int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        auto it_max = std::max_element(range.first, range.second);
        int pos = std::distance(_elements.begin(), it_max);
        return make_pair(*it_max, pos);
    }

    void forEachReverse(std::function<void(size_t index, const T &value, bool &stop)> callback, size_t step = 1, int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        std::size_t index = size() - 1;
        bool stop = false;
        for (auto it = std::reverse_iterator(range.second); it != std::reverse_iterator(range.first); it = it + step)
        {
            callback(index, *it, stop);
            if (stop)
                break;
            index = index - step;
        }
    }

    // Empty or Not
    bool isEmpty()
    {
        return this->_elements.empty();
    }

    vector<T> get()
    {
        return _elements;
    }

    int size()
    {
        return _elements.size();
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

    void sort(
        int start = 0, int end = INVALID_INDEX, std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
                                                { return a < b; })
    {
        auto range = getRange(start, end);
        std::sort(range.first, range.second, comparator);
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
        Vector<int> v1 = Vector<int>(n);
        Vector<int> v2 = Vector<int>(v1.get());
        v2.sort();

        int pos = -1;
        v1.forEachReverse([&pos,&v1,&v2](size_t i,int value,bool &stop) {
             if (v1[i] != v2[i])
                pos = i, stop = true;
        });
        int mx = pos == -1 ? 0 : v1.max(0, pos).first;
        cout << mx << endl;
    }
    return 0;
}