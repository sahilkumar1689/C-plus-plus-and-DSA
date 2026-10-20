using namespace std;
#include <iostream>
#include<vector>
int gcd(int a,int b){

    // Base conditions:
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if(a == b){
        return a;
    }

    return (a>b)?gcd(a-b,b):gcd(a,b-a);    // we use recursion but you can also use 
}

int main(){
    // 1. Sieve of Eratosthenes = It only says that if a number is prime,then the number comes upon that particular number table can'nt be prime.

    // 1. Make a program in which you need to count the number of prime number present in the given range by using sieve theorem at O(n*log(logn)):

    // int range,count=0;
    // cin>>range;
    
    // // Make a boolean vetor and mark all the number in the range is prime i.e. true
    // vector<bool> v(range,true);
    // v[0] = false;
    // for (int i = 1; i < range; i++)
    // {
    //     if (v[i])
    //     {
    //         count++;
    //         cout<<(i+1)<<" ";
    //         for (int j = (i+1)*2; j <=range; j += (i+1))
    //         {
    //             v[j-1] = false;
    //         } 
    //     }  
    // }
    // cout<<count<<endl;

    
    // 2. Euclid's Algorithm = It is used to find the gcd and lcm of the two numbers.
    // formula = gcd(a-b,b) or gcd(a,b-a) depending upon the greather value between the two.

    // int a,b;
    // cin>>a>>b;

    // int ans = gcd(a,b); 

    // cout<<"GCD is:"<<ans<<endl;


    // // formula to find the lcm:
    // // lcm(a,b) = a*b/gcd(a,b);

    // int lcm = a*b/ans;
    // cout<<"LCM is:"<<lcm<<endl;
    

    // 3. Modular Exponential or fast exponential




     


    return 0;
}