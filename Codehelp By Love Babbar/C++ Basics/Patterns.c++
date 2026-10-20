using namespace std;
#include <iostream>
int get_range(){
    int a;
    cout<<"Please enter the range:"<<endl;
    cin>>a;
    return a;
}
int main(){
    // 1. First problem:
    // int a;
    // cout<<"Please enter the range:"<<endl;
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < a; j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;  
    // }

    // 2. Second Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < a; j++)
    //     {
    //         cout<<j+1<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // 3. Third Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = a; j > 0; j--)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // 4. Fourth Problem:
    // int a;
    // cout<<"Please enter the range";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     static int a1=1;
    //     for (int j = 0; j < a; j++)
    //     {
    //         cout<<a1<<" ";
    //         a1++;
    //     }
    //     cout<<endl;
    // }
    
    // 5. Fifth Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout<<"*"<<" ";
    //     }
    //  cout<<endl;   
    // }

    // 6. Sixth Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j <=i; j++)
    //     {
    //         cout<<i+1<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // 7. Seven Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     static int n=1;
    //     for (int j = 0; j <=i; j++)
    //     {
    //         cout<<n<<" ";
    //         n++;
    //     }
    //     cout<<endl;
    // }

    // 8. Eight Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 1; i <= a; i++)
    // {   
    //     static int n =1,k=1;
    //     for (int j = 1; j <=i; j++)
    //     {
    //         cout<<n<<" ";
    //         n--;
    //     }
    //     k++;
    //     cout<<endl;
    //     n +=k;
    // }
    
    // 9. Nineth Problem:
    // int a;
    // cout<<"Please enter the range:";
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {   static char ch='A';
    //     for (int j = 0; j < a; j++)
    //     {
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    //     ch++;
    // }

    // 10. Tenth Problem:
    // int a = get_range();
    // for (int i = 0; i < a; i++)
    // {   char ch = 'A';
    //     for (int j = 0; j < a; j++)
    //     {
    //         cout<<ch<<" ";
    //         ch++;
    //     }
    //     cout<<endl;
    // }
    
    // 11. Eleventh Problem:
    // int a = get_range();
    // for (int i = 0; i < a; i++)
    // {   int n=i+1;
    //     for (int j = 0; j < a; j++)
    //     {
    //        cout<<n<<" ";
    //        n++;
    //     }
    //     cout<<endl;
    // }

    // 12. Tweleve Problem:
    // int a= get_range();
    // for (int i = 0; i < a; i++)
    // {   char ch = 'A'+i;
    //     for (int j = 0; j < a; j++)
    //     {
    //         cout<<ch<<" ";
    //         ch++;
    //     }
    //     cout<<endl;
    // }
    
    // // 13. Thirteenth Problem:
    // int a= get_range();
    // for (int i = 0; i < a; i++)
    // {   char ch = 'A'+(a-1)-i;
    //     for (int j = 0; j <=i; j++)
    //     {
    //         cout<<ch<<" ";
    //         ch++;
    //     }
    //     cout<<endl;
    // }
    
    // 14. Fourtheenth Problem:
    // int a= get_range();
    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = (a-1)-i; j >0; j--)
    //     {
    //         cout<<" ";
    //     }
    //     for (int k = 0; k <=i; k++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
     
     // 15. Fiftheenth Problem:
    //  int a = get_range();
    //  for (int i = 0; i < a; i++)
    //  {
    //     for (int j = 0; j <=i-1; j++)
    //     {
    //         cout<<" ";
    //     }
    //     for (int k = a-i; k >0; k--)
    //     {
    //         cout<<"*";
    //     }
    //    cout<<endl; 
    //  }
     
    // 16. Sixtheenth Problem:
    int a = get_range();
    for (int i = 0; i < a; i++)
    {
        for (int j = (a-1)-i; j >0; j--)
        {
            cout<<" ";
        }
        for (int k = 0; k <=i; k++)
        {
            cout<<k+1;
        }
        int n=0+i;
        for (int l = 0; l <=i-1; l++)
        {
            cout<<n;
            n--;
        }
        
        cout<<endl;
    }
    
    

    
    

    return 0;
}