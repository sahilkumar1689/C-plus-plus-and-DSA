using namespace std;
#include <iostream>
#include <queue>
#include <algorithm>
// Procedure 1:
// Time complexity = push O(n),other O(1),Space complexity = O(2n).
template <class t>
class stack1{
    queue<t>q1,q2;
    public:
    void push(t d){
        if(q1.empty()) q1.push(d);
        else{
            q2.push(d);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
    }
    void pop(){
        if(q1.empty()) cout<<"Empty List."<<endl;
        else q1.pop();
    }

    int top(){
        if(q1.empty()) return -1;
        else return q1.front();
    }

    int size(){
        if(q1.empty()) return 0;
        else return q1.size();
    }

    bool empty(){
        return q1.empty();
    }
};

// Procedure2:
// Time complexity=pop,top  O(n),other O(1),space complexity O(2n).
template <class t>
class stack2{
    queue<t>q1,q2;
    public:
    void push(t d){
        q1.push(d);
    }
    void pop(){
        if(q1.empty()) cout<<"Empty List."<<endl;
        else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            swap(q1,q2);
        }
    }

    int top(){
        if(q1.empty()) return -1;
        else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int temp=q1.front();
            q1.pop();
            q2.push(temp);
            swap(q1,q2);
            return temp;
        }
    }

    int size(){
        if(q1.empty()) return 0;
        else return q1.size();
    }

    bool empty(){
        return q1.empty();
    }
};

// Procedure3:
// Time Complexity = push O(n),other O(1), space complexity O(n).
template <class t>
class stack3{
    queue<t>qu;
    public:
    void push(int d){
        if(qu.empty()) qu.push(d);
        else{
            qu.push(d);
            int temp=qu.size()-1;
            while(temp>0){
                qu.push(qu.front());
                qu.pop();
                temp--;
            }
        }
    }

    void pop(){
        if(qu.empty()) cout<<"Empty list."<<endl;
        else qu.pop();
    }

    int top(){
        if(qu.empty()) return -1;
        else return qu.front();
    }

    int size(){
        if(qu.empty()) return -1;
        else return qu.size();
    }

    bool empty(){
        return qu.empty();
    }
};
int main(){
    // Implemenets stack using queue = In this you need to implements stack class but internally you need to implement it by using queue.
    stack3<int>st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;


    return 0;
}