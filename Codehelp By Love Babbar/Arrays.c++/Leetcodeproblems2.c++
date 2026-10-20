using namespace std;
#include <iostream>
#include <iomanip>
void get_element(int *ptr, int size)
{
    cout << "Please enter the element:" << endl;
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
int src_element(int *ptr, int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ptr[mid] == key)
        {
            return mid;
        }
        else if (ptr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int ispossible(int *arr, int size, int std, int mid)
{   
    int count=1;
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if (total + arr[i] <= mid)
        {
            total += arr[i];
        }
        else
        {
            count++;
            if (count> std || arr[i] > mid)
            {
                return 0;
            }
            total = arr[i];
        }
    }
    return 1;
}
void sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int isvalid(int *arr, int size, int cows, int mid)
{
    int count = 1;
    int first = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] - first >= mid)
        {
            count++;
            if (count == cows)
            {
                return 1;
            }
            first = arr[i];
        }
    }
    return 0;
}
int main()
{
    // 1. Make a program in which you given a array of size n and also the element of the array are in the monotonic form.You need to the first index and the last index of the key element in the array:
    // e.g. (1,2,2,2,3,3,4,5) ,key = 3, so the starting index is 3 and last index is 4:

    // int size,key,start,last;
    // cout<<"Please enter the size and the key element:";
    // cin>>size>>key;
    // int arr[size];
    // get_element(arr,size);
    // int i=0,j=size-1;
    // // Code to find the starting index:
    // while (i<=j)
    // {
    //     int mid = i+(j-i)/2;
    //     if (arr[mid] == key)
    //     {
    //         start = mid;
    //         j = mid-1;
    //     }
    //     else if (arr[mid] >key)
    //     {
    //         j = mid-1;
    //     }
    //     else{
    //         i = mid+1;
    //     }
    // }

    // // Code to find the last index:
    // i = start+1,j = size-1,last = start;
    // while (i<=j)
    // {
    //     int mid = i+(j-i)/2;
    //     if (arr[mid] == key)
    //     {
    //         last = mid;
    //         i = mid+1;
    //     }
    //     else if (arr[mid]>key)
    //     {
    //         j = mid-1;
    //     }
    //     else{
    //         i = mid+1;
    //     }
    // }

    // cout<<"Starting index of "<<key<<" is:"<<start<<endl;
    // cout<<"Ending index of "<<key<<" is:"<<last<<endl;

    // 2. Make a program in which you given a array of size n and also given that the elements of the array are in the monotonic form.You need to find the count of the key element in the given array:

    // To find the total number of the occurance firstly find the starting and the last index of the element from the above approach and after that use the below formula:
    // cout<<"Total number of ocurance are:"<<((last-start))+1<<endl;

    // 3. Make a program in which you given a array of size n and also given that the element of the array are in the mountain form.You need to find the peak element of the mountain array i.e. find the maximum element in the array:
    // e.g. (5 6 7 4 3 2 1) in this the peak element is 5:
    // Also do it for reverse mountain array and find the ground element:
    // e.g. (5 4 3 2 1 6 7 8) in this the ground element is 1:

    // Code for peak element:

    // First Approach:
    // int size = 7;
    // int arr[size] = {10,16,17,18,19,7,6,5};
    // int i = 0, j = size - 1;
    // while (i <= j)
    // {
    //     int mid = i + (j - i) / 2;
    //     if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    //     {
    //         cout << "Your peak element is " << arr[mid] << " present at " << mid << " index." << endl;
    //         break;
    //     }
    //     else if (arr[mid] < arr[mid + 1])
    //     {
    //         i = mid + 1;
    //     }
    //     else
    //     {
    //         j = mid - 1;
    //     }
    // }

    // Second Approach:
    // while (i<j)
    // {
    //     int mid = i+(j-i)/2;
    //     if (arr[mid]<arr[mid+1])
    //     {
    //         i = mid+1;
    //     }
    //     else{
    //         j = mid;
    //     }
    // }
    // cout<<i<<endl;

    // Code for ground element:

    // First Approach:
    // int size = 8;
    // int arr[size] = {8,7,5,4,3,2,1,6};
    // int i=0,j=size-1;
    // while (i<=j)
    // {
    //     int mid = i+(j-i)/2;
    //     if (arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
    //     {
    //         cout<<"Ground element is "<<arr[mid]<<" present at index "<<mid<<endl;
    //         break;
    //     }
    //     else if(arr[mid]>arr[mid+1]){
    //         i = mid+1;
    //     }
    //     else{
    //         j = mid-1;
    //     }
    // }

    // Second Approach:
    // while (i<j)
    // {
    //     int mid = i+(j-i)/2;
    //     if (arr[mid]>arr[mid+1])
    //     {
    //         i = mid+1;
    //     }
    //     else{
    //         j = mid;
    //     }
    // }
    // cout<<i<<endl;

    // 4. Make a program in which you given an array of size n,and also given that the array elements are in monotonic reverse order.You need to find the minimum and maximum pivot element from the array one by one:

    // Code for minimum pivot element:
    // int size=5;
    // int arr[size] = {5,1,2,3,4};
    // int i = 0,j = size-1;
    // while (i<j)
    // {
    //     int mid = i+(j-i)/2;
    //     if(arr[mid]>=arr[0]){
    //         i = mid+1;
    //     }
    //     else{
    //         j = mid;
    //     }
    // }
    // cout<<i;

    // Code for maximum pivot element:
    // while (i<j)
    // {
    //     int mid = i+(j-i)/2;
    //     if (arr[mid]>arr[0])
    //     {
    //         if (arr[mid]<arr[mid+1])
    //         {
    //             i = mid+1;
    //         }
    //         else{
    //             i = mid;
    //             j = mid;
    //         }
    //     }
    //     else if(arr[mid]==arr[0]){
    //         if (arr[mid]<arr[mid+1])
    //         {
    //             i = mid+1;
    //         }
    //         else{
    //             j = mid;
    //         }
    //     }
    //     else{
    //         j = mid-1;
    //     }
    // }
    // cout<<i<<endl;

    // 5. Make a program in which you given an array of size n,and also given that the array is the sorted rotated array.You have to find the key element in the array given by the user: 9 11 1 3 5 7

    // int size,key;
    // cout<<"Please enter the size and the key element:";
    // cin>>size>>key;
    // int arr[size];
    // get_element(arr,size);
    // int i=0,j= size-1;
    // First Approach:

    // Firstly find the minimum pivot element:
    // while (i<j)
    // {
    //     int mid = i +(j-i)/2;
    //     if (arr[mid]>=arr[0])
    //     {
    //         i = mid+1;
    //     }
    //     else{
    //         j = mid;
    //     }
    // }
    // int pivot = i;
    // if (key>=arr[pivot] && key<=arr[size-1])
    // {
    //    int a= src_element(arr,pivot,size-1,key);
    //    cout<<a<<endl;
    // }
    // else if(key >= arr[0] && key <= arr[pivot-1]){
    //     int a = src_element(arr,0,pivot-1,key);
    //     cout<<a<<endl;
    // }
    // else{
    //     cout<<"Your key element is out of range."<<endl;
    // }

    // Second Approach:
    // while (i<=j)
    // {
    //     int mid = i+(j-i)/2;
    //     if(arr[mid] == key){
    //         cout<<mid<<endl;
    //         break;
    //     }

    //     if(arr[i]<= arr[mid]){
    //         if(key>=arr[i] && key<arr[mid]){
    //             j = mid-1;
    //         }
    //         else{
    //             i = mid+1;
    //         }
    //     }
    //     else if(arr[mid]<= arr[j]){
    //         if(key>mid && key<=arr[j]){
    //             i = mid+1;
    //         }
    //         else{
    //             j = mid-1;
    //         }
    //     }
    // }

    // 6. Make a program in which you have to find the square root of the given number by using the binary search and after that also find the 2 fraction value by using the brute force solution:

    // int num,temp,precision;
    // cout<<"Please enter the number to find the square root:";
    // cin>>num;
    // cout<<"Please enter the precision you need:";
    // cin>>precision;
    // int i = 0,j = num;
    // // Code to find the square root of the number before fraction:
    // while (i <= j)
    // {
    //     int mid = i+(j-i)/2;
    //     int sqrt = mid*mid;
    //     if(sqrt== num){
    //         temp = mid;
    //         break;
    //     }
    //     else if(sqrt>num){
    //         j = mid-1;
    //     }
    //     else{
    //         temp = mid;
    //         i = mid+1;
    //     }
    // }
    // // Code to find the fraction value of the square root:
    // double ans = temp;
    // double factor = 1;
    // for (int i = 0; i < precision; i++)
    // {
    //     factor = factor/10;
    //     for (double j = ans; j*j < num; j += factor)
    //     {
    //         ans = j;
    //     }
    // }
    // cout<<fixed;
    // cout<<setprecision(2)<<"Square root of "<<num<<" is:"<<ans<<endl;

    // 7. Book Allocation Problem:
    // key line = Find the maximum of minimum number of pages allocated.
    // It means treat evey mid as maximum and condition is minimum.

    // int size, std;
    // cout << "Please enter the total number of books and the student respectively:";
    // cin >> size>>std;
    // int arr[size];
    // cout << "Please enter the pages of every book:" << endl;
    // get_element(arr, size);

    // Here we need to set our pointer between the (0 to sum of total number of elememnt):
    // int i = 0,sum = 0, j;
    // for (int i = 0; i < size; i++)
    // {
    //     sum += arr[i];
    // }
    // j = sum;

    // Here now we need to find the mid by using binary search in every iteration and check if it is valid solution of not,if valid store it and check in below aray but if not check in the further remainig array:
    //     int ans;
    //     while (i <= j)
    //     {
    //         int mid = i + (j - i) / 2;
    //         int flag = ispossible(arr, size, std, mid);
    //         if (flag == 1)
    //         {
    //             ans = mid;
    //             j = mid - 1;
    //         }
    //         else
    //         {
    //             i = mid + 1;
    //         }
    //     }
    //     cout<<ans<<endl;

    //     return 0;
    // }

    // Note  = In this type of question concept does'nt matters,procedure matters.So if any question statement says find the maximum of minimum, then you need to use the same procedure used in book allocation problem but only the values or statement will be change.


    // 8. Aggressive Cows:
    // Key line = Find the minimum of maximum distance between two cow's.
    // It means treat every mid as minimum and condition is maximum.

    int stall, cows;
    cout << "Please enter the total number of stalls and the cows respectively:";
    cin >> stall >> cows;
    int arr[stall];
    cout << "Please enter the stall number" << endl;
    get_element(arr, stall);
    sort(arr, stall);

    // Here range lies between (0 to maximum element present in the array);
    int i = 0, j = arr[stall - 1];

    // Here we find the mid element with the help of binary search and after that chek if mid is valid then move the pointer to forward because in this we want to find the maximum distance else move pointer to forward:
    int ans;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (isvalid(arr, stall, cows, mid))
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
