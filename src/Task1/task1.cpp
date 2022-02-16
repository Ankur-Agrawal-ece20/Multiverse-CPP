#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<string> arr){
    int answer=0;
    unordered_map <string,int> m;
    string op,v1,v2,v3;
    for(int i=0;i<n;i++)
    {
        stringstream ss;
        ss<<arr[i];
        ss>>op>>v1>>v2>>v3;
         if(op == "li")
        {
            v1.pop_back();
            m[v1]=stoi(v2);
        }
        else if(op == "add")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2]+ m[v3];
        }
        else if(op == "addi")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2]+ stoi(v3);
        }
        else if(op == "sub")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2]- m[v3];
        }
        else if(op == "mul")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2]*m[v3];
        }
        else if(op == "and")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2]&m[v3];
        }
        else if(op == "or")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2] | m[v3];
        }
        else if(op == "andi")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2] & stoi(v3);
        }
        else if(op == "ori")
        {
            v1.pop_back();
            v2.pop_back();
            m[v1]=m[v2] | stoi(v3);
        }
        else if(op == "sw")
        {
            v1.pop_back();
            answer=m[v1];
        }
        else{
            cout<<"Invalid operation";
        }
     }
     
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