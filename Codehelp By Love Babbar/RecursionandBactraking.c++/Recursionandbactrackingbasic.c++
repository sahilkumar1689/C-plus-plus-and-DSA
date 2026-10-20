using namespace std;
#include <iostream>
// 1. Write a program to print name n times:
void printNameR(string name,int n){
    // Base Case:
    if(n==0) return;

    cout<<name<<endl;       // recursion.
    // n--;                // you can also do here.
    printNameR(name,n-1); // n-- not work because n-- means that n=n-1,but you don't have rights to assign the value in the parameters.
}
    
// 2. Write a program to print name n times using backtracking:
void printNameB(string name,int n){
    // Base case:
    if(n==0) return;
    printNameB(name,n-1);
    cout<<name<<endl;      // Backtracking
}
    
// 3. Print 1 to n using recursion:
void printNR(int count,int n){
    // Base Case:
    if(count>n) return;
    cout<<count<<" ";
    printNR(count+1,n);
}

// 4. Print n to 1 using recursion:
void printReverseNR(int n){
    // Base Case:
    if(n==0) return;
    cout<<n<<" ";
    printReverseNR(n-1);
}

// 5. Print 1 to n using backtracking:
void printNB(int n){
    // Base Case:
    if(n==0) {return;}
    int temp=n;
    printNB(n-1);
    cout<<temp<<" ";
}

// 6. Print n to 1 using backtracking:
void printReverseNB(int count,int n){
    // Base Case:
    if(n==0) {return;}
    int temp=count;
    printReverseNB(count+1,n-1);
    cout<<temp<<" ";
}

// 7. Sum of first n number using parameterized recursion:
int sumNR1(int sum,int n){
    // Base Case:
    if(n==0){return sum;}
    sum += n;
    return sumNR1(sum,n-1); 
}

// 8. Sum of first n number using no-parameterized recursion:
int sumNR2(int n){
    // Base Case:
    if(n==0){return 0;}
    int sum = n+sumNR2(n-1);
    return sum;
}

// 9. Factorial of a number:
int fact(int n){
    // Base case:
    if(n==0) return 1;
    int factorial=n*fact(n-1);
    return factorial;
}

// 10. Reverse an array:
void reverseArr(int *arr,int start ,int end){
    // Base Case:
    if(start>=end) return;
    swap(arr[start],arr[end]);
    reverseArr(arr,start+1,end-1);
}

// 11. Check the string is palindrome or not:
bool isPalin(string str,int start,int end){
    // Base Case:
    if(start>=end) return true;

    if(str[start]!=str[end]) return false;
    return isPalin(str,start+1,end-1);
}

// 12. nth fibonacci number:
int fibo(int n){
    // Base Case:
    if(n<=1) return n;

    int last=fibo(n-1);
    int sLast=fibo(n-2);
    return last+sLast;
}
int main(){
    // 1. Recursion = When a function call itself untill some specified condition reached is called recursion.
    // There are three pillars of recursion:
    // 1. Base Case = It tell when you need to stop called itself.
    // 2. Recursive call = It call it self untill base case condition does'nt reached.
    // 3. Bactracking = A lines of code you want to execute only when your recursion call return itself is called backtracking.

    // 1. Write a program to print name n times:
    // int n;
    // string name;
    // cin>>name>>n;
    // printNameR(name,n);

    // 2. Write a program to print name n times using backtracking:
    // int n;
    // string name;
    // cin>>name>>n;
    // printNameB(name,n);

    // Note = 1. The line of code you write after base case and before recursion call is called recursion.
    // 2. The line of code you write after recursion call are called backtracking.


    // 3. Print 1 to n using recursion:
    // int n;
    // cin>>n;
    // printNR(1,n);

    // 4. Print n to 1 using recursion:
    // int n1;
    // cin>>n1;
    // cout<<endl;
    // printReverseNR(n1);

    // 5. Print 1 to n using recursion:
    // int n;
    // cin>>n;
    // printNB(n);

    // // 6. Print n to 1 using recursion:
    // int n1;
    // cin>>n1;
    // cout<<endl;
    // printReverseNB(1,n1);

    // 7. Sum of first n number using parameterized recursion:

    // int n;
    // cin>>n;
    // cout<<sumNR1(0,n)<<endl;

    // // 8. Sum of first n number using non-parameterized recursion:
    // int n1;
    // cin>>n1;
    // cout<<sumNR2(n1)<<endl;

    // 9. Factorial of a number:
    // int n;
    // cin>>n;
    // cout<<fact(n)<<endl;

    // 10. Reverse an array:
    // int size;
    // cin>>size;
    // int *arr=new int [size];
    // for(int i=0;i<size;i++) {
    //     cout<<"Please enter your "<<i+1<<" number:";
    //     cin>>arr[i];
    // }
    // reverseArr(arr,0,size-1);
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }

    // 11. Check the string is palindrome or not:
    // string str;
    // cin>>str;
    // cout<<isPalin(str,0,str.size()-1);

    // 12. nth fibonacci number:
    // int term;
    // cin>>term;
    // cout<<fibo(term)<<endl;



    return 0;
}
