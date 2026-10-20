using namespace std;
#include <iostream>
#include<queue>
#include<vector>
int main()
{
    // 1. Kadane's Algorithm = It is used to find the maximum sum of subarray elements in the array.In this there is no any subarray size given so we need to consider the all sizes of subarray.

    // Procedure:
    // 1. sum = sum +arr[i];
    // 2. maxi = max(maxi,sum);
    // 3. if (sum < 0) then sum=0;

    // e.g.:
    // 1. Make a program to find the maximum sum of subarray element:
    // int size = 5;
    // int arr[size] = {-1,2,-1,3,5};

    // int sum = 0, maxi = INT_MIN;
    // for (int i = 0; i < size; i++)
    // {
    //     sum = sum + arr[i];
    //     maxi = max(maxi,sum);
    //     if(sum <0){
    //         sum =0;
    //     }
    // }
    // cout<<"Maximum sum of subarray is:"<<maxi<<endl;

    // 2. Dutch flag algorithm = It is also called 0,1,2 sort algorithm.IN this type of question our array contains only three values of element and we have to sort it,so it can be easy sorted by ductch flag algorithm,we only need to used three pointer approach and find the condition to move them.

    // e.g.:
    // 1. Make a program to sort the array of elements 0,1,2:

    // int size = 10;
    // int arr[size] = {1,0,1,2,2,2,1,1,0,1};

    // int i=0,j=0,k=size-1;
    // while (j<k)
    // {
    //     if(arr[j]==0){
    //         swap(arr[j],arr[i]);
    //         i++;
    //     }
    //     else if(arr[j]==1){
    //         j++;
    //     }
    //     else{
    //         swap(arr[j],arr[k]);
    //         k--;
    //     }
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    // 3. Sliding Windows Algorithm = It is an algorithm used in array and string,it is used to solve the question in which we need to handle the subarray of the elements according to some given conditions.It reduced the time complexity from O(n^2) to O(n).
    // Types = 1. When window size can be fixed or given.
    // 2. When we need to vary the window size according to some conditions i.e. no fixed window size given.

    // Some Problems:

    // 1. Fixed Window Size:

    // 1. Maximum sum of subarray in the kth window size:

    // int window_size;
    // cout<<"Please enter the window size:";
    // cin>>window_size;
    // int size = 4;
    // int arr[size] = {100,200,300,400};

    // int i =0,j =window_size-1,sum=0,maxi = INT_MIN;

    // First Approach:
    // while (j<=size)
    // {
    //     if (j <= window_size-1)
    //     {
    //         sum = sum +arr[j];
    //         j++;
    //     }
    //     else{
    //         maxi = max(maxi,sum);
    //         sum = sum + arr[j];
    //         sum = sum -arr[i];
    //         i++;
    //         j++;
    //     } 
    // }

    // Second Approach:
    // while (i<=j)
    // {
    //    sum += arr[i];
    //    i++;
    // }
    // maxi = max(maxi,sum);
    // while (i<=size-1)
    // {
    //     sum += arr[i];
    //     sum -= arr[j-1];
    //     maxi = max(maxi,sum);
    //     i++;j++;
    // }
    // cout<<maxi<<endl;
    

    // 2. Make a program to print first maximum element in every k size window:

    // int window_size,size=5;
    // cout<<"Enter window size:";
    // cin>>window_size;

    // int arr[size] = {-8,3,2,-4,5};
    // queue<int> qu;
    // vector<int> v;

    // for (int i = 0; i < window_size-1; i++)
    // {   
    //     if (arr[i]<0)
    //     {
    //         qu.push(arr[i]);
    //     }
    // }
    // for (int i = window_size-1; i <=size-1; i++)
    // {
    //     if (arr[i]<0)
    //     {
    //         qu.push(arr[i]);
    //     }
    //     if (!qu.empty())
    //     {
    //         v.push_back(qu.front());
    //         if (qu.front()==arr[i-window_size+1])
    //         {
    //             qu.pop();
    //         }   
    //     }
    //     else{
    //         v.push_back(0);
    //     }
    // }
    // for(int i:v)cout<<i<<" ";
    
    

    return 0;
}