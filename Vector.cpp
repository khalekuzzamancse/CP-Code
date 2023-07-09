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

public:
    Vector() {}

    void pushBack(const T &value)
    {
        data.push_back(value);
    }

//hello
    void popBack()
    {
        if (!data.empty())
        {
            data.pop_back();
        }
    }

    T valueAt(size_t index)
    {
        return data[index];
    }

    size_t size() const
    {
        return data.size();
    }

    bool empty() const
    {
        return data.empty();
    }

    void printDataOnSingleLine() const
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    // This is mutable
    void forEach(std::function<void(T &)> func)
    {
        for (T &element : data)
        {
            func(element);
        }
    }
    // this is immutable
    //okay
    void forEach(std::function<void(const T &)> func) const
    {
        for (const T &element : data)
        {
            func(element);
        }
    }
    void forEachIndexed(std::function<void(size_t, const T &)> func) const
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            func(i, data[i]);
        }
    }

    template <typename UnaryOp>
    Vector<T> map(UnaryOp op) const
    {
        Vector<T> result;
        result.data.resize(data.size());

        std::transform(data.begin(), data.end(), result.data.begin(), op);

        return result;
    }
};
void printElement(const int &element)
{
    cout << element << " ";
}
int main()
{
    Vector<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    v.forEach([](const int &element) {});
    v.forEach(printElement);
    v.forEach([](int &element)
              { cout << "Hello" << endl; });

    v.forEachIndexed([](size_t index, const int &value)
                     { std::cout << "Index: " << index << ", Value: " << value << std::endl; });

    auto squaredVector = v
                             .map([](const int &x)
                                  { return x * x; })
                             .map([](const int &x)
                                  { return x * 2; })
                             .map([](const int &x)
                                  { return x * 3; });

    squaredVector.printDataOnSingleLine(); // Prints: 1 4 9

    return 0;
}
