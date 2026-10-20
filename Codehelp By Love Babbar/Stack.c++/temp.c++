using namespace std;
#include <iostream>

class stack
{
    int i;
    int size;
    int *arr;

public:
    stack(int s) : size(s)
    {
        arr = new int[size];
        i = -1;
    }

    void push(int data)
    {
        if (i != size - 1)
        {
            i++;
            arr[i] = data;
        }
        else
            cout << "Stack Overflow." << endl;
    }

    void pop()
    {
        if (i == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            i--;
        }
    }

    int top()
    {
        if (i < 0)
        {
            cout << "Stack is Empty." << endl;
            return -1;
        }
        return arr[i];
    }

    bool isEmpty()
    {
        if (i != size - 1)
            return 1;
        else
            return 0;
    }
};

int main()
{

    stack st(5);

    st.push(5);
    cout << st.top() << endl;
    cout << st.isEmpty() << endl;

    st.pop();
    cout << st.top() << endl;
    cout << st.isEmpty() << endl;

    return 0;
}
