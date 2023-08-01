#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
template <typename T>
class List
{
private:
    std::list<T> data;
    bool isOutOfBound(int position)
    {
        return position < 0 || position > getLastIndex();
    }

public:
    // constructors
    List()
    {
    }
    List(list<T> &data)
    {
        this->data = data;
    }
    List(int inputSize)
    {

        while (inputSize--)
        {
            T x;
            cin >> x;
            this->data.push_back(x);
        }
    }
    // adding elements
    void pushBack(const T &value)
    {
        this->data.push_back(value);
    }
    void pushFront(const T &value)
    {
        this->data.push_front(value);
    }
    void insertAt(T value, size_t position)
    {
        if (isOutOfBound(position))
            return;
        auto it = this->data.begin();
        advance(it, position);
        this->data.insert(it, value);
    }

    // removing elements
    void removeFirst()
    {
        if (isNotEmpty())
            this->data.pop_front();
    }
    void removeLast()
    {
        if (isNotEmpty())
            this->data.pop_back();
    }
    void removeAt(size_t position)
    {
        if (isOutOfBound())
            return;
        auto it = this->data.begin();
        advance(it, position);
        this->data.erase(it);
    }
    void remove(const T &value)
    {
        this->data.remove(value);
    }
    void removeIf(std::function<bool(const T &)> predicate)
    {
        this->data.remove_if(predicate);
    }

    // Diffiererent finding methods
    int find(const T &value)
    {
        auto it = std::find(this->data.begin(), this->data.end(), value);
        int pos = -1;
        bool isFound = it != this->data.end();
        if (isFound)
            pos = std::distance(this->data.begin(), it);
        return pos;
    }
    int findIf(std::function<bool(const T &)> predicate)
    {
        auto it = std::find_if(this->data.begin(), this->data.end(), predicate);
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
        if (end == -1)
            end = getLastIndex();
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        return ::count(it_start, it_end, value);
    }
    int countIf(std::function<bool(const T &)> predicate, int start = 0, int end = -1)
    {
        if (end == -1)
            end = getLastIndex();
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        return ::count_if(it_start, it_end, predicate);
    }

    // Minimum and maximum values
    // These methods have default paramter implementations

    pair<T, int> max(int start = 0, int end = -1)
    {
        if (end == -1)
            end = getLastIndex();
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        auto it_max = std::max_element(it_start, it_end);
        int pos = std::distance(this->data.begin(), it_max);
        return make_pair(*it_max, pos);
    }

    pair<T, int> min(int start = 0, int end = -1)
    {
        if (end == -1)
            end = getLastIndex();
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        auto it_min = std::min_element(it_start, it_end);
        int pos = std::distance(this->data.begin(), it_min);
        return make_pair(*it_min, pos);
    }

    //////////////////////////
    // ForEachIndexed

    void forEach(std::function<void(size_t, const T &)> func) const
    {
        size_t i = 0;
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            func(i, *it);
            i++;
        }
    }
    // map
    List<T> map(std::function<T(T)> transformFunction) const
    {
        list<T> result;
        for (const T &element : data)
            result.insert(result.end(), transformFunction(element));
        return List(result);
    }

    // Filter methods
    List<T> filter(std::function<bool(size_t, const T &)> predicate) const
    {
        list<T> result;
        size_t i = 0;
        for (const T &element : data)
        {
            if (predicate(i, element))
                result.insert(result.end(), element);
            i++;
        }
        return List(result);
    }

    // Empty or Not
    bool isEmpty() const
    {
        return this->data.empty();
    }
    bool isNotEmpty() const
    {
        return !isEmpty();
    }
    size_t getLastIndex()
    {
        return this->data.size() - 1;
    }

    // getter methods
    T get(size_t position)
    {
        if (isOutOfBound(position))
            throw std::out_of_range("Invalid range");
        auto it = this->data.begin();
        std::advance(it, position);
        return *it;
    }
    T getFirst()
    {
        return this->data.front();
    }
    T getLast()
    {
        return this->data.back();
    }

    int size()
    {
        return this->data.size();
    }
    // toString method
    void toString(const std::string &separator = " ")
    {
        if (data.empty())
            return;
        for (auto element : data)
            std::cout << element << separator;
        std::cout << std::endl;
    }
    // sorting
    // sorting comparator
    // Sort only a range using stl is not possible
    // because list has no random access on it elements
    void sort(std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
              { return a < b; })
    {
        this->data.sort(comparator);
    }

    //
    void reverse(int start = 0, int end = -1)
    {
        if (end == -1)
            end = getLastIndex();
        if (isOutOfBound(start) || isOutOfBound(end) || start > end)
            throw std::out_of_range("Invalid range");
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        std::reverse(it_start, it_end);
    }
};

int main()
{
    List<int> l = List<int>(5);
    // l.toString();
    // l.insertAt(10, 2);
    // l.toString();
    //  l.sort();
    //  l.toString();
    // l.sort([](const int &a, const int &b) -> bool
    //        { return a > b; });
    // l.toString();

    // l.forEach([](size_t i, const int &x)
    //           { cout << x << " "; });
    // l.forEach([](size_t i, const int &x)
    //                  { cout << i << ":" << x << endl; });

    //  l.toString();

    // cout << l.getFirst() << " " << l.getLast() << endl;
    // l.removeFirst();
    // l.removeLast();
    // l.toString();
    // l.removeFirst();
    // l.removeLast();
    // l.toString();
    // l.removeFirst();
    // l.removeLast();
    // cout << l.size() << endl;
    // l.toString();
    // // map filleter
    // l.map([](int x) -> int
    //       { return x * x; })
    //     .toString();

    // l.filter([](size_t index, const int &x) -> bool
    //          { return x % 2 == 0; })
    //     .toString();
    // l.filter([](size_t i, const int &x) -> bool
    //                 {
    //                     bool b=i>0&&x%2==0;
    //                     return b; })
    //     .toString();

    // cout << l.find(3) << endl;
    //  cout << l.findIf([](int x)
    //                 { return x % 3 == 0; });
    // cout << l.doesExits(3) << endl;
    // cout << l.count(2) << endl;
    // cout << l.count(2, 2, 4) << endl;
    // cout << l.countIf([](int x)
    //                   { return x % 2 == 1; })
    //      << endl;
    // cout << l.countIf([](int x)
    //                   { return x % 2 == 0; },
    //                   0, 2)
    //      << endl;

    // cout << l.get(3) << endl;
    //  cout << l.max().first << " " << l.max().second;
    // cout << l.min(0, 4).first << " " << l.min(0, 4).second << endl;
    //  cout << l.max(1, 2).first << " " << endl;
    // l.reverse();
    // l.toString();
    // l.reverse(3, 4);
    // l.toString();
}