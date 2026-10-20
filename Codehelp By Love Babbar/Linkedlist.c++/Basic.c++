using namespace std;
#include <iostream>

// 1. Code for singly linked list:
class node
{
public:
    int data;
    node *ptr;
    // Make constructor to add value easily:
    node(int d) : data(d)
    {
        ptr = NULL;
    }
    ~node()
    {
        if (this->ptr != NULL)
        {
            delete ptr;
            this->ptr = NULL;
        }
    }
};
void insertAthead(node *&tail, node *&head, int data)
{
    node *temp = new node(data);
    // Handle the empty linked list:
    if (tail == NULL && head == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    temp->ptr = head;
    head = temp;
}
void insertAttail(node *&head, node *&tail, int data)
{
    node *temp = new node(data);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    tail->ptr = temp;
    tail = temp;
}
void insertAtposition(node *&head, node *&tail, int pos, int d)
{
    // Handle insert at first position:
    if (pos == 1)
    {
        insertAthead(tail, head, d);
        return;
    }
    else
    {
        int count = 1;
        node *temp_head = head;
        while (count != pos - 1)
        {
            temp_head = temp_head->ptr;
            count++;
        }
        // Handle insert at last position:
        if (temp_head->ptr == NULL)
        {
            insertAttail(head, tail, d);
            return;
        }
        else
        {
            node *new_node = new node(d);
            new_node->ptr = temp_head->ptr;
            temp_head->ptr = new_node;
        }
    }
}
void delete_node(int pos, node *&head, node *&tail)
{
    // Handle edge case:
    if (head == NULL && tail == NULL)
        return;
    if (head == tail)
    {
        node *temp = head;
        head = NULL;
        tail == NULL;
        delete temp;
        return;
    }
    // Delete at first position:
    if (pos == 1)
    {
        node *temp_head = head;
        head = head->ptr;
        temp_head->ptr = NULL;
        delete temp_head;
    }
    else
    {
        // Delete at any position:
        node *prev = NULL;
        node *curr = head;
        int count = 1;
        while (count != pos)
        {
            prev = curr;
            curr = curr->ptr;
            count++;
        }
        // Handle tail if delete the last element:
        if (curr->ptr == NULL)
        {
            tail = prev;
        }
        prev->ptr = curr->ptr;
        curr->ptr = NULL;
        delete curr;
    }
}
void print_list(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->ptr;
    }
}
int find_len(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->ptr;
    }
    return count;
}

// 2. Code for Doubly linked list:
class node_double
{
public:
    int data;
    node_double *next_ptr;
    node_double *prev_ptr;
    node_double(int d) : data(d)
    {
        next_ptr = NULL;
        prev_ptr = NULL;
    }
    ~node_double()
    {
        if (this->next_ptr != NULL)
        {
            delete next_ptr;
            this->next_ptr = NULL;
        }
    }
};

void insertAtheaddouble(node_double *&head, node_double *&tail, int data)
{
    node_double *temp = new node_double(data);
    if (head == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    temp->next_ptr = head;
    head->prev_ptr = temp;
    head = temp;
}
void insertAttaildouble(node_double *&head, node_double *&tail, int data)
{
    node_double *temp = new node_double(data);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    tail->next_ptr = temp;
    temp->prev_ptr = tail;
    tail = temp;
}
void print_list_double(node_double *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next_ptr;
    }
}
void insertAtpositiondouble(node_double *&head, node_double *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertAtheaddouble(head, tail, data);
        return;
    }
    else
    {
        int count = 1;
        node_double *temp = head;
        while (count != pos - 1)
        {
            count++;
            temp = temp->next_ptr;
        }
        // Handle insert at last position:
        if (temp->next_ptr == NULL)
        {
            insertAttaildouble(head, tail, data);
            return;
        }
        node_double *new_node = new node_double(data);
        new_node->next_ptr = temp->next_ptr;
        temp->next_ptr->prev_ptr = new_node;
        temp->next_ptr = new_node;
        new_node->prev_ptr = temp;
    }
}
void delete_double(node_double *&head, node_double *&tail, int pos)
{
    // Handle edge case:
    if (tail == NULL && head == NULL)
    {
        return;
    }
    if (head == tail)
    {
        node_double *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if (pos == 1)
    {
        node_double *temp_head = head;
        head = head->next_ptr;
        head->prev_ptr = NULL;
        temp_head->next_ptr = NULL;
        delete temp_head;
    }
    else
    {
        node_double *ptr1 = NULL;
        node_double *ptr2 = head;
        int count = 1;
        while (count != pos)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next_ptr;
            count++;
        }
        // Handle delete at last:
        if (ptr2->next_ptr == NULL)
        {
            tail = ptr1;
            ptr1->next_ptr = NULL;
            ptr2->prev_ptr = NULL;
            delete ptr2;
            return;
        }
        ptr1->next_ptr = ptr2->next_ptr;
        ptr2->next_ptr->prev_ptr = ptr2->prev_ptr;
        ptr2->next_ptr = NULL;
        ptr2->prev_ptr = NULL;
        delete ptr2;
    }
}

// 3. Circular Linked List:
class circular_node
{
public:
    int data;
    circular_node *ptr;
    circular_node(int d) : data(d)
    {
        ptr = NULL;
    }
    ~circular_node()
    {
        if (this->ptr != NULL)
        {
            delete ptr;
            this->ptr = NULL;
        }
    }
};
void insertCircularnode(circular_node *&tail, int elem, int data)
{
    if (tail == NULL)
    {
        circular_node *temp = new circular_node(data);
        tail = temp;
        temp->ptr = temp;
        return;
    }
    else
    {
        circular_node *temp_tail = tail;
        while (temp_tail->data != elem)
        {
            temp_tail = temp_tail->ptr;
        }
        circular_node *new_node = new circular_node(data);
        new_node->ptr = temp_tail->ptr;
        temp_tail->ptr = new_node;
    }
}
void print_circular(circular_node *tail)
{
    if (tail == NULL)
    {
        cout << "Empty list." << endl;
    }

    circular_node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->ptr;
    } while (temp != tail);
}
void delete_cicularnode(circular_node *&tail, int elem)
{
    if (tail == NULL)
    {
        cout << "Empty list." << endl;
        return;
    }
    circular_node *prev = tail;
    circular_node *curr = prev->ptr;

    while (curr->data != elem)
    {
        prev = curr;
        curr = curr->ptr;
    }

    // If list have only one element:
    if (curr == prev)
        tail == NULL;

    if (curr == tail)
        tail = prev;

    prev->ptr = curr->ptr;
    curr->ptr = NULL;
    delete curr;
}

// 4. Double Circular Linked List:
class dcNode
{
public:
    int data;
    dcNode *next_ptr;
    dcNode *prev_ptr;

    dcNode(int d) : data(d)
    {
        next_ptr = NULL;
        prev_ptr = NULL;
    }
    ~dcNode()
    {
        if (this->next_ptr != NULL)
        {
            delete next_ptr;
            next_ptr = NULL;
        }
    }
};
void dcInsert(dcNode *&tail, int elem, int data)
{
    if (tail == NULL)
    {
        dcNode *temp = new dcNode(data);
        tail = temp;
        temp->next_ptr = temp;
        temp->prev_ptr = temp;
        return;
    }
    else
    {
        dcNode *temp_tail = tail;
        while (temp_tail->data != elem)
        {
            temp_tail = temp_tail->next_ptr;
        }
        dcNode *new_node = new dcNode(data);
        new_node->prev_ptr = temp_tail;
        new_node->next_ptr = temp_tail->next_ptr;
        temp_tail->next_ptr->prev_ptr = new_node;
        temp_tail->next_ptr = new_node;
    }
}
void dcDelete(dcNode *&tail, int elem)
{
    if (tail == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }
    dcNode *prev = tail;
    dcNode *curr = prev->next_ptr;
    while (curr->data != elem)
    {
        prev = curr;
        curr = curr->next_ptr;
    }
    if (prev == curr)
    {
        tail = NULL;
        delete curr;
        return;
    }
    if (tail == curr)
    {
        tail = curr->next_ptr;
    }
    prev->next_ptr = curr->next_ptr;
    curr->next_ptr->prev_ptr = prev;
    curr->next_ptr = NULL;
    curr->prev_ptr = NULL;
    delete curr;
}
void print_dc(dcNode *tail)
{
    if (tail == NULL)
    {
        cout << "Empty list";
        return;
    }
    dcNode *temp_tail = tail;
    do
    {
        cout << temp_tail->data << " ";
        temp_tail = temp_tail->next_ptr;
    } while (temp_tail != tail);
}

int main()
{
    // Linked List:

    // 1. Singly Linked list:
    // 1. Creating an linked list with two element:
    // Creating first node and head pointer:
    // node *n1 = new node(5);
    // node *head = n1;
    // // Creating the second node and the tail pointer:
    // node *n2 = new node(5);
    // node *tail = n1;
    // // Connect each other to form a list:
    // n1->ptr = n2;
    // n2->ptr = NULL;

    // // 2. Insertion in linked list:
    // // Function to insert at head or first position:
    // insertAthead(tail,head,5);
    // // Function to insert at tail or last position:
    // insertAttail(head,tail,10);
    // // Function to insert at any position:
    // insertAtposition(head,tail,4,10);
    // insertAtposition(head,tail,1,10);
    // insertAtposition(head,tail,7,10);

    // // 3. Deletion in linked list:
    // // Function to delete any node:
    // delete_node(1,head,tail);
    // delete_node(6,head,tail);
    // delete_node(5,head,tail);
    // delete_node(4,head,tail);

    // // 4. Traverse in the linked list:
    // // Function to traverse the list:
    // print_list(head);
    // cout<<endl<<head->data<<endl<<tail->data<<endl;

    // // 5. Find length of the linked list:
    // int l = find_len(head);
    // cout<<"Length:"<<l<<endl;

    // Note = 1. Tail pointer is only for our comfort it is not mendatory to initialize tail pointer every time.
    // 2. If we don't use the tail pointer then we need to traverse with our head pointer for each and every insertion and deletion.

    // 2. Doubly Linked List:

    // 1. Create a node:
    // node_double* n1 = new node_double(4);
    // node_double* head = n1;
    // node_double* tail = n1;

    // // 2. Insert functions:
    // // Function to insert at head:
    // insertAtheaddouble(head,tail,10);
    // // Function to insert at tail:
    // insertAttaildouble(head,tail,5);
    // // Function to insert at any position:
    // insertAtpositiondouble(head,tail,1,9);
    // insertAtpositiondouble(head,tail,3,3);
    // insertAtpositiondouble(head,tail,6,6);

    // // 3. Delete function:
    // // Function to delete at any position:
    // delete_double(head,tail,1);
    // delete_double(head,tail,2);
    // delete_double(head,tail,4);

    // // 4. Function to traverse the list:
    // print_list_double(head);
    // cout<<endl<<head->data<<endl<<tail->data<<endl;

    // 3. Circular singly linked list:

    // Create an empty tail node:
    // circular_node* tail = NULL;

    // 1. Insert the element in the list:
    // insertCircularnode(tail,0,5);
    // insertCircularnode(tail,5,4);
    // insertCircularnode(tail,4,3);
    // insertCircularnode(tail,4,2);
    // insertCircularnode(tail,3,1);

    // // 2. Deletion in the circular list:
    // delete_cicularnode(tail,5);
    // delete_cicularnode(tail,2);
    // delete_cicularnode(tail,1);

    // // 3. Traverse the circular linked list:
    // print_circular(tail);
    // cout<<endl<<tail->data<<endl;

    // Note = 1. In circular linked list we only need an single pointer tail.
    // 2. In circular list we don't need to maintain our tail.Unless in delete case.

    // 4. Double Circular Linked List:

    // Creating an empty tail ptr:
    dcNode *tail = NULL;

    // 1. Insertion in double circular linked list:
    dcInsert(tail, 0, 5);
    dcInsert(tail, 5, 4);
    dcInsert(tail, 4, 3);
    dcInsert(tail, 4, 2);
    dcInsert(tail, 3, 1);

    // 2. Delete in double circular linked list:
    dcDelete(tail, 5);
    dcDelete(tail, 2);
    dcDelete(tail, 1);

    // 3. Traverse the double circular linked list:
    print_dc(tail);
    cout << endl
         << tail->data;

    return 0;
}