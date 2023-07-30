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
    void pushBack(const T &value)
    {
        this->data.push_back(value);
    }
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
};

int main()
{
    List<char> l = List<char>(5);
    l.toString();
    cout << l.getFirst() << " " << l.getLast() << endl;
    l.removeFirst();
    l.removeLast();
    l.toString();
    l.removeFirst();
    l.removeLast();
    l.toString();
    l.removeFirst();
    l.removeLast();
    cout << l.size() << endl;
    l.toString();
}