#include <bits/stdc++.h>
		using namespace std;
		#include<bits/stdc++.h>
		#include<sstream>
		#include<vector>
		#include<map>
		#include<string>
		#include<iostream>
		using namespace std; 
		int answer=0;
		

		int solve(int n, vector<string> arr){
		    int answer=0;
		    // Start your code here
		map<string,int> map1;
		void calculation(string command,string p,string q,string r)
		{
		

		    // End your code here
		    if(command=="add")
		        map1[p]=map1[q]+map1[r];
		    else if(command=="sw")
		        map1["answer"]=map1[p];
		    else if(command=="mul")
		        map1[p]=map1[q]*map1[r];
		    else if(command=="sub")  
		        map1[p]=map1[q]-map1[r];
		    else if(command=="and")
		         map1[p] = map1[q] & map1[r];
		    else if(command=="or")
		          map1[p] = map1[q] | map1[r];
		

		     else if(command=="addi")
		    {
		    stringstream string_to_number(r);
			int i=0;
			string_to_number>>i;
		     map1[p]=map1[q]+i;
		    }
		

		    else if(command=="li")
		    {
		    stringstream string_to_num(q);
			int i=0;
			string_to_num>>i;
		    map1[p]=i;
		    }
		     else if(command=="ori")
		    {
		    stringstream string_to_num(r);
			int i=0;
			string_to_num>>i;
		    map1[p]=map1[q]|i;
		     }
		    else if(command=="andi")
		    {
		    stringstream string_to_num(r);
			int i=0;
			string_to_num>>i;
		    map1[p] = map1[q] & i;
		    }
		}
		int solve(int n, vector<string> arr1){ 
		    for (int j = 0; j < n; j++)
		    {
		        string str1;
		        for (int k = 0; k < arr1[j].size(); k++)
		        {
		            if(arr1[j][k] !=',')
		            {
		                str1=str1+arr1[j][k];
		            }
		        }
		        arr1[j]=str1;
		    }
		    for(int j=0;j<n;j++)
		    {   string str=arr1[j];
		        stringstream sstr;
		        sstr<<str;
		        sstr>>str;
		        string command=str;
		        sstr>>str;
		        string p=str;
		        sstr>>str;
		        string q=str;
		        sstr>>str;
		        string r=str;
		        calculation(command,p,q,r);      
		    }
		    answer = map1["answer"];
		    return answer;
		}
		

		int main(){
		    // int n;
		    // cin>>n;
		    // cin.ignore();
		    // vector<string> arr(n);
		    // for(int i=0;i<n;i++){
		    //     getline(cin,arr[i]);
		    //     cout<<arr[i]<<endl;
		    // }
		    // cout<<solve(n,arr);
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
		}
		}*/
		

		// ==> NOTE: Comment main function and uncomment below line to verify your code 
		// #include "../../include/test1_cases.h" 
		#include "../../include/test1_cases.h" 
