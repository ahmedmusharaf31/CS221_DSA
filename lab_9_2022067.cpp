#include <iostream>
using namespace std;

// Node structure for AVL tree
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// Function to get the height of a node
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create a new AVL tree node
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Perform a right rotation
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Perform a left rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Insert a key into the AVL tree
Node *insert(Node *root, int key)
{

    // Perform standard BST insert
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    { // Duplicate keys are not allowed
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Choose the appropriate rotation based on the key and balance factors
    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root); // Right Left Case
    }
    else if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left); // Left Right Case
        return rightRotate(root);
    }
    else if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root); // Right Right Case
    }
    else if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right); // Left Left Case
        return leftRotate(root);
    }

    // No rotation needed
    return root;
}

void inOrderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

// Find the node with the minimum key value
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete a leaf node from the AVL tree
Node *deleteLeafNode(Node *root, int key)
{
    // Base case: If the tree is empty
    if (root == nullptr)
    {
        cout << "Tree is empty. Nothing to delete." << endl;
        return root;
    }

    // Perform standard BST delete
    if (key < root->key)
    {
        root->left = deleteLeafNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteLeafNode(root->right, key);
    }
    else
    {
        // Node found, check if it's a leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr; // The node is a leaf, so delete it and return nullptr
        }
        else
        {
            cout << "Key " << key << " is not a leaf node." << endl;
            return root; // The node is not a leaf, so return the unchanged root
        }
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if necessary
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root); // Right Left Case

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root); // Left Right Case
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root); // Right Right Case

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root); // Left Left Case
    }

    // No rotation needed, return the unchanged root
    return root;
}

int main()
{
    Node *root = nullptr;

    // Insert keys
    int keys[] = {35, 50, 40, 25, 30, 60, 78, 20, 28};
    for (int key : keys)
    {
        root = insert(root, key);
    }

    int choice, insertKey, deleteKey;
    do
    {
        cout << "Choose an option:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display through inOrder traversal\n";
        cout << "3. Delete a leaf node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert: ";
            cin >> insertKey;
            root = insert(root, insertKey);
            break;
        case 2:
            cout << "InOrder Traversal: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        case 3:
            cout << "Enter the key of the leaf node to delete: ";
            cin >> deleteKey;
            root = deleteLeafNode(root, deleteKey);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
