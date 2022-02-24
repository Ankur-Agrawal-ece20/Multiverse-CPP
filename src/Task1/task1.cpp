#include <bits/stdc++.h>
using namespace std;

map<string,int>val;

void for_simplifying(string operation,string p,string q,string r)
{
    if(operation=="add")
    {
        val[p]=val[q]+val[r];

    }
    else if(operation=="li")
    {
    stringstream string_to_num(q);


        int num=0;
	string_to_num>>num;

        val[p]=num;

    }
    else if(operation=="sub")
    {
        val[p]=val[q]-val[r];
    }
    else if(operation=="mul")
    {
        val[p]=val[q]*val[r];
    }
    else if(operation=="addi")
    {
    stringstream string_to_num(r);


int num=0;
	string_to_num>>num;



     val[p]=val[q]+num;
    }
     else if(operation=="and")
    {
         val[p]=val[q]&val[r];
    }
     else if(operation=="or")
    {
          val[p]=val[q]|val[r];
    }
     else if(operation=="andi")
    {
    stringstream string_to_num(r);
	int num=0;
	string_to_num>>num;


     val[p]=val[q]&num;
    }
     else if(operation=="ori")
     {
    stringstream string_to_num(r);
	int num=0;
	string_to_num>>num;


     val[p]=val[q]|num;
     }
    else if(operation=="sw")
    {
        val["answer"]=val[p];
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
        string p=str;
        ss>>str;
        string q=str;
        ss>>str;
        string r=str;
        for_simplifying(operation,p,q,r);
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

// ==> NOTE: Comment main function and uncomment below line to verifq qour code
#include "../../include/test1_cases.h"