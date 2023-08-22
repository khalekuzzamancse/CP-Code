#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int distance;
    int parent;
    int color;
    int discoveryTime;
    int finishTime;
    std::vector<Node *> neighbors;
    Node(int k)
    {
        key = k;
    }
    Node() = default;
    void addNeighbor(int neighbor)
    {
        neighbors.push_back(new Node(neighbor));
    }
    void toString()
    {
        cout << key << " ->: ";
        for (auto node : neighbors)
            cout << node->key << " ";
        cout << endl;
    }
};

class Graph
{
    vector<Node> nodes;
    int maxNodeValue;

public:
    Graph() = default;
    Graph(int maxNodeValue, int totalEdges)
    {
        this->maxNodeValue = maxNodeValue;
        nodes.resize(maxNodeValue + 1);
        for (int i = 0; i <= maxNodeValue; i++)
            nodes[i].key = i;
        while (totalEdges--)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
    }
    void addEdge(int u, int v)
    {
        nodes[u].addNeighbor(v);
        nodes[v].addNeighbor(u);
    }

    void toString()
    {

        for (auto node : nodes)
            node.toString();
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Graph graph = Graph(n, m);
    graph.toString();
    return 0;
}