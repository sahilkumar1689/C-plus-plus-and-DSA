using namespace std;
#include <iostream>
// #include <stack>
// 2. Implementation using array:
class stackArr{
    int size;
    int *arr;
    int top=-1;
    public:
    stackArr(int s):size(s){
        arr=new int[size];
    }
    void push(int data){
        if(top==size-1) cout<<"Stack Overflow."<<endl;
        else{
            top++;
            arr[top]=data;
        }
    }
    void pop(){
        if(top<0) cout<<"Empty Stack."<<endl;
        else top--;
    }
    int topElem(){
        if(top<0){
            cout<<"Empty Stack."<<endl;
            return -1;
        }
        else return arr[top];
    }
    bool empty(){
        if(top<0) return 1;
        else return 0;
    }
    int sizeS(){
        return top+1;
    }
};

// 3. Implementation using linked list:
class Node{
    public:
    int data;
    Node *next;
    Node(int d):data(d){
        next=NULL;
    }
};
class stackList{
    int size;
    Node *top;
    Node *prev;
    Node *head;
    int refTop;
    public:
    stackList(int s):size(s){
        top=NULL;
        prev=NULL;
        head=NULL;
        refTop=-1;
    }
    void push(int d){
        // Handle overflow:
        if(refTop==size-1){
            cout<<"Stack Overflow."<<endl;
            return;
        }
        // Create the nodes:
        Node *newNode=new Node(d);
        if(refTop<0){
            head=newNode;
            top=newNode;
        }
        else{
            top->next=newNode;
            top=newNode; 
        }
        refTop++;
    }

    void pop(){
        // Handle edge case:
        if(refTop<0){
            cout<<"Empty List."<<endl;
            return;
        }

        if(refTop==0){
            head=NULL;
            delete top;
            top=NULL;
        }
        else{
            prev=head;
            while(prev->next!=top){
                prev=prev->next;
            }
            prev->next=top->next;
            delete top;
            top=prev;
        }
        refTop--;
    }

    int topL(){
        if(refTop<0){
            cout<<"Empty list."<<endl;
            return -1;
        }
        else return top->data;
    }

    bool emptyL(){
        if(refTop<0) return 1;
        else return 0;
    }

    int sizeL(){
        return refTop+1;
    }
};
int main(){
    // Stack = A stack is a linear data structure which follow the LIFO principal in order to store and delete the elements.LIFO principal stands for last in first out i.e. the element can be inserted at the first deleted as the last.In stack we can only use one pointer called top pointer which always pointed to the top of the element.So, we can say that a stack is a container which store and delete the element every time from the top.

    // A stack is implemented using three ways:
    // 1. Using STL.
    // 2. Using array.
    // 3. Using linked list.

    // 1. Using STL= In this we only need to add a header file <stack>.After that we use stack as a class and its object is used to use some features or properties of that stack class.

    // Syntax:
    // stack<data_type> objectName;
    
    // e.g.:
    // stack<int> st;

    // Function we use:
    // 1. push(data) = It is used to push the element at the top of the stack.
    // 2. pop() = It is used to delete the top most element from the top.
    // 3. top() = It gives the element which is present at the top of the stack.
    // 4. empty() = It tells our stack is empty or not.
    // 5. size() = It gives the size of the array.
    
    // Implementation:
    // st.push(5);
    // st.push(5);
    // st.push(5);
    // st.push(10);
    // st.push(5);
    // st.push(10);

    // cout<<st.top()<<endl;
    // st.pop();
    // cout<<st.top()<<endl;
    // cout<<st.size()<<endl;
    // cout<<st.empty()<<endl;


    // 2. Using array:
    // stackArr st(6);
    // st.push(5);
    // st.push(5);
    // st.push(5);
    // st.push(10);
    // st.push(5);
    // st.push(10);
    // // st.push(10);

    // cout<<st.topElem()<<endl;
    // cout<<st.sizeS()<<endl;
    // st.pop();
    // cout<<st.topElem()<<endl;
    // cout<<st.sizeS()<<endl;

    // cout<<st.empty()<<endl;
    // st.push(10);
    // cout<<st.topElem()<<endl;
    // cout<<st.sizeS()<<endl;
    // st.push(10);

    // 3. Using Linked List:
    stackList st(6);
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(10);
    st.push(5);
    st.push(10);

    cout<<st.topL()<<endl;
    cout<<st.sizeL()<<endl;
    st.pop();
    cout<<st.topL()<<endl;
    cout<<st.sizeL()<<endl;

    cout<<st.emptyL()<<endl;
    st.push(10);
    cout<<st.topL()<<endl;
    cout<<st.sizeL()<<endl;
    st.push(10);





    





    return 0;
}