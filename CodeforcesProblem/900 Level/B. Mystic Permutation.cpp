/*
https://codeforces.com/problemset/problem/1689/B
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
        if (!_elements.empty())
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
    int findIf(std::function<bool(const T &)> predicate, int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        auto it = std::find_if(range.first, range.second, predicate);
        int pos = -1;
        bool isFound = it != range.second;
        if (isFound)
            pos = std::distance(range.first, it) + start;
        return pos;
    }
    int findIfReseverse(std::function<bool(const char &)> predicate, int start = 0, int end = INVALID_INDEX)
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

    int count(const T &value, int start = 0, int end = INVALID_INDEX)
    {
        auto range = getRange(start, end);
        return ::count(range.first, range.second, value);
    }
    int countIf(std::function<bool(const T &)> predicate, int start = 0, int end = INVALID_INDEX)
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
        T firstMin = *range.first;
        T secondMin = std::numeric_limits<T>::max();
        int firstMinPos = 0;
        int secondMinPos = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (*it < firstMin)
            {
                secondMin = firstMin;
                secondMinPos = firstMinPos;
                firstMin = *it;
                firstMinPos = std::distance(range.first, it);
            }
            else if (*it < secondMin && *it != firstMin)
            {
                secondMin = *it;
                secondMinPos = std::distance(range.first, it);
            }
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

private: // finding nTh max or element O(nlogn),then O(1) for each query.
    vector<pair<T, int>> max_min;
    bool isAllMin_MAX_Calculated = false;

private:
    //..................N th MAX MIN ...
    void calculateAllMaxMin()
    {
        if (isAllMin_MAX_Calculated)
            return;
        vector<pair<T, int>> v;
        for (int i = 0; i < _elements.size(); ++i)
            v.emplace_back(_elements[i], i);
        std::sort(v.begin(), v.end());
        pair<T, int> last = v[0];
        max_min.push_back(last);
        for (int i = 1; i < v.size(); i++)
            if (v[i].first != last.first)
                max_min.push_back(v[i]), last = v[i];
        isAllMin_MAX_Calculated = true;
    }
    //..................N th MAX MIN ...
    //..................N th MAX MIN ...
public:
    pair<T, int> nThMin(int n)
    {
        calculateAllMaxMin();
        return max_min[n - 1];
    }
    pair<T, int> nThMax(int n)
    {
        calculateAllMaxMin();
        int pos = max_min.size() - n;
        return max_min[pos];
    }

    // ................END............

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
    void forEach(std::function<void(const T &value)> callback, size_t step = 1, int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        for (auto it = range.first; it != range.second; ++it)
            callback(*it);
    }
    void forEach(std::function<void(size_t index)> callback, size_t step = 1, int startIndex = 0, int endIndex = INVALID_INDEX)
    {
        auto range = getRange(startIndex, endIndex);
        size_t index = 0;
        for (auto it = range.first; it != range.second; ++it)
            callback(index), index++;
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
        if (_elements.empty())
            throw std::out_of_range("Vector is empty");
        return _elements[0];
    }
    T getLast()
    {
        if (_elements.empty())
            if (isEmpty())
                throw std::out_of_range("Vector is empty");
        return _elements[size() - 1];
    }

    void toString(string separator = " ")
    {
        if (_elements.empty())
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

    vector<pair<T, size_t>> sortWithPreserveIndex(
        std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
        { return a < b; })
    {
        vector<pair<T, size_t>> result;
        for (size_t i = 0; i < _elements.size(); ++i)
            result.push_back({_elements[i], i});
        std::sort(result.begin(), result.end(), comparator);
        return move(result);
    }
    Vector<pair<T, int>> sortWithPreserveIndex()
    {
        vector<pair<T, int>> result(_elements.size());
        for (size_t i = 0; i < _elements.size(); ++i)
            result[i] = {_elements[i], i};

        std::sort(result.begin(), result.end());
        return move(Vector<pair<T, int>>(result));
    }
    void swap(size_t i, size_t j)
    {
        T tmp = _elements[i];
        _elements[i] = _elements[j];
        _elements[j] = tmp;
    }
};

class Solution
{
private:
    Vector<int> old, sorted, ans;
    int get(int i)
    {

        int p = sorted.getLast();
        if (old[i] != p || sorted.size() == 1)
            sorted.removeLast();
        else
        {
            p = sorted[sorted.getLastIndex() - 1];
            sorted.removeAt(sorted.getLastIndex() - 1);
        }
        return p;
    }

public:
    Solution()
    {
        int n;
        cin >> n;
        old = Vector<int>(n);
    }

    void solve()
    {
        if (old.size() == 1)
        {
            cout << -1 << endl;
            return;
        }
        sorted = old;
        sorted.sort(0, -1, std::greater<int>());
        Vector<int> ans;
        for (int i = 0; i < old.size(); i++)
            ans.pushBack(get(i));
        if (old[old.size() - 1] == ans.getLast())
            ans.swap(ans.getLastIndex() - 1, ans.getLastIndex());

        ans.toString();
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