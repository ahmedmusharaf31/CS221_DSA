#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    Graph(int V) : numVertices(V)
    {
        adjLists.resize(V + 1); // Adjust size for 1-based indexing
    }

    void addEdge(int u, int v)
    {
        adjLists[u].push_back(v);
        adjLists[v].push_back(u); // Since it's undirected
    }

    void printGraph()
    {
        for (int i = 1; i <= numVertices; ++i)
        { // Start from 1 for 1-based indexing
            cout << "Vertex " << i << ": Connected to vertices ";
            for (auto j : adjLists[i])
            {
                cout << j << " -> ";
            }
            cout << endl;
        }
    }

private:
    int numVertices;
    vector<vector<int>> adjLists;
};

int main()
{
    Graph g(5); // 5 vertices (1-5)

    g.addEdge(1, 2); // connects vertex 1 and 2
    g.addEdge(1, 3); // connects vertex 1 and 3
    g.addEdge(1, 4); // connects vertex 1 and 4
    g.addEdge(2, 3); // connects vertex 2 and 3
    g.addEdge(2, 5); // connects vertex 2 and 5

    g.printGraph();
    
    return 0;
}
