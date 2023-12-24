#include <iostream> // Standard C++ Libraries
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<unordered_map<char, bool>> adjacencyList; // Use bool instead of int for unweighted graph

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(char u, char v)
    {
        adjacencyList[u - 'A'][v] = true;
    }

    vector<int> unweightedShortestPath(char source, vector<int> &predecessors)
    {
        vector<int> distance(vertices, INT_MAX);
        distance[source - 'A'] = 0;

        predecessors.assign(vertices, -1);

        queue<char> q;
        q.push(source);

        while (!q.empty())
        {
            char u = q.front();
            q.pop();

            for (const auto &neighbor : adjacencyList[u - 'A'])
            {
                char v = neighbor.first;

                if (distance[u - 'A'] + 1 < distance[v - 'A'])
                {
                    distance[v - 'A'] = distance[u - 'A'] + 1;
                    predecessors[v - 'A'] = u - 'A';
                    q.push(v);
                }
            }
        }

        return distance;
    }

    void printPath(char source, char destination, const vector<int> &predecessors)
    {
        stack<char> path;
        int sourceIndex = source - 'A';
        int destinationIndex = destination - 'A';

        for (int v = destinationIndex; v != sourceIndex; v = predecessors[v])
        {
            if (predecessors[v] == -1)
            {
                cout << "No path from " << source << " to " << destination << " exists." << endl;
                return;
            }
            path.push(v + 'A');
        }
        path.push(source);

        cout << "Shortest path from " << source << " to " << destination << ": ";
        while (!path.empty())
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graph g(7);

    g.addEdge('A', 'B');
    g.addEdge('B', 'G');
    g.addEdge('B', 'C');
    g.addEdge('B', 'E');
    g.addEdge('G', 'E');
    g.addEdge('A', 'C');
    g.addEdge('C', 'E');
    g.addEdge('C', 'D');
    g.addEdge('D', 'A');
    g.addEdge('E', 'D');
    g.addEdge('E', 'F');
    g.addEdge('D', 'F');

    char sourceVertex = 'B';
    vector<int> predecessors;
    vector<int> shortestDistances = g.unweightedShortestPath(sourceVertex, predecessors);

    cout << "Shortest distances from vertex " << sourceVertex << ":\n";
    for (int i = 0; i < shortestDistances.size(); i++)
    {
        cout << "To vertex " << static_cast<char>('A' + i) << ": " << shortestDistances[i] << "\n";
    }

    // Print paths
    for (char destination = 'A'; destination <= 'G'; destination++)
    {
        if (destination != sourceVertex)
        {
            g.printPath(sourceVertex, destination, predecessors);
        }
    }

    return 0;
}
