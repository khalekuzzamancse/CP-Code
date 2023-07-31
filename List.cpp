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
    // constructor
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

    // ForEachIndexed
    //  This is mutable
    void forEach(std::function<void(T &)> func)
    {
        for (T &element : data)
            func(element);
    }

    void forEachIndexed(std::function<void(size_t, const T &)> func) const
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
    List<T> filter(std::function<bool(const T &)> predicate) const
    {
        list<T> result;
        for (const T &element : data)
            if (predicate(element))
                result.insert(result.end(), element);
        return List(result);
    }
    List<T> filterIndexed(std::function<bool(size_t, const T &)> predicate) const
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

    //
    bool isEmpty() const
    {
        return data.empty();
    }
    bool isNotEmpty() const
    {
        return !data.empty();
    }
    T get(size_t index)
    {
        return data[index];
    }
    T getFirst()
    {
        return this->data.front();
    }
    T getLast()
    {
        return this->data.back();
    }
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
    int size()
    {
        return this->data.size();
    }
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
    // l.forEach([](const char &ch)
    //           { cout << ch << " "; });
    // l.forEachIndexed([](size_t i, const char &ch)
    //                  { cout << i << ":" << ch << endl; });

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
    // map filleter
    // l.map([](int x) -> int
    //       { return x * x; })
    //     .toString();

    // l.filter([](const int &x) -> bool
    //          { return x % 2 == 0; })
    //     .toString();
    // l.filterIndexed([](size_t i, const int &x) -> bool
    //                 { 
    //                     bool b=i>0&&x%2==0;
    //                     return b; })
    //     .toString();
}