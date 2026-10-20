using namespace std;
#include <iostream>
#include<cstring>
#include<string>

int main(){
    // 1. C-strings = It is also called character string.It is implemented by using character arrays.It terminate with the null character '\0'.There are many built in functions to use them include <cstring> header file.

    // Syntax:
    // char variable_name[size];

    // 1. Various ways to declare and initialize a c-string:
    // char str1[] = "Sahil";
    // char str2[5] = {'S','a','h','i','l'};
    // char str3[6] = "Sahil";
    // Null '\0' character automatically initialized at the end of every string.

    // 2. Take input from the user:
    // char str[16];
    // cin>>str;   // You not need to run a loop like in array.
    // // If space,tab and enter come then cin terminates.
    // // Print output:
    // cout<<str;  // You not need to run a loop like in array.

    // 3. To get the complete line we use get(array_name,size) function;
    // cin.get(str,16);
    // cout<<str;

    // 4. If terminator symbol come inside the array then stop printing:
    // str[2] = '\0';
    // cout<<str;


    // Some functions:
    // 1. Strcat(first_Str,last_str) = It is used to concatenate two string with each other.
    // e.g.:
    // char str[10] = "Hello";
    // char str2[5] = "Hi";
    // strcat(str,str2);
    // cout<<str;

    // 2. strlen(string_name) = Used to find the lenght or element present in the c-string.
    // e.g.:
    // cout<<strlen(str)<<endl;

    // 3. strcpy(destination_string,source_string) = Copy one strig into another.
    // e.g.:
    // char str1[10];
    // strcpy(str1,str);
    // cout<<str1<<endl;

    // 4. strcmp(str1,str2) = Compare two string.
    // e.g.:
    // cout<<strcmp(str1,str)<<endl;
    // cout<<strcmp(str1,"H")<<endl;
    // cout<<strcmp(str1,"Hello")<<endl;

    // 5. strlwr(str_name) = Convert lower case.
    // e.g.:
    // strlwr(str);

    // 6. strupr(str_name) = Convert Upper case.
    // e.g.:
    // strupr(str2);
    // cout<<str2<<endl;

    // 7. strrev(str_name) =  Reverse the string.
    // e.g.:
    // strrev(str1);
    // cout<<str1<<endl;



    // 2. String = These are the objects of the string class which is used to hold the characters string like c-string,but the strings objects have no length so we can add number of characters according to our requirement.String are also automatically teminated with the null character '\0'.There are numbers of member function to increase our productivity only include <string> header file.

    // Syntax:
    // string object_name;

    // 1. Declaration and initialization:
    // string str = "Sahil Kumar is a good boy.";

    // 2. Take input from the users:
    // string str;
    // cin>>str;           // Not need to run a loop.
    // // Print the string:
    // cout<<str;         // Not need to run a loop.

    // 3. If null character come in the string then it only skip that character and continue further:
    // str[2] = '\0';
    // cout<<str;

    // 4. If space,tab and enter come then cin terminates.
    // To get the complete line we use getline(cin,object_name) function.
    // getline(cin,str);
    // cout<<str;

    // 5. You can also make a string array:
    // string arr[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     cin>>arr[i];
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // Some functions:
    // string str;
    // 1. push_back() and pop_back() = It is used to add any new element or delete element at the end of the string.
    // str.push_back('H');
    // str.push_back('e');
    // str.push_back('l');
    // str.push_back('l');
    // str.push_back('o');

    // // str.pop_back();

    // cout<<str;

    // 2. at() and []function = It is used to access any random element from the string.
    // str.at(0) = 'h';
    // str[1] = 'E';
    // cout<<str;

    // 3. front() and back() = To get front and last element.
    // cout<<str.front()<<endl;
    // cout<<str.back()<<endl;

    // 4. begin() and end() = It is used to given the iterator at the front and the last element.
    // string::iterator it1 = str.begin();
    // string::iterator it2= str.end();

    // cout<<*(it1+1)<<endl<<*(it2-1);

    // 5. Capacity functions = 
    // size(),length(),max_size(),capacity(),reverse(),empty(),clear().

    // 6. insert(iterator,value)=
    // 7. swap(),erase(iterator),find(value).

    return 0;
}