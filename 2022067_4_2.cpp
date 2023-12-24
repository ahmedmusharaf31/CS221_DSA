#include <iostream> // Standard C++ libraries
#include <cstdlib>
#include <ctime>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    Node *insertRecursive(Node *node, int value)
    {
        if (!node)
        {
            return new Node(value);
        }

        if (value < node->value)
        {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    int removeStrategyA()
    {
        return removeStrategyAHelper(root);
    }

    int removeStrategyB()
    {
        return removeStrategyBHelper(root);
    }

    int removeStrategyC()
    {
        return removeStrategyCHelper(root);
    }

    static int getRandomNumber(int min, int max)
    {
        return rand() % (max - min + 1) + min;
    }

private:
    int removeStrategyAHelper(Node *&node)
    {
        if (!node->right)
        {
            int value = node->value;
            node = node->left;
            delete node;
            return value;
        }
        else
        {
            return removeStrategyAHelper(node->right);
        }
    }

    int removeStrategyBHelper(Node *&node)
    {
        if (!node->right)
        {
            int value = node->value;
            node = node->left;
            delete node;
            return value;
        }
        else if (!node->left)
        {
            int value = node->value;
            node = node->right;
            delete node;
            return value;
        }
        else
        {
            if (rand() % 2 == 0)
            {
                return removeStrategyBHelper(node->right);
            }
            else
            {
                return removeStrategyBHelper(node->left);
            }
        }
    }

    int removeStrategyCHelper(Node *&node)
    {
        if (!node->right)
        {
            int value = node->value;
            node = node->left;
            delete node;
            return value;
        }
        else if (!node->left)
        {
            int value = node->value;
            node = node->right;
            delete node;
            return value;
        }
        else
        {
            if (rand() % 2 == 0)
            {
                return removeStrategyCHelper(node->right);
            }
            else
            {
                return removeStrategyCHelper(node->left);
            }
        }
    }
};

int main()
{
    // Seed function similar to srand(time(0));
    srand(static_cast<unsigned int>(time(nullptr)));

    BinarySearchTree bst;

    // Insert values into the BST
    for (int i = 0; i < 10; i++)
    {
        bst.insert(BinarySearchTree::getRandomNumber(1, 100));
    }

    // Evaluate and print the results for each removal strategy
    int comparisonsA = bst.removeStrategyA();
    int comparisonsB = bst.removeStrategyB();
    int comparisonsC = bst.removeStrategyC();

    cout << "Strategy (a): " << comparisonsA << " comparisons\n";
    cout << "Strategy (b): " << comparisonsB << " comparisons\n";
    cout << "Strategy (c): " << comparisonsC << " comparisons\n";

    return 0;
}

// THEORETICAL ANSWER:
// Balance:
// Strategy (c) seems to have the potential to achieve better balance due to the random selection of nodes from either subtree.
// CPU Time:
// Strategy (c) may take the least CPU time in processing the entire sequence, especially if the random choices lead to efficient balancing.
