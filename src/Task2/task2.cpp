#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs

    void solve_task1(){
        // solve task1 and save the answer in ans1
        set<unsigned int> s;
        for(auto i: v) s.insert(i);
        for(auto i: s) ans1.push_back(i);
        
    }
    void solve_task2(){
        // solve task2 and save the answer in ans2
        vector <pair<unsigned int, unsigned int>> vec;
        for(int i = 0;i<n;i+=2){
            pair <unsigned int, unsigned int> p{v[i], v[i+1]};
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end(), [](pair <unsigned int, unsigned int> a, pair <unsigned int, unsigned int> b){
            if (a.second == b.second){
                return a.first < b.first;
            }
            return a.second>b.second;
        });
        
        for(auto i: vec){
            ans2.push_back(i.first);
        }
        
    }
    void solve_task3(){
        // solve task3 and save the answer in ans3
        vector <pair<unsigned int, unsigned int>> set;
        queue <unsigned int> myQueue;
        for(int i=0;i<n;i+=2){
            if (v[i]%2==1){
                myQueue.push(v[i+1]);
            }else{
                myQueue.push(v[i+1]);   
                myQueue.pop();
            }
        }
        while(!myQueue.empty()){
            ans3.push_back(myQueue.front());
            myQueue.pop();
        }

    }
    
    public:
    Solution(int num, vector <unsigned int> vec){
        n = num;
        v = vec;
        solve_task1();
        solve_task2();
        solve_task3(); 
    }
    // create a constructor to take input
    string FINDMATCH(string path){
        
        path = "../../"+path;
        ifstream file;
        file.open(path, ios::binary);

        if (!file.is_open()) return "ERROR";

        file.seekg(0, ios::end);
        int file_size = file.tellg();
        file.seekg(0, ios::beg);

        unsigned int read_data;
        vector<unsigned int> answer;

        while (file.tellg() != file_size) {
            file.read((char *) &read_data, sizeof(int));
            answer.push_back(read_data);
        }

        if (answer == ans1) return "TASK1";
        else if (answer == ans2) return "TASK2";
        else if (answer == ans3) return "TASK3";
        else return "NOTFOUND";
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

//     // Make a for loop to go through paths array and call FINDMATCH function

//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"