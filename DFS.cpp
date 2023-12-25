#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<list<int>> adjLists;
    vector<bool> visited;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int vertex);
};

Graph::Graph(int V) : vertices(V), adjLists(V), visited(V, false) {}

void Graph::addEdge(int v, int w)
{
    adjLists[v].push_back(w);
    adjLists[w].push_back(v); // Assuming an undirected graph
}

void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjLists[vertex].begin(); i != adjLists[vertex].end(); ++i)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "Depth-First Search (DFS): ";
    g.DFS(0); // Starting DFS from vertex 0

    return 0;
}
