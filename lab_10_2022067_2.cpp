#include <iostream> // BFS Implementation
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
  Graph(int V) : numVertices(V) {
    adjLists.resize(V + 1); // Adjust size for 1-based indexing
  }

  void addEdge(int u, int v) {
    adjLists[u].push_back(v);
    adjLists[v].push_back(u); // Since it's undirected
  }

  void printGraph() {
    for (int i = 1; i <= numVertices; ++i) { // Start from 1 for 1-based indexing
      cout << "Vertex " << i << ": Connected to vertices ";
      for (auto j : adjLists[i]) {
        cout << j << " -> ";
      }
      cout << endl;
    }
  }

  void BFS(int startVertex) {
    vector<bool> visited(numVertices + 1, false); // Initialize all vertices as not visited
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    cout << "BFS Traversal starting from Vertex " << startVertex << ": ";

    while (!q.empty()) {
      int currentVertex = q.front();
      q.pop();
      cout << currentVertex << " ";

      for (auto neighbor : adjLists[currentVertex]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }

    cout << endl;
  }

private:
  int numVertices;
  vector<vector<int>> adjLists;
};

int main() {
  Graph g(5); // 5 vertices (1-5)

  g.addEdge(1, 2);  // connects vertex 1 and 2
  g.addEdge(1, 3);  // connects vertex 1 and 3
  g.addEdge(1, 4);  // connects vertex 1 and 4
  g.addEdge(2, 3);  // connects vertex 2 and 3
  g.addEdge(2, 5);  // connects vertex 2 and 5

  g.printGraph();

  // Perform BFS traversal starting from Vertex 1
  g.BFS(1);

  // The user can input their own starting vertex and perform BFS
  int startVertex;
  cout << "Enter the starting vertex for BFS traversal: ";
  cin >> startVertex;

  g.BFS(startVertex);

  return 0;
}
