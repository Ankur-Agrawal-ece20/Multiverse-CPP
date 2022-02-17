#include<bits/stdc++.h>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std; 
int answer=0;

map<string,int> map1;
void calculator(string command,string x,string y,string z)
{

    if(command=="add")
        map1[x]=map1[y]+map1[z];
    else if(command=="sw")
        map1["answer"]=map1[x];
    else if(command=="mul")
        map1[x]=map1[y]*map1[z];
    else if(command=="sub")  
        map1[x]=map1[y]-map1[z];
    else if(command=="and")
         map1[x] = map1[y] & map1[z];
    else if(command=="or")
          map1[x] = map1[y] | map1[z];

     else if(command=="addi")
    {
    stringstream string_to_number(z);
	int i=0;
	string_to_number>>i;
     map1[x]=map1[y]+i;
    }

    else if(command=="li")
    {
    stringstream string_to_num(y);
	int i=0;
	string_to_num>>i;
    map1[x]=i;
    }
     else if(command=="ori")
    {
    stringstream string_to_num(z);
	int i=0;
	string_to_num>>i;
    map1[x]=map1[y]|i;
     }
    else if(command=="andi")
    {
    stringstream string_to_num(z);
	int i=0;
	string_to_num>>i;
    map1[x] = map1[y] & i;
    }
}
int solve(int n, vector<string> array){ 
    for (int j = 0; j < n; j++)
    {
        string str1;
        for (int k = 0; k < array[j].size(); k++)
        {
            if(array[j][k] !=',')
            {
                str1=str1+array[j][k];
            }
        }
        array[j]=str1;
    }
    for(int j=0;j<n;j++)
    {   string str=array[j];
        stringstream sstr;
        sstr<<str;
        sstr>>str;
        string command=str;
        sstr>>str;
        string x=str;
        sstr>>str;
        string y=str;
        sstr>>str;
        string z=str;
        calculator(command,x,y,z);      
    }
    answer = map1["answer"];
    return answer;
}
/*int main(){
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
}*/

#include "../../include/test1_cases.h"