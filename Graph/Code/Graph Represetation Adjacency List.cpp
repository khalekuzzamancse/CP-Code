#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class UndirectedGraph
{
    int maxNodeValue;
    vector<list<int>> adjacencyList;

public:
    UndirectedGraph() = default;
    UndirectedGraph(int maxNodeValue, int totalEdges)
    {
        this->maxNodeValue = maxNodeValue;
        adjacencyList.resize(maxNodeValue + 1);
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
        for (int i = 1; i <= maxNodeValue; i++)
        {
            cout << i << " : ";
            for (auto it : adjacencyList[i])
                cout << it << " ";
            cout << endl;
        }
    }
};
int main()
{

    int n, m;
    cin >> n >> m;
    UndirectedGraph graph = UndirectedGraph(n, m);
    graph.toString();

    return 0;
}
