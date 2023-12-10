#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertintoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d == root->data)
    {
        // Value already exists, do not insert duplicates
        return root;
    }

    if (d > root->data)
    {
        root->right = insertintoBST(root->right, d);
    }
    else
    {
        root->left = insertintoBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    // Insert values until -1 is occurred
    while (data != -1)
    {
        root = insertintoBST(root, data);
        cin >> data;
    }
}

Node *maxVal(Node *&root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *minVal(Node *&root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
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

bool searchinBST(Node *&root, int val)
{
    // if (root == NULL)
    // {
    //     return false;
    // }
    // if (val == root->data)
    // {
    //     return true;
    // }
    // if (val < root->data)
    // {
    //     return searchinBST(root->left,val);
    // }
    // else
    // {
    //     return searchinBST(root->right,val);
    // }

    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        if (val < temp->data)
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

Node *deleteinBST(Node *&root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteinBST(root->right, min);
            return root;
        }
    }
    else if (val < root->data)
    {
        root->left = deleteinBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteinBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    inorder(root);
    cout << endl;

    cout << "Maximum value in BST: " << maxVal(root)->data << endl;
    cout << "Minimum value in BST: " << minVal(root)->data << endl;

    // DELETION
    root = deleteinBST(root, 98);
    cout << "Printing the BST: " << endl;
    inorder(root);
    cout << endl;

    cout << "Maximum value in BST: " << maxVal(root)->data << endl;
    cout << "Minimum value in BST: " << minVal(root)->data << endl;

    return 0;
}
