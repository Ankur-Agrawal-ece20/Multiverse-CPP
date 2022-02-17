#include <bits/stdc++.h>
using namespace std;

vector<string> seperate(string& args) {
    
    vector<string> v;
    string delim = ", ";
    size_t start = 0U;
    size_t end = args.find(delim);
    while (end != std::string::npos)
    {
        v.push_back(args.substr(start, end - start));
        start = end + delim.length();
        end = args.find(delim, start);
    }

    v.push_back(args.substr(start, end));
    return v;
}


void do_add(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] + variables[params[2]];
}


void do_sub(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] - variables[params[2]];
}


void do_addi(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] + stoi(params[2], nullptr);
}


void do_mul(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] * variables[params[2]];
}


void do_and(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] & variables[params[2]];
}


void do_or(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] | variables[params[2]];
}


void do_andi(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] & stoi(params[2], nullptr);
}


void do_ori(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = variables[params[1]] | stoi(params[2], nullptr);
}


void do_li(vector<string>& params, unordered_map<string, int>& variables) {
    variables[params[0]] = stoi(params[1], nullptr);
}

int solve(int n, vector<string>& arr){

    unordered_map<string, int> variables;

    for (string& command : arr) {

        string instruction = command.substr(0, command.find(' '));
        string rest = command.substr(command.find(' ') + 1);
        vector<string> params = seperate(rest);
        
        if (instruction == "add") do_add(params, variables);
        else if (instruction == "sub") do_sub(params, variables);
        else if (instruction == "addi") do_addi(params, variables);
        else if (instruction == "mul") do_mul(params, variables);
        else if (instruction == "and") do_and(params, variables);
        else if (instruction == "or") do_or(params, variables);
        else if (instruction == "andi") do_andi(params, variables);
        else if (instruction == "ori") do_ori(params, variables);
        else if (instruction == "li") do_li(params, variables);
        else if (instruction == "sw") {
            return variables[params[0]];
        }
    }
    return -1;
}






#include "../../include/test1_cases.h"