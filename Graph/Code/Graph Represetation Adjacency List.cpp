#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
class Neighbour
{
public:
    int neighbour, weight;
    Neighbour(int u, int weight)
    {
        this->neighbour = u;
        this->weight = weight;
    }
    void toString()
    {
        cout << " (" << neighbour << " , " << weight << " ) ";
    }
};

class UndirectedGraph
{
    int maxNodeValue;
    vector<list<Neighbour>> adjacencyList;

public:
    UndirectedGraph() = default;
    UndirectedGraph(int maxNodeValue, int totalEdges, bool isWeighted = false)
    {
        this->maxNodeValue = maxNodeValue;
        adjacencyList.resize(maxNodeValue + 1);
        if (isWeighted)
        {
            while (totalEdges--)
            {
                int u, v, w;
                cin >> u >> v >> w;
                addEdge(u, v, w);
            }
        }
        else
        {
            while (totalEdges--)
            {
                int u, v;
                cin >> u >> v;
                addEdge(u, v);
            }
        }
    }

    void addEdge(int u, int v, int w = 1)
    {
        adjacencyList[u].push_back(Neighbour(v, w));
        adjacencyList[v].push_back(Neighbour(u, w));
    }

    void toString()
    {
        for (int node = 1; node <= maxNodeValue; node++)
        {
            cout << node << " : ";
            list<Neighbour> neighbors = adjacencyList[node];
            for (Neighbour neighbor : neighbors)
                neighbor.toString();
            cout << endl;
        }
    }
};
int main()
{

    int n, m;
    cin >> n >> m;
    UndirectedGraph graph = UndirectedGraph(n, m, true);
    graph.toString();

    return 0;
}
