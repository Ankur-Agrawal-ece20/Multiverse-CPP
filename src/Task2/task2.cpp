#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

bool secondSort(const pair<int,int> &p1, const pair<int,int> &p2)
{
    if (p1.second == p2.second){
        return (p1.first < p2.first) ;
    }
    else{
        return (p1.second > p2.second);
    }
}

class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
    void solve_task1(){
        // solve task1 and save the answer in ans1
        set<unsigned int> a;
        for (auto i: v){
            a.insert(i);
        }
        for (auto i: a){
            ans1.push_back(i);
        }
    }
    void solve_task2(){
        // solve task2 and save the answer in ans2
        vector<pair<unsigned int, unsigned int>> a ;
        for (int i=0; i<v.size(); i = i+2){
            a.push_back(make_pair(v[i], v[i+1]));
        }
        sort(a.begin(), a.end(), secondSort);
        for (auto i: a){
            ans2.push_back(i.first);
        }
    }
    void solve_task3(){
        // solve task3 and save the answer in ans3
        queue<unsigned int> q;
        vector<pair<unsigned int, unsigned int>> a ;
        for (int i=0; i<v.size(); i = i+2){
            a.push_back(make_pair(v[i], v[i+1]));
        }
        for (auto i: a){
            if (i.first % 2 == 0){
                q.push(i.second);
                q.pop();
            }
            else{
                q.push(i.second);
            }
        }
        while (!q.empty()){
            ans3.push_back(q.front());
            q.pop();
        }
    }
    
    public:
    // create a constructor to take input
    Solution(size_t length, vector<unsigned int> a){
        n = length;
        v = a;
        solve_task1();
        solve_task2();
        solve_task3();
    }

    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        vector<unsigned int> binFile ;
        int length = 0;
        ifstream binaryFile;
        binaryFile.open("../../" + path, ios::in | ios::binary) ;
        binaryFile.seekg(0, ios::end) ;
        length = (int)binaryFile.tellg();
        binaryFile.seekg(0, ios::beg) ;
        while (binaryFile.tellg() < length){
            unsigned int x;
            binaryFile.read((char*)&x, sizeof(unsigned int)) ;
            binFile.push_back(x);
        }
        binaryFile.close(); 

        // and return the answer
        if (ans1 == binFile){
            binFile.clear() ;
            return ("TASK1");
        }
        else if (ans2 == binFile && v.size()%2 == 0){
            binFile.clear() ;
            return ("TASK2");
        }
        else if (ans3 == binFile && v.size()%2 == 0){
            binFile.clear() ;
            return ("TASK3");
        }
        else{
            binFile.clear() ;
            return ("NOTFOUND");
        }
    }
};



// int main(){
//     vector<unsigned int>a{5,7,6,5,2,1,4,0,1,3};
//     string paths[]={
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };
//     // Intialize your solution object here
//     Solution solution(a.size(), a) ;
//     // Make a for loop to go through paths array and call FINDMATCH function

//     for (auto path: paths){
//         cout<<solution.FINDMATCH(path)<<endl;
//     }

//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"