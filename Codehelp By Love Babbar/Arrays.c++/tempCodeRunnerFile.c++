using namespace std;
#include <iostream>
void print_arr(int *arr,int size){
    cout<<"Your array is:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
// Uncomment when use:
// void merge1(int *arr,int s,int mid,int e){
//     // Initialize pointers:
//     int i = s;
//     int j = mid+1;
//     int k = s;
//     // Find the total size of the array:
//     int totalsize = e+1  // becauce (e) is the last index value,so (e+1) gives the actual size.
//     int *temp = new int[e+1];

//     // Start compairing and copying in the temp array:
//     while (i<=mid && j<=e)
//     {
//         if (arr[i]<=arr[j])
//         {
//             temp[k] = arr[i];
//             k++;i++;
//         }
//         else{
//             temp[k] = arr[j];
//             k++;j++;
//         }
//     }
//     // Remaining element copying:
//     while (i<=mid)
//     {
//         temp[k] = arr[i];
//         k++;
//         i++;
//     }
//     while (j<=e)
//     {
//         temp[k] = arr[j];
//         k++;
//         j++;
//     }
//     // Copy temp element in the actual array:
//     for (int i = s; i <=e; i++)
//     {
//         arr[i] = temp[i];
//     }
//     // Free up space:
//     delete []temp;
// }
// void merge2(int *arr,int start,int mid,int end){
//     // Find the size of the arr before and after mid:
//     int size1 = mid-start+1;
//     int size2 = end-mid;
//     // Make temp array:
//     // int *temp1 = new int [size1];    // Uncomment when use
//     // int *temp2 = new int [size2];    
//     // Initialize the pointers:
//     int arrstart1 = start;
//     int arraftermid = mid+1;
//     // Copying the values:
//     for (int i = 0; i < size1; i++)
//     {
//         temp1[i] = arr[arrstart1++];
//     }
//     for (int i = 0; i < size2; i++)
//     {
//         temp2[i] = arr[arraftermid++];
//     }
//     // Start Comparing and store in the main array:
//     int i=0,j=0,arrstart2 = start;
//     while (i<=size1-1 && j <=size2-1)
//     {
//         if (temp1[i]<=temp2[j])
//         {
//             arr[arrstart2] = temp1[i];
//             arrstart2++;
//             i++;
//         }
//         else{
//             arr[arrstart2] = temp2[j];
//             arrstart2++;
//             j++;
//         }
//     }
//     // Copy remaining element:
//     while (i<=size1-1)
//     {
//         arr[arrstart2] = temp1[i];
//         arrstart2++;
//         i++;
//     }
//     while (j<=size2-1)
//     {
//         arr[arrstart2] = temp2[j];
//         arrstart2++;
//         j++;
//     }
//     // Free the up space:
//     delete []temp1;
//     delete []temp2;  
// }
// void mergeSort1(int *arr,int i,int j){
//     // Base case:
//     if (i>=j)
//     {
//         return ;
//     }
//     int mid = i+(j-i)/2;
//     mergeSort1(arr,i,mid);
//     mergeSort1(arr,mid+1,j);

//     merge1(arr,i,mid,j);
// }
// void mergeSort2(int *arr,int i,int j){
//     // Base case:
//     if (i>=j)
//     {
//         return;
//     }
//     int mid = i+(j-i)/2;
//     mergeSort2(arr,i,mid);
//     mergeSort2(arr,mid+1,j);

//     merge2(arr,i,mid,j); 
// }
int partition(int *arr,int i,int j){
    int pivot = arr[i];
    int count = 0;
    // Count the smaller element than pivot.
    for (int k = i+1; k <j; k++)
    {
        if (arr[k]<=pivot)
        {
            count++;
        }
    }
    // Swap at pivot index:
    int pivotIndex = i+count;
    swap(arr[i],arr[pivotIndex]);
    
    int start = i,end = j;
    while (start<pivotIndex && end>pivotIndex)
    {
        if(arr[start]<=pivot){
            start++;
        }
        else if(arr[end]>pivot)
        {
            end--;
        }
        else{
            swap(arr[start],arr[end]);
            start++;
            end--;
        } 
    }
    return pivotIndex;  
}
void quickSort(int *arr,int i,int j){
    // Base case:
    if (i>=j)
    {
        return;
    }
    int p= partition(arr,i,j);

    quickSort(arr,i,p-1);
    quickSort(arr,p+1,j);
    
}
void countSort(int *arr,int size){
    // Find the maximum element of the array so that we know the size of the temp arary.
    int maxi=arr[0];
    for (int i = 1; i < size; i++)
    {
        if (maxi<arr[i])
        {
            maxi = arr[i];
        }
    }
    // Make a temp array = Space Complexity = O(n+k):
    int k  = maxi+1;        // maxi+1 think about it.Dry run with hashing technique.
    int temp[k] = {0};      // O(k)  where k is the maximum element.
    int b[size];            // O(n)

    // Hashing technique:
    for (int i = 0; i < size; i++)
    {
        temp[arr[i]]++;
    }
    // Update the temp array with the actual size:
    for (int i = 1; i <=k-1; i++)
    {
        temp[i] += temp[i-1];
    }
    // Make sorted array:
    for (int i =size-1; i >=0 ; i--)
    {
        b[--temp[arr[i]]]=arr[i];
    }
    // Copy in the main array:
    for (int i = 0; i < size; i++)
    {
        arr[i]=b[i];
    }   
}
void RcountSort(int *arr,int size,int pos){
    int count[10] = {0};
    int b[size];

    for (int i = 0; i < size; i++)
    {   
        count[(arr[i]/pos)%10]++;
    }
    for (int i = 1; i <=9; i++)
    {   
        count[i] += count[i-1];
    }
    for (int i =size-1; i >=0; i--)
    {
        b[--count[(arr[i]/pos)%10]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = b[i];
    }   
}
void radixSort(int *arr,int size){
    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (maxi<arr[i])
        {
            maxi = arr[i];
        } 
    }
    cout<<maxi<<endl;
    for (int pos = 1; maxi/pos>0; pos*=10)
    {
        RcountSort(arr,size,pos);
    } 
}
int main(){
    // Sorting = It means the arrangement of element in the ordered sequence either in the increasing order or either in the decreasing order.We have numbers of sorting algorithms but the only difference between all of them is the amount of space and time they consume while being running in the program.
    
    // C++ has its own function of sorting which used intosort technique to sort the element.The intro sort is the combination of different algorithm,they start with quicksort and switches to heapsort.This intosort guaranteeing a worst-case time complexity is O(n*logn).

    // Some of the mostly used sorting algorithms are:
    // 1. Selection Sort.
    // 2. Bubble Sort.
    // 3. Insertion Sort.
    // 4. QuicK Sort.
    // 5. Merge Sort.
    // 6. Counting Sort.
    // 7. Radix Sort.
    // 8. Heap Sort.

    // Now these algorithms classified into following categories:
    // 1. In-place and Out-place sorting = In in-place sorting there is no need to aquier the extra space. e.g.: Selection Sort,Bubble Sort,Insertion Sort,Quick Sort,Heap sort,etc.
    // In out-place sorting there is a need to aquier the extra space.e.g.:Merge Sort,Counting Sort,Radix Sort,etc.

    // 2. Stable and Unstable = A sorting algorithm is said to be stable,if the order of two same elements in the unsorted array and in the sorted array will be same.
    // e.g.: Bubble Sort,Insertion Sort,Merge Sort,Counting Sort,Radix Sort,etc.
    // A sorting algorithm is said to be unstable,if the order of two same elements in the unsorted array and in the sorted array will not be same.
    // e.g.: Selection Sort,Quick Sort,Heap Sort,etc.

    // 3. Adaptive or Non-adaptive = A sorting algorithm is said to be adaptive,if the numbers of element in the array affects the time complexity of the algorithm.
    // e.g.:Bubble Sort,Insertion Sort,Quick Sort,etc.
    // A sorting algorithm is said to be non-adaptive,if the numbers of element in the array does'nt affects the time complexity of the algorithm.
    // e.g.:Selection Sort,Merge Sort,Radix Sort,Heap Sort,etc.


    // 1. Selection Sort =
    // Procedure = 1. Run upper loop from (i=0 to <n-1).
    // 2. Run inner loop from (j=i+1 to <n).
    // 3. Inside Conditions:
    //      1. if(arr[i]>arr[j])then swap(arr[i],arr[j]);

    // e.g.:
    // int arr[10] = {1,6,5,4,3,2,7,8,9,10};
    // int size = 10;

    // for (int i = 0; i < size-1; i++)
    // {   int minelem = i;
    //     for (int j =i+1; j < size; j++)
    //     {
    //         if (arr[i]>arr[j])
    //         {   
    //             minelem = j;    // swap (arr[i],arr[j]) you can also use this directly.
    //         }
    //     }
    //     swap(arr[i],arr[minelem]);
    // }
    // print_arr(arr,size);

    // Time complexity is = O(n^2) [In every case best case,worst case,average case].
    // Space complexity is = O(1).


    // 2. Bubble Sort = 
    // Procedure = 1. Run upper loop till (i=0 to <n-1).
    // 2. int flag = 0;
    // 3. Run inner loop till (j = 0 to <n-i-1).
    // 4. Inside Conditions:
    //      1. if(arr[j]>arr[j+1]) then swap(arr[j],arr[j+1]).
    //      2. flag==1;
    // 5. End of upper loop if(!flag) then break;

    // e.g.:

    // int arr[10] = {1,6,5,4,3,2,7,8,9,10};
    // int n = 10;

    // for (int i = 0; i < n-1; i++)
    // {
    //     int flag =0;
    //     for (int j = 0; j < n-i-1; j++)
    //     {
    //         if (arr[j]>arr[j+1])
    //         {
    //             swap(arr[j],arr[j+1]);
    //             flag=1;
    //         }
    //     }
    //     if (!flag)
    //     {
    //         break;
    //     }  
    // }
    // print_arr(arr,n);
    
    // Time complexity is = O(n^2) [In worst and average case]. But in the best case O(n).
    // Space complexity is = O(1).
    

    // 3. Insertion Sort = 
    // Procedure = 1. Run upper loop till (i=1 to <n).
    // 2. in temp = arr[i];
    // 3. Run either inner for or while loop till (j=i-1 to >=0 && arr[j]>temp).
    // 4. Inside conditions:
    //      1. arr[j+1] = arr[j];
    //      2. j--;
    // 5. End of upper loop arr[j+1] = temp;

    // int arr[10] = {1,6,5,4,3,2,7,8,9,10};
    // int n = 10;

    // for (int i = 1; i < n; i++)
    // {
    //     int temp = arr[i];
    //     int j = i-1;
    //     // You can also use for loop:
    //     // for (j; j >= 0 && arr[j]>temp; j--)
    //     // {
    //     //     arr[j+1] = arr[j];
    //     // }
    //     while (j>=0 && arr[j]>temp)
    //     {
    //         arr[j+1] = arr[j];
    //         j--;
    //     }
    //     arr[j+1] = temp;
    // }
    // print_arr(arr,n);

    // Time complexity is = O(n^2) [In worst and average case]. But in the best case O(n).
    // Space complexity is = O(1).


    // 4. Merge Sort = It is defined as the preocess in which we divide the array in two halfs then sort each half after that merge both sorted half together to form the merge sorted array.

    // First Approach:
    // Procedure = 1.Call the mergesort function send arguments (arr,start,end);
    // 2. Inside merge sort:
    //      1. Base case is = if(start>=end) then return.
    //      2. find mid.
    //      3. First recursive call with arguments (arr,start,mid).
    //      4. Second recursive call with arguments (arr,mid+1,end).
    //      5. call merge funtion with arguments(arr,start,mid,end).
    // 3. Inside merge function:
    //      1. int i = start,j=mid+1,k=start.
    //      2. int *temp = new int[end+1].
    //      3. Run while till (i<=mid && j<=end).
    //      4. Inide while:
    //          1. if(arr[i]<arr[j]) then temp[k++] = arr[i++].
    //          2. else then temp[k++] = arr[j++];
    //      5. Run while till (i<=mid) then temp[k++] = arr[i++];
    //      6. Run while till (j<=end) then temp[k++] = arr[j++];
    //      7. Run for loop till (i=start to <= end) then arr[i] = temp[i];
    //      8. delete []temp;

    // Recommendation = Draw recursive tree for better understanding.

    // int arr[10] = {1,6,5,4,3,2,7,8,9,10};
    // int n = 10;

    // mergeSort1(arr,0,n-1);
    // print_arr(arr,n);

    // Second Approach:
    // Procedure = 1.Call the mergesort function send arguments (arr,start,end);
    // 2. Inside merge sort:
    //      1. Base case is = if(start>=end) then return.
    //      2. find mid.
    //      3. First recursive call with arguments (arr,stat,mid).
    //      4. Second recursive call with arguments (arr,mid+1,end).
    //      5. call merge funtion with arguments(arr,start,mid,end).
    // 3. Inside merge function:
    //      1. int size1 = mid-start+1,size2 = end-mid.
    //      2. Create two temp array by using the above size.
    //      3. int start1 = start,start2 = mid+1.
    //      4. Run loop from (i=0 to <start1) then temp1[i] = arr[start1++].
    //      5. Run loop from (i=0 to <start2) then temp2[i] = arr[start2++].
    //      6. int i=0,j=0,start3=start.
    //      7. Run while till (i<=size1-1 && j<=size2-1)
    //      8. Inide while:
    //          1. if(temp1[i]<temp2[j]) then arr[start3++] = temp1[i++].
    //          2. else then arr[start3++] = temp2[j++].
    //      9. Run while till (i<=size1-1) then arr[start3++] = temp1[i++].
    //      10. Run while till (j<=size2-1) then arr[start3++] = temp2[j++].
    //      11. delete []temp1;
    //      12. delete []temp2;

    // mergeSort2(arr,0,n-1);
    // print_arr(arr,n);

    // Time complexity is = O(nlogn) [In average case and best case,worst case]
    // Space complexity is = O(n).

    // To know application,advantages and disadvantages visit gfg.


    // 5. Quick Sort = It is a sorting algorithm which follow the divide and conquer technique to sort the element.
    // Procedure = 1. Make a quickSort function with parameters (arr,i,j).
    // 2. Inside quickSort:
    //      1. Base case if(i>=j)then return.
    //      2. int p = partition(arr,i,j).
    //      3. First recursive call quickSort(arr,i,p-1).
    //      4. Second recursive call quickSort(arr,p+1,j).
    // 3. Inside Partition:
    //      1. int pivot = arr[i],count=0.
    //      2. Run for loop till (k=0 to <= j).
    //      3. int pivotIndex = i+count.
    //      4. Swap(arr[i],arr[pivotIndex]).
    //      5. int s=i,e=j.
    //      6. Run while till (i<pivotIndex && j>pivotIndex).
    //      7. Inside while:
    //          1. if(arr[s]<=pivot)then s++.
    //          2. else if(arr[e]>pivot) then j--.
    //          3. else then swap(arr[s],arr[e]) then s++;j--.
    //      8. Return pivotIndex.

    int arr[8] = {12,13,11,12,13,12,11,12};
    int n = 8;

    quickSort(arr,0,n-1);
    print_arr(arr,n);

    // Time complexity is = O(nlogn) [In average case and best case].But in worst case is O(n^2).
    // Space complexity is = O(1).

    
    // 6. Counting Sort = All the other sorting algorithms use the comparison technique to sort the array,but the counting sort and the radix sort use special technique called counting technique to sort the array element.

    // Procedure = 1. Find the maximum element present in the array.
    // 2. Make a two temp array first array of size (maximum element+1) and initially {0} and second array of size is equal to the actual array size.
    // 3. Run loop from (i=0 to < actual size) inside temp1[arr[i]]++;
    // 4. Run loop from (i=1 to <=maximum element) inside temp1[i]+= temp1[i-1];
    // 5. Run loop from (i= actual size-1 to >=0) inside temp2[--temp1[arr[i]] = arr[i];
    // 6. Run loop from (i=o to < actual size) inide arr[i] = temp2[i];


    // int arr[10] = {1,9,8,7,5,1,2,3,4,5};
    // int n = 10;

    // countSort(arr,n);
    // print_arr(arr,n);

    // Time complexity is = O(n+k) [In average case and best case and worst case].
    // Space complexity is = O(n+k) == O(n) [Where k is the maximum element in the array.]

    // To know the drawback visit gfg.

    // 7. Radix Sort = Radix sort is used to overcome the disadvatages of counting sort.Radix sort use counting sort but some modification.

    // Procedure = 1. Find the maximum element of the array.
    // 2. Run for loop from (pos=1 to maxi/pos >0 and pos*=10) inside rcountSort(arr,size,pos);
    // 3. Inside rcountSort:
    //      1. int count[10]={0},b[size].
    //      2. Run loop from (i=0 to<size) indise count[(arr[i]/pos)%10]++.
    //      3. Run loop form (i=1 to <=9) inside count[i] += count[i-1].
    //      4. Run loop from (i=size-1 to >=0) inside b[--count[(arr[i]/pos)%10)]]=arr[i].
    //      5. Run loop from (i=0 to <size) inside arr[i]= b=[i].


    // int arr[10] = {11,119,81,7420,534,101,201,304,405,507};
    // int n = 10;

    // radixSort(arr,n);
    // print_arr(arr,n);

    // Time complexity is = O(nk) [In average case and best case and worst case].
    // Space complexity is = O(n+k) [Where k is the maximum element digits in the array.]









    return 0;
}