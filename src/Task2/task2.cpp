#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
    void solve_task1(){
        // solve task1 and save the answer in ans1
        set<int> st1;
        for(int i=0;i<n;i++)
        {
            st1.insert(v[i]);
        }
        set<int>:: iterator itr;
        for(itr=st1.begin(); itr!=st1.end(); itr++){
            cout<< *itr<< ' ';
            ans1.push_back(*itr);
        }
    }
    void solve_task2(){
        // solve task2 and save the answer in ans2
        vector<vector <unsigned int>> vec1;
        vector<unsigned int> vec2 = v;
        for (auto itr=vec2.begin(); itr!=vec2.end(); itr+=2){
            vector<unsigned int> temp={*itr,*(itr+1)};
            vec1.push_back(temp);
        }

        vector<unsigned int> temp1;
        map<int, vector<unsigned int>> mp1;
        for(auto itr=vec1.begin(); itr!=vec1.end();itr++){
            temp1.push_back((*itr)[1]);
            mp1[(*itr)[1]]= *itr;
        }
        sort(temp1.begin(), temp1.end(), greater<>());
        for(auto itr=temp1.begin();itr!=temp1.end();itr++){
            ans2.push_back(mp1[*itr][0]);
        }

    }
    void solve_task3(){
        // solve task3 and save the answer in ans3
        vector<vector <unsigned int>> vec1;
        vector<unsigned int> vec2 = v;
        for (auto itr=vec2.begin(); itr!=vec2.end(); itr+=2){
            vector<unsigned int> temp={*itr,*(itr+1)};
            vec1.push_back(temp);
        }

        queue<int> q1;
        for(auto itr= vec1.begin(); itr!=vec1.end(); itr++){
            if((*itr)[0]%2!=0){
                q1.push((*itr)[1]);
            }
            else{
                q1.push((*itr)[1]);
                q1.pop();
            }
        }
        queue<int> q_temp=q1;
        while(!q_temp.empty()){
            cout<<q_temp.front()<<" ";
            q_temp.pop();
        }

    }
    
    public:
    // create a constructor to take input
    Solution(int x, vector<unsigned int> v1){
        n=x;
        v=v1;
        solve_task1();
        solve_task2();        
        solve_task3();        

    }


    string FINDMATCH(string path){
        // complete this function to read file, compare with ans1, ans2, ans3
        vector<unsigned int> bfile;
        ifstream binaryFile;
        binaryFile.open(path, ios::in|ios::binary);
        binaryFile.seekg(0,ios::end);
        int length=binaryFile.tellg();
        binaryFile.seekg(0,ios::beg);
        while(binaryFile.tellg()!=length){
            int x;
            binaryFile.read((char*)&x, sizeof(int));
            bfile.push_back((int)x);
        }
        binaryFile.close();
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
// #include "../../include/test2_cases.h"