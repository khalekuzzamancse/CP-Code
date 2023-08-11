#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Vector
{
private:
    std::vector<T> elements;
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
        auto it_start = this->elements.begin();
        auto it_end = this->elements.begin();
        std::advance(it_start, start);
        std::advance(it_end, end + 1);
        return std::make_pair(it_start, it_end);
    }

public:
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
    Vector(vector<T> &v)
    {
        this->elements = v;
    }

    void pushBack(const T &value)
    {
        value.push_back(value);
    }

    size_t getLastIndex()
    {
        return this->elements.size() - 1;
    }

    bool isEmpty()
    {
        return this->elements.empty();
    }

    vector<T> get()
    {
        return elements;
    }
    T getLast()
    {
        return elements[size() - 1];
    }

    int size()
    {
        return elements.size();
    }

    void toString(string separator = " ")
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size() - 1; i++)
            cout << elements[i] << separator;
        cout << elements[elements.size() - 1];
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
        return elements[position];
    }

    pair<T, int> max(int start = 0, int end = -1)
    {
        auto range = getRange(start, end);
        auto it_max = std::max_element(range.first, range.second);
        int pos = std::distance(this->elements.begin(), it_max);
        return make_pair(*it_max, pos);
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
        Vector<int> v1 = Vector<int>(n);
        vector<int> v2 = v1.get();
        Vector<int> v3 = Vector<int>(v2);
        v3.sort();

        int pos = -1;
        for (int i = v1.size() - 1; i >= 0; i--)
        {
            if (v1.get(i) != v3.get(i))
            {
                pos = i;
                break;
            }
        }
        int mx = pos == -1 ? 0 : v1.max(0, pos).first;
        cout << mx << endl;
    }
    return 0;
}