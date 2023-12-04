#include <iostream> // Header File
using namespace std;

// Define a structure for a single node in the linked list
struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
};

class Queue
{
private:
    Node *front; // Pointer to the front (first) element
    Node *rear;  // Pointer to the rear (last) element

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = NULL; // Initialize the front pointer to NULL (empty queue)
        rear = NULL;  // Initialize the rear pointer to NULL (empty queue)
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == NULL; // Queue is empty if the front pointer is NULL
    }

    // Function to add an element to the rear of the queue
    void enqueue(int data)
    {
        Node *newNode = new Node; // Create a new node
        newNode->data = data;     // Set the data of the new node
        newNode->next = NULL;     // Initialize the next pointer to NULL

        if (isEmpty())
        {
            front = rear = newNode; // If the queue is empty, set both front and rear to the new node
        }
        else
        {
            rear->next = newNode; // Link the current rear to the new node
            rear = newNode;       // Update the rear to the new node
        }
    }

    // Function to remove and return the front element of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int data = front->data; // Get the data from the front node
        Node *temp = front;     // Create a temporary pointer to the front node
        front = front->next;    // Move the front pointer to the next node

        delete temp; // Free the memory of the previous front node
        return data;
    }

    // Function to get the front element without removing it
    int Front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return front->data; // Return the data of the front node
    }
};

int main()
{
    Queue checkoutQueue; // Object of Queue Class

    // Sample Inputs
    checkoutQueue.enqueue(1);
    checkoutQueue.enqueue(2);
    checkoutQueue.enqueue(3);
    checkoutQueue.enqueue(4);

    // Print Servings
    while (!checkoutQueue.isEmpty())
    {
        cout << "Serving: " << checkoutQueue.dequeue() << endl;
    }

    return 0; // Terminate program
}
