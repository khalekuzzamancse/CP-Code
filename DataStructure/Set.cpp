#include <iostream>
#include <functional>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
class Set
{
private:
    set<T> _elements;

public:
    Set() = default;
    Set(set<T> &s)
    {
        _elements = s;
    }
    Set(size_t size)
    {
        while (size--)
        {
            T x;
            cin >> x;
            _elements.insert(x);
        }
    }

public: // operator overloads
    bool operator==(const Set<T> &other) const
    {
        return _elements == other._elements;
    }

    bool operator!=(const Set<T> &other) const
    {
        return !(*this == other);
    }
    Set(std::initializer_list<T> initList)
    {
        for (const T &value : initList)
        {
            insert(value);
        }
    }

public:
    void insert(T value)
    {
        this->_elements.insert(value);
    }

    Set<T> getCommonWith(const Set<T> &set2) const
    {
        std::set<T> commonSet;
        std::set_intersection(_elements.begin(), _elements.end(),
                              set2._elements.begin(), set2._elements.end(),
                              std::inserter(commonSet, commonSet.begin()));
        return Set<T>(commonSet);
    }

    void toString(string separator = " ")
    {
        if (_elements.empty())
            return;
        for (auto element : _elements)
            cout << element << separator;
        cout << endl;
    }
    bool isEmpty()
    {
        return _elements.empty();
    }

    template <typename U>
    Set<T> toSet(const U &container)
    {
        return Set<T>(std::set<typename U::value_type>(container.begin(), container.end()));
    }

    Set<T> map(std::function<T(T)> transformFunction)
    {
        const std::set<T> &inputSet = this->_elements;
        std::set<T> newSet;
        std::transform(inputSet.begin(), inputSet.end(), std::inserter(newSet, newSet.begin()), transformFunction);
        return Set(newSet);
    }
    Set<T> filter(std::function<bool(const T &)> predicate) const
    {
        Set<T> result;
        for (const T &element : _elements)
            if (predicate(element))
                result.insert(element);
        return result;
    }
};

int main()
{

    Set<int> s;
    s.insert(2);
    s.insert(3);
    Set<int> s2(s);
    s.toString();
    s2.toString();
    cout << (s == s2) << endl;
    Set<int> s3 = {1, 2, 3, 4, 5};
    s3.toString();
  

    // string input;
    // cin >> input;
    // Set<char> evenIndexSet;
    // Set<char> oddIndexSet;

    // for (size_t i = 0; i < input.length(); i++)
    // {
    //     if (i % 2 == 0)
    //         evenIndexSet.insert(input[i]);
    //     else
    //         oddIndexSet.insert(input[i]);
    // }
    // evenIndexSet.toString("");
    // evenIndexSet.commonSet(oddIndexSet).toString("");
    // std::set<int> mySet = {1, 2, 3, 4};
    // Set<int> set = Set(mySet);
    // Set<int> newSet = set.map(cube).map([](int x)
    //                                     { return x * 2; });

    // newSet.toString(" ");
    // newSet.filter([](const int &element)
    //               { return element % 4 == 0; })
    //     .toString(" ");

    return 0;
}
