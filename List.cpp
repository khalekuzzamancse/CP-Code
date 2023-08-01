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
        bool isOutOfBound = position < 0 || position > this->size();
        if (isOutOfBound)
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

        if (position < 0 || position >= this->size())
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
    int find(std::function<bool(const T &)> predicate)
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
        bool isFound = find(value) != -1;
        return !isFound;
    }

    int count(const T &value)
    {
        return ::count(this->data.begin(), this->data.end(), value);
    }
    int count(std::function<bool(const T &)> predicate)
    {
        return ::count_if(this->data.begin(), this->data.end(), predicate);
    }
    // Minimum and maximum values
    pair<T, int> min()
    {
        auto it = std::min_element(this->data.begin(), this->data.end());
        int pos = std::distance(this->data.begin(), it);
        return make_pair(*it, pos);
    }
    pair<T, int> max()
    {
        auto it = std::max_element(this->data.begin(), this->data.end());
        int pos = std::distance(this->data.begin(), it);
        return make_pair(*it, pos);
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

    // getter methods
    T get(size_t pos) const
    {

        if (pos < 0 || pos >= this->data.size())
        {
            throw std::out_of_range("Invalid position");
        }
        auto it = this->data.begin();
        std::advance(it, pos);
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
    void sort()
    {
        this->data.sort();
    }

    void sort(std::function<bool(const T &, const T &)> comparator)
    {
        this->data.sort(comparator);
    }
    //
    void reverse()
    {
        this->data.reverse();
    }
};

int main()
{
    List<int> l = List<int>(5);
    l.toString();
    // l.insertAt(3, 2);
    // l.toString();
    //  l.sort();
    //  l.toString();
    //  l.sort([](const int &a, const int &b) -> bool
    //         { return a > b; });
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
    // cout << l.find([](int x)
    //                { return x % 3 == 0; });
    // cout << l.doesExits(-3) << endl;
    // cout << l.count(2) << endl;
    // cout << l.count([](int x)
    //                 { return x % 2 == 0; })
    //      << endl;
    // cout << l.min().first << " " << l.min().second << endl;
    //  cout << l.max().first << " " << l.max().second << endl;
    // cout<<l.get(3)<<endl;
}