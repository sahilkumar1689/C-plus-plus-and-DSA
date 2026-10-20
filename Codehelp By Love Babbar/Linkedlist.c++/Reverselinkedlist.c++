using namespace std;
#include <iostream>

// 1. Reverse the singly linked list:
class node{
    public:
    int data;
    node* ptr;
    node(int d):data(d){
        ptr=NULL;
    }
};
void insertAtend(node* &head,node* &tail,int data){
    node* new_node = new node(data);
    if(tail==NULL){
        head=new_node;
        tail = new_node;
        return;
    }
    tail->ptr = new_node;
    tail = new_node;
}
void reverseListiterative(node* &head){

    // Handle edge case:
    if(head==NULL || head->ptr==NULL) return;

    node* prev = NULL;
    node* curr = head;
    while(curr!=NULL){
        node* temp = curr->ptr;
        curr->ptr = prev;
        prev = curr;
        curr = temp;
    }
    head=prev;
}
node* reverseListrecursive(node* head){
    // Base case:
    if(head==NULL || head->ptr==NULL) return head;

    node* temp = reverseListrecursive(head->ptr);

    head->ptr->ptr = head;
    head->ptr = NULL;
    return temp;
}
void printList(node* head){
    if(head==NULL){
        cout<<"Empty list.";
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->ptr;
    }
}

// 2. Reverse the doubly linked list:
class doubly{
    public:
    int data;
    doubly* next_ptr;
    doubly* prev_ptr;
    doubly(int d):data(d){
        next_ptr=NULL;
        prev_ptr=NULL;
    }
};
void insertAtenddoubly(doubly* &head,doubly* &tail,int data){
    doubly* new_node = new doubly(data); 
    if(tail==NULL){
        tail=new_node;
        head=new_node;
        return;
    }
    tail->next_ptr = new_node;
    new_node->prev_ptr = tail;
    tail = new_node;
}
void reverseListiteratived(doubly* &head){
    // Handle edge case:
    if(head==NULL || head->next_ptr ==NULL) return;

    doubly* prev = head->prev_ptr;
    doubly* curr = head;
    while (curr!=NULL)
    {
        doubly* temp = curr->next_ptr;
        curr->next_ptr = prev;
        curr->prev_ptr = temp;
        prev = curr;
        curr = temp;
    }
    head = prev;
    
}
doubly* reverseListrecursived(doubly* head){
    // Base case:
    if(head==NULL || head->next_ptr==NULL) {
        head->prev_ptr=NULL;
        return head;
    }

    doubly* new_head = reverseListrecursived(head->next_ptr);

    head->next_ptr->next_ptr = head;
    head->prev_ptr = head->next_ptr;
    head->next_ptr =NULL;

    return new_head;
}
void printListd(doubly* head){
    if(head==NULL){
        cout<<"Empty list.";
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next_ptr;
    }
}
int main()
{
    // 1. Reverse singly linked list:

    // 1. Iteratively = In this you only need to follow three pointer approach.Time complexity O(n),space complexity O(1).

    // int size;
    // cout<<"please enter the size of the list:";
    // cin>>size;
    // node* head = NULL;
    // node* tail = NULL;
    // cout<<"Please enter your element:"<<endl;
    // for(int i=0;i<size;i++){
    //     int data;
    //     cout<<"Please enter the "<<i+1<<" element:";
    //     cin>>data;
    //     insertAtend(head,tail,data);
    // }
    // cout<<"Before reverse:"<<endl;
    // printList(head);

    // reverseListiterative(head);

    // cout<<endl<<"After reverse:"<<endl;
    // printList(head);

    // 2. Recursively = Time complexity O(n) and space complexity O(n).

    // printList(head);

    // node* new_head = reverseListrecursive(head);

    // cout<<endl<<"After reverse:"<<endl;
    // printList(new_head);


    // 2. Reverse doubly linked list:

    // 1. Iteratively = In this we also use the three pointer.Time complexity O(n) and space complexity O(1).

    // int size;
    // cout<<"please enter the size of the list:";
    // cin>>size;
    // doubly* head = NULL;
    // doubly* tail = NULL;
    // cout<<"Please enter your element:"<<endl;
    // for(int i=0;i<size;i++){
    //     int data;
    //     cout<<"Please enter the "<<i+1<<" element:";
    //     cin>>data;
    //     insertAtenddoubly(head,tail,data);
    // }
    // cout<<"Before reverse:";
    // printListd(head);

    // reverseListiteratived(head);

    // cout<<endl<<"After reverse:"<<endl;
    // printListd(head);


    // 2. Recursively = Time complexity O(n) ans space complexity O(n).

    // cout<<"Before reverse:";
    // printListd(head);

    // doubly* new_head= reverseListrecursived(head);

    // cout<<endl<<"After reverse:"<<endl;
    // printListd(new_head);

    return 0;
}