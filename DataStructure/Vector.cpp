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
    void pushFront(const T &value)
    {
        _elements.insert(_elements.begin(), value);
    }
    void insertAt(T value, size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = _elements.begin();
        advance(it, position);
        _elements.insert(it, value);
    }

    // Removing elements
    //  removing elements
public:
    void removeFirst()
    {
        if (isNotEmpty())
            this->_elements.erase(this->_elements.begin());
    }
    void removeLast()
    {
        if (isNotEmpty())
            this->_elements.pop_back();
    }
    void removeAt(size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = this->_elements.begin();
        advance(it, position);
        this->_elements.erase(it);
    }
    void remove(const T &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->_elements.erase(std::remove(range.first, range.second, value), range.second);
    }
    void removeIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->_elements.erase(std::remove_if(range.first, range.second, predicate), range.second);
    }
    void removeDuplicate(int start = 0, int end = -1)
    {
        // Complexity: O(N)
        auto range = getRange(start, end);
        std::unordered_set<T> s;
        auto is_duplicate = [&s](T x)
        {
            return !s.insert(x).second;
        };
        this->_elements.erase(std::remove_if(range.first, range.second, is_duplicate), range.second);
    }
    // Diffiererent finding methods
    int find(const T &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find(range.first, range.second, value);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }
    int findReseverse(const T &value, int start = 0, int end = -1)
    {
        std::pair<typename std::string::iterator,
                  typename std::string::iterator>
            range = getRange(start, end);
        auto it = std::find(std::make_reverse_iterator(range.second), std::make_reverse_iterator(range.first), value);
        int pos = -1;
        bool isFound = it != std::make_reverse_iterator(range.first);
        if (isFound)
            pos = std::distance(range.first, it.base()) - 1 + start;
        return pos;
    }
    int findIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find_if(range.first, range.second, predicate);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }
    int findIfReseverse(std::function<bool(const char &)> predicate, int start = 0, int end = -1)
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

    bool doesExits(const T &value)
    {
        bool isFound = find(value) != -1;
        return isFound;
    }
    bool doesNotExits(const T &value)
    {

        return !doesExits(value);
    }

    int count(const T &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        return ::count(range.first, range.second, value);
    }
    int countIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        return ::count_if(range.first, range.second, predicate);
    }

    //--------------Different methods for finding minimum element-----.

    // ------------- 1st Minimum element ------------------
    pair<T, int> min(int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        auto it_min = std::min_element(range.first, range.second);
        int pos = std::distance(_elements.begin(), it_min);
        return make_pair(*it_min, pos);
    }
    // ------------- 2nd Minimum element ------------------
    pair<T, int> secondMin(int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        T firstMin = *range.first, secondMin = *range.first;
        int firstMinPos = 0, secondMinPos = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (*it < firstMin)
                secondMin = firstMin, secondMinPos = firstMinPos, firstMin = *it,
                firstMinPos = std::distance(range.first, it);
            else if (*it < secondMin && *it != firstMin)
                secondMin = *it, secondMinPos = std::distance(range.first, it);
        }
        return make_pair(secondMin, secondMinPos);
    }

    //...........Different methods for finding MAX element..........
    //...................1st MAX MAX MAX MAX....

    pair<T, int> max(int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        auto it_max = std::max_element(range.first, range.second);
        int pos = std::distance(_elements.begin(), it_max);
        return make_pair(*it_max, pos);
    }
    //...................2nd 2nd MAX MAX MAX MAX....
    pair<T, int> secondMax(int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        T firstMax = *range.first, secondMax = std::numeric_limits<T>::lowest();
        int firstMaxPos = 0, secondMaxPos = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (*it > firstMax)
                secondMax = firstMax, secondMaxPos = firstMaxPos, firstMax = *it,
                firstMaxPos = std::distance(range.first, it);
            else if (*it > secondMax && *it != firstMax)
                secondMax = *it, secondMaxPos = std::distance(range.first, it);
        }
        return make_pair(secondMax, secondMaxPos);
    }


    // -------------END!!----------

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

    // map
    Vector<T> map(std::function<T(T)> transformFunction) const
    {
        vector<T> result;
        for (const T &element : _elements)
            result.insert(result.end(), transformFunction(element));
        return Vector(result);
    }

    // Filter methods
    Vector<T> filter(std::function<bool(size_t, const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        vector<T> result;

        size_t i = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (predicate(i, *it))
                result.insert(result.end(), *it);
            i++;
        }
        return Vector(result);
    }
    //

    vector<T> get()
    {
        return _elements;
    }
    T getFirst()
    {
        if (isEmpty())
            throw std::out_of_range("Vector is empty");
        return _elements[0];
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

    Vector<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    v.pushFront(10);
    v.pushFront(20);
    v.insertAt(10, 4);
    v.toString();
    cout << v.secondMax(2, 5).first << endl;
    // v.forEachReverse([](size_t i, int value, bool &stop)
    //                  { cout << i << ":" << value << endl; });
    // v.forEach([](size_t i, int value, bool &stop)
    //           { cout << i << ":" << value << endl; });

    // v.removeFirst();
    // v.removeLast();
    // v.removeAt(2);
    // v.remove(10);
    //  v.remove(10, 0, 3);
    //  v.removeIf([](int x)
    //            { return x % 2 == 0; });
    // v.removeIf([](int x)
    //            { return x % 2 == 0; },
    //            0, 2);

    // v.removeDuplicate(1,5);
    // v.toString();

    // Vector<int> v2 = Vector<int>(v);
    // v.toString();
    // Vector<int> v3 = Vector<int>(3);
    // v3.toString();

    // cout << v.getFirst() << endl;
    // cout << v.getLast() << endl;

    // v.forEach([](size_t index, const int &value)
    //           { std::cout << "Index: " << index << "Value: "
    //                       << value << std::endl; });
    //   v.forEachReverse([](size_t index, const int &value)
    //           { std::cout << "Index: " << index << "Value: "
    //                       << value << std::endl; });

    // v.map([](const int &x)
    //       { return x * x; })
    //     .map([](const int &x)
    //          { return x * 2; })
    //     .map([](const int &x)
    //          { return x * 3; }).toString();

    // auto squaredVector = v.map(squre);

    // Filter example
    // v.filter([](size_t index, const int &x) -> bool
    //          { return x % 2 == 0; })
    //     .toString();
    // v.filter([](size_t i, const int &x)
    //          {
    //                     bool b=i>0&&x%2==0;
    //                     return b; })
    //     .toString();

    return 0;
}
