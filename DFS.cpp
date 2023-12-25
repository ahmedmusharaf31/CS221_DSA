#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Graph
{
    int v; // number of vertices

    // pointer to a vector containing adjacency lists
    vector<int> *adj;

public:
    Graph(int v); // Constructor
    // function to add an edge to graph
    void add_edge(int v, int w);
    // prints dfs traversal from a given source `s`
    void dfs();
    void dfs_util(int s, vector<bool> &visited);
};
Graph::Graph(int v)
{
    this->v = v;
    adj = new vector<int>[v];
}
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v); // add v to u’s list
    adj[v].push_back(u); // add u to v's list (remove this statement if the graph is directed!)
}
void Graph::dfs()
{
    // visited vector - to keep track of nodes visited during DFS
    vector<bool> visited(v, false); // marking all nodes/vertices as not visited
    for (int i = 0; i < v; i++)
        if (!visited[i])
            dfs_util(i, visited);
}
// notice the usage of call-by-reference here!
void Graph::dfs_util(int s, vector<bool> &visited)
{
    // mark the current node/vertex as visited
    visited[s] = true;
    // output it to the standard output (screen)
    cout << s << " ";

    // traverse its adjacency list and recursively call dfs_util for all of
    // its neighbours !
    // (only if the neighbour has not been visited yet!)
    for (vector<int>::iterator itr = adj[s].begin(); itr !=
                                                     adj[s].end();
         itr++)
        if (!visited[*itr])
            dfs_util(*itr, visited);
}
int main()
{
    // create a graph using the Graph class we defined above
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    cout << "Following is the Depth First Traversal of the provided graph"
         << "(starting from vertex 0): ";
    g.dfs();
    // output would be: 0 1 2 3
    return 0;
}
