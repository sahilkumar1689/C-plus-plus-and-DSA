using namespace std;
#include <iostream>
#include <stack>
// Procedure1:
// Time Complexity = push O(n),other O(1) , Space Complexity = O(2n).
template <class t>
class queue1{
    stack<t>s1,s2;
    public:
    void push(t d){
        if(s1.empty()) s1.push(d);
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(d);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    void pop(){
        if(s1.empty()) cout<<"Empty."<<endl;
        else s1.pop();
    }
    int front(){
        if(s1.empty()) return -1;
        else return s1.top();
    }
    int size(){
        if(s1.empty()) return 0;
        else return s1.size();
        
    }
    bool empty(){
        return s1.empty();
    }
};
// Procedure2:
// Time Complexity = pop,front O(n),other O(1) , Space Complexity = O(2n).
template <class t>
class queue2{
    stack<t>s1,s2;
    public:
    void push(t d){
        s1.push(d);
    }
    void pop(){
        if(s1.empty()) cout<<"Empty."<<endl;
        else {
            while(s1.size()>1){
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    int front(){
        if(s1.empty()) cout<<"Empty."<<endl;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int temp=s2.top();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return temp;
    }
    int size(){
        if(s1.empty()) return 0;
        else return s1.size();
        
    }
    bool empty(){
        return s1.empty();
    }
};
// Procedure3:
// Time Complexity = pop O(n),other O(1) , Space Complexity = O(n).
template <class t>
class queue3{
    stack<t>st;
    public:
    void push(t d){
        st.push(d);
    }
    void pop(){
        if(st.empty()) cout<<"Empty."<<endl;
        
        int temp=st.top();
        st.pop();

        if(st.empty()) return;

        pop();
        st.push(temp);
    }
    int front(){
        if(st.empty()) cout<<"Empty."<<endl;
        int temp=st.top();
        st.pop();

        if(st.empty()){
            st.push(temp);
            return temp;
        }
        int ans=front();
        st.push(temp);
        return ans;
    }
    int size(){
        if(st.empty()) return 0;
        else return st.size();
    }
    bool empty(){
        return st.empty();
    }
};
int main(){
    // Implement queue using stack = In this we implement a queue class in which we internally implement queue by using stack.
    queue3<int>qu;
    qu.push(5);
    qu.push(6);
    qu.push(7);
    qu.push(8);
    qu.push(9);

    cout<<qu.front()<<endl;
    cout<<qu.size()<<endl;
    cout<<qu.empty()<<endl;
    qu.pop();
    cout<<qu.front()<<endl;
    cout<<qu.size()<<endl;
    cout<<qu.empty()<<endl;



    return 0;
}