#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<string> arr){
    int answer=0;
    string mips,a,b,c;
    // Started my code here
    map<string,int>mp1;
    for (int i = 0; i < n;i++){
        string s;
        for (int j = 0; j < arr[i].size();j++){
            if (arr[i][j] !=','){
                  s += arr[i][j];
            }
         
        }
        arr[i]=s;
    }
    for (int i=0; i < n; i++){
        string s=arr[i];
        stringstream ss;
        ss<<s;
        ss>>s;
        mips = s;
        ss>>s;
        a = s;
        ss>>s;
        b = s;
        ss>>s;
        c =s;
    
    if (mips=="li"){
        stringstream str_to_num(b);
        int add=0;
        str_to_num>>add;
        mp1[a]=add;
    }
    else if (mips == "add"){
        mp1[a]=mp1[b]+mp1[c];
    }
    else if (mips == "sub"){
        mp1[a]=mp1[b]-mp1[c];
    }
    else if (mips == "addi"){
        stringstream str_to_num(c);
        int add=0;
        str_to_num>>add;
        mp1[a]=mp1[b]+add;
    }
    else if(mips == "mul"){
        mp1[a] = mp1[b]*mp1[c];
    }
    else if (mips == "and"){
        mp1[a] = mp1[b]&mp1[c];
    }
    else if (mips == "or"){
        mp1[a] = mp1[b]|mp1[c];
    }
    else if (mips == "andi"){
        stringstream str_to_num(c);
        int add =0;
        str_to_num>>add;
        mp1[a]=mp1[b]&add;
    }
    else if (mips == "ori"){
        stringstream str_to_num(c);
        int add=0;
        str_to_num>>add;
        mp1[a] = mp1[b]|add;
    }
    else if (mips == "sw"){
        mp1["answer"]=mp1[a];
        answer =mp1["answer"];
    
    }
    
    // End your code here
    }  return answer;
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

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"