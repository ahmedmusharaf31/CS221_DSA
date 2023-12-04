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

Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(Node *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchInBST(Node *&root, int x)
{
    /*
        if(root==NULL)
        {
            return false;
        }
        if(root->data==x)
        {
            return true;
        }

        if(root->data>x)
        {
            return searchInBST(root->left,x);
        }
        else
        {
            return searchInBST(root->right,x);
        }
    */

    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        if (temp->data > x)
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

Node *minVal(Node *&root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
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

Node *deletefromBST(Node *&root, int val)
{
    // Base case
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
        {
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
        }
        // 2 child
        {
            if (root->left != NULL && root->right != NULL)
            {
                int min = minVal(root->right)->data; // find min value and replace with node to delete
                root->data = min;
                root->right = deletefromBST(root->right, min); // delete node i.e. existing twice in a BST
                return root;
            }
        }
    }
    else if (root->data > val)
    {
        root->left = deletefromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deletefromBST(root->right, val);
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
    cout << "Minimum value in BST: " << minVal(root)->data << endl;
    cout << "Maximum value in BST: " << maxVal(root)->data << endl;

    // DELETION
    root = deletefromBST(root, 98);
    cout << "Printing the BST: " << endl;
    inorder(root);
    cout << endl;
    cout << "Minimum value in BST: " << minVal(root)->data << endl;
    cout << "Maximum value in BST: " << maxVal(root)->data << endl;

    return 0;
}
