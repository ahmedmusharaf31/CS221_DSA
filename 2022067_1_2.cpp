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
            throw "Collection is full."; // Exception thrown
        }
        arr[size++] = value; // size is incremented by 1
    }

    void Remove(int value)
    {
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                found = true;
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                size--;
                break;
            }
        }
        if (!found)
        {
            throw "Value not found inside the Collection";
        }
    }

    bool Contains(int x)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x) // This condition returns true if and only if 'x' is present inside the Collection
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Collection collection;
    try
    {
        cout << "Inserting values..." << endl;
        collection.Insert(10);
        collection.Insert(5);
        collection.Insert(30);
        collection.Insert(20);
        collection.Insert(50);
        // Following line will throw an Exception
        // collection.Insert(40);

        // Checking for any value inside the Collection
        int temp = 20;
        if (collection.Contains(temp))
        {
            cout << "Value " << temp << " exists inside the Collection!" << endl;
        }
        else
        {
            cout << "Value " << temp << " does not exist inside the Collection!" << endl;
        }

        collection.Remove(temp);
        collection.Remove(temp); // Exception thrown as 20 is removed
    }
    catch (const char *txtException)
    {
        cout << "Exception: " << txtException << endl;
    }

    return 0;
}
