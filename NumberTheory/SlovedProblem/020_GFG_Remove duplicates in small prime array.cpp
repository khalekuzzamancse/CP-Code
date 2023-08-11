/*
Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1?page=1&difficulty[]=0&category[]=Prime%20Number&category[]=number-theory&sortBy=submissions

Given an array consisting of only prime numbers,
 remove all duplicate numbers from it.
 Solution:
 paste the code from Vector class and use it.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

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
    // Constructors
    Vector()
    {
    }
    Vector(vector<T> &v)
    {
        this->elements = v;
    }

    void removeDuplicate(int start = 0, int end = -1)
    {
        // Complexity: O(N)
        auto range = getRange(start, end);
        std::unordered_set<T> s;
        auto is_duplicate = [&s](T x)
        {
            return !s.insert(x).second;
        };
        this->elements.erase(std::remove_if(range.first, range.second, is_duplicate), range.second);
    }
    vector<T> get()
    {
        return elements;
    }
    size_t getLastIndex()
    {
        return this->elements.size() - 1;
    }
};

class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        Vector<int> v = Vector<int>(arr);
        v.removeDuplicate();
        return v.get();
    }
};
