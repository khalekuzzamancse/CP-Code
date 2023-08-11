#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;
template <typename T>
class Vector
{
private:
    const static int INVALID_INDEX = -1;

private:
    std::vector<T> elements;
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
        auto it_start = elements.begin();
        auto it_end = elements.begin();
        std::advance(it_start, start), std::advance(it_end, end + 1);
        return std::make_pair(it_start, it_end);
    }

public:
    Vector() = default;
    Vector(const std::vector<T> &v) : elements(v) {}
    Vector(std::vector<T> &&v) : elements(std::move(v)) {}
    Vector(int inputSize)
    {
        while (inputSize--)
        {
            T x;
            cin >> x;
            pushBack(x);
        }
    }

    // adding elements
    void pushBack(const T &value)
    {
        elements.push_back(value);
    }
    void pushFront(const T &value)
    {
        elements.insert(elements.begin(), value);
    }
    void insertAt(T value, size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = elements.begin();
        advance(it, position);
        elements.insert(it, value);
    }

    // Removing elements
    //  removing elements
    void removeFirst()
    {
        if (isNotEmpty())
            this->elements.erase(this->elements.begin());
    }
    void removeLast()
    {
        if (isNotEmpty())
            this->elements.pop_back();
    }
    void removeAt(size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = this->elements.begin();
        advance(it, position);
        this->elements.erase(it);
    }
    void remove(const T &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->elements.erase(std::remove(range.first, range.second, value), range.second);
    }
    void removeIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->elements.erase(std::remove_if(range.first, range.second, predicate), range.second);
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
        this->elements.erase(std::remove_if(range.first, range.second, is_duplicate), range.second);
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

    // Minimum and maximum values
    // These methods have default paramter implementations

    pair<T, int> max(int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it_max = std::max_element(range.first, range.second);
        int pos = std::distance(this->elements.begin(), it_max);
        return make_pair(*it_max, pos);
    }

    pair<T, int> min(int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it_min = std::min_element(range.first, range.second);
        int pos = std::distance(this->elements.begin(), it_min);
        return make_pair(*it_min, pos);
    }
    // ForEachIndexed
    void forEach(std::function<void(size_t, const T &)> func, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        size_t i = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            func(i, *it);
            i++;
        }
    }
    void forEachReverse(std::function<void(size_t, const T &)> func, int end = -1, int start = 0)
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

    // map
    Vector<T> map(std::function<T(T)> transformFunction) const
    {
        vector<T> result;
        for (const T &element : elements)
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

    size_t getLastIndex()
    {
        return this->elements.size() - 1;
    }

    // Empty or Not
    bool isEmpty()
    {
        return this->elements.empty();
    }
    bool isNotEmpty()
    {
        return !isEmpty();
    }

    // Getters
    T get(size_t position)
    {
        if (isOutOfBound(position))
            throw std::out_of_range("Invalid Position");
        return elements[position];
    }
    vector<T> get()
    {
        return elements;
    }
    T getFirst()
    {
        return elements[0];
    }
    T getLast()
    {
        return elements[size() - 1];
    }

    int size()
    {
        return elements.size();
    }

    void toString(string separator = " ")
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size() - 1; i++)
            cout << elements[i] << separator;
        cout << elements[elements.size() - 1];
        cout << endl;
        return;
    }
    // sorting
    // sorting comparator
    void sort(
        int start = 0, int end = -1, std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
                                     { return a < b; })
    {
        auto range = getRange(start, end);
        std::sort(range.first, range.second, comparator);
    }
};
void printElement(const int &element)
{
    cout << element << " ";
}
int squre(const int &element)
{
    return element * element;
}
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
