using namespace std;
#include <iostream>
void get_element(int *ptr, int size)
{
    if (size != 0)
    {
        cout << "Please enter the element:";
    }
    for (int i = 0; i < size; i++)
    {
        cin >> *(ptr + i);
    }
}
void print_arr(int *ptr, int size)
{
    cout << "Your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
}
void reverse_arr(int *ptr, int size, int key)
{
    int i = key, j = size - 1;
    while (i < j)
    {
        int temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    // 1. Make a program in which you given an array of size n and also given a key position,you only need to reverse the array after the key position;
    // int size,key;
    // cout<<"Please enter size and the key position respectively:";
    // cin>>size>>key;
    // int arr[size];
    // get_element(arr,size);
    // reverse_arr(arr,size,key);
    // print_arr(arr,size);

    // 2. Make a program in which you given two sorted arrays of size n and m,also given that the first array are not completly filled you need to merge the second array in the first array and print sorted merge array.Duplicates can be exists.
    // case1 = if n ==0 and m<0;
    // case2 = if m<n;
    // case3 = if m>n;
    // case4 = if n == m;

    // Optimal Solution = With 3-pointer approach:
    // int n = 2, m = 4, size = n + m;
    // int arr1[size], arr2[m];
    // get_element(arr1, n);
    // get_element(arr2, m);

    // int i = (n == 0) ? 0 : (n - 1), j = m - 1, k = size - 1;
    // while (i >= 0 && j >= 0)
    // {
    //     if (arr1[i] > arr2[j])
    //     {
    //         arr1[k] = arr1[i];
    //         k--;
    //         i--;
    //     }
    //     else if (arr1[i] < arr2[j])
    //     {
    //         arr1[k] = arr2[j];
    //         j--;
    //         k--;
    //     }
    //     else
    //     {
    //         arr1[k] = arr2[j];
    //         j--;
    //         k--;
    //     }
    // }
    // print_arr(arr1, size);

    // 3. Make a program in which you given an array of size n,also given that some of the array element are zero you only need to separate the zeroes right side and rest of the element left side.
    // int size;
    // cout<<"Enter size:";
    // cin>>size;
    // int arr[size];
    // get_element(arr,size);

    // int j = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     if(arr[i]!=0){
    //         int temp = arr[i];
    //         arr[i] = arr[j];
    //         arr[j] = temp;
    //         j++;
    //     }
    // }
    // print_arr(arr,size);

    // 4. Make a program in which you given an array of size n,and also given the number of rotation.You only need to rotate the array element:
    // int size,rotations;
    // cout<<"Enter the size and the rotation respectively:";
    // cin>>size>>rotations;
    // int arr[size];
    // get_element(arr,size);

    // First Approach = Brute force
    // for (int i = 0; i < rotations; i++)
    // {   int temp = arr[size-1];
    //     for (int j = size-1; j >0; j--)
    //     {
    //         arr[j] = arr[j-1];
    //     }
    //     arr[0] = temp;
    // }
    // print_arr(arr,size);

    // Second Approach = Optimal Solutions:
    // int temp[size];
    // for (int i = 0; i < size; i++)
    // {
    //     temp[(i+rotations)%size] = arr[i];     // formula
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // print_arr(arr,size);

    // 5. Make a program to check whether the given array is sorted rotated or not:

    // case1 = 1,2,3,4,5    // sorted and rotated with 0
    // case2 = 4,5,1,2,3    // sorted and rotated with n
    // case3 = 1 6 3 4 2    // random element
    // case4 = 5 5 5 5 5    // same element sorted with n

    // int size =5;
    // int arr[size] = {1,6,3,4,2};
    // static int count;
    // for (int i = 1; i < size; i++)
    // {
    //     if (arr[i]<arr[i-1])
    //     {
    //         count++;
    //     }
    // }
    // if (arr[size-1]>arr[0])
    // {
    //     count++;
    // }

    // if(count<=1){
    //     cout<<"True"<<endl;
    // }
    // else{
    //     cout<<"False"<<endl;
    // }

    // 6. Make a program in which you given two array of size n and m,you need to add the element of two array and store sum in the another array and print them:
    // e.g. : (1 2 3 4)     // array1
    //            (2,2)     // array2
    //        (1 2 5 6)     // new array

    // Case1 = when arr1 is larger then arr2.
    // Case2 = When arr2 is larger then arr2.
    // Case3 = When arr1 and arr2 are equal handle the carry.

    // int n,m;
    // cout<<"Enter sizes:";
    // cin>>n>>m;
    // int arr1[n],arr2[m];
    // get_element(arr1,n);
    // get_element(arr2,m);

    // // Two pointer approach:
    // int i = n-1;
    // int j = m-1;
    // int carry = 0;
    // int temp[n+m];
    // static int count=0;
    // while (i>=0 && j>=0)
    // {
    //     int val1 = arr1[i];
    //     int val2 = arr2[j];

    //     int sum = val1+val2+carry;
    //     carry = sum/10;
    //     sum = sum%10;

    //     temp[count] = sum;
    //     i--;j--;
    //     count++;
    // }

    // // Handle case1:
    // while (i>=0)
    // {
    //     int sum = arr1[i]+carry;

    //     carry = sum/10;
    //     sum = sum%10;

    //     temp[count] = sum;
    //     i--;
    //     count++;
    // }

    // // Handle case2;
    // while (j>=0)
    // {
    //     int sum = arr2[j]+carry;

    //     carry = sum/10;
    //     sum = sum%10;

    //     temp[count] = sum;
    //     j--;
    //     count++;
    // }

    // // Handle case3:
    // while (carry!=0)
    // {
    //     int sum = carry;

    //     carry = sum/10;
    //     sum = sum%10;

    //     temp[count] = sum;
    //     count++;
    // }

    // reverse_arr(temp,count,0);
    // print_arr(temp,count);

    return 0;
}