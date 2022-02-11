#include <bits/stdc++.h>
using namespace std;

// Creating some helper functions to process the data
string popFrontAndBack(string s){
    s.erase(0, 1);
    s.erase(s.size() - 1);
    return s;
}

string popFront(string s){
    s.erase(0,1);
    return s;
}

string popBack(string s){
    s.erase(s.size()-1);
    return s;
}

// Structure for storing the variable names and their values
map<string, int> variables;

void perform_instruction(vector<string> args){
    string opr = args[0];

    if (opr=="add"){
        string a,b,c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = popFront(args[3]);
        
        variables[a] = variables[b] + variables[c];
    }
    else if (opr=="sub"){
        string a,b,c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = popFront(args[3]);
        
        variables[a] = variables[b] - variables[c];
    }
    else if (opr=="addi"){
        string a,b;
        int c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = stoi(args[3]);

        variables[a] = variables[b] + c;
    }
    else if (opr=="mul"){
        string a,b,c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = popFront(args[3]);
        
        variables[a] = variables[b] * variables[c];
    }
    else if (opr=="and"){
        string a,b,c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = popFront(args[3]);
        
        variables[a] = variables[b] & variables[c];
    }
    else if (opr=="or"){
        string a,b,c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = popFront(args[3]);
        
        variables[a] = variables[b] | variables[c];
    }
    else if (opr=="andi"){
        string a,b;
        int c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = stoi(args[3]);
        
        variables[a] = variables[b] & c;
    }
    else if (opr=="ori"){
        string a,b;
        int c;
        a = popFrontAndBack(args[1]);
        b = popFrontAndBack(args[2]);
        c = stoi(args[3]);
        
        variables[a] = variables[b] | c;
    }
    else if (opr=="li"){
        string a;
        int b;
        a = popFrontAndBack(args[1]);
        b = stoi(args[2]);

        variables[a] = b;
    }
    else if (opr=="sw"){
        string a = popFrontAndBack(args[1]);
        variables["answer"] = variables[a];
    }
    else{
        cout<< "Unrecognised operation encountered";
    }
}


int solve(int n, vector<string> arr){
    int answer=0;

    // Start your code here
    
    variables.clear();

    for(int i=0; i<n; i++){

        string instr = arr[i];
        string opr;
        stringstream instruction(instr);

        vector<string> args;

        while(instruction >> opr){
            args.push_back(opr);
        }
        perform_instruction(args);

    }

    answer = variables["answer"];

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