#include <iostream>
#include <stack>
#include <climits> // Used for INT_MAX and INT_MIN in this code

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node *next_smallest;
    Node *next_largest;

    Node(int val) : value(val), left(nullptr), right(nullptr), next_smallest(nullptr), next_largest(nullptr) {}
};

class SetWithBST
{
private:
    Node *root;
    Node *head;
    Node *tail;

public:
    SetWithBST() : root(nullptr)
    {
        head = new Node(INT_MIN); // Dummy node for the smallest element
        tail = new Node(INT_MAX); // Dummy node for the largest element
        head->next_largest = tail;
        tail->next_smallest = head;
    }

    void insert(int value)
    {
        if (!root)
        {
            root = new Node(value);
            head->next_largest = root;
            tail->next_smallest = root;
        }
        else
        {
            _insert(root, value);
        }
    }

    void _insert(Node *node, int value)
    {
        if (value < node->value)
        {
            if (node->left)
            {
                _insert(node->left, value);
            }
            else
            {
                Node *new_node = new Node(value);
                node->left = new_node;
                new_node->next_largest = node;
                new_node->next_smallest = node->next_smallest;
                if (node->next_smallest)
                {
                    node->next_smallest->next_largest = new_node;
                }
                node->next_smallest = new_node;
            }
        }
        else if (value > node->value)
        {
            if (node->right)
            {
                _insert(node->right, value);
            }
            else
            {
                Node *new_node = new Node(value);
                node->right = new_node;
                new_node->next_smallest = node;
                new_node->next_largest = node->next_largest;
                if (node->next_largest)
                {
                    node->next_largest->next_smallest = new_node;
                }
                node->next_largest = new_node;
            }
        }
    }

    class Iterator
    {
    private:
        stack<Node *> node_stack;

    public:
        Iterator(Node *root)
        {
            while (root)
            {
                node_stack.push(root);
                root = root->left;
            }
        }

        bool hasNext() const
        {
            return !node_stack.empty();
        }

        int next()
        {
            if (!hasNext())
            {
                throw out_of_range("Iterator out of range");
            }

            Node *current = node_stack.top();
            node_stack.pop();
            int result = current->value;

            if (current->right)
            {
                Node *node = current->right;
                while (node)
                {
                    node_stack.push(node);
                    node = node->left;
                }
            }

            return result;
        }

        Iterator &operator++()
        {
            // pre-increment
            if (hasNext())
            {
                next();
            }
            return *this;
        }

        int operator*() const
        {
            // dereference
            if (!hasNext())
            {
                throw out_of_range("Iterator out of range");
            }
            return node_stack.top()->value;
        }
    };

    Iterator begin()
    {
        return Iterator(head->next_largest);
    }

    Iterator end()
    {
        return Iterator(tail);
    }
};

int main()
{
    SetWithBST my_set;
    my_set.insert(5);
    my_set.insert(3);
    my_set.insert(7);
    my_set.insert(2);

    for (SetWithBST::Iterator it = my_set.begin(); it.hasNext(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
