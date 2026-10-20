using namespace std;
#include <iostream>
int fibo(int n){
    // Base Condition:
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    // Recursive Relation:
    return fibo(n-1)+fibo(n-2);
}
int countStairs(int n){
    // Base Case:
    if (n<0)
    {
        return 0;
    }
    if (n==0)
    {
        return 1;
    }
    
    // Recursive Relation:
    return countStairs(n-1)+countStairs(n-2);
}
void say_digit(int digit,string *ptr){
    // Base case:
    if (digit == 0)
    {
        return;
    }

    int last = digit%10;

    say_digit(digit /= 10,ptr); 

    cout<<ptr[last]<<" ";         // Now we print after the recursive relation because of stack call we need to print in the forward manner not the reverse.
    
}
bool is_sorted(int *arr,int size){

    // Base Case:
    if (size == 0 || size == 1)
    {
        return true;
    }

    // Calculation:
    if (arr[0]>arr[1])
    {
        return false;
    }
    else{
        bool ans = is_sorted(arr+1,size-1);
        return ans;
    }
}
int total(int *arr,int size){

    // Base condition:
    if (size == 0)
    {
        return 0;
    }

    // Calculation:
    int sum = arr[0]+total(arr+1,size-1);
    return sum;

    // return arr[size-1]+total(arr,size-1);
}
bool is_present(int *arr,int size,int key){
    // Base case:
    if (size == 0)
    {
        return false;
    }
    // Calculation:
    if (arr[0]== key)
    {
        return true;
    }
    return is_present(arr+1,size-1,key); 
}
bool binary_recur(int *arr,int i,int j,int key){
    // Base case:
    if(i>j){
        return false;
    }

    int mid = i+(j-i)/2;

    if (arr[mid]== key)
    {
        return true;
    }
    else if (arr[mid]<key)
    {
        return binary_recur(arr,mid+1,j,key);
    }
    else{
        return binary_recur(arr,i,mid-1,key);
    }
}
void reverse_str(string &str,int i,int j){

    // Base case:
    if (i>j)
    {
        return ;
    }
    // Calculation:
    swap(str[i],str[j]);
    reverse_str(str,i+1,j-1);
}
bool check_palin(string &str,int i,int j){
    // Base case:
    if (i>j)
    {
        return true;
    }
    // Calculation:
    if (str[i]!=str[j])
    {
        return false;
    }
    else{
        return check_palin(str,i+1,j-1);
    } 
}
int get_pow(int num,int pow){
    // Base case:
    if (pow == 0)
    {
        return 1;
    }
    if (pow ==1)
    {
        return num;
    }
    
    // Calculation:
    int ans = get_pow(num,pow/2);

    if (pow&1)
    {
        return num*ans*ans;
    }
    else{
        return ans*ans;
    }
}
int get_peak(int *arr,int i,int j){
    // Base case:
    if (i==j)
    {
        return i;
    }

    // Calculation:
    int mid = i+(j-1)/2;
    if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
    {
        return arr[mid];
    }
    else if (arr[mid]<arr[mid+1])
    {
        return get_peak(arr,mid+1,j);
    }
    else{
        return get_peak(arr,i,mid-1);
    }  
}
int get_pivot(int *arr,int i,int j){
    // Base case:
    if (i==j)
    {
        return arr[i];
    }
    // Calculation:
    int mid = i+(j-i)/2;

    if (arr[mid]>=arr[0])
    {
        return get_pivot(arr,mid+1,j);
    }
    else{
        return get_pivot(arr,i,mid);
    }   
}
int main(){
    // 1. Recursion = Any function which call itself is called recursion.In recursion a function solves the problem by calling a copy of itself which handle the smaller problem.This sequence of calling the function for smaller problem eventually converges on a base case.

    // Steps of recursive approach:
    // 1. Base case = It is necessary in order to terminate the program.
    // 2. Recursive Relation = It is necessary to call itself on a comparitively smaller problem.
    // 3. Calculation = It is optional step you may be included or not according to the requirenment of the question.It can be added before or after to the recursive relation call depending upon the question.

    // Note = 1. Make recursive tree for better understanding.
    // 2. Stack calls.

    // 1. Fibonacci nth term and also print the series:
    // int n,result;
    // cin>>n;
    // for (int i = 1; i <=n; i++)
    // {
    //     result = fibo(i);
    //     cout<<result<<" ";
    // }
    // cout<<endl<<result;

    // // 2. Climb Stairs = Condition you can climb one or two steps,you need to find the total number of possible ways:
    // int stairs;
    // cin>>stairs;

    // int b = countStairs(stairs);
    // cout<<b<<endl;

    // 3. Say numbers = You given a digit you only need to print each digit one by one.
    // e.g.: I/p = 789 , O/p = Seven Eight Nine

    // int digit;
    // cin>>digit;
    // string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    // say_digit(digit,arr);
    // cout<<endl;

    // 4. Make a program to check whther the given array is sorted or not by using recursion:
    // int arr[7] = {1,2,3,4,5,6,7};
    // int size = 7;

    // bool ans = is_sorted(arr,size);
    // if (ans)
    // {
    //     cout<<"True"<<endl;
    // }
    // else{
    //     cout<<"False"<<endl;
    // }

    // 5. Make a program to find the sum of the array element by using recursion:

    int arr[5] = {1,2,3,4,5};
    int size = 5;

    int ans = total(arr,size);
    cout<<ans<<endl;

    // 6. Make a program to search the key element in the array using recursion:
    // int arr[7] = {1,2,3,4,5};
    // int size = 7;
    // int key = 6;

    // bool ans = is_present(arr,size,key);
    // cout<<ans<<endl;

    // 7. Make a program to reverse the string using recursion:
    // string str;
    // cin>>str;

    // reverse_str(str,0,str.size()-1);
    // cout<<"After reverse:"<<str<<endl;

    // 8. Make a program to check whether the given string is palindrome or not by using recursion:
    // string str;
    // cin>>str;

    // bool ans = check_palin(str,0,str.size()-1);
    // cout<<ans<<endl;

    // 9. Make a program to find the power of a given number:
    // int num,pow;
    // cin>>num>>pow;

    // int ans = get_pow(num,pow);
    // cout<<ans<<endl;



    // 2. Binary Search with Recursion = It is also called divide and conquere technique.

    // 1. Make a program to find the key element by using binary search with recursion:
    // int arr[7] = {1,2,3,4,5,6,7};
    // int size = 7;
    // int key = 5;

    // bool ans = binary_recur(arr,0,size-1,key);
    // cout<<ans<<endl;

    // 2. Find the peak element in the mountain array using recursion:
    // int arr[5] = {2,3,4,5,1};
    // int size = 5;
    
    // int ans = get_peak(arr,0,size-1);
    // cout<<"Peak element is:"<<ans<<endl;

    // 3. Find the minimum pivot element in the sorted rotated array using recursion:
    // int arr[5] = {3,4,5,1,2};
    // int size = 5;

    // int ans = get_pivot(arr,0,size-1);
    // cout<<"Pivot element is:"<<ans<<endl;
    
    


    return 0;
}