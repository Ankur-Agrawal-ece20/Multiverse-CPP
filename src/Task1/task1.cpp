#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;

void Simplify_operators(string oper,string x,string y,string z)
{
    if(oper=="add")
    {
        mp[x]=mp[y]+mp[z];

    }
    else if(oper=="li")
    {
    stringstream string_to_num(y);


        int a=0;
	string_to_num>>a;

        mp[x]=a;

    }
    else if(oper=="sub")
    {
        mp[x]=mp[y]-mp[z];
    }
    else if(oper=="mul")
    {
        mp[x]=mp[y]*mp[z];
    }
    else if(oper=="addi")
    {
    stringstream string_to_num(z);


int a=0;
	string_to_num>>a;



     mp[x]=mp[y]+a;
    }
     else if(oper=="and")
    {
         mp[x]=mp[y]&mp[z];
    }
     else if(oper=="or")
    {
          mp[x]=mp[y]|mp[z];
    }
     else if(oper=="andi")
    {
    stringstream string_to_num(z);
	int a=0;
	string_to_num>>a;


     mp[x]=mp[y]&a;
    }
     else if(oper=="ori")
     {
    stringstream string_to_num(z);
	int a=0;
	string_to_num>>a;


     mp[x]=mp[y]|a;
     }
    else if(oper=="sw")
    {
        mp["answer"]=mp[x];
    }
}

int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j] !=',')
            {


s+=arr[i][j];
            }
        }
        arr[i]=s;
    }

    for(int i=0;i<n;i++)
    {
        stringstream ss;
        string str=arr[i];
        ss<<str;
        ss>>str;
        string oper=str;



        ss>>str;
        string x=str;


        ss>>str;
        string y=str;


        ss>>str;
        string z=str;


        Simplify_operators(oper,x,y,z);
    }
    answer = mp["answer"];
    // End your code here
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
