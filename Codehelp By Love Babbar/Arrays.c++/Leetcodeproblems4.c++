using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

int get_length(string str)
{
    int count = 0, i = 0;
    while (str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
void reverse(vector<char> &str)
{
    for (int i = 0; i < str.size() / 2; i++)
    {
        swap(str[i], str[(str.size()) - (i + 1)]);
    }
}
void reverse_word(vector<char> &vec, int start, int end)
{
    int i = start, j = end;
    while (i <= j)
    {
        swap(vec[i++], vec[j--]);
    }
}
char lwr(char str)
{
    if (str >= 'A' && str <= 'Z')
    {
        str += 32;
    }
    return str;
}
int check_palindrome(string str)
{
    int i = 0, flag = 0;
    int j = str.size() - 1;
    while (i <= j)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
        {
            i++;
        }
        if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[i] <= 'z') || (str[j] >= '0' && str[j] <= '9')))
        {
            j--;
        }

        if (lwr(str[i]) == lwr(str[j]))
        {
            flag = 1;
            i++;
            j--;
        }
        else
        {
            return flag = 0;
        }
    }
    return flag;
}
char maxOccurance(string str)
{
    // Using hashing technique:
    int temp[26] = {};
    for (int i = 0; i < str.length(); i++)
    {
        // if (str[i] >= 'A' && str[i] <= 'Z')
        // {
        //     temp[str[i] - 'A']++;
        // }
        // else
        // {
        // }
        temp[str[i] - 'a']++;
    }

    // Simple find the maximum element in a array:
    int max = temp[0], ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < temp[i])
        {
            max = temp[i];
            ans = i;
        }
    }

    return 'a' + ans;
}
int is_equal(int *arr1,int *arr2){
    for (int i = 0; i <26 ; i++)
    {
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        for (int j = 1, count = 1; j <= chars.size(); j++, count++)
        {
            if ( j == chars.size() || chars[j] != chars[j - 1]) // conditions position is important
            {
                chars[i++] = chars[j - 1];
                if (count >= 2)
                {
                    for (char digit : to_string(count))
                    {
                        chars[i++] = digit;
                    }
                }
                count = 0;
            }
        }
        return i;
    }
};
int main()
{
    // 1. Find the lenght of the given string:
    // string str;
    // cout<<"Please enter your string:";
    // getline(cin,str);

    // // By using member function:
    // cout<<"Lenght of the string is:"<<str.length()<<endl;

    // // By using user defined function:
    // cout<<"Lenght of the string is:"<<get_length(str)<<endl;

    // 2. Reverse in the same array:

    // string str;
    // cout<<"Please enter your string:";
    // getline(cin,str);

    // reverse(str);
    // cout<<str;

    // 3. Make a program in which you given an string,and you need to check if the given string is palindrome or not.string element is not case sensitive.You only need to consider the alphabets and numbers.Ignore the special symbol and white space.

    // string str;
    // getline(cin,str);

    // int flag = check_palindrome(str);
    // cout << flag << endl;

    // 4. Reverse the position of the worlds in the given vector string:
    // e.g.: I/p = "My name is Sahil" , O/p = "Sahil is name My"

    // vector<char> vec = {'T', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    // reverse(vec);
    // int i = 0, j = 0;
    // while (j <= vec.size() - 1)
    // {
    //     if (vec[j + 1] == ' ' || j + 1 == vec.size())
    //     {
    //         reverse_word(vec, i, j);
    //         j += 2;
    //         i = j;
    //     }
    //     else
    //     {
    //         j++;
    //     }
    // }
    // for (auto i : vec)
    // {
    //     cout << i;
    // }

    // 5. Make a program in which you given an string s,you need to find the maximum occurance character and print them.

    // string str;
    // cin >> str;
    // cout << maxOccurance(str);

    // 6. Make a program in which you given a string s,you only need to replace the spaces with '@40'and print them.Try to due in O(1) space complexity.
    // e.g.: I/p = "My name is Sahil" , O/p = "My@40name@40is@40Sahil".

    // string str;
    // string key = "@40";   // You can also get key input by the user.
    // getline(cin,str);
    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (str[i] == ' ')
    //     {   str.erase(str.find(' '),1);     // You can also use i instead of str.find(' ')
    //         str.insert(i,key);
    //         i +=key.size();
    //     }
    // }
    // cout<<str;

    // 7. Make a program in which you given a string s and string key,you need to delete the key string in the main string s,i.e. you need to delete all the substrings in the main strings.

    // string str,key;
    // cin>>str>>key;

    // while (str.size()!=0 && str.find(key)<str.size())
    // {

    //     str.erase(str.find(key),key.size());
    // }
    // cout<<str;

    // 8. Permutations of string = Make a program in which you given two string s1 and s2,s1 is the key and s2 is the main string,you only need to find whether any one of the permutations combinations are present in the main substring or not.
    // e.g. : I/p  key = "abc" , str = "xyzbac"
    // permutations of "abc" is = "abc","bac","bca","acb","cab","cba".

    // Approach Used = Sliding Windows

    // string key, main_str;
    // cin >> key >> main_str;

    // // Store count of key string element by using hashing technique:
    // int temp1[26] = {0};
    // for (int i = 0; i < key.size(); i++)
    // {
    //     temp1[key[i] - 'a']++;
    // }

    // // Prepare a first window and store the element count by using hashing technique:
    // int temp2[26] = {0};
    // int i = 0;
    // int j = key.size() - 1;

    // while (i <= j && i <= main_str.size() - 1)
    // {
    //     temp2[main_str[i] - 'a']++;
    //     i++;
    // }

    // // if window one element count is equal to the key window count then return true:
    // if (is_equal(temp1, temp2))
    // {
    //     cout<<"True"<<endl;
    // }

    // // Else move your window forward by adding next element count in the temp2 and delete the previous element count from the temp2 then check again:
    // else
    // {   
    //     int flag =0;
    //     while (i<=main_str.size()-1)
    //     {   
    //         // Adding new element count in the temp2:
    //         temp2[main_str[i]-'a']++;

    //         // Deleting previous one element from the temp2:
    //         temp2[main_str[i-key.size()]-'a']--;
    //         i++;

    //         // Again check:
    //         if(is_equal(temp1,temp2)){
    //             cout<<"True"<<endl;
    //             flag =1;
    //         }
    //     }
    //     (flag==0)?cout<<"False":cout<<"";
    // }

    // 9. String Compression = Make a program  in which you given an string s,you need to count the occurance of every element and stored in the same string in the compression format,if occurance is 1 then no need to store in the string:
    // e.g.: I/p = a,a,b,c,c,c , O/p = a,2,b,c,3

    // string str;
    // cin>>str;

    // int i=0;
    // int tracking_index = 0;
    // while (i<= str.size()-1)
    // {
    //     int j = i+1;
    //     int count = 1;
    //     while (j<=str.size()-1 && str[i] == str[j])
    //     {
    //         j++;
    //         count++;
    //     }
    //     str[tracking_index++] = str[i];
    // 
    //     if(count>1){
    //         string temp = to_string(count);
    //         for(auto i:temp){
    //             str[tracking_index++] = i;
    //         }
    //     }
    //     i = j;
    // }
    // int a = str.size()-tracking_index;
    // str.erase(tracking_index,a);
    // cout<<str<<endl;
    // cout<<tracking_index;

    // Better ans easy solution:
    // Solution obj;
    // vector<char> vec{'a','a','b','b','c','c','c'};

    // int a = obj.compress(vec);
    // cout << a;


    // 10. Remove adjacent duplicate in the string = Make a program in which you given an string s,you need to remove all the adjacent dulicates.
    // e.g.: I/p = abbaca , O/p = ca 
    
    // string str;
    // cin>>str;

    // int i=0,j = i+1;
    // while (j<=str.size()-1)
    // {
    //     if(str[i] == str[j]){

    //         while (str[i] == str[j+1] && j+1<= str.size()-1)
    //         {
    //            j++;
    //         }
    //         str.erase(i,j-i+1);
    //         i=0;
    //         j=i+1;
    //     }
    //     else{
    //         i++;
    //         j = i+1;
    //     }
    // }
    // cout<<str;

    
    
    

    
    


    


    return 0;
}