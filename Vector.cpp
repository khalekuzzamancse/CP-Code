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
    void set(vector<T> &v)
    {
        this->data = v;
    }
    void pushBack(const T &value)
    {
        data.push_back(value);
    }

    void popBack()
    {
        if (!data.empty())
            data.pop_back();
    }

    T get(size_t index)
    {
        return data[index];
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

    bool isEmpty() const
    {
        return data.empty();
    }

    // This is mutable
    void forEach(std::function<void(T &)> func)
    {
        for (T &element : data)
            func(element);
    }

    void forEachIndexed(std::function<void(size_t, const T &)> func) const
    {
        for (size_t i = 0; i < data.size(); i++)
            func(i, data[i]);
    }

    Vector<T> map(std::function<T(T)> transformFunction) const
    {
        Vector<T> result;
        result.data.resize(data.size());
        std::transform(data.begin(), data.end(), result.data.begin(), transformFunction);
        return result;
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
    void sort()
    {
        std::sort(data.begin(), data.end());
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
