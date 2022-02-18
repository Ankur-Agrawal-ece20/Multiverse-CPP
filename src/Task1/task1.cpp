#include <bits/stdc++.h>
#include<sstream>
using namespace std;
map<string, int> map1;
void instruction(string command, string str1, string str2, string str3){
  if (command=="add"){
    map1[str1]=map1[str2]+map1[str3];
  }
  else if(command=="sub"){
    map1[str1]=map1[str2]-map1[str3];
  }
  else if(command=="addi"){
    stringstream ss(str3);
    int i=0;
    ss>>i;
    map1[str1]=map1[str2]+ i;
  }
  else if(command=="mul"){
    map1[str1]=map1[str2]*map1[str3];
  }
  else if(command=="and"){
    map1[str1]=map1[str2]&map1[str3];
  }
  else if(command=="or"){
    map1[str1]=map1[str2]|map1[str3];
  }
  else if(command=="andi"){
    stringstream ss(str3);
    int i=0;
    ss>>i;
    map1[str1]=map1[str2]&i;
  }
  else if(command=="ori"){
    stringstream ss(str3);
    int i=0;
    ss>>i;
    map1[str1]=map1[str2]|i;
  }
  else if(command=="sw"){
    map1["answer"]=map1[str1];
  }
  else if(command=="li"){
    stringstream ss(str3);
    int i=0;
    ss>>i;
    map1[str1]=i;
  }
    }
int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
for(int i=0; i<n;i++){
  string str;
  for(int j=0; j < arr[i].size(); j++){
    if(arr[i][j] != ','){
    str=str + arr[i][j];
    }
  }
  arr[i]=str;
}
for(int i=0; i<n;i++){
  string a, command, x, y, z;
   a = arr[i];
  stringstream ss1;
  ss1<<a;
  ss1>>a;
  command=a;
  ss1>>a;
  x=a;
  ss1>>a;
  y=a;
  ss1>>a;
  z=a;
  instruction(command,x,y,z);
}
  answer=map1["answer"];
    // End your code here
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