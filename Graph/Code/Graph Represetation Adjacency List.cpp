#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
class Edge
{
public:
    int u, v, weight;
    Edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
    void toString()
    {
        cout << "   " << u << "--" << v << " = " << weight << endl;
    }
};

class UndirectedGraph
{
    int maxNodeValue;
    vector<list<Edge>> adjacencyList;

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
        adjacencyList[u].push_back(Edge(u, v, w));
        adjacencyList[v].push_back(Edge(u, v, w));
    }

    void toString()
    {
        for (int node = 1; node <= maxNodeValue; node++)
        {
            cout << node << " : " << endl;
            list<Edge> neighbors = adjacencyList[node];
            for (Edge neighbor : neighbors)
                neighbor.toString();
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
