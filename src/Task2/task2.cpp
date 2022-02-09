#include <bits/stdc++.h>
using namespace std;

bool custom_sort(pair<int,int> p1, pair<int,int> p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}

void write_to_file(string path,vector<unsigned int> &a){
    ofstream binaryfile;
    binaryfile.open(path, ios::out | ios::binary);
    for(auto &e:a){
        binaryfile.write((char *)&e, sizeof(int));
    }
    binaryfile.close();
}

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
    void solve_task2(){
        vector<pair<int,int> > vp;
        for(int i=0;i<n;i+=2){
            vp.push_back({v[i],v[i+1]});
        }
        sort(vp.begin(),vp.end(),custom_sort);
        for(auto &e:vp){
            ans2.push_back(e.first);
        }
    }
    void solve_task3(){
        queue<int> q;
        for(int i=0; i<n; i+=2){
            q.push(v[i+1]);
            if(v[i] % 2 == 0)
                q.pop();
        }
        while (!q.empty()) {
            ans3.push_back(q.front());
            q.pop();
        }
    }
    
    public:
    Solution(int x,vector<unsigned int> &a) {
        n=x;
        v=a;
        solve_task1();
        solve_task2();
        solve_task3();
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
            return "TASK1";
        }
        else if(data==ans2){
            return "TASK2";
        }
        else if(data==ans3){
            return "TASK3";
        }
        else{
            return "NOTFOUND";
        }
    }
};



// int main(){
//     vector<unsigned int> testcase1;
//     vector<unsigned int> testcase2;
//     vector<unsigned int> solve;
//     for(int i=0;i<77;i++){
//         solve.push_back(random()%1000);
//         cout<<solve.back()<<", ";
//         if(i%2==0){
//             testcase1.push_back(solve.back());
//         }
//         else{
//             testcase2.push_back(solve.back());
//         }
//     }
//     cout<<endl;
//     // write_to_file("missing_files/testcase5.bin",testcase1);
//     // write_to_file("missing_files/testcase4.bin",testcase2);
//     Solution solution1(solve.size(),solve);
//     // string path="missing_files/testcase1.bin";
//     // string ans=solution1.FINDMATCH(path);
//     // cout<<ans<<endl;
//     for(int i=0;i<5;i++){
//         string path="missing_files/testcase"+to_string(i+1)+".bin";
//         string ans=solution1.FINDMATCH(path);
//         cout<<ans<<endl;
//     }
// //     // int n;
// //     // cin>>n;
// //     // vector<string> arr(n);
// //     // for(int i=0;i<n;i++) getline(cin,arr[i]);
// //     // cout<<solve(n,arr);
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"