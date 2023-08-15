#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
class Edge
{
public:
    int u, v, weight;
    Edge(int u, int v, int weight = 1)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
    void toString()
    {
        cout<<u<<"--"<<v<<" = "<<weight<<endl;
    }
};

class UndirectedGraph
{
    int maxNodeValue;
    vector<list<Edge>> adjacencyList;

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
        adjacencyList[u].push_back(Edge(u, v));
        adjacencyList[v].push_back(Edge(u, v));
    }

    void toString()
    {
        for (int node = 1; node <= maxNodeValue; node++)
        {
            cout << node << " : "<<endl;
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
