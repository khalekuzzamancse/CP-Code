#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
private:
    std::vector<T> data;
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
        auto it_start = this->data.begin();
        auto it_end = this->data.begin();
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

    void pushBack(const T &value)
    {
        data.push_back(value);
    }

    size_t getLastIndex()
    {
        return this->data.size() - 1;
    }

    bool isEmpty()
    {
        return this->data.empty();
    }

    vector<T> get()
    {
        return data;
    }
    T getLast()
    {
        return data[size() - 1];
    }

    int size()
    {
        return data.size();
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

    void sort(
        int start = 0, int end = -1, std::function<bool(const T &, const T &)> comparator = [](const T &a, const T &b)
                                     { return a < b; })
    {
        auto range = getRange(start, end);
        std::sort(range.first, range.second, comparator);
    }

    T get(size_t position)
    {
        if (isOutOfBound(position))
            throw std::out_of_range("Invalid Position");
        return data[position];
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
        int x = n * (n - 1) / 2;
        Vector<long long> b = Vector<long long>(x);
        b.sort();
        int start = 0;
        Vector<long long> a = Vector<long long>();
        for (int i = 1; i <= n - 1; i++)
        {
            int rangeLength = n - i;
            int end = start + rangeLength;
            int _start = start + 1;
            a.pushBack(b.get(_start - 1));
            start = start + rangeLength;
        }
        a.pushBack(b.getLast());
        a.toString();
    }
    return 0;
}