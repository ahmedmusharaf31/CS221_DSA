#include <iostream>
#include <stack>
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

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void pop()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;

    st.push(5);
    st.push(6);
    st.push(8);
    st.push(15);
    st.push(20);

    st.display();
    st.pop();
    st.display();

    st.pop();
    st.display();
    return 0;
}
