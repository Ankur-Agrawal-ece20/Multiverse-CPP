#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
    void solve_task1(){
        // solve task1 and save the answer in ans1
        set<unsigned int>s;
        for(auto &value:v)
        {
            s.insert(value);
        }
        for(auto &value:s)
        {
            ans1.push_back(value);
        }
        
    }
    void solve_task2(){
        // solve task2 and save the answer in ans2
         vector<pair<unsigned int,unsigned int>> v2;
        for(int i=0;i<v.size();i=i+2)
        {
              v2.push_back(make_pair(v[i],v[i+1]));
        }
        sort(v2.begin(),v2.end(),cmp);
        for(int i=0;i<v2.size();i++)
        {
            ans2.push_back(v2[i].first);
        }
    }
    void solve_task3(){
        // solve task3 and save the answer in ans3
        queue <unsigned int> q;
        for(int i=0;i<v.size();i=i+2)
        {
            if(v[i]%2!=0)
            {
                q.push(v[i+1]);
            }
            else
            {
                q.push(v[i+1]);
                q.pop();
            }
        }
        while(!q.empty())
        {
            ans3.push_back(q.front());
            q.pop();
        }
    }
    
    public:
    // create a constructor to take input
    Solution(int p,vector<unsigned int> q)
    {
        n=p;
        v=q;
        solve_task1();
        solve_task2();
        solve_task3();
    }
    static bool cmp(pair<unsigned int,unsigned int>a,pair<unsigned int,unsigned int>b)
    {
      if(a.second<b.second)
        {
          return false;
        }
        else if(a.second==b.second)
        {
            if(a.first>b.first)
            {
               return false;
            }
        }
        return true;
    }

    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer
        ifstream myfile;
        myfile.open(path , ios::binary);
        if(!myfile.is_open())
       {
           cout<<"File cannot be opened."<<endl;
           return "ERROR";
       }
        myfile.seekg(0, ios::end);
        int myfile_size = myfile.tellg();
        myfile.seekg(0, ios::beg);
        vector<unsigned int> answer;
        while(myfile.tellg() != myfile_size)
        {
            int x;
            myfile.read((char *)&x,sizeof(int));
            answer.push_back(x);
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
//     Solution x(a.size(),a)
//     // Make a for loop to go through paths array and call FINDMATCH function
//     for(auto value : paths)
//     {
//         cout<<x.FINDMATCH(value)<<endl;
//     }
//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"