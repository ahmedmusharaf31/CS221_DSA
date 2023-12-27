// #include <iostream>
// #include <list>
// using namespace std;

// class Graph
// {
// public:
//     int V;
//     list<int> *adj;

//     Graph(int V);
//     void addEdge(int v, int w);
//     void BFS(int s);
// };

// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }

// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w);
// }

// void Graph::BFS(int s)
// {
//     bool *visited = new bool[V];
//     for (int i = 0; i < V; i++)
//     {
//         visited[i] = false;
//     }

//     list<int> queue;
//     visited[s] = true;
//     queue.push_back(s);

//     list<int>::iterator i;

//     while (!queue.empty())
//     {
//         s = queue.front();
//         cout << s << " ";
//         queue.pop_front();

//         for (i = adj[s].begin(); i != adj[s].end(); i++)
//         {
//             if (!visited[*i])
//             {
//                 visited[*i] = true;
//                 queue.push_back(*i);
//             }
//         }
//     }
// }

// // Driver program to test methods of graph class
// int main()
// {
//     // Create a graph given in the above diagram
//     Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);

//     cout << "Following is Breadth First Traversal "
//          << "(starting from vertex 2) \n";
//     g.BFS(2);

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;

// class Graph
// {
// public:
//     int vertices;
//     vector<list<int>> adjLists;
//     vector<bool> visited;

//     Graph(int V);
//     void addEdge(int v, int w);
//     void DFS(int vertex);
// };

// Graph::Graph(int V) : vertices(V), adjLists(V), visited(V, false){};

// void Graph::addEdge(int v, int w)
// {
//     adjLists[v].push_back(w);
//     adjLists[w].push_back(v); // Creating a directed graph
// }

// void Graph::DFS(int vertex)
// {
//     visited[vertex] = true;
//     list<int> adjList = adjLists[vertex];

//     cout << vertex << " ";

//     list<int>::iterator i;
//     for (i = adjList.begin(); i != adjList.end(); i++)
//     {
//         if (!visited[*i])
//         {
//             DFS(*i);
//         }
//     }
// }

// int main()
// {
//     Graph g(6);

//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 3);
//     g.addEdge(2, 4);
//     g.addEdge(3, 5);

//     cout << "Depth-First Search (DFS): ";
//     g.DFS(0); // Starting DFS from vertex 0

//     return 0;
// }

/*
#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
    int n;
    list<int> *adjlist;

    Graph(int V)
    {
        n = V;
        adjlist = new list<int>[V];
    }

    void addEdge(int u, int v, bool bi)
    {
        adjlist[u].push_back(v);
        if (bi)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "-->";
            for (auto it : adjlist[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 2, true);
    g.addEdge(4, 2, true);
    g.addEdge(1, 3, true);
    g.addEdge(4, 3, true);
    g.addEdge(1, 4, true);
    g.print();

    return 0;
}
*/

// int graph[][V];
// #include <iostream>
// using namespace std;

// const int V = 4;

// void printgraph(int graph[][V])
// {
//     cout << "Adjacency Matrix Representation: " << endl;
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int graph[V][V] = {0};

//     graph[0][1] = graph[1][0] = 1;
//     graph[0][3] = graph[3][0] = 1;
//     graph[1][2] = graph[2][1] = 1;
//     graph[2][3] = graph[3][2] = 1;

//     printgraph(graph);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int key;
//     int height;
//     Node *left;
//     Node *right;
// };

// Node *newNode(int key)
// {
//     Node *node = new Node();
//     node->key = key;
//     node->left = NULL;
//     node->right = NULL;
//     node->height = 1;
//     return (node);
// }

// int height(Node *&N)
// {
//     if (N == NULL)
//     {
//         return 0;
//     }
//     return N->height;
// }

// int getBalance(Node *&N)
// {
//     if (N == NULL)
//     {
//         return 0;
//     }
//     return height(N->left) - height(N->right);
// }

// Node *rightRotate(Node *&y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     x->height = 1 + max(height(x->left), height(x->right));
//     y->height = 1 + max(height(y->left), height(y->right));

//     return x;
// }

// Node *leftRotate(Node *&x)
// {
//     Node *y = x->right;
//     Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = 1 + max(height(x->left), height(x->right));
//     y->height = 1 + max(height(y->left), height(y->right));

//     return y;
// }

// Node *insertnode(Node *&node, int key)
// {
//     if (node == NULL)
//     {
//         return newNode(key);
//     }
//     if (key < node->key)
//     {
//         node->left = insertnode(node->left, key);
//     }
//     else if (key > node->key)
//     {
//         node->right = insertnode(node->right, key);
//     }
//     else
//     {
//         return node;
//     }

//     node->height = 1 + max(height(node->left), height(node->right));
//     int balance = getBalance(node);

//     if (balance > 1 && key < node->left->key)
//     {
//         return rightRotate(node);
//     }
//     if (balance < -1 && key > node->right->key)
//     {
//         return leftRotate(node);
//     }
//     if (balance > 1 && key > node->left->key)
//     {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }
//     if (balance < -1 && key < node->right->key)
//     {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     return node;
// }

// Node *nodewithMinimumValue(Node *&N)
// {
//     Node *temp = N;
//     while (temp->left != NULL)
//     {
//         temp = temp->left;
//     }
//     return temp;
// }

// Node *deleteNode(Node *&root, int key)
// {
//     if (root == NULL)
//     {
//         return root;
//     }
//     if (key < root->key)
//     {
//         root->left = deleteNode(root->left, key);
//     }
//     else if (key > root->key)
//     {
//         root->right = deleteNode(root->right, key);
//     }
//     else
//     {
//         if ((root->left == NULL) || (root->right == NULL))
//         {
//             Node *temp = root->left ? root->left : root->right;
//             if (temp == NULL)
//             {
//                 temp = root;
//                 root = NULL;
//             }
//             else
//             {
//                 *root = *temp;
//                 free(temp);
//             }
//         }
//         else
//         {
//             Node *temp = nodewithMinimumValue(root->right);
//             root->key = temp->key;
//             root->right = deleteNode(root->right, temp->key);
//         }
//     }
//     if (root == NULL)
//     {
//         return root;
//     }

//     root->height = 1 + max(height(root->left), height(root->right));
//     int balance = getBalance(root);

//     if (balance > 1 && getBalance(root->left) >= 0)
//     {
//         return rightRotate(root);
//     }
//     if (balance > 1 && getBalance(root->left) < 0)
//     {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }
//     if (balance < -1 && getBalance(root->right) <= 0)
//     {
//         return leftRotate(root);
//     }
//     if (balance < -1 && getBalance(root->right) > 0)
//     {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }

//     return root;
// }

// void inorder(Node *&root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout << root->key << " ";
//     inorder(root->right);
// }

// int main()
// {
//     Node *root = NULL;
//     root = insertnode(root, 33);
//     root = insertnode(root, 13);
//     root = insertnode(root, 53);
//     root = insertnode(root, 9);
//     root = insertnode(root, 21);
//     root = insertnode(root, 61);
//     root = insertnode(root, 8);
//     root = insertnode(root, 11);
//     inorder(root);
//     root = deleteNode(root, 13);
//     cout << endl;
//     cout << "After deleting: " << endl;
//     inorder(root);
// }

// // Contributed by Ahmed Musharaf

// #include <iostream>
// using namespace std;

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = (low - 1);
//     for (int j = low; j <= high - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int N = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original Array: " << endl;
//     for (int i = 0; i < N; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     quickSort(arr, 0, N - 1);
//     cout << "Sorted Array: " << endl;
//     for (int i = 0; i < N; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// void merge(int arr[], int const left, int const mid, int const right)
// {
//     int const subArrayOne = mid - left + 1;
//     int const subArrayTwo = right - mid;

//     auto *leftArray = new int[subArrayOne],
//          *rightArray = new int[subArrayTwo];
//     for (int i = 0; i < subArrayOne; i++)
//     {
//         leftArray[i] = arr[left + i];
//     }
//     for (int j = 0; j < subArrayTwo; j++)
//     {
//         rightArray[j] = arr[mid + 1 + j];
//     }

//     auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
//     int indexOfMergedArray = left;

//     while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
//     {
//         if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
//         {
//             arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//             indexOfSubArrayOne++;
//         }
//         else
//         {
//             arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//             indexOfSubArrayTwo++;
//         }
//         indexOfMergedArray++;
//     }

//     while (indexOfSubArrayOne < subArrayOne)
//     {
//         arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
//         indexOfSubArrayOne++;
//         indexOfMergedArray++;
//     }

//     while (indexOfSubArrayTwo < subArrayTwo)
//     {
//         arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
//         indexOfSubArrayTwo++;
//         indexOfMergedArray++;
//     }

//     // arr is original array left and right are temp arrays
//     delete[] leftArray;
//     delete[] rightArray;
// }

// void mergeSort(int arr[], int const begin, int const end)
// {
//     if (begin >= end)
//     {
//         return;
//     }
//     int mid = begin + (end - begin) / 2;
//     mergeSort(arr, begin, mid);
//     mergeSort(arr, mid + 1, end);
//     merge(arr, begin, mid, end);
// }

// void printArray(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// int main()
// {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original Array: " << endl;
//     printArray(arr, arr_size);

//     cout << endl
//          << endl;
//     cout << "Sorted Array: " << endl;

//     mergeSort(arr, 0, arr_size - 1);
//     printArray(arr, arr_size);

//     return 0;
// }
/*Recursive Sorting Algorithms*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertNode(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d == root->data)
    {
        return root; // duplicates are not allowed
    }
    else if (d < root->data)
    {
        root->left = insertNode(root->left, d);
    }
    else
    {
        root->right = insertNode(root->right, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertNode(root, data);
        cin >> data;
    }
}

Node *nodeWithMinimumValue(Node *&root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *deleteNode(Node *&root, int d)
{
    if (root == NULL)
    {
        return root;
    }
    if (d == root->data)
    {
        // 0 child
        if ((root->left == NULL) && (root->right == NULL))
        {
            delete root;
            return NULL;
        }

        // 1 child
        if ((root->left != NULL) && (root->right == NULL))
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if ((root->left == NULL) && (root->right != NULL))
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if ((root->left != NULL) && (root->right != NULL))
        {
            int min = nodeWithMinimumValue(root->right)->data;
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    else if (d < root->data)
    {
        root->left = deleteNode(root->left, d);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, d);
        return root;
    }
}

bool searchInBST(Node *&root, int d)
{
    // if (root == NULL)
    // {
    //     return false;
    // }
    // if (d == root->data)
    // {
    //     return true;
    // }
    // if (d < root->data)
    // {
    //     return searchInBST(root->left, d);
    // }
    // else
    // {
    //     return searchInBST(root->right, d);
    // }

    Node *temp = root;
    while (temp != NULL)
    {
        if (d == temp->data)
        {
            return true;
        }
        if (d < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

Node *nodeWithMaximumValue(Node *&root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

void inorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    inorder(root);
    cout << endl;

    cout << "Maximum value in BST: " << nodeWithMaximumValue(root)->data << endl;
    cout << "Minimum value in BST: " << nodeWithMinimumValue(root)->data << endl;

    // DELETION
    root = deleteNode(root, 15);
    cout << "Printing the BST: " << endl;
    inorder(root);
    cout << endl;

    cout << "Maximum value in BST: " << nodeWithMaximumValue(root)->data << endl;
    cout << "Minimum value in BST: " << nodeWithMinimumValue(root)->data << endl;

    return 0;
}
