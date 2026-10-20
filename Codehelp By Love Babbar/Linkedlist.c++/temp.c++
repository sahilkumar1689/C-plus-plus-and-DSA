using namespace std;
#include <iostream>

class node
{
public:
    int data;
    node *next;

    node(int d) : data(d)
    {
        this->next = NULL;
    }
};

void insertionInCircularList(node *&head, int value, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    node *temp = head;

    while (temp->data != value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteCircularList(node *&head, int data)
{
    if (head == NULL)
        return;

    if (head->data == data && head->next == head)
    {
        head = NULL;
        return;
    }

    node *prev = head;
    node *curr = head->next;

    while (curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head)
    {
        head = curr->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void printList(node *head)
{
    node *temp = head;
    do
    {
        cout << head->data << " ";
        head = head->next;

    } while (head != temp);
}

int main()
{

    node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        int data, value;
        cout << "Please enter the data and value to insert:";
        cin >> data >> value;
        insertionInCircularList(head, value, data);
    }

    printList(head);

    int data;
    cout << "Please enter the data to be delete:";
    cin >> data;

    deleteCircularList(head, data);

    printList(head);

    return 0;
}