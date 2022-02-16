#include <bits/stdc++.h>
using namespace std;

string popfront(string s){
    s.erase(0,1);
    return s;
}
string popfront_back(string s){
    s.erase(0,1);
    s.erase(s.size()-1);
    return s;
}
string popback(string s){
    s.erase(s.size()-1);
    return s;
}
map<string, int> variables;

void processing(vector<string> args){
    string operator=args[0];
    
    if(operator=="add"){
        string i,j,k;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = popfront(args[3]);
        variables[i]=variables[j]+variables[k];
    }
    else if(operator=="sub"){
        string i,j,k;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = popfront(args[3]);
        variables[i]=variables[j]-variables[k];
    }
    else if(operator=="addi"){
        int k;
        string i,j;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = stoi(args[3]);
        variables[i]=variables[j]+k;
    }
    else if(operator=="and"){
        string i,j,k;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = popfront(args[3]);
        variables[i]=variables[j]&variables[k];
    }
    else if(operator=="or"){
        string i,j,k;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = popfront(args[3]);
        variables[i]=variables[j] | variables[k];
    }
    else if(operator=="mul"){
        string i,j,k;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = popfront(args[3]);
        variables[i]=variables[j]*variables[k];
    }
    else if(operator=="andi"){
        int k;
        string i,j;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = stoi(args[3]);
        variables[i]=variables[j]&k;
    }
    else if(operator=="ori"){
        int k;
        string i,j;
        i = popfront_back(args[1]);
        j = popfront_back(args[2]);
        k = stoi(args[3]);
        variables[i]=variables[j] | k;
    }
    else if(operator=="li"){
        string i;
        int j;
        i = popfront_back(args[1]);
        j = stoi(args[2]);
        variables[i]=j;
    }
    else if(operator=="sw"){
        string i = popfront_back(args[1]);
        variables["answer"]= variables[i]
    }
    else{
        cout <<"ERROR";
    }
}

int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    variables.clear();
    for(int l=0;l<n;l++){
        string operator;
        string instr = arr[l];
        stringstream instruction(instr);
        vector<string> args;
        while(instruction>>operator){
            args.push_back(operator);
        }
        processing(args); 
    }
    answer=variables["answer"];

    // End your code here
    return answer;
}

//int main(){
//    int n;
//    cin>>n;
//    cin.ignore();
//    vector<string> arr(n);
//    for(int i=0;i<n;i++){
//        getline(cin,arr[i]);
//        cout<<arr[i]<<endl;
//    }
//    cout<<solve(n,arr);
//    return 0;
//}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"
