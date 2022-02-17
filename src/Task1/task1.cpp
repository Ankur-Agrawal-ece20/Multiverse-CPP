#include <bits/stdc++.h>
using namespace std;



int solve(int n, vector<string> arr){
    int answer=0;
    unordered_map<string, int> variables;
    for(string command: arr){
        int first_space = command.find(' ');
        
        string keyword = command.substr(0, first_space);
        string param = command.substr(first_space+1);
        
        
        
        if(keyword=="li"){
        
            string var_name = param.substr(0, param.find(','));
            string value = param.substr(param.find(' ')+1);
        
            variables[var_name] = stoi(value, nullptr, 10);

        }
        else if(keyword == "add" || keyword == "sub" || keyword=="addi" || keyword=="and" || keyword=="or" || keyword=="andi" || keyword=="ori" || keyword=="mul"){
        
            string target_var = param.substr(0, param.find(','));

            string delimiter = " ";
            size_t pos = 0;
            std::string token;
            vector <string> tokens;
            while ((pos = param.find(delimiter)) != std::string::npos) {
                token = param.substr(0, pos);
                tokens.push_back(token);
                param.erase(0, pos + delimiter.length());
            }
            tokens.push_back(param);
            string b_var = tokens[2];
            string a_var = tokens[1];
            a_var = a_var.substr(0, a_var.size()-1);
            
            if (keyword=="add")
                variables[target_var] = variables[a_var] + variables[b_var];
            else if (keyword == "sub")
                variables[target_var] = variables[a_var] - variables[b_var];
            else if (keyword == "addi")
                variables[target_var] = variables[a_var] + stoi(b_var, nullptr, 10);
            else if (keyword == "andi")
                variables[target_var] = variables[a_var] & stoi(b_var, nullptr, 10);
            else if (keyword == "ori")
                variables[target_var] = variables[a_var] | stoi(b_var, nullptr, 10);
            else if (keyword == "and")
                variables[target_var] = variables[a_var] & variables[b_var];
            else if (keyword == "or")
                variables[target_var] = variables[a_var] | variables[b_var];
            else if (keyword == "mul")
                variables[target_var] = variables[a_var] * variables[b_var];

        }else if(keyword == "sw"){
            string target_var = param.substr(0, param.find(','));
            answer = variables[target_var];
            
            return answer;
        }

    }

    // Start your code here

    // End your code here
    return answer;
}

// int main(){
//     vector<string> testcase1{
//     "li $t1, 25",	
// 	"li $t2, 35",
// 	"add $t3, $t1, $t2",
// 	"sub $t4, $t1, $t2",
// 	"sw $t4, answer"
//     };

//     cout << solve(5, testcase1)<<endl;
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"