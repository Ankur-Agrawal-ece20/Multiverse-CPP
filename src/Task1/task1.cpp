#include <bits/stdc++.h>
using namespace std;

map<string,int>val;

void for_simplifying(string operation,string 1,string 2,string 3)
{
    if(operation=="add")
    {
        val[1]=val[2]+val[3];

    }
    else if(operation=="li")
    {
    stringstream string_to_num(2);


        int num=0;
	string_to_num>>num;

        val[1]=num;

    }
    else if(operation=="sub")
    {
        val[1]=val[2]-val[3];
    }
    else if(operation=="mul")
    {
        val[1]=val[2]*val[3];
    }
    else if(operation=="addi")
    {
    stringstream string_to_num(3);


int num=0;
	string_to_num>>num;



     val[1]=val[2]+num;
    }
     else if(operation=="and")
    {
         val[1]=val[2]&val[3];
    }
     else if(operation=="or")
    {
          val[1]=val[2]|val[3];
    }
     else if(operation=="andi")
    {
    stringstream string_to_num(3);
	int num=0;
	string_to_num>>num;


     val[1]=val[2]&num;
    }
     else if(operation=="ori")
     {
    stringstream string_to_num(3);
	int num=0;
	string_to_num>>num;


     val[1]=val[2]|num;
     }
    else if(operation=="sw")
    {
        val["answer"]=val[1];
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
        string operation=str;
        ss>>str;
        string 1=str;
        ss>>str;
        string 2=str;
        ss>>str;
        string 3=str;
        for_simplifying(operation,1,2,3);
    }
    answer = val["answer"];
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

// ==> NOTE: Comment main function and uncomment below line to verif2 2our code
#include "../../include/test1_cases.h"