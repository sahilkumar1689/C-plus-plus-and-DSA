using namespace std;
#include <iostream>
#include <vector>
void get_powerset(vector<int> vec, vector<int> output, int index, vector<vector<int>> &ans)
{
    // Base case:
    if (index >= vec.size())
    {
        ans.push_back(output);
        return;
    }
    // Exclusive call:
    get_powerset(vec, output, index + 1, ans);

    // Inclusive call:
    int element = vec[index];
    output.push_back(element);
    get_powerset(vec, output, index + 1, ans);
}
void get_subsequence(string str, string output, int index, vector<string> &ans)
{
    // Base case:
    if (index >= str.size())
    {
        if (output.size() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    // Exclusice call:
    get_subsequence(str, output, index + 1, ans);
    // Inclusive call:
    char ch = str[index];
    output.push_back(ch);
    get_subsequence(str, output, index + 1, ans);
}
void get_pairs(string str, string output, int index, vector<string> &ans, vector<string> mapping)
{
    // Base case:
    if (index >= str.size())
    {
        ans.push_back(output);
        return;
    }

    int i = str[index] - '0';  // change the string number into actual number.
    string alpha = mapping[i]; // Use that number to get the equivalent mapping letters.
    for (int i = 0; i < alpha.size(); i++)
    {
        output.push_back(alpha[i]);
        get_pairs(str, output, index + 1, ans, mapping);
        output.pop_back();
    }
}
void get_permutation(string str, int index, vector<string> &ans)
{
    // Base case:
    if (index >= str.size())
    {
        ans.push_back(str);
        return;
    }
    for (int i = index; i < str.size(); i++)
    {
        swap(str[i], str[index]);
        get_permutation(str, index + 1, ans);
        swap(str[i], str[index]);
    }
}
bool isvalid(int newx, int newy, vector<vector<int>> &visit, vector<vector<int>> mat, int size)
{
    if ((newx >= 0 && newx < size) && (newy >= 0 && newy < size) && (visit[newx][newy] != 1) && (mat[newx][newy] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void get_path(int x, int y, vector<vector<int>> mat, int size, vector<vector<int>> &visit, vector<string> &ans, string path)
{
    // Base case:
    if (x == size - 1 && y == size - 1)
    {
        ans.push_back(path);
        return;
    }

    // Check the 4 directions: D/L/R/U
    visit[x][y] = 1;
    // For down:
    if (isvalid(x + 1, y, visit, mat, size))
    {
        get_path(x + 1, y, mat, size, visit, ans, path + 'D');
    }
    // For left:
    if (isvalid(x, y - 1, visit, mat, size))
    {
        get_path(x, y - 1, mat, size, visit, ans, path + 'L');
    }
    // For right:
    if (isvalid(x, y + 1, visit, mat, size))
    {
        get_path(x, y + 1, mat, size, visit, ans, path + 'R');
    }
    // For up:
    if (isvalid(x - 1, y, visit, mat, size))
    {
        get_path(x - 1, y, mat, size, visit, ans, path + 'U');
    }
    visit[x][y] = 0;
}
int main()
{
    // 1. Subsets of the array elements = Make a program in which given an array you need to find all the subsets of the array elements and return the power set of those by storing in the vector of vector.
    // e.g.: I/p = {1,2,3} ,O/p ={{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}} ;

    // vector<int> vec = {1,2,3};
    // vector<int> output;
    // vector<vector<int> > ans;
    // get_powerset(vec,output,0,ans);
    // Your code not run here.Run you code in code studio.

    // 2. Subsequence of the string = Make a program in which given a string you only need to find all the possible subsequence ans return it.
    // e.g.: I/p = "abc"  ,  O/p = {{a},{b},{c},{a,b},{a,c},{b,c},{a,b,c}};

    // string str = "abc";
    // string output="";
    // vector<string> ans;
    // get_subsequence(str,output,0,ans);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    // Recommendation = Make recussion tree for better understanding.

    // 2. Phone keypad problem = Make a program in which given a string of digits.You need to find the equivalent alphabets to given string number and then find all the possible pair.
    // e.g.: I/p = "23" , O/p = {"ad","ae","af","bd","be","bf","cd","ce","cf"};

    // string str = "89";
    // vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqr","stuv","wxyz"};
    // vector<string> ans;
    // string output = "";
    // get_pairs(str,output,0,ans,mapping);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    // Recommendation = Make recurssion tree for better understanding.

    // 3. Permutations of a string = Make a program in which you given an string.You only need to store all the possible permutaion of a string in the vector of string and return it.
    // e.g.: I/p = "abc" , O/p = {"abc","acb","bac","bca","cba","cab"};

    // string str = "abc";
    // vector<string> ans;
    // get_permutation(str,0,ans);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    // Recommendation = Please make recursion tree for better understanding.

    // 4. Rat in a maze problem = Make a program in which you given an matrix of 0 and 1 elements,1 means valid,0 means not valid.Your rat is currently at (0,0) and you have to reach at (n-1,n-1).You need to find all the valid paths and return it.
    int n = 4;
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 0},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<vector<int>> visited = {{0, 0, 0, 0},
                                   {0, 0, 0, 0},
                                   {0, 0, 0, 0},
                                   {0, 0, 0, 0}};
    vector<string> ans;
    string path = "";
    // Handle edge case:
    if (mat[0][0] == 0)
    {
        cout << " " << endl;
    }

    get_path(0, 0, mat, n, visited, ans, path);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}