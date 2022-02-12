#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int n;                                    // n is size that user inputs
    vector<unsigned int> v, ans1, ans2, ans3; // v is the vector that user inputs

    void solve_task1()
    {
        // solve task1 and save the answer in ans1

        set<unsigned int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(v[i]);
        }

        for (int i : s)
        {
            ans1.push_back(i);
        }
    }

    // compare pairs
    // returns true if p1 < p2
    bool compare_pairs(pair<unsigned int, unsigned int> p1, pair<unsigned int, unsigned int> p2)
    {

        if (p1.second > p2.second)
            return false;
        else if (p1.second == p2.second)
        {
            if (p1.first > p2.first)
                return true;
            else
                return false;
        }
        else
            return true;
    }

    // function to sort the pairs
    vector<pair<unsigned int,unsigned int>> selectionSortTask2(vector<pair<unsigned int,unsigned int>> v, int n)
    {
        int i, j;
        pair<unsigned int,unsigned int> temp;

        for (i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (compare_pairs(v[i], v[j]))
                {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
        return v;
    }

    void solve_task2()
    {

        // solve task2 and save the answer in ans2

        // create pairs
        vector<pair<unsigned int, unsigned int>> pairs;
        for (int i = 1; i <= n / 2; i++)
        {
            pair<unsigned int, unsigned int> p;
            p.first = v[2 * i - 2];
            p.second = v[2 * i - 1];
            pairs.push_back(p);
        }

        // sorting the pairs
        pairs = selectionSortTask2(pairs, n / 2);

        // forming the answer vector

        for (int i = 0; i < n / 2; i++)
        {
            ans2.push_back(pairs[i].first);
        }
    }

    void solve_task3()
    {
        // solve task3 and save the answer in ans3

        vector<pair<unsigned int, unsigned int>> pairs;
        for (int i = 1; i <= n / 2; i++)
        {
            pair<unsigned int, unsigned int> p;
            p.first = v[2 * i - 2];
            p.second = v[2 * i - 1];
            pairs.push_back(p);
        }

        queue<unsigned int> q;
        for (pair<unsigned int, unsigned int> p : pairs)
        {
            if (p.first % 2 == 1)
                q.push(p.second);
            else
            {
                q.push(p.second);
                q.pop();
            }
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

        // Functions to print out the answer arrays to verify the answers.

        // for(unsigned int i:ans1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        // for(unsigned int i:ans2){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        // for(unsigned int i:ans3){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
       
    }

    string FINDMATCH(string path)
    {
        // complete this function to read file, compare with ans1, ans2, ans3
        // and return the answer

        ifstream file;
        file.open(path, ios::binary);

        if (!file.is_open()){
            cout<<"The file can't be opened.\n";
            return "ERROR";
        }

        file.seekg(0, ios::end);
        int file_size = file.tellg();
        file.seekg(0, ios::beg);

        unsigned int read_data;
        int size_int = sizeof(int);
        vector<unsigned int> answer;

        while(file.tellg() != file_size){
            file.read((char *) &read_data, size_int);
            answer.push_back(read_data);
        }
        
        // Function for testing the answer array formed

        // for(unsigned int i:answer){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        if (ans1==answer) return "TASK1";
        else if (ans2==answer) return "TASK2";
        else if (ans3==answer) return "TASK3";
        else return "NOTFOUND";
         
    }
};

// int main()
// {
//     vector<unsigned int> a{5, 7, 6, 5, 2, 1, 4, 0, 1, 3};
//     string paths[] = {
//         "missing_files/missing1.bin",
//         "missing_files/missing2.bin",
//         "missing_files/missing3.bin",
//         "missing_files/missing4.bin",
//     };

//     // Intialize your solution object here
//     Solution sol(a.size(), a);

//     // Make a for loop to go through paths array and call FINDMATCH function
//     for(string path : paths){
//         cout<<sol.FINDMATCH(path)<<endl;
//     }


//     return 0;
// }

// ==> NOTE: Comment main function and uncomment below line to verify your code
#include "../../include/test2_cases.h"