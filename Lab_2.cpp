#include <iostream>
#define II long long
using namespace std;

float var = 0;
class Node
{
public:
    string name;
    int id;
    float gpa;
    Node *next;
    Node(string name, int id, float gpa)
    {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
        this->next = NULL;
        var++;
    }
    ~Node()
    {
        int value = this->id;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for address with id " << value << endl;
    }
};

void AddStudent(Node *&head, string name, int id, float gpa)
{
    Node *temp = new Node(name, id, gpa);
    temp->next = head;
    head = temp;
}

void DeleteStudent(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if (!(prev->next))
        {
            tail = prev;
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Name: " << temp->name << " ID: " << temp->id << " GPA: " << temp->gpa << endl;
        temp = temp->next;
    }
    cout << endl;
}

void FindStudent(Node *&head, int target)
{
    Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->id == target)
        {
            cout << "Name: " << temp->name << " ID: " << temp->id << " GPA: " << temp->gpa << endl;
        }
        temp = temp->next;
        position++;
    }
}

void CalculateGpa(Node *&head)
{
    Node *temp = head;
    float sum = 0;
    for (int i = 1; i <= var; i++)
    {
        sum += temp->gpa;
        temp = temp->next;
    }
    cout << "Average GPA of Students is: " << ((sum) / var) << endl;
}

int main()
{
    Node *node1 = new Node("Ahmed", 2022067, 3.49);
    Node *head = node1;
    Node *tail = node1;
    int option, id, position;
    string name, choice;
    float gpa;
    AddStudent(head, "Arsal", 2022350, 3.22);
    do
    {
        cout << "Enter your choice from the menu: " << endl;
        cout << "1) Add a Student " << endl;
        cout << "2) Delete a Student " << endl;
        cout << "3) Display List of Students " << endl;
        cout << "4) Find a Student " << endl;
        cout << "5) Calculate average GPA of current students " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "Enter name of Student: ";
            cin >> name;
            cout << "Enter ID of Student: ";
            cin >> id;
            cout << "Enter GPA of Student: ";
            cin >> gpa;
            AddStudent(head, name, id, gpa);
            break;
        }
        case 2:
        {
            cout << "Enter position number of Student you want to delete: ";
            cin >> position;
            DeleteStudent(position, head, tail);
            break;
        }
        case 3:
        {
            print(head);
            break;
        }
        case 4:
        {
            cout << "Enter ID of the Student: ";
            cin >> id;
            FindStudent(head, id);
            break;
        }
        case 5:
        {
            CalculateGpa(head);
            break;
        }
        default:
        {
            cout << "You have entered an Invalid Choice." << endl;
        }
        }
        cout << "Do you want to continue (Y/N)? " << endl;
        cin >> choice;
    } while (choice == "Y" || choice == "y");
    cout << "Thanks for using GIK Services!" << endl;
    return 0;
}
