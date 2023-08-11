/*
https://codeforces.com/contest/1857/problem/A

Parity means:Even or odd
let two set be a and b
a+b=sum
    if sum==even
        even+even=even
        odd+odd=even
    it has same parity
    if sum==odd
        even+odd=odd
      in this case the never the parity can be same.

*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Vector
{
private:
    std::vector<T> _elements;
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
        auto it_start = this->_elements.begin();
        auto it_end = this->_elements.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        return std::make_pair(it_start, it_end);
    }

public:
    // Constructors
    Vector()
    {
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
    bool isEmpty()
    {
        return this->_elements.empty();
    }
    bool isNotEmpty()
    {
        return !isEmpty();
    }

    // adding elements
    void pushBack(const T &value)
    {
        value.push_back(value);
    }
    void pushFront(const T &value)
    {
        this->_elements.insert(this->_elements.begin(), value);
    }

    // ForEachIndexed
    void forEach(std::function<void(size_t, const T &)> func, int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        size_t i = 0;
        for (auto it = range.first; it != range.second; ++it)
        {
            func(i, *it);
            i++;
        }
    }

    vector<T> get()
    {
        return _elements;
    }
    T getFirst()
    {
        return _elements[0];
    }
    size_t getLastIndex()
    {
        return this->_elements.size() - 1;
    }

    int size()
    {
        return _elements.size();
    }

    void toString(string separator = " ")
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size() - 1; i++)
            cout << _elements[i] << separator;
        cout << _elements[_elements.size() - 1];
        cout << endl;
        return;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Vector<int> v = Vector<int>(n);
        int sum = 0;
        v.forEach([&sum](size_t index, const int &value)
                  { sum += value; });
        bool isEven = sum % 2 == 0;
        if (isEven)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
