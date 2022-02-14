#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;

// void v1(string arr)
// {
//     string s="$",t=",";
// 	size_t found1=arr.find(s);
//     size_t found2=arr.find(t);
//     string str;
//     for (int i = found1+1; i < found2; i++)
//     {
//         str=str+arr[i];
//     }
//     return str;
// }

// void v2(string arr)
// {
//     string s="$",t=",";
// 	// size_t found1=arr.find(s);
//     size_t found1=arr.find(t);
//     size_t found2=arr.find(s,found1+1);
//     size_t found3=arr.find(t,found1+1);
//     string str;
//     for (int i = found2+1; i < found3; i++)
//     {
//         str=str+arr[i];
//     }
//     return str;
// }

// void v3(string arr)
// {
//     string s="$",t="$";
// 	// size_t found1=arr.find(s);
//     size_t found1=arr.find(t);
//     size_t found2=arr.find(t,found1+1);
//     size_t found3=arr.find(t,found2+1);
//     string str;
//     for (int i = found3+1; i < arr.size(); i++)
//     {
//         str=str+arr[i];
//     }
//     return str;
// }

void calc(string oper,string var1,string var2,string var3)
{
    if(oper=="add")
    {
        mp["var1"]=mp["var2"]+mp["var3"];
    }
    else if(oper=="li")
    {
    stringstream string_to_num(var2);
	int x=0;
	string_to_num>>x;
    mp["var1"]=x;
    }
    else if(oper=="sub")  
    {
        mp["var1"]=mp["var2"]-mp["var3"];
    } 
    else if(oper=="mul")
    {
        mp["var1"]=mp["var2"]*mp["var3"];
    }
    else if(oper=="addi")
    {
    stringstream string_to_num(var3);
	int x=0;
	string_to_num>>x;
     mp["var1"]=mp["var2"]+x;
    }
     else if(oper=="and")
    {
         mp["var1"]=mp["var2"]&mp["var3"];
    }
     else if(oper=="or")
    {
          mp["var1"]=mp["var2"]|mp["var3"];
    }
     else if(oper=="andi")
    {
    stringstream string_to_num(var3);
	int x=0;
	string_to_num>>x;
     mp["var1"]=mp["var2"]&x;
    }
     else if(oper=="ori")
     {
    stringstream string_to_num(var3);
	int x=0;
	string_to_num>>x;
     mp["var1"]=mp["var2"]|x;
     }
    else if(oper=="sw")
    {
        mp["answer"]=mp["var1"];
    }
}

int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    for (int i = 0; i < n; i++)
    {
        string po;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j] !=',')
            {
                po=po+arr[i][j];
            }
        }
        arr[i]=po;
    }
    
    for(int i=0;i<n;i++)
    {
        stringstream ss;
        string t=arr[i];
        ss<<t;
        ss>>t;
        string oper=t;
        // calc(t);
        ss>>t;
        string var1=t;
        ss>>t;
        string var2=t;
        ss>>t;
        string var3=t;
        calc(oper,var1,var2,var3);      
    }
    answer = mp["answer"];
    // End your code here
    return answer;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
        cout<<arr[i]<<endl;
    }
    cout<<solve(n,arr);
    return 0;
}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
// #include "../../include/test1_cases.h"