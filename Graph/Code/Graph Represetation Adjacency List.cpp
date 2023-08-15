#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class UndirectedGraph
{
    const int MX = 1e5 + 1;
    vector<list<int>> adjacencyList;

public:
    UndirectedGraph() = default;
    UndirectedGraph(int totalEdges)
    {
        while (totalEdges--)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void toString()
    {
        for (int i = 1; i <= MX; i++)
        {
            cout << "Adjacency List of " << i << ":";
            for (auto it : adjacencyList[i])
                cout << it << " ";
            cout << endl;
        }
    }
};
int main()
{

    return 0;
}
