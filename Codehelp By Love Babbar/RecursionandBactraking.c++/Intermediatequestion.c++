using namespace std;
#include <iostream>
#include <vector>
void subArr1(int arr[],int size,int index,vector<int>&ans){
    // Base Case:
    if(index==size){
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
        return;
    }

    ans.push_back(arr[index]);
    subArr1(arr,size,index+1,ans);
    ans.pop_back();
    subArr1(arr,size,index+1,ans);
}
void subArr2(int arr[],int size,int index,vector<int>&ans,int target){
    // Base Case:
    if(index==size || target==0){
        if(target==0){
            for(auto it:ans) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    if(arr[index]<=target){
        ans.push_back(arr[index]);
        subArr2(arr,size,index+1,ans,target-arr[index]);
        ans.pop_back();
    }
    subArr2(arr,size,index+1,ans,target);
}
bool subArr3(int arr[],int size,int index,vector<int>&ans,int s,int sum){
    // Base Case:
    if(index==size){
        if(sum==s){
            for(int it:ans) cout<<it<<" ";
            return true;
        }
        return false;
    }

    ans.push_back(arr[index]);
    sum=sum+arr[index];
    if(subArr3(arr,size,index+1,ans,s,sum)==true) return true;

    ans.pop_back();
    sum=sum-arr[index];
    if(subArr3(arr,size,index+1,ans,s,sum)==true) return true;

    return false;
}
int subArr4(int arr[],int size,int index,int s,int sum){
    // Base Case:
    if(index==size){
        if(sum==s) return 1;
        else return 0;
    }

    sum = sum+arr[index];
    int left=subArr4(arr,size,index+1,s,sum);
    sum=sum-arr[index];
    int right=subArr4(arr,size,index+1,s,sum);

    return left+right;
}
void merge(int *arr,int start,int mid,int end){
    vector<int>ans;
    int first=start;
    int last=mid+1;

    while (first<=mid && last<=end)
    {
        if(arr[first]<=arr[last]) {
            ans.push_back(arr[first]);
            first++;
        }
        else {
            ans.push_back(arr[last]);
            last++;
        }
    }

    while(first<=mid) {
        ans.push_back(arr[first]);
        first++;
    }
    while(last<=end){
        ans.push_back(arr[last]);
        last++;
    }

    for(int i=start;i<=end;i++){
        arr[i]=ans[i-start];
    }
}
void mergeArr(int *arr,int start,int end){
    // Base Case:
    if(start>=end) return;

    int mid=(start+end)/2;

    mergeArr(arr,start,mid);
    mergeArr(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int partition(int *arr,int start,int end){
    // Procedure 1:
    // int pivotIndex=start;
    // int i=start+1,j=end,count=0;
    // while(i<=j){
    //     if(arr[i]<=arr[pivotIndex]) count++;
    //     i++;
    // }
    // pivotIndex+=count;
    // swap(arr[start],arr[pivotIndex]);
    // i=start;
    // while(i<pivotIndex && j>pivotIndex){
    //     if(arr[i]<=arr[pivotIndex]) i++;
    //     else if(arr[j]>arr[pivotIndex]) j--;
    //     else swap(arr[i],arr[j]);
    // }
    // return pivotIndex;

    // Procedure 2:
    int pivot=arr[start];
    int i=start,j=end;
    while(i<j){
        while(i<=j && arr[i]<=pivot) i++;
        while(j>=i && arr[j]>=pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[start],arr[j]);
    return j;
}
void quickArr(int *arr,int start,int end){
    // Base Case:
    if(start>=end) return;

    int pIndex=partition(arr,start,end);

    quickArr(arr,start,pIndex-1);
    quickArr(arr,pIndex+1,end);
}
int main(){
    // 1. Print all the subsequence of an array using recursion=Basically subsquence can be the contigous or non-contigous part of the array which follow some particular order.
    // In this we basically follow the logic of trial room.
    // Recommended=Make a recursion tree in which left side is decised to take it and the right side decided to not take it.

    // int arr[3]={3,1,2};
    // vector<int>ans;
    // subArr1(arr,3,0,ans);

    // 2. Print all the subsequence of an array whose sum is equal to given s=A little bit change in the above approach instead of print every one we print only those whose sum is satisfied.

    int arr[4]={1,2,1,4};
    int s=2;
    vector<int>ans;
    subArr2(arr,4,0,ans,s);

    // 3. Print any of the one subsequence of an array whose sum is equal to given s=A little bit change in the above code to print only one pattern,we check in every recursion call is it satisfied or not if it is then no need to go further return from there.

    // int arr[3]={1,2,1};
    // int s=2;
    // vector<int>ans;
    // subArr3(arr,3,0,ans,s,0);

    // 4. Print count of all the subsequence of an array whose sum is equal to given s=A little bit change in the above code.Insted of printing you only need to count the total number of subsequence.

    // int arr[3]={1,2,1};
    // int s=2;
    // cout<<subArr4(arr,3,0,s,0)<<endl;

    // Note = 1. You only need to understand the first question and the pattern used to solve in that question rest of the question will be the similar.
    // 2. Pattern used left side take it right side note take it.
    // 3. Instead of using sum variable you can also directly subtract from the target value.

    // 5. Merge Sort:
    // int arr[]={1,9,8,7,6,5,4,3,2};
    // mergeArr(arr,0,8);
    // for(int i=0;i<9;i++) cout<<arr[i]<<" ";

    // 6. Quick Sort:
    // int arr[]={1,9,8,7,6,5,4,3,2};
    // quickArr(arr,0,8);
    // for(int i=0;i<9;i++) cout<<arr[i]<<" ";




    return 0;
}