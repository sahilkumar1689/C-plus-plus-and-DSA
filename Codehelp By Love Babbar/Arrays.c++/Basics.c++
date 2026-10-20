using namespace std;
#include <iostream>
int linear_src(int *ptr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (*(ptr + i) == key)
        {
            return 1;
        }
    }
    return 0;
}

void reverse_arr(int *ptr, int size)
{
    int first, last, n = 1;
    for (int i = 0; i < size / 2; i++)
    {
        // Initializes the array first and the last value:
        int temp;
        first = *(ptr + i);         // ptr[i]
        last = *(ptr + (size - n)); // ptr[size-n]

        temp = *(ptr + i);
        *(ptr + i) = *(ptr + (size - n));
        *(ptr + (size - n)) = temp;
        n++;
    }
}

void swap_alter(int *ptr, int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if ((i+1)>size)
        {
            break;
        }
        int temp = ptr[i];
        ptr[i] = ptr[i+1];
        ptr[i+1] = temp;
    }
}
int main()
{
    // Array = It is a set of similar data types stored at contiguous memory locations.In array index value starting from the (0 to size-1);

    // Declaration of the array:
    // data_type name_of_array[size];

    // Initialization of the array:
    // 1. int arr[5] = {1,2,3,4,5};
    // 2. int arr[5] = { };        // In this every element are set with the value 0;
    // 3. int arr[5] = {0};        // In this every element are set with the value 0;

    // If we want to set all the element with the same value instead of the - then we need to use following approach:
    // 4. int arr[10] = {[0...9] = 1};  // In this way we can set any value,to all of the element.
    // 5. Using fill_n() function:
    // int n =4,a =1,arr[n];
    // fill_n(arr,n,a);

    // Note = 1. The 4th approach is only applicable on the gcc compliler.
    //        2. The 5th approach is applicable on all type of the compiler.

    // 1. Linear Search: In this we need to find an element in the given array.
    // int size,key;
    // cout<<"Enter the size of the array:";
    // cin>>size;
    // int arr[size];
    // cout<<"Please enter your arrray elements:"<<endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin>>arr[i];
    // }
    // cout<<"Please enter the key element to find:";
    // cin>>key;
    // bool flag = linear_src(arr,size,key);
    // if (flag)
    // {
    //     cout<<"Present"<<endl;
    // }
    // else{
    //     cout<<"Not Present"<<endl;
    // }

    // 2. Reverse the array after that then print it:
    // int size;
    // cout<<"Enter the size of the array:";
    // cin>>size;
    // int arr[size];
    // cout<<"Please enter your arrray elements:"<<endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cin>>arr[i];
    // }

    // reverse_arr(arr,size);
    // cout<<"Afte Reverse your array is:"<<endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // 3. Swap alternative element of the array and after that print them:

    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int arr[size];
    cout << "Please enter your arrray elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    swap_alter(arr, size);
    cout << "After swaping your array is:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}