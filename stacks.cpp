#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    // properties
    int *arr;
    int top;
    int size;
    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow!" << endl;
        }
    }

    int peak()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {                   
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    /*
        // Creation of stack
        stack<int> s;

        // push opertation
        s.push(2);
        s.push(3);

        // pop
        s.pop();

        cout << "Printing top element: " << s.top() << endl;

        if (s.empty())
        {
            cout << "Element is empty!" << endl;
        }
        else
        {
            cout << "Stack is not empty!" << endl;
        }
        cout << "Size of stack is: " << s.size() << endl;
    */

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peak() << endl;

    st.pop();

    cout << st.peak() << endl;

    st.pop();

    cout << st.peak() << endl;

    st.pop();

    cout << st.peak() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is Empty mere dost " << endl;
    }
    else
    {
        cout << "Stack is not Empty mere dost " << endl;
    }

    return 0;
}
