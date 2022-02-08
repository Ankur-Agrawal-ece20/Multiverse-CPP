#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int n;
    vector<unsigned int>v,ans1,ans2,ans3;
    void solve_task1(){
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(v[i]);
        }
        for(auto &e:s){
            ans1.push_back(e);
        }
    }
    public:
    Solution(int x,vector<unsigned int> &a) {
        n=x;
        v=a;
        solve_task1();
    }
    string FINDMATCH(string path){
        vector<unsigned int> data;
        ifstream binaryfile;
        binaryfile.open(path, ios::in | ios::binary);
        binaryfile.seekg(0, ios::end);
        int length = binaryfile.tellg();
        binaryfile.seekg(0, ios::beg);
        while (binaryfile.tellg() != length){
            unsigned int x;
            binaryfile.read((char *)&x, sizeof(int));
            data.push_back(x);
        }
        if(data==ans1){
            return "task1";
        }
        else if(data==ans2){
            return "task2";
        }
        else if(data==ans3){
            return "task3";
        }
        else{
            return "Not Found";
        }
    }
};

void write_to_file(string path,vector<unsigned int> &a){
    ofstream binaryfile;
    binaryfile.open(path, ios::out | ios::binary);
    for(auto &e:a){
        binaryfile.write((char *)&e, sizeof(int));
    }
    binaryfile.close();
}

int main(){
    vector<unsigned int> testcase1{1,2,3,4,5,6};
    vector<unsigned int> testcase2{1,2,4,5,6};
    write_to_file("missing_files/testcase1.bin",testcase1);
    write_to_file("missing_files/testcase2.bin",testcase2);
    vector<unsigned int> solve{1,5,2,6,3,4,4,4,6,2,2};
    Solution solution1(solve.size(),solve);
    string path="missing_files/testcase1.bin";
    string ans=solution1.FINDMATCH(path);
    cout<<ans<<endl;
    path="missing_files/testcase2.bin";
    ans=solution1.FINDMATCH(path);
    cout<<ans<<endl;
    // int n;
    // cin>>n;
    // vector<string> arr(n);
    // for(int i=0;i<n;i++) getline(cin,arr[i]);
    // cout<<solve(n,arr);
    return 0;
}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
// #include "../../include/test1_cases.h"