#include <iostream>
using namespace std;

class Node
{
public:
    int Number;
    Node *Next;

    Node(int num) : Number(num), Next(nullptr) {}
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList() : head(nullptr) {}

    // Insert a new node with value X after node P.
    void Insert(int X, Node *P)
    {
        Node *TmpCell = new Node(X);
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
    }

    // Delete the node after node P.
    void DeleteNext(Node *P)
    {
        Node *TmpCell = P->Next;
        P->Next = TmpCell->Next;
        delete TmpCell;
    }

    // Solve the Josephus problem for N people and M passes.
    int Josephus(int N, int M)
    {
        if (N <= 0 || M < 0)
        {
            cout << "Invalid input." << endl;
            return -1;
        }

        head = new Node(1);
        head->Next = head;
        Node *LastCell = head;
        int count = 0;

        for (int i = 2; i <= N; i++)
        {
            Insert(i, LastCell);
            LastCell = LastCell->Next;
        }

        while (head != head->Next)
        {
            if (++count == M)
            {
                DeleteNext(head);
                count = 0;
            }
            head = head->Next;
        }

        return head->Number;
    }
};

int main()
{
    int N, M;
    cout << "Enter the total number of people (N): ";
    cin >> N;
    cout << "Enter the elimination count (M): ";
    cin >> M;

    if (N > 0 && M == 0)
    {
        cout << "The winner is player " << N << endl;
    }
    else
    {
        CircularLinkedList game;
        int winner = game.Josephus(N, M);

        cout << "The winner is player " << winner << endl;
    }

    return 0;
}
