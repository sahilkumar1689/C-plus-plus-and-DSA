using namespace std;
#include <bits/stdc++.h>

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {

        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(vector<int> &arr, int start, int mid, int end)
{

    // Creating the new array:
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy the element in the array:
    int tempStart = start;
    int tempMid = mid + 1;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[tempStart++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[tempMid++];
    }

    // Apply merge two sorted array logic:

    int i = 0, j = 0;
    tempStart = start;

    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
        {
            arr[tempStart++] = first[i++];
        }
        else
        {
            arr[tempStart++] = second[j++];
        }
    }

    // Store the remiang element if left behind:
    while (i < len1)
    {
        arr[tempStart++] = first[i++];
    }

    while (j < len2)
    {
        arr[tempStart++] = second[j++];
    }

    // Free up space:
    delete[] first;
    delete[] second;
}

void mergeSort(vector<int> &arr, int start, int end)
{
    // Base Case:
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] <= pivot)
            i++;
        else if (arr[j] > pivot)
            j--;
        else
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end)
{
    // Base Case:
    if (start >= end)
        return;

    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

void printArr(vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};

    // 1. Working of bubble sort is completly depends upon finding the maximum and bubble it to the end.
    // bubbleSort(arr);

    // 2. Working of selection is completly depends upon selecting the minimum value and place it to the actual posisiton.
    // selectionSort(arr);

    // 3. Working of the insertion sort is completely depends upon inserting the minimum element at their right place.
    // insertionSort(arr);

    // 4. Merge sort is a divide and conquer algorithm , its working starts with finding the mid element and after that start dividing the array recusively into smaller half until they remains with only one elements and after that they merge them back into the sorted order.The merge sort make sure that at each merging step the array merge in the sorted format.
    // mergeSort(arr, 0, 4);

    // 5. Quick sort is a divide and conquer algorithm, that starts finding the pivot element and after that divide the array in to two subarrays one subarray with elements less that pivot element and one subarray with element grather thatn pivot element.And further starts sort these subarrays recursively in the same way.

    quickSort(arr, 0, 4);

    printArr(arr);

    return 0;
}