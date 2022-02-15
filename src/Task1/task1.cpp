#include <bits/stdc++.h>
using namespace std;
#define per(i , j , n) for(int i = j ; i >= n ; i--) 

int STOI(string s) { 
    int num = 0; 
    int po = 1; 
    per(i , s.size() - 1 , 0) { 
        num += po * (s[i] - '0'); 
        po *= 10; 
    } 
    return num; 
} 

int process(string op, string var1, string var2, map<string, int> data) {
    if(op=="add") {
        return data[var1] + data[var2];
    } else if(op=="addi") {
        return data[var1] + STOI(var2);
    }else if(op=="sub") {
        return data[var1] - data[var2];
    } else if(op=="mul") {
        return data[var1] * data[var2];
    } else if(op=="and") {
        return data[var1] & data[var2];
    } else if(op=="or") {
        return data[var1] | data[var2];
    } else if(op=="andi") {
        return data[var1] & STOI(var2);
    } else if(op=="ori") {
        return data[var1] | STOI(var2);
    } else {
        return 0;
    }
}

int solve(int n, vector<string> arr){
    map<string, int> data;
    int answer=0;
    // Start your code here
    for(int i=0; i<n; i++) {
        stringstream ss;
        for(int j=0; j<arr[i].size(); j++) {
            if(arr[i][j]==',') {
                arr[i][j] = ' ';
            }
        }
        ss << arr[i];
        string temp;
        vector<string> v;
        while(ss >> temp) {
            v.push_back(temp);
        }

        if(v[0] == "sw" && v[2]=="answer") {
            answer = data[v[1]];
            return answer;
        } else if (v[0] == "li") {
            data[v[1]] = STOI(v[2]);
        } else {
            data[v[1]] = process(v[0], v[2], v[3], data);
        }
    }
    // End your code here
    return answer;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
    }
    cout<<solve(n,arr);
    return 0;
}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
// #include "../../include/test1_cases.h"