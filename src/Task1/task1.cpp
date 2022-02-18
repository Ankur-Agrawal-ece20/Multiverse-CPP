#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
void instruction(string name, string v1, string v2, string v3)
{
    if (name == "add")              m[v1] = m[v2] + m[v3];
    
    else if (name == "sub")        m[v1] = m[v2] - m[v3];
    
    else if (name == "addi")
    {
        int i = 0;
        stringstream ss(v3);
        ss >> i;
        m[v1] = m[v2] + i;
    }
    else if (name == "mul")        m[v1] = m[v2] * m[v3];
    
    else if (name == "and")        m[v1] = m[v2] & m[v3];
    
    else if (name == "or")        m[v1] = m[v2] | m[v3];
    
    else if (name == "andi")
    {
        int i = 0;
        stringstream ss(v3);
        ss >> i;
        m[v1] = m[v2] & i;
    }
    else if (name == "ori")
    {
        int i = 0;
        stringstream ss(v3);
        ss >> i;
        m[v1] = m[v2] | i;
    }
    else if (name == "li")
    {
        int i = 0;
        stringstream ss(v2);
        ss >> i;
        m[v1] = i;
    }
    else if (name == "sw")
    {
        int i = 0;
        stringstream ss(v3);
        ss >> i;
        m["answer"] = m[v1];
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
                str = str +  arr[i][j];
            }
        }
        arr[i] = str;
    }

    for (int i = 0; i < n; i++)
    {
        stringstream ss;
        string str1, oper, v1, v2, v3;
        str1 = arr[i];
        ss << str1;
        ss >> str1;
        
        oper = str1;
        ss >> str1;
        
        v1 = str1;
        ss >> str1;
        
        v2 = str1;
        ss >> str1;
        
        v3 = str1;
        instruction(oper, v1, v2, v3);
    }
    answer = m["answer"];
    return answer;
}

// int main(){
//     int n;
//     cin>>n;
//     cin.ignore();
//     vector<string> arr(n);
//     for(int i=0;i<n;i++){
//         getline(cin,arr[i]);
//         cout<<arr[i]<<endl;
//     }
//     cout<<solve(n,arr);
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"
