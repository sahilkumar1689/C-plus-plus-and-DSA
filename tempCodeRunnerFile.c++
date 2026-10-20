#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findPivot(vector<int> &arr, int start, int end)
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

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] <= pivot)
            i++;
        else if (arr[j] > pivot)
            j--;
        else
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quicksort(vector<int> &arr, int start, int end)
{

    // Base Case:
    if (start >= end)
        return;

    int pivotIndex = findPivot(arr, start, end);

    quicksort(arr, start, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, end);
}

void printArr(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";

    cout << endl;
}

int main()
{

    vector<int> arr = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};

    quicksort(arr, 0, arr.size() - 1);

    printArr(arr);

    return 0;
}