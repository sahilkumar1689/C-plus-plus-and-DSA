#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class linkedList
{
private:
    Node *head;

public:
    linkedList()
    {
        head = nullptr;
    }

    void insertEnd(int value)
    {
        Node *newNode = new Node(value);

        // Check if it is the first element:
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertHead(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value)
    {
        // If list empty:

        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        // first element we need to delete:
        if (head->data == value)
        {
            head = head->next;
            temp->next = NULL;
            return;
        }

        // Rest of the deletion:
        while (temp)
        {
            if (temp->data == value)
            {
                prev->next = temp->next;
                temp->next = NULL;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Element is not present" << endl;
    }

    void reverseList()
    {
        // if list empty
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void display()
    {
        // If no element:
        if (!head)
        {
            cout << "No element in the list." << endl;
        }
        else
        {
            Node *temp = head;

            while (temp)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "null" << endl;
        }
    }
};

int main()
{

    linkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertHead(5);

    // list.deleteNode(30);

    list.reverseList();

    list.display();

    return 0;
}