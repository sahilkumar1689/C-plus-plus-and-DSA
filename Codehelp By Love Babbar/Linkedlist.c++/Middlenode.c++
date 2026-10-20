using namespace std;
#include <iostream>
// 1. Find Middle node in singley list:
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
int getMiddle1(node* head){
    // Find length of the list:
    node* temp = head;
    int length=0;
    if(head==NULL && head->ptr==NULL) return -1;
    while (temp!=NULL)
    {
        length++;
        temp=temp->ptr;
    }

    // Iterate to find the middle element:
    int count=1;
    temp=head;
    while(count<(length/2+1)){
        count++;
        temp=temp->ptr;
    }
    return temp->data;
    
}
int getMiddle2(node* head){
    if(head==NULL && head->ptr==NULL) return head->data;
    node* prev = head;
    node* forward = head->ptr;
    while (forward!=NULL)
    {
        forward=forward->ptr;
        if(forward!=NULL) forward=forward->ptr;
        prev=prev->ptr;
    }
    return prev->data;
}
// 2. Find middle element in doubly linked list.
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
int getMiddled1(doubly* head){
    // Find length of the list:
    doubly* temp = head;
    int length=0;
    if(head==NULL) return -1;
    while (temp!=NULL)
    {
        length++;
        temp=temp->next_ptr;
    }

    // Iterate to find the middle element:
    int count=1;
    temp=head;
    while(count<(length/2+1)){
        count++;
        temp=temp->next_ptr;
    }
    return temp->data;
}
int getMiddled2(doubly* head){
    if(head==NULL && head->next_ptr==NULL) return head->data;
    doubly* prev = head;
    doubly* forward = head->next_ptr;
    while (forward!=NULL){
        forward=forward->next_ptr;
        if(forward!=NULL) forward=forward->next_ptr;
        prev=prev->next_ptr;
    }
    return prev->data;
}
int main(){
    // 1. Find Middle node in singley list:

    // Approacd 1= Simple linear search for finding length.
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

    // cout<<"Your middle element is:"<<getMiddle1(head);

    // 2. Find Middle node in Doubly list:

    int size;
    cout<<"please enter the size of the list:";
    cin>>size;
    doubly* head = NULL;
    doubly* tail = NULL;
    cout<<"Please enter your element:"<<endl;
    for(int i=0;i<size;i++){
        int data;
        cout<<"Please enter the "<<i+1<<" element:";
        cin>>data;
        insertAtenddoubly(head,tail,data);
    }
    // cout<<"Your middle element is:"<<getMiddled1(head);


    // Approach2= Two pointer approach.
    // 1. Single list:

    // cout<<"Your middle element is:"<<getMiddle2(head)<<endl;

    // 2. Doubly linked list:

    cout<<"Your middle element is:"<<getMiddled2(head);




    return 0;
}