#include <bits/stdc++.h>
using namespace std;

map<string, int> variables;

int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    vector<string> instruction ;
    
    for (int i=0; i<n; i++){
        stringstream ss(arr[i]);
        string word; 
        while (ss >> word) {
            instruction.push_back(word);
        }

        for (int j=1; j<instruction.size()-1; j++){
            instruction[j].pop_back();
        }

        if (instruction[0] == "li"){
            variables[instruction[1]] = stoi(instruction[2]) ;
        }
        else if (instruction[0] == "add"){
            variables[instruction[1]] = variables[instruction[2]] + variables[instruction[3]];
        }
        else if(instruction[0] == "addi"){
            variables[instruction[1]] = variables[instruction[2]] + stoi(instruction[3]);
        }
        else if(instruction[0] == "sub"){
            variables[instruction[1]] = variables[instruction[2]] - variables[instruction[3]];
        }
        else if(instruction[0] == "mul"){
            variables[instruction[1]] = variables[instruction[2]] * variables[instruction[3]];
        }
        else if(instruction[0] == "and"){
            variables[instruction[1]] = variables[instruction[2]] & variables[instruction[3]];
        }
        else if (instruction[0] == "or"){
            variables[instruction[1]] = variables[instruction[2]] | variables[instruction[3]];
        }
        else if(instruction[0] == "andi"){
            variables[instruction[1]] = variables[instruction[2]] & stoi(instruction[3]);
        }
        else if(instruction[0] == "ori"){
            variables[instruction[1]] = variables[instruction[2]] | stoi(instruction[3]);
        }
        else if(instruction[0] == "sw"){
            variables[instruction[2]] = variables[instruction[1]];
        }
        
        instruction.clear();
        ss.clear();
    }
    answer = variables["answer"];
    
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