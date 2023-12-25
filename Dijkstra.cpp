#include <iostream>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum distance value
int minimumDist(int dist[], bool Tset[])
{
    int min_index, min_value = INT_MAX;

    for (int v = 0; v < 6; v++)
    {
        if (!Tset[v] && dist[v] <= min_value)
        {
            min_value = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void Dijkstra(int graph[6][6], int src)
{
    int dist[6];
    bool Tset[6];

    for (int i = 0; i < 6; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < 6; count++)
    {
        int m = minimumDist(dist, Tset);
        Tset[m] = true;
        for (int i = 0; i < 6; i++)
        {
            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                dist[i] = dist[m] + graph[m][i];
        }
    }

    // Print the calculated shortest distances
    cout << "Shortest distances from source vertex " << src << " to all other vertices:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    // Example graph represented as an adjacency matrix
    int graph[6][6] = {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}};

    int sourceVertex = 0; // Source vertex for Dijkstra's algorithm

    // Applying Dijkstra's algorithm
    Dijkstra(graph, sourceVertex);

    return 0;
}
