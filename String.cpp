#include <bits/stdc++.h>
using namespace std;

class String
{
private:
    string data;

public:
    String(const string &data)
    {
        this->data = data;
    }
    void set(const string &data)
    {
        this->data = data;
    }
    void toString(string separator = "")
    {
        if (data.empty())
            return;
        for (auto element : data)
            cout << element << separator;
        cout << endl;
    }
    String filter(std::function<bool(const char &)> predicate) const
    {
        string result;
        for (const char &element : data)
            if (predicate(element))
                result.push_back(element);
        return String(result);
    }
    String filterIndexed(std::function<bool(const char &, size_t)> predicate) const
    {
        std::string result;
        size_t index = 0;
        for (const char &element : data)
        {
            if (predicate(element, index))
            {
                result.push_back(element);
            }
            index++;
        }
        return String(result);
    }
    char getFirst()
    {
        return this->data[0];
    }
    char getLast()
    {
        return this->data[this->data.size() - 1];
    }
    string getData()
    {
        return this->data;
    }
    bool isPresent(char ch)
    {
        return this->data.find(ch) != std::string::npos;
    }

    void removeFirst()
    {
        if (!this->data.empty())
            this->data.erase(0, 1);
    }

    void removeLast()
    {
        if (!this->data.empty())
            this->data.pop_back();
    }
    int size()
    {
        return this->data.size();
    }
    char get(size_t index)
    {
        return this->data[index];
    }
};
int main()
{
    string s = "abacde";
    String str = String(s);
    // str.filter([](const char &ch)
    //            { return (ch == 'a') || (ch == 'e'); })
    //     .toString(",");

    // str.filterIndexed([](const char &ch, size_t index)
    //                   { return (ch == 'a' && index % 2 == 0); })
    //     .toString(",");
    // str.filterIndexed([](const char &ch, size_t index)
    //                   { return (index % 2 == 0); })
    //     .toString("");
    // cout << str.getFirst() << str.getLast() << endl;
    // str.removeFirst();
    // str.removeLast();
    // str.toString();
    // str.removeFirst();
    // str.removeLast();
    // str.toString();
    // str.removeFirst();
    // str.removeLast();
    // str.toString();
    // str.removeFirst();
    // str.removeLast();
    // str.toString();

    return 0;
}