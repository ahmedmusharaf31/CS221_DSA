#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int size;
    int top1;
    int top2;
    int *arr;

    Stack(int s)
    {
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }

    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "Overflow Statement!" << endl;
        }
    }

    void pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            cout << "Element " << ans << " popped! " << endl;
        }
        else
        {
            cout << "Undeflow Statement!" << endl;
        }
    }

    void pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            cout << "Element " << ans << " popped! " << endl;
        }
        else
        {
            cout << "Underflow Statement!" << endl;
        }
    }
};

int main()
{
    Stack st(10);
    st.push1(11);
    st.push1(15);
    st.push1(17);
    st.push1(19);
    st.push1(25);
    st.push2(30);
    st.push2(49);
    st.push2(51);
    st.push2(66);
    st.push2(99);

    for (int i = 0; i < st.size; i++)
    {
        cout << st.arr[i] << " ";
    }
    cout << endl;
    st.pop1();
    st.pop2();

    return 0;
}
