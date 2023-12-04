#include <iostream>
using namespace std;

class Collection
{
    int arr[5];
    int size;

public:
    Collection()
    {
        size = 0;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    void Insert(int value)
    {
        if (size >= 5)
        {
            throw "Collection is full.";
        }
        arr[size++] = value; // size is incremented by 1
    }

    int findMin()
    {
        if (isEmpty())
        {
            throw "Collection is Empty.";
        }
        int min = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        return min;
    }

    int findMax()
    {
        if (isEmpty())
        {
            throw "Collection is Empty.";
        }
        int max = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        return max;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Collection collection;
    try
    {
        if (collection.isEmpty())
        {
            cout << "Initially no values inside the array!" << endl;
        }
        // Following two lines will throw an exception and no Insertion could be performed
        // cout << collection.findMax() << endl;
        // cout << collection.findMin() << endl;

        cout << "Inserting values..." << endl;
        collection.Insert(10);
        collection.Insert(5);
        collection.Insert(30);
        collection.Insert(20);
        collection.Insert(50);

        cout << "Minimum value of the collection is: " << collection.findMin() << endl;
        cout << "Maximum value of the collection is: " << collection.findMax() << endl;
        if (!collection.isEmpty())
        {
            cout << "Values exist inside the Collection!" << endl;
        }
        collection.Insert(99); // This line will throw an exception
    }
    catch (const char *txtException)
    {
        cout << "Exception: " << txtException << endl;
    }

    return 0;
}
