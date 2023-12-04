/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(17);
    cout << "front of queue is: " << q.front() << endl;

    q.push(15);
    cout << "front of queue is: " << q.front() << endl;

    q.push(13);
    cout << "front of queue is: " << q.front() << endl;

    cout << "size of queue is: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();
    cout << "size of queue is: " << q.size() << endl;

    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty" << endl;
    }

    return 0;
}
*/

#include <iostream>
using namespace std;

class Queue
{

    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int Front()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    void display()
    {
        for (int i = front; i < rear ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue queue; // Create a Queue object

    // Enqueue some elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();
    // Check if the queue is empty
    if (queue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    // Get and print the front element
    int frontElement = queue.Front();
    cout << "Front element: " << frontElement << endl;

    // Dequeue elements
    int removedElement = queue.dequeue();
    cout << "Dequeued element: " << removedElement << endl;

    // Get and print the new front element
    frontElement = queue.Front();
    cout << "Front element: " << frontElement << endl;

    // Dequeue the remaining elements
    removedElement = queue.dequeue();
    cout << "Dequeued element: " << removedElement << endl;

    removedElement = queue.dequeue();
    cout << "Dequeued element: " << removedElement << endl;

    // Check if the queue is empty again
    if (queue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
