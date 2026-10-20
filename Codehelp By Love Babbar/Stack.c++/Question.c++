using namespace std;
#include <iostream>
#include<stack>

int main(){
    // 1. Reverse a string using stack:

    string str;
    cout<<"Please enter you name:";
    getline(cin,str);
    // cout<<str;

    stack<char>st;

    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }

    string temp="";
    while(!st.empty()){
        temp.push_back(st.top());
        st.pop();
    }
    cout<<"Your name is:"<<temp<<endl;


    return 0;
}