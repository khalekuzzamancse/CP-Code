#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
template <typename T>
class Vector
{
private:
    std::vector<T> data;
    bool isOutOfBound(int position)
    {
        return position < 0 || position > getLastIndex();
    }
    std::pair<typename std::vector<T>::iterator,
              typename std::vector<T>::iterator>
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
    Vector()
    {
    }
    Vector(vector<T> &v)
    {
        this->data = v;
    }
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
        data.push_back(value);
    }
    void pushFront(const T &value)
    {
        this->data.insert(this->data.begin(), value);
    }
    void insertAt(T value, size_t position)
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
    void remove(const T &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->data.erase(std::remove(range.first, range.second, value), range.second);
    }
    void removeIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        this->data.erase(std::remove_if(range.first, range.second, predicate), range.second);
    }
    // Diffiererent finding methods
    int find(const T &value, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find(range.first, range.second, value);
        int pos = -1;
        bool isFound = it != this->data.end();
        if (isFound)
            pos = std::distance(this->data.begin(), it);
        return pos;
    }
    int findIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it = std::find_if(range.first, range.second, predicate);
        int pos = -1;
        bool isFound = it != this->data.end();
        if (isFound)
            pos = std::distance(this->data.begin(), it);
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
        int pos = std::distance(this->data.begin(), it_max);
        return make_pair(*it_max, pos);
    }

    pair<T, int> min(int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it_min = std::min_element(range.first, range.second);
        int pos = std::distance(this->data.begin(), it_min);
        return make_pair(*it_min, pos);
    }
    // ForEachIndexed

    void forEach(std::function<void(size_t, const T &)> func, int start = 0, int end = -1) const
    {
        auto range = getRange(start, end);

        size_t i = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            func(i, *it);
            i++;
        }
    }
    // map
    Vector<T> map(std::function<T(T)> transformFunction) const
    {
        vector<T> result;
        for (const T &element : data)
            result.insert(result.end(), transformFunction(element));
        return Vector(result);
    }

    // Filter methods
    Vector<T> filter(std::function<bool(size_t, const T &)> predicate, int start = 0, int end = -1) const
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

    size_t getLastIndex()
    {
        return this->data.size() - 1;
    }

    // Empty or Not
    bool isEmpty()
    {
        return this->data.empty();
    }
    bool isNotEmpty()
    {
        return !isEmpty();
    }

    void set(vector<T> &v)
    {
        this->data = v;
    }

    T get(size_t position)
    {
        if (isOutOfBound(position))
            throw std::out_of_range("Invalid Position");
        return data[position];
    }
    T getFirst()
    {
        return data[0];
    }
    T getLast()
    {
        return data[size() - 1];
    }

    int size()
    {
        return data.size();
    }

    Vector<T> filter(std::function<bool(const T &)> predicate) const
    {
        Vector<T> result;
        for (const T &element : data)
            if (predicate(element))
                result.pushBack(element);
        return result;
    }

    void toString(string separator = " ")
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size() - 1; i++)
            cout << data[i] << separator;
        cout << data[data.size() - 1];
        cout << endl;
        return;
    }
    // sorting
    // sorting comparator
    void sort(std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
              { return a < b; })
    {
        this->data.sort(comparator);
    }
    void sortRange(
        int start, int end, std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
                            { return a < b; })
    {
        auto range = getRange(start, end);
        this->data.sort(range.first, range.second, comparator);
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
    // v.remove(10,0,3);
    // v.removeIf([](int x)
    //            { return x % 2 == 0; });
    // v.removeIf([](int x)
    //        { return x % 2 == 0; },0,2);

    v.toString();

    // Vector<int> v2 = Vector<int>(v);
    // v.toString();
    // Vector<int> v3 = Vector<int>(3);
    // v3.toString();

    // cout << v.getFirst() << endl;
    // cout << v.getLast() << endl;

    // v.forEach([](const int &element) {});
    // v.forEach(printElement);
    // v.forEach([](int &element)
    //           { cout << "Hello" << endl; });

    // v.forEachIndexed([](size_t index, const int &value)
    //                  { std::cout << "Index: " << index << ", Value: " << value << std::endl; });

    // auto squaredVector = v
    //                          .map([](const int &x)
    //                               { return x * x; })
    //                          .map([](const int &x)
    //                               { return x * 2; })
    //                          .map([](const int &x)
    //                               { return x * 3; });

    // auto squaredVector = v.map(squre);

    //  squaredVector.printDataOnSingleLine(); // Prints: 1 4 9

    // Filter example
    // v.filter([](const int &element){ return element % 2 == 0; })
    //  .map([](const int &x) { return x * x * x; })
    //  .toString();
    // v.toString();

    return 0;
}
