// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// int countNodes(Node *head)
// {
//     int cnt = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         cnt++;
//     }
//     return cnt;
// }

// int main()
// {
//     Node *node1 = new Node(22);
//     Node *node2 = new Node(33);
//     node1->next = node2;
//     Node *node3 = new Node(44);
//     node1->next->next = node3;
//     Node *head = node1;
//     cout << "Number of nodes created: " << countNodes(head);
//     return 0;
// }

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool isListEmpty(Node *head)
{
    return (head == NULL);
}

int main()
{
    Node *head = new Node(22); // Node* head=NULL;
    if (isListEmpty(head))
    {
        cout << "The linked list is empty!" << endl;
    }
    else
    {
        cout << "The linked list is not empty!" << endl;
    }
    return 0;
}

// 3rd Code is Same as singly_linked_list.cpp
