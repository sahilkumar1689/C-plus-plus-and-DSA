using namespace std;
#include <iostream>
void get_element(int *ptr, int size)
{
    cout << "Please enter the elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(ptr + i);
    }
}
int main()
{
    // Binary Search = In this we divide the array from mid in every iteration and check that mid element is equal to the key element or not.If equal then return that index value but if not we simply check if the mid element is greather than or smaller than the key element.Run the similar procedure in every iteration.Condition array element must be monotonic function.

    // e.g. :
    int size, key;
    cout << "Please enter the size of the array and the key element respectively:";
    cin >> size >> key;
    int arr[size];
    get_element(arr, size);
    int i = 0, j = size - 1, flag = 0;
    while (i <= j)
    {
        int mid = (i + j) / 2;  // int mid = i+(j-i)/2;
        if (arr[mid] == key)
        {
            cout << key << " is peresent at " << mid << " index." << endl;
            flag = 1;
            break;
        }
        if (arr[mid] > key)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    if (flag == 0)
    {
        cout << key << " is not present in the array." << endl;
    }



    // Note = Very popular question how we know to apply which searching technique on the array to search the element:
    // 1. See You need to know,linear search can be apply on any array seaching question.It time complexity will be O(n). 
    // 2. But binary search can be apply only those array whose element is the monotonic function i.e. increasing or the decreasing order.Time complexity is O(logn).
    // 3. So read the question perfectly,if question says they need time complexity  O(logn) or element of the array in the monotonic function form then only use the binary serach.If questionn say nothing then simply use the linear serach. 
    return 0;
}