using namespace std;
#include <iostream>
// #include <queue>
// 2. Using array:
class queue{
    int *arr;
    int sSize,rsize;
    int sFront,rear;
    public:
    queue(int s):sSize(s){
        sFront=0;
        rear=0;
        rsize=0;
        arr=new int[sSize];
    }
    void push(int d){
        // Handle overflow:
        if(rear==sSize) cout<<"Overflow Occurs."<<endl;
        else{
            arr[rear]=d;
            rear++;
            rsize++;
        }
    }
    void pop(){
        // Handle empty queue:
        if(sFront==rear) cout<<"Empty queue."<<endl;
        else{
            sFront++;
            rsize--;
            if(sFront==rear) {
                sFront=0;
                rear=0;
                rsize=0;
            }
        }

    }
    int front(){
        if(sFront==rear) return -1;
        else return arr[sFront];
    }
    int back(){
        if(rear==sSize) return arr[rear-1];
        else if(rear==sFront) return -1;
        else return arr[rear];
    }
    int size(){
        return rsize;
    }
    bool isempty(){
        if(sFront==rear) return 1;
        else return 0;
    }
};
// 3. Using linked list:
class Node{
    public:
    int data;
    Node *next;
    Node(int d):data(d){
        next=NULL;
    }
};
class queuelist{
    Node *lfront,*rear,*temp;
    int lsize;
    public:
    queuelist(){
        lfront=NULL;
        rear=NULL;
        temp=NULL;
        lsize=0;
    }
    void push(int d){
        Node *newNode=new Node(d);
        if(lfront==NULL){
            lfront=newNode;
            rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
        lsize++;
    }
    void pop(){
        if(lfront==NULL) cout<<"Empty List."<<endl;
        else{
            temp=lfront;
            if(lfront==rear) rear=rear->next;
            lfront=lfront->next;
            delete temp;
        }
        lsize--;
    }
    int front(){
        if(lfront==NULL) return -1;
        else return lfront->data;
    }
    int back(){
        if(rear==NULL) return -1;
        else return rear->data;
    }
    int size(){
        return lsize;
    }
    bool isempty(){
        if(lfront==NULL) return 1;
        else return 0;
    }
};
int main(){
    // Queue = A queue is a linera data structure which follow the FIFO principal in ordered to store and delete the elements.FIFO principal stands for first in first out i.e. the elements can be inserted at the first deleted as the first.In queue we use two pointers called front and rear in ordered to store and delete the elements.So, we can say that a queue is a list in which elements are stored at the one end and delete at the other end.

    // A queue is implemented using three ways:
    // 1. Using STL.
    // 2. Using array.
    // 3. Using linked list.

    // 1. Using STL=In this we only need to add a header file <queue>. After that we use queue as a class and its object is used to use some predefined features or properties of that queue class.

    // Syntax:
    // queue<data_type> objectName;

    // e.g.:
    // queue<int> qu;

    // Function we use:
    // 1.push(data) = It is used to push the element at the front of the queue.
    // 2. pop() = It is used to delete the element at the front of the queue.
    // 3. front() = It is used to access the front element of the queue.
    // 4. back() = It is used to access the back element of the queue.
    // 5. empty() = It tells our queue is empty or not.
    // 6. size() = It gives the current size of the queue.

    // Implementation:
    // qu.push(5);
    // qu.push(6);
    // qu.push(7);
    // qu.push(8);
    // qu.push(9);

    // cout<<qu.front()<<endl;
    // cout<<qu.size()<<endl;
    // cout<<qu.back()<<endl;
    // qu.pop();
    // cout<<qu.front()<<endl;
    // cout<<qu.size()<<endl;
    // cout<<qu.back()<<endl;
    // cout<<qu.empty()<<endl;

    // 2. Using array:
    // queue qu(5);
    // qu.push(5);
    // qu.push(6);
    // qu.push(7);
    // qu.push(8);
    // qu.push(9);

    // cout<<qu.front()<<endl;
    // cout<<qu.back()<<endl;
    // cout<<qu.isempty()<<endl;
    // cout<<qu.size()<<endl;
    // qu.pop();
    // cout<<qu.front()<<endl;
    // cout<<qu.back()<<endl;
    // cout<<qu.isempty()<<endl;
    // cout<<qu.size()<<endl;

    // 3.Using linked list:
    queuelist qu;
    qu.push(5);

    cout<<qu.front()<<endl;
    cout<<qu.back()<<endl;
    cout<<qu.size()<<endl;
    cout<<qu.isempty()<<endl;
    qu.pop();
    cout<<qu.front()<<endl;
    cout<<qu.back()<<endl;
    cout<<qu.size()<<endl;
    cout<<qu.isempty()<<endl;


    return 0;
}