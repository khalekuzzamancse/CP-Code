#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Set
{
private:
    set<T> data;

public:
    Set(const set<T> &data)
    {
        this->data = data;
    }

    Set()
    {
    }
    template <typename U>
    Set(const U &container)
    {
        this->data = set<T>(std::set<typename U::value_type>(container.begin(), container.end()));
    }
    void insert(T value)
    {
        this->data.insert(value);
    }

    /*
    Passing the set as reference so it takes constant time
    returing the common set as copy(not by reference) because
    returing local variable refernce is not safe,but if you get
    time limit then move the commoSet as instance variable
    */
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

    /*
    Returing a Set so that we can use chaning,but if we do need to return result
    then this method takes your time unessary so use the next overload method
    if you do not need to return value immedialy then use the constructor

    */
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

    return 0;
}
