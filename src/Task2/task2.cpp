#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
    void solve_task1(){
        set <unsigned int>  s;
        for (int i = 0; i < n; i++)         s.insert(v[i]);
        for (int i = 0; i < n; i++)         ans1.push_back(v[i]);
    }
    

    void solve_task2(){
        // solve task2 and save the answer in ans2
        vector < pair<unsigned int , unsigned int > >   vec_grp;
        for (int i = 0; i <= (n/2); i++)
        {
            pair<unsigned int, unsigned int> p;
            p.first = v[2*i -2];
            p.second = v[2*i -1];
            vec_grp.push_back(p);
        }
        pair<unsigned int,unsigned int> temp;
        for (int i = 0; i < vec_grp.size(); i++)
        {
            for (int j = i + 1; j < vec_grp.size(); j++)
            {
                if (vec_grp[i].second > vec_grp[j].second)
                    continue;
                else if (vec_grp[i].second == vec_grp[j].second)
                {
                    if (vec_grp[i].first > vec_grp[j].first)
                    {
                        temp = vec_grp[i];
                        vec_grp[i] = vec_grp[j];
                        vec_grp[j] = temp;
                    }
                    else
                        continue;
                }
                else{
                    temp = vec_grp[i];
                    vec_grp[i] = vec_grp[j];
                    vec_grp[j] = temp;
                }    
                    
               
            }
        }
        
        for (int i = 0; i < n / 2; i++)
            ans2.push_back(vec_grp[i].first);
        

    }
                   


    void solve_task3(){
        // solve task3 and save the answer in ans3
        queue <unsigned int>    q;
        vector < pair<unsigned int , unsigned int > >   vec_grp;
        for (int i = 0; i < (n/2)+1; i++)
        {
            pair<unsigned int, unsigned int> p;
            p.first = v[2*i -2];
            p.second = v[2*i -1];
            vec_grp.push_back(p);
        }
        for (pair<unsigned int, unsigned int> p : vec_grp)
        {
            if (p.first % 2 == 0){
                q.push(p.second);
                q.pop();
            }
            else
                q.push(p.second);            
        }

        int element;
        while (!q.empty()) 
        {
            element = q.front();
            ans3.push_back(element);
            q.pop();
        }



    }
public:
    // create a constructor to take input
    Solution(int size, vector<unsigned int> arr)
    {
        n = size;
        v = arr;
        solve_task1();
        solve_task2();
        solve_task3();
    }

    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        vector<unsigned int> bfile;
        ifstream binfile;
        if (!binfile.is_open()){
            return "ERROR";
        }
        binfile.open(path, ios::in|ios::binary);
        binfile.seekg(0,ios::end);
        int length=binfile.tellg();
        binfile.seekg(0,ios::beg);
        while(binfile.tellg()!=length){
            int x;
            binfile.read((char*)&x, sizeof(int));
            bfile.push_back((int)x);
        }
        binfile.close();
        cout<<endl;
        string str;
        if(ans1==v){
            str="TASK1";
        }
        else if(ans2==v){
            str="TASK2";
        }
        else if(ans3==v){
            str="TASK3";
        }
        else{
            str="NOTFOUND";
        }
        return str;
        // and return the answer
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
