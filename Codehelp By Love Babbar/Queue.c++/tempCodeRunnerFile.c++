using namespace std;
#include <iostream>
#include<deque>
// 1. Implementation of circular queue:
template <class t>
class cirQueue{
    t *arr;
    t qSize;
    int count;
    t front,rear;
    public:
    cirQueue(t s):qSize(s){
        arr=new int[qSize];
        front=-1;
        rear=-1;
        count=0;
    }

    void push(t d){
        if(front==-1) {
            front=0;
            rear=0;
        }
        else if((front==0 && rear ==qSize-1) || (front!=0 && rear<=(front-1))) cout<<"Full."<<endl;
        else if(rear == qSize-1 && front!=0) rear=0;
        else rear++;
        arr[rear]=d;
        count++;
    }

    void pop(){
        if(front==-1) cout<<"Empty."<<endl;
        else if(front==rear){front-1;rear-1;}
        else if(front==qSize-1 && rear!=qSize-1) front=0;
        else front++;
        count--;
    }

    int top(){
        if(front==-1) return -1;
        else return arr[front];
    }
    
    int size(){
        return count;
    }
    bool empty(){
        if(front==-1) return 1;
        else return 0;
    }   
};

// 4. Implementaion of dequeue array:
template <class t>
class dequeue{
    t *arr;
    int qsize;
    t front,rear;
    int count;
    public:
    dequeue(int s):qsize(s){
        arr=new int [qsize];
        front=-1;
        rear=-1;
        count=0;
    }
    void push_front(t d){
        if(front==-1) {
            front=0;
            rear=0;
        }
        else if((front==0 && rear ==qsize-1) || (front!=0 && rear==(front-1))) cout<<"Full."<<endl;
        else if(front==0 && rear !=qsize-1) front=qsize-1;
        else front--;
        arr[front]=d;
        count++;
    }
    void push_back(t d){
         if(front==-1) {
            front=0;
            rear=0;
        }
        else if((front==0 && rear ==qsize-1) || (front!=0 && rear==(front-1))) cout<<"Full."<<endl;
        else if(rear == qsize-1 && front!=0) rear=0;
        else rear++;
        arr[rear]=d;
        count++;

    }
    void pop_front(){
        if(front==-1) cout<<"Empty."<<endl;
        else if(front==rear){front=-1;rear=-1;}
        else if(front==qsize-1 && rear!=qsize-1) front=0;
        else front++;
        count--;
    }
    void pop_back(){
        if(front==-1) cout<<"Empty."<<endl;
        else if(front==rear){front=-1;rear=-1;}
        else if(rear==0 && front!=0) rear=qsize-1;
        else rear--;
        count--;
    }

    int qfront(){
        if(front==-1) return -1;
        else return arr[front];
    }
    int back(){
        if(rear==-1) return -1;
        else return arr[rear];
    }
    int size(){
        return count;
    }
    int empty(){
        if(front==-1) return 1;
        else return 0;
    }
};
int main(){
    // Types of queue = There are basically five types of queue.

    // 1.circular queue = It is also a liner data structure which follows the FIFO principal but the only difference is that the last position is connected to the first position in ordered to make a cirular queue.It is also called a "Ring Buffer".It is basically used in the memory management,traffic signal,cpu scheduling.

    // 2. Input restricted queue = It is basically a simple queue but only one difference is that the element can be inserted only from the one end calles rear but element can be delete from the both end.

    // 3. Output restricted queue = It is basically a simple queue but only one difference is that the element can be inserted from both the end but delete from only one end called front.

    // 4. Dequeue = It is called a doubly ended queue in which the element can be inserted and deleted from both the end i.e. the element can be inserted from the front and rear.Similary the element can be deleted from the front and rear.

    // 5. Priority queue = 1. Ascending oredered queue 2. Descending oredered queue.


    // 1. Implementation of circular queue:

    // cirQueue<int>cq(5);
    // cq.push(5);
    // cq.push(6);
    // cq.push(7);
    // cq.push(8);
    // cq.push(9);

    // cout<<cq.top()<<endl;
    // cout<<cq.size()<<endl;
    // cout<<cq.empty()<<endl;
    // cq.pop();
    // cq.push(10);
    // cout<<cq.top()<<endl;
    // cout<<cq.size()<<endl;
    // cout<<cq.empty()<<endl;

    
    // 4. (i) Implementation of dequeue using array:
    // dequeue<int>dq(5);
    // dq.push_front(5);
    // dq.push_back(6);

    // cout<<dq.qfront()<<endl;
    // cout<<dq.back()<<endl;
    // cout<<dq.size()<<endl;
    // cout<<dq.empty()<<endl;
    // dq.pop_front();
    // dq.pop_back();
    // cout<<dq.qfront()<<endl;
    // cout<<dq.back()<<endl;
    // cout<<dq.size()<<endl;
    // cout<<dq.empty()<<endl;

    // (ii) Implementation using STL:
    deque<int>dq;
    dq.push_front(5);
    dq.push_back(6);

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;
    dq.pop_front();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;
    dq.pop_back();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;
    




    




    return 0;
}