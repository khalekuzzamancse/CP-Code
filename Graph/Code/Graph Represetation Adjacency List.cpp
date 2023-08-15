#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
/*

 void removeNeighbor(const Node<T> &value)
    {
        adjutants.remove(value);
    }
    int degree()
    {
        return adjutants.size();
    }
    bool containsNeighbor(const Node<T> &value)
    {
        return std::find(adjutants.begin(), adjutants.end(), value) != adjutants.end();
    }
    bool isAdjacentEmpty()
    {
        return adjutants.empty();
    }
    std::list<T> getAdjacencyList()
    {
        return adjutants;
    }
  Node &operator=(const Node<T> &other)
    {
        if (this != &other)
        {
            data = other.data;
            adjutants = other.adjutants;
        }
        return *this;
    }
    bool operator==(const Node<T> &other) const
    {
        return data == other.data && adjutants == other.adjutants;
    }

    bool operator!=(const Node<T> &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Node<T> &other) const
    {
        return data < other.data;
    }

    bool operator>(const Node<T> &other) const
    {
        return data > other.data;
    }

*/
template <typename T>
class Node
{
private:
    T _value;
    std::list<Node *> adjutants;

public:
    Node(T value) : _value(value) {}
    Node() = default;

public:
    void addNeighbor(Node<T> *value)
    {
        adjutants.push_back(value);
    }

    T data()
    {
        return _value;
    }

public: //
    void toString(string separator = " ")
    {
        cout << _value << " : ";
        for (auto it : adjutants)
            cout << it->data() << separator;
        cout << "\n";
    }
};
int main()
{
    Node<int> node;
    node = Node<int>(10);
    node.addNeighbor(new Node<int>(5));
    node.addNeighbor(new Node<int>(7));
    node.toString();

    return 0;
}
