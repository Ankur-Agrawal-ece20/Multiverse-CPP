#include <bits/stdc++.h>
using namespace std;
map<string,int>map1;

void operation(string oper,string var1,string var2,string var3)
{
    if(oper=="li")
    {
    map1[var1]=stoi(var2);
    }

    else if(oper=="add")
    {
        map1[var1]=map1[var2]+map1[var3];
    }
    
    else if(oper=="sub")  
    {
        map1[var1]=map1[var2]-map1[var3];
    } 

    else if(oper=="mul")
    {
        map1[var1]=map1[var2]*map1[var3];
    }

    else if(oper=="addi")
    {
        map1[var3]=stoi(var3);
        map1[var1]=map1[var2]+map1[var3];
    }

     else if(oper=="and")
    {
         map1[var1]=map1[var2]&map1[var3];
    }

     else if(oper=="or")
    {
          map1[var1]=map1[var2]|map1[var3];
    }

     else if(oper=="andi")
    {
     map1[var3]=stoi(var3);
        map1[var1]=map1[var2]&map1[var3];
    }

     else if(oper=="ori")
    {
        map1[var3]=stoi(var3);
        map1[var1]=map1[var2]|map1[var3];
    }

    else if(oper=="sw")
    {
        cout<<map1[var1]<<endl;
    }

    else{
      cout<<"not identified";
    }
}


int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    for (int i = 0; i < n; i++)
    {
        string str1;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j] ==',')
            {
                break;
            }
            else{
              str1=str1+arr[i][j];
            }
        }
        arr[i]=str1;
    }

    for(int i=0;i<n;i++)
    {
        stringstream ss;
        string stri=arr[i];
        ss<<stri;
        ss>>stri;
        string oper=stri;
        ss>>stri;
        string var1=stri;
        ss>>stri;
        string var2=stri;
        ss>>stri;
        string var3=stri;
        operation(oper,var1,var2,var3);      
    }
    // End your code here
    return answer;
}

string oper;
string var1;
string var2;
string var3;

//void changed(string l1)
//{
  //int n;
//  n=stoi(l1);
//}



//int main(){
    // int n;
    // cin>>n;
    // cin.ignore();
    // vector<string> arr(n);
    // for(int i=0;i<n;i++){
    //     getline(cin,arr[i]);
    //     cout<<arr[i]<<endl;
    // }
    // cout<<solve(n,arr);
    //return 0;
//}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"
