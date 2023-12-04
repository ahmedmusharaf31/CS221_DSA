#include <iostream>
using namespace std;

// Define a Node class for the linked list
class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}

	// Destructor to free memory recursively
	~Node()
	{
		int value = this->data;
		if (this->next != NULL)
		{
			delete next;
			next = NULL;
		}
		cout << "Memory is free for data with value " << value << endl;
	}
};

// Function to check if a value exists in the linked list
bool Contains(Node *&head, int x)
{
	Node *temp = head;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

// Function to insert a value at the head of the linked list
void InsertAtHead(Node *&head, int x)
{
	if (!Contains(head, x))
	{
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;
	}
	else
	{
		cout << "Value " << x << " already exists inside the linked list!" << endl;
	}
}

// Function to delete a node with the specified value from the linked list
void DeleteNode(Node *&head, int x)
{
	Node *curr = head;
	Node *prev = NULL;

	if (!Contains(head, x))
	{
		cout << "Value " << x << " does not exist!" << endl;
	}

	while (curr != NULL)
	{
		if (curr->data == x)
		{
			if (prev)
			{
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				curr = prev->next;
			}
			else
			{
				Node *temp = head;
				head = head->next;
				temp->next = NULL;
				delete temp;
				curr = head;
			}
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

// Function to return the size of the linked list
int Size_Linkedlist(Node *&head)
{
	Node *temp = head;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

// Function to print the linked list
void Print(Node *&head)
{
	if (head == NULL)
	{
		cout << "Linked list is empty!" << endl;
	}
	else
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

int main()
{
	char again;
	Node *node1 = new Node(20);
	Node *head = node1;

	do
	{
		cout << "Choose from 1/2/3/4/5: " << endl;
		cout << "1) Return the size of the linked list" << endl;
		cout << "2) Print the linked list" << endl;
		cout << "3) Test if a value x is contained in the linked list" << endl;
		cout << "4) Add a value x if it is not already contained in the linked list" << endl;
		cout << "5) Remove a value x if it is contained in the linked list" << endl;

		int flag, val;
		cin >> flag;
		switch (flag)
		{
		case 1:
			cout << "Size of Linked List: " << Size_Linkedlist(head) << endl;
			break;

		case 2:
			Print(head);
			break;

		case 3:
			cout << "Enter value to be checked: " << endl;
			cin >> val;
			if (Contains(head, val))
			{
				cout << "Value " << val << " exists! " << endl;
			}
			else
			{
				cout << "Value " << val << " does not exist! " << endl;
			}
			break;

		case 4:
			cout << "Enter value to be inserted: " << endl;
			cin >> val;
			InsertAtHead(head, val);
			break;

		case 5:
			cout << "Enter value to be removed: " << endl;
			cin >> val;
			DeleteNode(head, val);
			break;

		default:
			cout << "Invalid choice!" << endl;
		}

		cout << "Do you want to continue? (Y/N) " << endl;
		cin >> again;
	} while (again == 'y' || again == 'Y');

	return 0;
}
