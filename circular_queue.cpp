#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int counter;
    int size;
    int *values;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        values = new int[size];
        front = 0;
        rear = 0;
        counter = 0;
    }

    bool isEmpty()
    {
        // return (counter == 0);
        if (counter)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool isFull()
    {
        //    return (counter == size);
        if (counter < size)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool enqueue(int x)
    {
        if (isFull())
        {
            cout << "Circular Queue is already full." << endl;
            return false;
        }
        else
        {
            values[rear] = x;
            rear = (rear + 1) % size;
            // If rear is set to -1 inside constructor, interchange the above two lines
            counter++;
            return true;
        }
    }

    bool dequeue(int &x)
    {
        if (isEmpty())
        {
            cout << "Circular Queue is Empty.Insert values first!" << endl;
            return false;
        }
        else
        {
            x = values[front];
            front = (front + 1) % size;
            counter--;
            return true;
        }
    }

    void Display_Queue()
    {
        cout << "front--> ";
        for (int i = 0; i < counter; i++)
        {
            if (i != 0)
            {
                cout << "\t\t";
            }
            else
            {
                cout << "\t";
            }
            cout << values[(front + i) % size];
            if (i != counter - 1)
            {
                cout << endl;
            }
            else
            {
                cout << "\t\t<-- rear";
            }
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue queue(5);
    if (queue.isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }

    cout << "Enqueue 5 times." << endl;
    for (int i = 0; i < 5; i++)
    {
        queue.enqueue(i);
    }
    cout << "Now attempting to enqueue again." << endl;
    queue.enqueue(5);
    queue.Display_Queue();
    int value;
    queue.dequeue(value);
    cout << "Retrieved element = " << value << endl;
    queue.Display_Queue();
    queue.enqueue(7);
    queue.Display_Queue();

    return 0;
}
