#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
void instruction(string name, string a, string b, string c)
{
    if (name == "add")
    {
        m[a] = m[b] + m[c];
    }
    else if (name == "sub")
    {
        m[a] = m[b] - m[c];
    }
    else if (name == "addi")
    {
        int i = 0;
        stringstream ss(c);
        ss >> i;
        m[a] = m[b] + i;
    }
    else if (name == "mul")
    {
        m[a] = m[b] * m[c];
    }
    else if (name == "and")
    {
        m[a] = m[b] & m[c];
    }
    else if (name == "or")
    {
        m[a] = m[b] | m[c];
    }
    else if (name == "andi")
    {
        int i = 0;
        stringstream ss(c);
        ss >> i;
        m[a] = m[b] & i;
    }
    else if (name == "ori")
    {
        int i = 0;
        stringstream ss(c);
        ss >> i;
        m[a] = m[b] | i;
    }
    else if (name == "li")
    {
        int i = 0;
        stringstream ss(b);
        ss >> i;
        m[a] = i;
    }
    else if (name == "sw")
    {
        int i = 0;
        stringstream ss(c);
        ss >> i;
        m["answer"] = m[a];
    }
};

int solve(int n, vector<string> arr){
    int answer=0;
    for (int i = 0; i < n; i++)
    {
        string str;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] != ',')
            {
                str += arr[i][j];
            }
        }
        arr[i] = str;
    }

    for (int i = 0; i < n; i++)
    {
        stringstream ss;
        string str1, oper, x, y, z;
        str1 = arr[i];
        ss << str1;
        ss >> str1;
        oper = str1;
        ss >> str1;
        x = str1;
        ss >> str1;
        y = str1;
        ss >> str1;
        z = str1;
        instruction(oper, x, y, z);
    }
    answer = m["answer"];
    return answer;
}

// int main(){
//     // int n;
//     // cin>>n;
//     // cin.ignore();
//     // vector<string> arr(n);
//     // for(int i=0;i<n;i++){
//     //     getline(cin,arr[i]);
//     //     cout<<arr[i]<<endl;
//     // }
//     // cout<<solve(n,arr);
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"