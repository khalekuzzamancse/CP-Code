#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Set
{
private:
    set<T> data;

public:
   
    void insert(T value)
    {
        this->data.insert(value);
    }

 
    Set<T> commonSet(const Set<T> &set2) const
    {
        std::set<T> commonSet;
        std::set_intersection(data.begin(), data.end(),
                              set2.data.begin(), set2.data.end(),
                              std::inserter(commonSet, commonSet.begin()));
        return Set<T>(commonSet);
    }

    void toString(string separator)
    {
        if (isEmpty())
            return;
        for (auto element : data)
            cout << element << separator;
        cout << endl;
    }
    bool isEmpty()
    {
        return data.empty();
    }

  
    template <typename U>
    Set<T> toSet(const U &container)
    {
        return Set<T>(std::set<typename U::value_type>(container.begin(), container.end()));
    }

    Set<T> map(std::function<T(T)> transformFunction)
    {
        const std::set<T> &inputSet = this->data;
        std::set<T> newSet;
        std::transform(inputSet.begin(), inputSet.end(), std::inserter(newSet, newSet.begin()), transformFunction);
        return Set(newSet);
    }
    Set<T> filter(std::function<bool(const T &)> predicate) const
    {
        Set<T> result;
        for (const T &element : data)
            if (predicate(element))
                result.insert(element);
        return result;
    }
};
int cube(const int &element)
{
    return element * element * element;
}

int main()
{

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
    std::set<int> mySet = {1, 2, 3, 4};
    Set<int> set = Set(mySet);
    Set<int> newSet = set.map(cube).map([](int x)
                                        { return x * 2; });

    newSet.toString(" ");
    newSet.filter([](const int &element)
                  { return element % 4 == 0; })
        .toString(" ");

    return 0;
}
