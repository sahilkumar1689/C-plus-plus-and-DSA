using namespace std;
#include <iostream>
#include<cmath>

int main(){
    // 1. Make a program to take input the numbers from the user and after that we need to find their product and sum and print there subtraction value:
    // int num,product=1,sum=0;
    // cout<<"Please enter any number:";
    // cin>>num;
    // for (int i = num; i >0; i/=10)
    // {
    //     int last = i%10;
    //     product *= last;
    //     sum += last;
    // }
    // int sub = product - sum;
    // cout<<"Your subtract value is:"<<sub<<endl;
    
    // 2. Make a program to take a number from the user and count the numbers of 1 bit present in the relative binary format and print them:

     // First Approach = Greedy Approach:
    // int digit,count=0;
    // cout<<"Please enter the number:";
    // cin>>digit;
    // while (digit!=0)
    // {
    //     int bit = digit & 1;
    //     if(bit == 1){
    //         count++;
    //     }
    //     digit >>= 1;
    // }
    // cout<<count<<endl;

    // Second Approach = Old Skool Approach:
    // int digit,binary =0,i=0,count=0;
    // cout<<"Please enter the number:";
    // cin>>digit;
    // while (digit!=0)
    // {
    //     int remainder = digit%2;
    //     binary += remainder * pow(10,i);
    //     digit /=2;
    //     i++;
    // }
    // cout<<binary<<endl;

    // for (int i = binary; i >0; i/=10)
    // {
    //     int last = i%10;
    //     if (last == 1)
    //     {
    //         count++;
    //     }
    // }
    // cout<<count<<endl;
    

    // 3. Make a program to convert the binary in to decimal and vice versa:
    // int num,flag;
    // cout<<"Please enter 1 to convert binary into decimal and 2 for decimal in to binary:";
    // cin>>flag;
    // if (flag == 1)
    // {   
    //     int decimal=0,n=0;
    //     cout<<"Please enter the binary number:";
    //     cin>>num;
    //     for (int i = num; i > 0; i/=10)
    //     {
    //         int last = i%10;
    //         if (last == 1)
    //         {
    //             decimal += last * pow(2,n); 
    //         }  
    //         n++;
    //     }
    //     cout<<"Decimal is:"<<decimal<<endl;    
    // }
    // else if(flag ==2){
    //     int binary=0,i=0;
    //     cout<<"Please enter you decimal number:";
    //     cin>>num;
    //     while (num!=0)
    //     {
    //         int last = num &1;
    //         binary += last *pow(10,i);
    //         num >>= 1;
    //         i++;
    //     }
    //     cout<<"Binary number is:"<<binary<<endl;
    // }
    // else{
    //     cout<<"Please enter the valid number:"<<endl;
    // }

    // 4. Make a program to take input from the user and after that reverse the integer value and after that check that if after reverse integer goes out of range [-2^31,(2^31)-1] then return zero,else print the reverse number: 
    // int num,sum=0;
    // cout<<"Please enter the number:";
    // cin>>num;
    // while (num!=0)
    // {
    //     int last = num%10;
    //     if((sum > INT_MAX/10) || (sum < INT_MIN/10)){
    //         cout<<"Integer value goes out of the range."<<endl;  //  return 0;
    //     }
    //     sum = (sum*10)+ last;
    //     num /=10;
    // }
    // cout<<sum<<endl;

    // 4. Make a program to take input from the user and print its complemented numbers:

    // int num,temp,mask =0,flag =0;
    // cout<<"Please enter any number:";
    // cin>>num;
    // temp = num;
    // // Edge case:
    // if (num == 0)
    // {
    //     cout<<"1"<<endl;
    //     flag++;
    // }
    // while (temp !=0)
    // {
    //     mask = (mask<<1) | 1;    // We add 1 every time in mask.
    //     temp >>= 1;              // We remove one bit from the temp.
    // }
    // if (flag == 0)
    // {
    //      int complemented = (~num) & mask;  // Formula to find the complement.
    //      cout<<complemented<<endl;  
    // }

    // 5. Make a program to take input from the user and check if the number can be represented in the form of power of two or not:
    
    // First Approach:
    // int num,flag =0;
    // cout<<"Please enter the number:";
    // cin>>num;
    // for (int i = 0; i <=30; i++)
    // {
    //     int val = pow(2,i);
    //     if(val == num){
    //         cout<<"TRUE"<<endl;
    //         flag++;
    //     }
    // }
    // if (flag == 0)
    // {
    //     cout<<"false"<<endl; 
    // }
    
    // Second Approach:
    int a,count=0;
    cout<<"Please enter the number:";
    cin>>a;
    while (a!=0)
    {
        int last = a &1;
        if(last == 1){
            count++;
        }
        a >>= 1;
    }
    if (count == 1)
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }


    
        
    return 0;
}