#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

std::map<string, int> reg;

string rem_comma(string s) {
    s.pop_back();
    return s;
}

void parseLine(vector<string>& line_arr) {
    if (line_arr[0] == "li") {
        reg[rem_comma(line_arr[1])] = stoi(line_arr[2]);
    }
    else if (line_arr[0] == "add") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] + reg[line_arr[3]];
    }
    else if (line_arr[0] == "sub") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] - reg[line_arr[3]];
    }
    else if (line_arr[0] == "sw") {
        reg[line_arr[2]] = reg[rem_comma(line_arr[1])]; 
    }
    else if (line_arr[0] == "mul") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] * reg[line_arr[3]];
    }
    else if (line_arr[0] == "and") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] & reg[line_arr[3]];
    }
    else if (line_arr[0] == "or") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] | reg[line_arr[3]];
    }
    else if (line_arr[0] == "andi") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] & stoi(line_arr[3]);
    }
    else if (line_arr[0] == "ori") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] | stoi(line_arr[3]);
    }
    else if (line_arr[0] == "addi") {
        reg[rem_comma(line_arr[1])] = reg[rem_comma(line_arr[2])] + stoi(line_arr[3]);
    }
}

int solve(int n, vector<string>& arr) {
    int answer = 0;
    // Start your code here

    // Okay, so what we could do is store each line in a stringstream, then iterate over it to 
    for (string& val : arr) {
        std::stringstream ss(val);
        vector<string> line_arr;

        string word;
        while (ss >> word) {
            line_arr.push_back(word);
        }

        parseLine(line_arr);
    }

    // End your code here
    return reg["answer"];
}

// int main() {
//     int n{};
//     cin >> n;
//     cin.ignore();

//     vector<string> arr(n);
//     for (int i = 0; i < n; i++) {
//         std::getline(cin, arr[i]);
//         cout << arr[i] << endl;
//     }

//     cout << solve(n, arr);
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"







