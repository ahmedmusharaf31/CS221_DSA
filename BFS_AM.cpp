#include <iostream>
#include <queue>

using namespace std;

class Graph
{
public:
    int V;
    int **adj;

    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;

    // Allocate memory for the adjacency list
    adj = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        adj[i] = new int[V];
    }

    // Initialize the list with zeros
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(int v, int w)
{
    // Add an edge by setting the corresponding matrix entries to 1
    adj[v][w] = 1;
    adj[w][v] = 1;
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (int i = 0; i < V; ++i)
        {
            if (adj[s][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    Graph g(10);

    g.addEdge(2, 8);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(8, 0);
    g.addEdge(8, 9);
    g.addEdge(1, 3);
    g.addEdge(1, 7);
    g.addEdge(1, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(7, 6);
    g.addEdge(5, 6);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
