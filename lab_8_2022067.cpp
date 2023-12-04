#include <iostream>   // standard library 

using namespace std;

class TreeNode {
public:
    int emp_id;
    string emp_name;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int id, const string& name) : emp_id(id), emp_name(name), left(nullptr), right(nullptr) {}
};

class EmployeeBST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int emp_id, const string& emp_name) {
        if (root == nullptr) {
            return new TreeNode(emp_id, emp_name);
        }

        if (emp_id < root->emp_id) {
            root->left = insert(root->left, emp_id, emp_name);
        } else if (emp_id > root->emp_id) {
            root->right = insert(root->right, emp_id, emp_name);
        } else {
            cout << "Employee with ID " << emp_id << " already exists." << endl;
        }

        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int emp_id) {
        if (root == nullptr) {
            cout << "Employee with ID " << emp_id << " not found." << endl;
            return root;
        }

        if (emp_id < root->emp_id) {
            root->left = deleteNode(root->left, emp_id);
        } else if (emp_id > root->emp_id) {
            root->right = deleteNode(root->right, emp_id);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* minNode = findMin(root->right);
                root->emp_id = minNode->emp_id;
                root->emp_name = minNode->emp_name;
                root->right = deleteNode(root->right, minNode->emp_id);
            }
        }

        return root;
    }

    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << "ID: " << root->emp_id << ", Name: " << root->emp_name << endl;
            inorderTraversal(root->right);
        }
    }

public:
    EmployeeBST() : root(nullptr) {}

    void insert(int emp_id, const string& emp_name) {
        root = insert(root, emp_id, emp_name);
    }

    void deleteEmployee(int emp_id) {
        root = deleteNode(root, emp_id);
    }

    void displayRecords() {
        cout << "Employee Records:" << endl;
        inorderTraversal(root);
    }
};

int main() {
    EmployeeBST bst;

    // Insert employees
    bst.insert(5, "John Doe");
    bst.insert(3, "Jane Smith");
    bst.insert(7, "Bob Johnson");
    bst.insert(2, "Alice White");
    bst.insert(4, "Charlie Brown");
    bst.insert(6, "David Lee");
    bst.insert(8, "Eva Davis");

    // Display the tree
    bst.displayRecords();

    // Delete an employee
    bst.deleteEmployee(3);

    // Display the tree after deletion
    cout << "\nEmployee Records after Deletion:" << endl;
    bst.displayRecords();

    return 0;
}
