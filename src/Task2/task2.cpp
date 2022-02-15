#include <bits/stdc++.h>
using namespace std;
#define int unsigned int
#define pb push_back

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    if (a.second==b.second)
    {
        return(a.first<b.first);
    }
    else
    return (a.second > b.second);
}

class Solution {
    private:
    int n; // n is size that user inputs
    vector<unsigned int>v,ans1,ans2,ans3; // v is the vector that user inputs
   
    void solve_task1()
    {
        // solve task1 and save the answer in ans1
        set<int>s;
        for (int i = 0; i < n; i++)
        {
            s.insert(v[i]);
        }
        for (int i = 0; i < s.size(); i++)
        {
            ans1.pb(s[i]);
        }        
    }

    void solve_task2()
    {
        // solve task2 and save the answer in ans2
        vector<pair<int,int>>t;
        for (int i = 0; i < n-1; i=i+2)
        {
            int x=v[i];
            int y=v[i+1];
            t.pb({x,y});
        }
        sort(t.begin(), t.end(), sortbysec);
        for (int i = 0; i <t.size() ; i++)
        {
            ans2.pb(t[i].first);
        }

    }
    void solve_task3()
    {
        // solve task3 and save the answer in ans3
          vector<pair<int,int>>t;
        for (int i = 0; i < n-1; i=i+2)
        {
            int x=v[i];
            int y=v[i+1];
            t.pb({x,y});
        }
        queue<int>q;
        for (int i = 0; i < t.size(); i++)
        {
            if(t[i].first%2 !=0)
            {
                q.push(t[i].second);
            }
            else
            {
                q.push(t[i].second);
                q.pop();
            }
        }

        while(!q.empty())
        {
            int x=q.front();
            ans3.pb(x);
            q.pop();
        }        
    }
    
    public:
    // create a constructor to take input
        Solution(int size, vector<int>vect)
    {
        n = size;
        v = vect;
        solve_task1();
        solve_task2();
        solve_task3();
    }

    string FINDMATCH(string path)
    {
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer
};



// int main(){
//     vector<unsigned int>a{5,7,6,5,2,1,4,0,1,3};
//     string paths[]={
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };
    // Intialize your solution object here

    // Make a for loop to go through paths array and call FINDMATCH function

    return 0;
}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test2_cases.h"