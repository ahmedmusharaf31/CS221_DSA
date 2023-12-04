#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    char *arr;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new char[size];
    }

    void Push(char element)
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

    void Pop()
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

    bool isBalanced(const std::string &parentheses)
    {
        int n = parentheses.length();
        for (int i = 0; i < n; i++)
        {
            char x = parentheses[i];
            if (x == '(')
            {
                Push(x);
            }
            else if (x == ')')
            {
                if (top >= 0 && arr[top] == '(')
                {
                    Pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return top == -1;
    }
};

int main()
{
    string s1;
    cout << "Input: ";
    cin >> s1;

    int n = s1.length();
    Stack st(n);

    if (st.isBalanced(s1))
    {
        cout << "String is Balanced!" << endl;
    }
    else
    {
        cout << "String is not Balanced!" << endl;
    }
    return 0;
}
