#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for data with value " << data << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *NodetoInsert = new Node(d);
    NodetoInsert->next = temp->next;
    temp->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

void DeleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if (!(prev->next))
        {
            tail = prev;
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Swap Node M(not a tail node) and head node in doubly LL

void Swap(Node *&head, Node *&M)
{
    M->prev->next = M->next;
    M->next->prev = M->prev;

    M->next = head;
    M->prev = NULL;
    head->prev = M;
    head = M;
}

// void find(Node *&head, int value)
// {
//     Node *temp = head;
//     while (temp->data != value)
//     {
//         temp = temp->next;
//     }
//     Node *curr = temp;
//     temp->prev->next = temp->next;
//     temp->next->prev = temp->prev;
//     curr->next = head;
//     head->prev = curr;
//     head = curr;
// }

int main()

{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 22);
    print(head);
    InsertAtTail(tail, 25);
    print(head);
    InsertAtPosition(tail, head, 2, 32);
    print(head);
    // DeleteNode(3, head, tail);
    // print(head);

    Node *M = head->next->next;
    Swap(head, M);
    print(head);

    // find(head, 10);
    // print(head);
    return 0;
}

/*
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for data with value " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    Node *NodetoInsert = new Node(d);
    NodetoInsert->next = temp->next;
    temp->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

void DeleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if (!(prev->next))
        {
            tail = prev;
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(22);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    InsertAtHead(head, 24);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertAtPosition(tail, head, 2, 33);
    print(head);

    InsertAtPosition(tail, head, 4, 10);
    print(head);

    InsertAtPosition(tail, head, 1, 5);
    print(head);

    DeleteNode(1, head, tail);
    print(head);

    DeleteNode(2, head, tail);
    print(head);

    DeleteNode(3, head, tail);
    print(head);

    return 0;
}
*/
