using namespace std;
#include <iostream>
#include<vector>

int main()
{
    // Matrix = The matrix is also called a 2-Dimensional array.It is used to store the element in the tabular format.It time complexity is O(n*m).Where n is rows and m is columns.

    // Syntax:
    // data_type variable_name[row_size][columns_size];

    // int arr[3][4];

    // Initialization :
    // 1. int mat[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // 2. int mat[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};   // Recommended

    // 1. Take input from the user and store element in rows by rows/columns by columns and print them:

    // Rows by Rows = In this the upper loop runs till number of rows and inner loop runs till number of columns:
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Columns by Columns = In this the upper loop runs till number of columns and the inner loop runs till numbers of rows:
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin>>arr[j][i];
    //     }
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // 1. Make a program in which you need to find the key element in the given matrix by using linera search:
    // int key,flag =0;
    // cout<<"Please enter the element to find:";
    // cin>>key;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if(arr[i][j] == key){
    //             cout<<"Present"<<endl;
    //             flag = 1;
    //         }
    //     }
    // }
    // (flag==0)?cout<<"Not present"<<endl:cout<<"";

    // 2. Make a program in which you need to print the sum of each row/columns elements and also print the maximum of these and also tell present in which row:

    // For rows elements:
    // int sum;
    // int temp[3];
    // for (int i = 0; i < 3; i++)
    // {   sum=0;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         sum += arr[i][j];
    //     }
    //     cout<<i+1<<" row sum is:"<<sum<<endl;
    //     temp[i] = sum;
    // }

    // // Find the maximum sum and the row_no:
    // int max= temp[0],row_no=0;
    // for (int i = 1; i < 3; i++)
    // {
    //     if (max<temp[i])
    //     {
    //         max = temp[i];
    //         row_no = i;
    //     }  
    // }
    // cout<<"Row "<<row_no+1<<" has maximum sum "<<max<<endl;

    // For columns element:
    // int sum;
    // int temp[4];
    // for (int i = 0; i < 4; i++)
    // {   sum=0;
    //     for (int j = 0; j < 3; j++)
    //     {
    //         sum += arr[j][i];
    //     }
    //     cout<<i+1<<" column sum is:"<<sum<<endl;
    //     temp[i] = sum;
    // }

    // // Find the maximum sum and the row_no:
    // int max= temp[0],row_no=0;
    // for (int i = 1; i < 4; i++)
    // {
    //     if (max<temp[i])
    //     {
    //         max = temp[i];
    //         row_no = i;
    //     }  
    // }
    // cout<<"Column "<<row_no+1<<" has maximum sum "<<max<<endl;


    // 3. Make a program in which you need to print the matrix element in the wave format:

    // for (int i = 0; i < 4; i++)   
    // {
    //     if(i&1){
    //         // for odd index value
    //         for (int j = 3-1; j >=0 ; j--)
    //         {
    //             cout<<arr[j][i]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     else{
    //         // for even index value
    //         for (int j = 0; j < 3; j++)
    //         {
    //             cout<<arr[j][i]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    // 4. Spiral matrix = Make a program in which you need to print the element of the matrix in the spiral format:

    // vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // vector<int> temp;

    // int row = mat.size();           // it is used to find the size of the rows.
    // int col = mat[0].size();        // it is used to find the size of the columns.
    // int total = row*col;     // find the total element.
    // int count = 0;

    // // use four pointer:
    // int starting_row=0;
    // int ending_row = row-1;
    // int starting_col = 0;
    // int ending_col = col-1;

    // while (count<total)
    // {
    //     // print the starting row:
    //     for (int i = starting_col; count<total && i <= ending_col; i++)
    //     {
    //         temp.push_back(mat[starting_row][i]);
    //         count++;
    //     }
    //     starting_row++;

    //     // print the ending col:
    //     for (int i = starting_row; count<total && i <= ending_row; i++)
    //     {
    //         temp.push_back(mat[i][ending_col]);
    //         count++;
    //     }
    //     ending_col--;

    //     // print the ending row:
    //     for (int i = ending_col; count<total && i>= starting_col; i--)
    //     {
    //         temp.push_back(mat[ending_row][i]);
    //         count++;
    //     }
    //     ending_row--;

    //     // print the starting col:
    //     for (int i = ending_row; count<total && i >= starting_row; i--)
    //     {
    //         temp.push_back(mat[i][starting_col]);
    //         count++;
    //     }
    //     starting_col++; 
    // }
    // for(auto i:temp){
    //     cout<<i<<" ";
    // }


    // 5. Make a program to find a key element in the given matrix by using binary search:


    // vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // int key;
    // cout<<"Please enter the key element:";
    // cin>>key;

    // int row = mat.size();
    // int col = mat[0].size();
    // int total = row*col;

    // int i = 0,j = total-1,flag=0;

    // while (i<=j)
    // {
    //     int mid = i+(j-i)/2;

    //     // find the equivalent row and column number:
    //     int element = mat[mid/col][mid%col];

    //     if(element== key){
    //         cout<<"Present"<<endl;
    //         flag=1;
    //         break;
    //     }
    //     else if(element<key){
    //         i = mid+1;
    //     }
    //     else{
    //         j = mid-1;
    //     }
    // }
    // (flag==0)?cout<<"Not present":cout<<"";
    

    // 6. Make program to search a key element in the given matrix,when the elements present in the rows and columns are also sorted in increasing order:

    // vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int key;
    // cout<<"Please enter the key element:";
    // cin>>key;

    // int row = mat.size();
    // int col = mat[0].size();
    
    // int i = 0,j = col-1,flag=0;

    // while (i< row && j>=0)
    // {
    //     int element = mat[i][j];

    //     if(element == key){
    //         cout<<"True"<<endl;
    //         flag=1;
    //         break;
    //     }
    //     else if(element<key){
    //         i++;
    //     }
    //     else{
    //         j--;
    //     }
    // }
    // (flag==0)?cout<<"False":cout<<"";
    

    // 7. Make a program to rotate the matrix by 90 degree:

    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    int row = mat.size();
    int col = mat[0].size();

    // Rotate the matrix with respect to left diagonal:
    for (int i = 0; i <= row-1 ; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    // Rotate the matrix with respect to center column:
    for (int i = 0; i <= row-1; i++)
    {
        for (int j = 0; j < col/2; j++)
        {
            swap(mat[i][j],mat[i][col-j-1]);
        }
    }
    // Print matrix:
    for (int i = 0; i <= row-1; i++)
    {
        for (int j = 0; j <= col-1; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;  
    }
 
    return 0;
}