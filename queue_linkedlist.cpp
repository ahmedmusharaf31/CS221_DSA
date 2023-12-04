#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int data)
    {
        if (rear == nullptr)
        {
            Node *newNode = new Node(data);
            front = newNode;
            rear = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1; // Return a sentinel value indicating an empty queue
        }
        return front->data;
    }

    void display()
    {
        Node *temp = front;
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
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.display();

    cout << "Front element: " << myQueue.getFront() << endl;

    myQueue.dequeue();

    cout << "Front element after dequeue: " << myQueue.getFront() << std::endl;

    return 0;
}
