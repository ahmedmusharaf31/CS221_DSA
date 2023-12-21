#include <iostream>
#include <list>
using namespace std;

class graph
{
public:
    list<int> *adjList;
    int n;

    graph(int v)
    {
        adjList = new list<int>[v];
        n = v;
    }

    void addEdge(int u, int v, bool bi)
    {
        adjList[u].push_back(v);
        if (bi)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "--->";
            for (auto it : adjList[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5);
    g.addEdge(1, 2, true);
    g.addEdge(4, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(4, 3, true);
    g.addEdge(1, 4, true);
    g.print();
    
    return 0;
}
