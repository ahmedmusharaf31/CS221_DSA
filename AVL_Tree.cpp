// AVL tree implementation in C++
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};
int max(int a, int b);
// Calculate height
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// New node creation
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}
// Rotate right
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    return x;
}
// Rotate left
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    return y;
}
// Get the balance factor of each node
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}
// Insert a node
Node *insertNode(Node *node, int key)
{
    // Find the correct postion and insert the node
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;
    // Update the balance factor of each node and
    // balance the tree
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) // LL
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) // RR
    {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) // LR
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) // RL
    {
        node->right = rightRotate(node->right);
        leftRotate(node);
    }
    return node;
}
// Node with minimum value
Node *nodeWithMimumValue(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
// Delete a node
Node *deleteNode(Node *root, int key)
{
    // Find the node and delete it
    if (root == NULL)
        return root;
    if (key < root->key)

        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = nodeWithMimumValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }
    if (root == NULL)
        return root;
    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) // LL
    {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) // LR
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) // RR
    {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) // RL
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// Print the tree
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    root = insertNode(root, 33);
    root = insertNode(root, 13);
    root = insertNode(root, 53);
    root = insertNode(root, 9);
    root = insertNode(root, 21);
    root = insertNode(root, 61);
    root = insertNode(root, 8);
    root = insertNode(root, 11);
    inorder(root);
    root = deleteNode(root, 13);
    cout << endl;
    cout << "After deleting: " << endl;
    inorder(root);
}
