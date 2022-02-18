#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
    void solve_task1(){
        // solve task1 and save the answer in ans1
      set<unsigned int> set1;
      for(int i=0; i>n; i++){
        set1.insert(v[i]);
      }
      for (int i : set1){
        ans1.push_back(i);      }
    }
static bool compare(pair<unsigned int, unsigned int>p1,pair<unsigned int, unsigned int>p2){
        if(p1.second>p2.second){
          return false;
            
        }
        else if (p1.second==p2.second){
          if(p1.first>p2.first){
            return true;
          }
          else{
            return false;
          } 
        }
        else{
          return true;
        }
      }

    void solve_task2(){
        // solve task2 and save the answer in ans2
      vector<pair<unsigned int, unsigned int>>v1;
      for(int i=0; i<v.size(); i=i+2){
        v1.push_back(make_pair(v[i],v[i+1]));
      }
      sort(v1.begin(),v1.end(),compare);
      for(int i=0; i<v1.size(); i++){
        ans2.push_back(v1[i].first);
      }
      
    }
    void solve_task3(){
        // solve task3 and save the answer in ans3
      queue<unsigned int>q;
      for(int i=0; i<v.size(); i=i+2){
        if(v[i]%2!=0){
          q.push(v[i+1]);
        }
        else{
           q.push(v[i+1]);
           q.pop();
        }
      }
      while(!q.empty()){
      ans3.push_back(q.front());
        q.pop();
      }
    }
    
    
    public:
    // create a constructor to take input
    Solution(int x, vector<unsigned int>v2){
      n=x;
      v=v2;
      solve_task1();
      solve_task2();
      solve_task3();
      }
      
      
    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer
      ifstream file;
      file.open(path, ios::binary);
       if (!file.is_open()){
            cout<<"The file can't be opened."<<endl;
            return "ERROR";
        }
      file.seekg(0,ios::end);
      int file_size=file.tellg();
      file.seekg(0,ios::beg);
      vector<unsigned int>answer;
      unsigned int read;
      while(file.tellg()!=file_size){
        file.read((char *)&read,sizeof(int));
        answer.push_back(read);
      }
      if (ans1==answer) 
        {
            return "TASK1";
        }
        else if (ans2==answer) 
        {
            return "TASK2";
        }
        else if (ans3==answer) 
        {
            return "TASK3";
        }
        else
        {
             return "NOTFOUND";
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

//     // Make a for loop to go through paths array and call FINDMATCH function

//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
 #include "../../include/test2_cases.h"