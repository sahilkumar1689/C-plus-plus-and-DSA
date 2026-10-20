using namespace std;
#include <iostream>
#include <bits/stdc++.h>
void get_element(int *ptr, int size)
{
    cout << "Please enter the elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(ptr + i);
    }
}
void print_arr(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
}
int main()
{

    //  Unique elements question:
    // 1. Make a program in which every array elements is present in the duplicate form twice but out of it only one element is present unique find that element e.g. (1 2 1 3 2) in this 1 and 2 apperars twice and 3 apperars only single time find them:

    // First Approach: Optimal Solution
    // int size = 9;
    // int arr[size] = {1,2,1,3,2,3,8,-1,-1};  // input can be anything but it satisfy the above conditions.
    // int ans=0;
    // for (int i = 0; i < 9; i++)
    // {
    //     ans = ans^arr[i];    // xor operator make same bit zero,it means same element become zero.
    // }
    // cout<<ans<<endl;

    // Second Approach: Brute Force
    // bool temp[size] = {false};
    // for (int i = 0; i < size; i++)
    // {
    //     if (temp[i] == true)
    //     {
    //         continue;
    //     }
    //     int count=1;
    //     for (int j = i+1; j < size; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             temp[j] = true;
    //             count++;
    //         }
    //     }
    //     if (count == 1)
    //     {
    //         cout<<arr[i]<<endl;
    //         break;
    //     }
    // }

    // 2. Make a program in which you have a array with duplicate elements you need to count the occurance of each and every element and after that check if all the occurance is unique or not:
    // e.g. 1.(1,2,1,2,5) in this 1 and 2 occures 2 time and 5 occurs 1 time,so it is not unique.
    // 2. (1,2,1,1,2,5) in this 1 appears 3 time and 2 appears 2 times and 5 apperars 1 time,so it is unique:

    // Brute Force Solution:
    // int n,a=0,flag=0;
    // cout<<"Please enter the size:";
    // cin>>n;
    // int arr[n],temp[n];
    // bool flag_arr[n] = {false};
    // get_element(arr,n);
    // for (int i = 0; i < n; i++)
    // {
    //     if (flag_arr[i] == true)
    //     {
    //         continue;
    //     }
    //     int count =1;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             flag_arr[j] = true;
    //             count++;
    //         }
    //     }
    // temp[a] = count;
    // a++;
    // }
    // int i=0,j=a-1;
    // while (i<j)
    // {
    //     if (temp[i] == temp[j])
    //     {
    //         cout<<"Not unique";
    //         flag =1;
    //         break;
    //     }
    //     else if(temp[i] != temp[j]){
    //         j--;
    //     }
    //     if (j == i)
    //     {
    //         j = a-1;
    //         i++;
    //     }
    // }
    // if (flag == 0)
    // {
    //     cout<<"Unique";
    // }

    // Optimal Solution:
    // int n;
    // cout<<"Please enter the size of the array:";
    // cin>>n;
    // int arr[n];
    // map<int,int> mp;
    // get_element(arr,n);
    // for (int i = 0; i < n; i++)
    // {
    //     mp[arr[i]]++;
    // }
    // for (auto x:mp)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    // Find Duplicate elements questions:
    // 3. Make a program in which you have an a array of size n, but in the array you have elements from [1,n-1] apperars one time and out of them only one elements occurs twice find that duplicate element:

    // int n;
    // cout<<"Please enter the size:";
    // cin>>n;
    // int arr[n];
    // get_element(arr,n);           // Array must satisfy the above rule.

    // First Approach = It is the optimal solution:
    // int ans=0;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = ans^arr[i];
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     ans = ans^i;
    // }
    // cout<<ans<<endl;

    // It is also a optimal solution:
    // int temp[n] ={0};
    // for (int i = 0; i < n; i++)
    // {
    //     temp[arr[i]]++;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (temp[i]==2)
    //     {
    //         cout<<i<<endl;
    //         break;
    //     }
    // }

    // Second Method:
    // int temp[arr.size()] = {0};

    // for(int i = 0;i<arr.size();i++){
    //     temp[arr[i]]++;
    // }
    // for(int i = 0;i<arr.size();i++){
    //     if(temp[i]==2){
    //         return i;
    //     }
    // }

    // Second Approach = It is the brute force solution:
    // int temp;
    // for (int i = 0; i < n; i++)
    // {   int flag = 0;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             temp = arr[i];
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if (flag == 1)
    //     {
    //         break;
    //     }
    // }
    // cout<<temp<<endl;

    // 4. Make a program in which you gave an array of length n, but the elements of the array in the range of [1,n] or it can be appear one time or two time.You only need to find the twice elements:
    // int n;
    // cout<<"Please enter the size:";
    // cin>>n;
    // int arr[n];
    // get_element(arr,n);  // Array must satisfy the above rule.

    // Optimal Solution:
    // int temp[n+1] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     temp[arr[i]]++;
    // }
    // for (int i = 0; i < n+1; i++)
    // {
    //     if (temp[i] == 2)
    //     {
    //         cout<<i<<" ";
    //     }
    // }


    // Brute Force Solution:
    // int a = 0, temp[n];
    // for (int i = 0; i < n; i++)
    // {
    //     if(n == 1){
    //         exit(1);
    //     }
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             temp[a] = arr[i];
    //             a++;
    //         }
    //     }
    // }
    // print_arr(temp,n+1);

    // Intersection of the array question:
    // 5. Make a program in which you have two array both the array are in the non decreasing order and also the size of both array may be equak or not.You have to find the intersection of the two array:

    // First Approach = It is the optimal solution:
    // int n1,n2,i=0,j=0;
    // cout<<"Please enter the size of the first array:";
    // cin>>n1;
    // int arr1[n1];
    // get_element(arr1,n1);
    // cout<<"Please enter the size of the second array:";
    // cin>>n2;
    // int arr2[n2];
    // get_element(arr2,n2);
    // int a=0,temp[n1];

    // while (i<n1 && j < n2)
    // {
    //     if (arr1[i] == arr2[j])
    //     {
    //         temp[a] = arr1[i];
    //         a++;
    //         i++;
    //         j++;
    //     }
    //     else if(arr2[j] > arr1[i]){
    //         i++;
    //     }
    //     else if(arr1[i]> arr2[j]){
    //         j++;
    //     }
    // }
    // print_arr(temp,a);

    // Second Approach = It is the brute force solution:
    // int n1,n2;
    // cout<<"Please enter the size of the first array:";
    // cin>>n1;
    // int arr1[n1];
    // get_element(arr1,n1);
    // cout<<"Please enter the size of the second array:";
    // cin>>n2;
    // int arr2[n2];
    // get_element(arr2,n2);
    // int a=0,temp[n1];
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < n2; j++)
    //     {
    //         if (arr2[j] > arr1[i])
    //         {
    //             break;
    //         }
    //         if (arr1[i] == arr2[j])
    //         {
    //             temp[a] = arr1[i];
    //             arr2[j] = -1;
    //             a++;
    //             break;
    //         }
    //     }
    // }
    // print_arr(temp,a);

    // Pairs of the elements question:

    // 6. Make a program in which you have a array and key element.You need to find the pairs of the element whose sum is equal to the key element and print that pair:

    // int n, key;
    // cout << "Please enter the size of the array and key element:";
    // cin >> n >> key;
    // int arr[n];
    // get_element(arr, n);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (arr[i]+arr[j] == key)
    //         {
    //             if (arr[i]<arr[j])
    //             {
    //                 cout<<arr[i]<<" "<<arr[j]<<endl;
    //             }
    //             else{
    //                 cout<<arr[j]<<" "<<arr[i]<<endl;
    //             }
    //         }
    //     }
    // }

    // Optimal Solution:
    // int i = 0, j = i + 1;
    // while (i < n)
    // {
    //     if (arr[i] + arr[j] == key)
    //     {
    //         cout << arr[i] << " " << arr[j] << endl;
    //         if (j == n - 1)
    //         {
    //             i++;
    //             j = i + 1;
    //         }
    //     }
    //     else
    //     {
    //         if (j == n - 1)
    //         {
    //             i++;
    //             j = i + 1;
    //         }
    //     }
    //     j++;
    // }

    // 7. Triplet of the element question:

    // int n, key;
    // cout << "Please enter the size of the array and key element:";
    // cin >> n >> key;
    // int arr[n];
    // get_element(arr, n);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         for (int k = j+1; k < n; k++)
    //         {
    //             if (arr[i]+arr[j]+arr[k] == key)
    //             {
    //                 cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
    //             }
    //         }
    //     }
    // }

    // Optimal Solution:
    // int i = 0, j = i + 1, k = j + 1;
    // while (i < n)
    // {
    //     int flag = 0;
    //     if (arr[i] + arr[j] + arr[k] == key)
    //     {
    //         cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
    //         if (k == n - 1)
    //         {
    //             j++;
    //             k = j + 1;
    //         }
    //         if (k > n - 1)
    //         {
    //             i++;
    //             j = i + 1;
    //             k = j + 1;
    //             flag = 1;
    //         }
    //     }
    //     else
    //     {
    //         if (k == n - 1)
    //         {
    //             j++;
    //             k = j + 1;
    //         }
    //         if (k > n - 1)
    //         {
    //             i++;
    //             j = i + 1;
    //             k = j + 1;
    //             flag = 1;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         k++;
    //     }
    // }

    // Sort 0,1 question:

    // 8. Make a program in which you have a array with numbers of 0's and 1's and sort it and then print it:

    // Optimal Solution:
    // int n;
    // cout<<"Please enter the size of the array:";
    // cin>>n;
    // int arr[n];
    // get_element(arr,n);
    // int i = 0,j = n-1;
    // while (i<= j)
    // {
    //     if(arr[i] == 0){
    //         i++;
    //     }
    //     else if(arr[j] == 1){
    //         j--;
    //     }
    //     else{
    //         int temp = arr[i];
    //         arr[i] = arr[j];
    //         arr[j] = temp;
    //         i++;
    //         j--;
    //     }
    // }
    // print_arr(arr,n);

    // 9. Make a program in which you have a array in which you have number of 0's ,1's and 2's sort them and then print them:

    // Optimal Solution:
    // int n;
    // cout<<"Please enter the size of the array:";
    // cin>>n;
    // int arr[n];
    // get_element(arr,n);
    // int low =0,mid =0,high = n-1;
    // while (mid<=high)
    // {
    //     if(arr[mid] == 0){
    //         int temp = arr[low];
    //         arr[low] = arr[mid];
    //         arr[mid] = temp;
    //         low++;
    //         mid++;
    //     }
    //     else if(arr[mid] == 1){
    //         mid++;                               // 2 2 2 1 1 1 0 0 0 1
    //     }                                        // 0 0 0 1 1 1 1 2 2 2
    //     else{
    //         int temp = arr[high];
    //         arr[high] = arr[mid];
    //         arr[mid] = temp;
    //         high--;
    //     }
    // }
    // print_arr(arr,n);

    // 10. Make a program in which you have two array with size n and m,you have to sort the array in the following format:
    // e.g.: I/p1 = 1 2 3 3 2 1 4 5 7 8, I/p2 = 1 3 2 , O/p = 1 1 3 3 2 2 4 5 7 8
    // Second array element always present in the first array you have to sort the first array with respect to the second array element and remaing element will be same.

    // int size1,size2;
    // cout<<"Please enter your size:";
    // cin>>size1>>size2;
    // int arr1[size1],arr2[size2];
    // get_element(arr1,size1);
    // get_element(arr2,size2);

    // int i = 0;
    // int j = size1-1;
    // int k = 0;

    // while (k<=size2-1)
    // {
    //     if(arr1[i] == arr2[k]){
    //         i++;
    //     }
    //     if(arr1[j] == arr2[k]){
    //         int temp = arr1[j];
    //         arr1[j] = arr1[i];
    //         arr1[i] = temp;
    //         i++;
    //         j--;
    //     }
    //     else{
    //         j--;
    //     }
    //     if(i>=j){
    //         j= size1-1;
    //         k++;
    //     }
    // }
    // print_arr(arr1,size1);

    return 0;
}