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
    vector<unordered_map<char, int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(char u, char v, int weight)
    {
        adjacencyList[u - 'A'][v] = weight;
    }

    vector<int> dijkstra(char source, vector<int> &predecessors)
    {
        vector<int> distance(vertices, INT_MAX);
        distance[source - 'A'] = 0;

        predecessors.assign(vertices, -1);

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0, source});

        while (!pq.empty())
        {
            int u = pq.top().second - 'A';
            pq.pop();

            for (const auto &neighbor : adjacencyList[u])
            {
                char v = neighbor.first;
                int weight = neighbor.second;

                if (distance[u] + weight < distance[v - 'A'])
                {
                    distance[v - 'A'] = distance[u] + weight;
                    predecessors[v - 'A'] = u;
                    pq.push({distance[v - 'A'], v});
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

    g.addEdge('A', 'B', 5);
    g.addEdge('B', 'G', 1);
    g.addEdge('B', 'C', 2);
    g.addEdge('B', 'E', 3);
    g.addEdge('G', 'E', 1);
    g.addEdge('A', 'C', 3);
    g.addEdge('C', 'E', 7);
    g.addEdge('C', 'D', 7);
    g.addEdge('D', 'A', 2);
    g.addEdge('E', 'D', 2);
    g.addEdge('E', 'F', 1);
    g.addEdge('D', 'F', 6);

    char sourceVertex = 'A';
    vector<int> predecessors;
    vector<int> shortestDistances = g.dijkstra(sourceVertex, predecessors);

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
