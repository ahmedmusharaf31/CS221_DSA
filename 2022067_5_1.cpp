#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
    }

    vector<int> topologicalSortStack()
    {
        stack<int> s;
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; ++i)
        {
            if (!visited[i])
            {
                topologicalSortDFS(i, visited, s);
            }
        }

        vector<int> result;
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }

    void topologicalSortDFS(int v, vector<bool> &visited, stack<int> &s)
    {
        visited[v] = true;

        for (int neighbor : adjacencyList[v])
        {
            if (!visited[neighbor])
            {
                topologicalSortDFS(neighbor, visited, s);
            }
        }

        s.push(v);
    }

    vector<int> topologicalSortQueue()
    {
        vector<int> inDegree(vertices, 0);
        queue<int> q;

        for (int i = 0; i < vertices; ++i)
        {
            for (int neighbor : adjacencyList[i])
            {
                inDegree[neighbor]++;
            }
        }

        for (int i = 0; i < vertices; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();

            result.push_back(currentVertex);

            for (int neighbor : adjacencyList[currentVertex])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};

int main()
{
    // Illustration of the graph: (directed acyclic graph)
    //  5 ---> 0 <--- 4
    //  |           / |
    //  v          /  v
    //  2 -----> 3 <--- 1

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 3);

    cout << "Topological Sort using Stack: ";
    vector<int> stackResult = g.topologicalSortStack();
    for (int vertex : stackResult)
    {
        cout << vertex << " ";
    }
    cout << endl;

    cout << "Topological Sort using Queue: ";
    vector<int> queueResult = g.topologicalSortQueue();
    for (int vertex : queueResult)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

// FIRST THEORETICAL ANSWER:
// Using a stack results in a reverse topological order, while a queue produces a standard topological order for directed acyclic graphs.
// The choice impacts the sequence in which nodes are processed during depth-first or breadth-first traversal.

// SECOND THEORETICAL ANSWER:
// A stack (DFS) is preferable for deep exploration and can be more memory-efficient, while a queue (BFS) is suitable for level-wise traversal and finding shortest paths in unweighted graphs.
// The choice depends on the graph characteristics and problem requirements.
