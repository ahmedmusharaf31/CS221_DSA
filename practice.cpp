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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return (node);
}

int height(Node *&N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->height;
}

Node *rightRotate(Node *&y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max((height(y->left)), (height(y->right))) + 1;
    x->height = max((height(x->left)), (height(x->right))) + 1;

    return x;
}

Node *leftRotate(Node *&x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max((height(y->left)), (height(y->right))) + 1;
    x->height = max((height(x->left)), (height(x->right))) + 1;
    return y;
}

int getBalance(Node *&N)
{
    if (N == NULL)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node *insert(Node *&node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

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

    return (node);
}

Node *minVal(Node *&node)
{
    Node *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *deletenode(Node *&root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            Node *temp = minVal(root->right);
            root->key = temp->key;
            root->right = deletenode(root->right, temp->key);
        }
    }
    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

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

void inorder(Node *&root)
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

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Inorder traversal: " << endl;
    inorder(root);

    root = deletenode(root, 10);

    cout << endl;
    cout << "\nInorder traversal after deletion: " << endl;
    inorder(root);

    return 0;
}
